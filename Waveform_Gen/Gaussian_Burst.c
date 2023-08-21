#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "rp.h"

int main(int argc, char **argv){
	int i;
    int buff_size = 16384;
	double A1 = 2;
    double A2 = 1;
    double sigma1 = sqrt(200);
    double sigma2 = sqrt(50);
	
    /* Print error, if rp_Init() function failed */
    if(rp_Init() != RP_OK){
            fprintf(stderr, "Rp api init failed!\n");
    }
	
	float *t = (float *)malloc(buff_size * sizeof(float));
    float *x = (float *)malloc(buff_size * sizeof(float));
    float *y = (float *)malloc(buff_size * sizeof(float));
	
	for(i = 1; i < buff_size; i++){
        t[i] = (2 * M_PI) / buff_size * i;
    }
	
	for (int i = 0; i < buff_size; ++i){
        x[i] = A1 * exp(-pow((t[i] - 20), 2) / pow(sigma1, 2)); //sin(t[i]) + ((1.0/3.0) * sin(t[i] * 3));
        y[i] = A2 * exp(-pow((t[i] - 50), 2) / pow(sigma2, 2));
    }

    rp_GenSynchronise(); // The generator is reset on both channels.

    rp_GenWaveform(RP_CH_1, RP_WAVEFORM_ARBITRARY);
	rp_GenArbWaveform(RP_CH_1, x, buff_size);
    rp_GenFreq(RP_CH_1, 4000);
    rp_GenAmp(RP_CH_1, 0.7);

    rp_GenWaveform(RP_CH_2, RP_WAVEFORM_ARBITRARY);
	rp_GenArbWaveform(RP_CH_2, y, buff_size);
    rp_GenFreq(RP_CH_2, 4000);
    rp_GenAmp(RP_CH_2, 1.0);

    rp_GenMode(RP_CH_1, RP_GEN_MODE_BURST);
    rp_GenBurstCount(RP_CH_1, 2);
    rp_GenBurstRepetitions(RP_CH_1, 1);
    rp_GenBurstPeriod(RP_CH_1, 5000);

    rp_GenMode(RP_CH_2, RP_GEN_MODE_BURST);
    rp_GenBurstCount(RP_CH_2, 2);
    rp_GenBurstRepetitions(RP_CH_2, 1);
    rp_GenBurstPeriod(RP_CH_2, 5000);

    rp_GenOutEnableSync(true);
    sleep(2);
    rp_GenTriggerOnly(RP_CH_1);
    sleep(2);
    rp_GenTriggerOnly(RP_CH_2);
    sleep(1);
    //rp_GenSynchronise();

	free(y);
    free(x);
    free(t);
    rp_Release();
    rp_Release();
}