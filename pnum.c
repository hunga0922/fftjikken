#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 128
#define LOG_MAX 7
#define N 10

int main(int argc, char *argv[]) 
{
	FILE *fp, *fpo;
	float real;
	char fname[10];
	float sum[MAX],a[MAX],b[MAX];
    int i,j;
	int tmp;
    int correct_flag = 1;
    double ts, te;
	    if(argc!=3) { fprintf(stderr,"pnum infile outfile\n");
                exit(1); }
    if( (fp=fopen(argv[1],"r"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }
    if( (fpo=fopen(argv[2],"w"))==NULL) {
        fprintf(stderr,"file cannot open\n");
            exit(1);
    }

    for (i = 0; i < MAX; i++) {
		fscanf(fp,"%f", &real);
		fprintf(fpo,"%d %f\n", i,real);
	}
}
