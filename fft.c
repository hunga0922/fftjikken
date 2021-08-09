#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 128
#define LOG_MAX 7
#define N 10

void fft(float x_r[], float x_i[]) 
{
    float tmp_r, tmp_i, tmp_r_lower, tmp_i_lower;
    int i, j, i_lower, index ;
    int stage, dft_pts, num_bf, bf_id;
    float pi;

    pi = -2 * M_PI;

    float arg, e, cos_result, sin_result;

    for (stage = 1; stage <= LOG_MAX; stage++) {
        dft_pts = 1 << stage;
        num_bf = dft_pts / 2;
        e = pi / dft_pts;
        for (j = 0; j < num_bf; j++) {
            arg = e * j;
            cos_result = cos(arg);
            sin_result = sin(arg);
            for (i = j; i < MAX; i += dft_pts) {
                i_lower = i + num_bf;

                tmp_r = x_r[i_lower] * cos_result - x_i[i_lower] * sin_result;
                tmp_i = x_i[i_lower] * cos_result + x_r[i_lower] * sin_result;
                x_r[i_lower] = x_r[i] - tmp_r;
                x_i[i_lower] = x_i[i] - tmp_i; 
                x_r[i] = x_r[i] + tmp_r;
                x_i[i] = x_i[i] + tmp_i;
            }
        }
    }
}

unsigned int reverse_bits(unsigned int input)
{
    unsigned int rev = 0;
    int i;

    for (i = 0; i < LOG_MAX; i++) {
        rev = (rev << 1) | (input & 1);
        input = input >> 1;
    }
    return rev;
}

void bit_reverse(float x_r[], float x_i[])
{
    unsigned int reversed, i;
    float tmp;

    for (i = 0; i < MAX; i++) {
        reversed = reverse_bits(i);
        if (i < reversed) {
            tmp = x_r[i];
            x_r[i] = x_r[reversed];
            x_r[reversed] = tmp;
            
            tmp = x_i[i];
            x_i[i] = x_i[reversed];
            x_i[reversed] = tmp;
        }
    }
}

int main(int argc, char *argv[]) 
{
	FILE *fp, *fsp, *fab, *frad, *fin;
	FILE *f[64];
    float x_r[MAX], x_i[MAX];
	float real;
	char fname[10];
	float sum[MAX],a[MAX],b[MAX];
    int i,j;
	int tmp;
    int correct_flag = 1;
    double ts, te;
	    if(argc!=2) { fprintf(stderr,"fft datafile\n");
                exit(1); }
    if( (fp=fopen(argv[1],"r"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }
    if( (fin=fopen("input.dat","w"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }
    if( (fsp=fopen("sp.dat","w"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }
    if( (frad=fopen("rad.dat","w"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }
    if( (fab=fopen("ab.dat","w"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }
	fname[0]='f';
	fname[1]='0';
	fname[2]='0';
	fname[3]='\0';
	for(i=0; i<10; i++) {
    	if( (f[i]=fopen(fname,"w"))==NULL) {
        	fprintf(stderr,"file cannot open\n");
            exit(1);
		}
		fname[2]++;
	}
	fname[1]='1';
	fname[2]='0';
	for(; i<20; i++) {
    	if( (f[i]=fopen(fname,"w"))==NULL) {
        	fprintf(stderr,"file cannot open\n");
            exit(1);
		}
		fname[2]++;
	}
	fname[1]++;
	fname[2]='0';
	for(; i<30; i++) {
    	if( (f[i]=fopen(fname,"w"))==NULL) {
        	fprintf(stderr,"file cannot open\n");
            exit(1);
		}
		fname[2]++;
	}
    if( (f[63]=fopen("f63","w"))==NULL) {
       	fprintf(stderr,"file cannot open\n");
           exit(1);
	}

    //initialization
/*
    for (i = 0; i < MAX; i++) {
        x_r[i] = cos(N * 2 * M_PI * i / MAX);
        x_i[i] = 0;
		printf("%d %lf\n",i,x_r[i]);
    }
*/
    for (i = 0; i < MAX; i++) {
		fscanf(fp,"%d %f", &tmp, &real);
		fprintf(fin,"%d %f\n", i,real);
        x_r[i] = real;
        x_i[i] = 0;
	}

    bit_reverse(x_r, x_i);
    fft(x_r, x_i);
/*
    for (i = 0; i < MAX; i++) {
        if (i == N || i == MAX - N) {
            if (round(x_r[i]) != MAX/2 || round(x_i[i]) != 0)
                correct_flag = 0;
        } else {
            if (round(x_r[i]) != 0 || round(x_i[i]) != 0)
                correct_flag = 0;
        }
    }

	*/
	fprintf(fab,"an, bn, An, Phi_n\n");
    for (i = 0; i < MAX/2; i++) {
		if(i==0) {
			a[i]=x_r[i]/MAX; b[i]=x_i[i]; }
		else {
			a[i]=x_r[i]/(MAX/2); b[i]=-x_i[i]/(MAX/2); }
		fprintf(fab,"%d	%f %f %f %f\n",i, a[i],b[i],sqrt(a[i]*a[i]+b[i]*b[i]), atan2(b[i],a[i]) );
	}
    for (i = 0; i < MAX/2; i++) {
		fprintf(fsp,"%d	%lf\n",i, sqrt(a[i]*a[i]+b[i]*b[i]) ); 
		fprintf(frad,"%d %lf\n",i, atan2(b[i],a[i]) );
		}
    	for (i = 0; i < MAX; i++) {
				sum[i] = a[0]/MAX;
				fprintf(f[0],"%i %f\n", i, sum[i]);
		}
		for(j=1;j<MAX/2;j++) {
    		for (i = 0; i < MAX; i++) {
				sum[i] = sum[i] + a[j]*cos(2*M_PI*(float)j*(float)i/(float)MAX)+b[j]*sin(2*M_PI*(float)j*(float)i/(float)MAX); 
				if(j<30)
					fprintf(f[j],"%i %f\n", i, sum[i]);
				if(j==MAX/2-1)
					fprintf(f[63],"%i %f\n", i, sum[i]);
			}
		}
}
