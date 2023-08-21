#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//#define M_PI 3.14159265358979323846

//FUNCTION FOR GENERATING GAUSSIAN PULSES
double calculateFunction(double t) {
    double A1 = 2;
    double A2 = 1;
    double sigma1 = sqrt(200);
    double sigma2 = sqrt(50);
    
    double term1 = A1 * exp(-pow(t, 2) / (2 * pow(sigma1, 2)));
    double term2 = A2 * exp(-pow((t - 50), 2) / (2 * pow(sigma2, 2)));
    
    return term1 + term2;
}


int main(int argc, char **argv){
	
	
        int i,j=0=;
        int buff_size = 163;
        

		float *t = (float *)malloc(buff_size * sizeof(float));
		float *x = (float *)malloc(buff_size * sizeof(float));
		
		/*for(i = 1; i < buff_size; i++){
			t[i] = (2 * M_PI) / buff_size * i;
		}*/
		for(j=0;j<5;j++){
		for(i = 1; i < buff_size; i++){
			t[i] = i;
		}
	
		for (i = 0; i < buff_size; ++i) {
		x[i] = calculateFunction(t[i]);
		printf("%f\n",x[i]);
		}
	
	}
		free(t);
		free(x);
		
	}