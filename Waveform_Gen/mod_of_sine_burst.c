#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "rp.h"

int main(int argc, char **argv){

        int i;
		int buff_size = 16384;
		
		float *t = (float *)malloc(buff_size * sizeof(float));
		float *x = (float *)malloc(buff_size * sizeof(float));


        /* Print error, if rp_Init() function failed */
        if(rp_Init() != RP_OK){
                fprintf(stderr, "Rp api init failed!\n");
        }
		
		for (int i = 0; i < buff_size; ++i){
	    x[i] = (sin(t[i]));
		if(x[i]<0){
		x[i]=-x[i];}
            }

        rp_GenReset();
		
		rp_GenWaveform(RP_CH_2, RP_WAVEFORM_ARBITRARY);
		rp_GenArbWaveform(RP_CH_2, x, buff_size);
        rp_GenFreq(RP_CH_1, 1000);
        rp_GenAmp(RP_CH_1, 1.0);

        rp_GenMode(RP_CH_1, RP_GEN_MODE_BURST);
        rp_GenBurstCount(RP_CH_1, 1);
        rp_GenBurstRepetitions(RP_CH_1, 10000);
        rp_GenBurstPeriod(RP_CH_1, 5000);

        rp_GenOutEnable(RP_CH_1);
        rp_GenTriggerOnly(RP_CH_1);

        rp_Release();
}