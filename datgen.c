#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 128
#define N 10

void main(int argc, char *argv[]){
	FILE *fp;
	int i, cmd;
	if(argc!=2) { fprintf(stderr,"datagen datafile\n");
				exit(1); }
	if( (fp=fopen(argv[1],"w"))==NULL) {
		fprintf(stderr,"file cannot open\n");
			exit(1);
	}
	printf("1: cos, 2: sin, 3:step, 4:triangle, 5:beat, 6:sawtooth, 7:cos*cos 8: pulse =>");
	scanf("%d",&cmd);
	// Cos
	if(cmd==1) {
	 for (i = 0; i < MAX; i++) 
	         fprintf(fp,"%d %lf\n", i, cos(2 * M_PI * i / MAX));
	}
	// Sin
	else if(cmd==2) {
	 for (i = 0; i < MAX; i++) 
	         fprintf(fp,"%d %lf\n", i, sin(2 * M_PI * i / MAX));
	}
	// Step
	else if(cmd==3) {
		for(i=0; i<MAX;i++) {
			fprintf(fp,"%d ",i);
			if(i<MAX/3) fprintf(fp,"0.0\n");
			else if(i<2*MAX/3) fprintf(fp,"1.0\n");
			else fprintf(fp,"0.0\n");
		}
	}
	// Triangle
	else if(cmd==4) {
		for(i=0; i<MAX;i++) {
			fprintf(fp,"%d ",i);
			if(i<MAX/2) fprintf(fp,"%f\n",(float)i/(float)(MAX/2) );
			else fprintf(fp,"%f\n",1.0-(float)(i-MAX/2)/(float)(MAX/2) );
		}
	}
	// Beat
	else if(cmd==5) {
		for(i=0; i<MAX;i++) {
	        fprintf(fp,"%d %lf\n", i, cos(6 * 2 * M_PI * i / MAX)+
	        						cos(7 * 2 * M_PI * i / MAX));
		}
	}
	// Sawtooth
	else if(cmd==6) {
		for(i=0; i<MAX;i++) {
			if(i<MAX/2)
	        	fprintf(fp,"%d %f\n", i, (float)i*2 / (float)MAX);
			else
	        	fprintf(fp,"%d %f\n", i, -2 + (float)i*2 / (float)MAX);
		}
	}
	// cos2
	else if(cmd==7) {
	 for (i = 0; i < MAX; i++) 
	         fprintf(fp,"%d %lf\n", i, cos(2 * M_PI * i / MAX)* cos(2*M_PI*i/MAX));
	}
	// Pulse
	else if(cmd==8) {
	 for (i = 0; i < MAX; i++) 
	 	if(i==MAX/2)
	         fprintf(fp,"%d 1.0\n", i );
	 	else
	         fprintf(fp,"%d 0.0\n", i );
	}
}

