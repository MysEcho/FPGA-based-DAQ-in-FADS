#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "rp.h"

#define M_PI 3.14159265358979323846

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
	
	
        int i;
        int buff_size = 16384;
        if(rp_Init() != RP_OK){
            fprintf(stderr, "Rp api init failed!\n");
        }

		float *t = (float *)malloc(buff_size * sizeof(float));
		float *x = (float *)malloc(buff_size * sizeof(float));
		
		for(i = 1; i < buff_size; i++){
			t[i] = (2 * M_PI) / buff_size * i;
		}

		for (int i = 0; i < buff_size; ++i) {
		x[i] = calculateFunction(t[i]);
		}


        rp_GenReset();

        rp_GenWaveform(RP_CH_2, RP_WAVEFORM_ARBITRARY);
		rp_GenArbWaveform(RP_CH_2, x, buff_size);
        rp_GenFreq(RP_CH_2, 1000);
        rp_GenAmp(RP_CH_2, 1.0);

	/*	//FOR BURST MODE
        rp_GenMode(RP_CH_2, RP_GEN_MODE_BURST);
        rp_GenBurstCount(RP_CH_2, 1);
        rp_GenBurstRepetitions(RP_CH_2, 10000);
        rp_GenBurstPeriod(RP_CH_2, 5000);
	*/

        rp_GenOutEnable(RP_CH_2);
        rp_GenTriggerOnly(RP_CH_2);

		free(x);
		free(t);
        rp_Release();
}



