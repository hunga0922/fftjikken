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
	printf("1: cos, 2: sin, 3:step, 4:triangle, 5:beat =>");
	scanf("%d",&cmd);
	// Cos
	if(cmd==1) {
	 for (i = 0; i < MAX; i++) 
	         fprintf(fp,"%d %lf\n", i, cos(2 * M_PI * i / MAX));
	}
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
	else if(cmd==5) {
		for(i=0; i<MAX;i++) {
	        fprintf(fp,"%d %lf\n", i, cos(6 * 2 * M_PI * i / MAX)+
	        						cos(7 * 2 * M_PI * i / MAX));
		}
	}
}

