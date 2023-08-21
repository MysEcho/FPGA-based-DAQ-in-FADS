#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "rp.h"

#define M_PI 3.14159265358979323846

int main(int argc, char **argv){

    int i;
    int buff_size = 16384;

    // Print error, if rp_Init() function failed 
    if(rp_Init() != RP_OK){
        fprintf(stderr, "Rp api init failed!\n");
    }

    float *t = (float *)malloc(buff_size * sizeof(float));
    float *x = (float *)malloc(buff_size * sizeof(float));

    for(i = 1; i < buff_size; i++){
        t[i] = (2 * M_PI) / buff_size * i;
    }

    for (int i = 0; i < buff_size; ++i){
	    x[i] = (sin(t[i]));
		if(x[i]<0){
		x[i]=-x[i];}
            }

    rp_GenSynchronise();

    rp_GenWaveform(RP_CH_2, RP_WAVEFORM_ARBITRARY);
    rp_GenArbWaveform(RP_CH_2, x, buff_size);

    rp_GenFreq(RP_CH_2, 1000.0);
    rp_GenAmp(RP_CH_2, 1.0);


	rp_GenOutEnable(RP_CH_2);
    rp_GenTriggerOnly(RP_CH_2);

    // Releasing resources 
    free(x);
    free(t);
    rp_Release();
}