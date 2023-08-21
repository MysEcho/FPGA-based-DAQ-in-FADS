/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rp.h"

int main(int argc, char **argv){
    //Print error, if rp_Init() function failed 
    if(rp_Init() != RP_OK){
            fprintf(stderr, "Rp api init failed!\n");
    }

    rp_GenSynchronise(); // The generator is reset on both channels.

    rp_GenWaveform(RP_CH_1, RP_WAVEFORM_SINE);
    rp_GenFreq(RP_CH_1, 4);
    rp_GenAmp(RP_CH_1, 1.0);

    rp_GenWaveform(RP_CH_2, RP_WAVEFORM_SINE);
    rp_GenFreq(RP_CH_2, 4);
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
    rp_GenTrigger(RP_CH_1);
    sleep(2);
    rp_GenTrigger(RP_CH_2);
    sleep(1);
    rp_GenSynchronise();

    rp_Release();
}*/

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

    /*rp_GenMode(RP_CH_2, RP_GEN_MODE_BURST);
    rp_GenBurstCount(RP_CH_2, 2);
    rp_GenBurstRepetitions(RP_CH_2, 1);
    rp_GenBurstPeriod(RP_CH_2, 5000);*/

	rp_GenOutEnable(RP_CH_2);
    rp_GenTriggerOnly(RP_CH_2);

    // Releasing resources 
    free(x);
    free(t);
    rp_Release();
}

/*
#include <stdio.h>
#include <stdlib.h>
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
        x[i] = (sin(t[i]);
		if(x[i]<0)x[i]=-x[i];
    }

    rp_GenSynchronise();

    rp_GenWaveform(RP_CH_2, RP_WAVEFORM_ARBITRARY);

    rp_GenArbWaveform(RP_CH_2, x, buff_size);

    rp_GenAmp(RP_CH_2, 1.0);

    rp_GenFreq(RP_CH_2, 4000.0);
	
	//BURST MODE
	rp_GenMode(RP_CH_1, RP_GEN_MODE_BURST);
    rp_GenBurstCount(RP_CH_1, 2);
    rp_GenBurstRepetitions(RP_CH_1, 1);
    rp_GenBurstPeriod(RP_CH_1, 4000);

    rp_GenOutEnable(RP_CH_2);
    rp_GenTriggerOnly(RP_CH_2);

    // Releasing resources 
    free(x);
    free(t);
    rp_Release();
}
*/


