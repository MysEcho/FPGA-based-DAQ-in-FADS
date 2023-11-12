This project introduces an innovative approach to
data acquisition utilizing FPGA technology, focusing on real-time
peak detection and storage. The centerpiece of the study is the
design and implementation of a custom Sampling module for
peak detection within an FPGA-based Data Acquisition System.
The Sampling module is characterized by its ability to discern
input signal variations against a user-specified threshold. Upon
detection of a peak in the input signal, the module triggers a
precise sampling process and archives the captured data within
the FPGA’s Block RAM. The paper also emphasizes adaptability
by enabling users to define the number of samples for each peak
and the total number of peaks desired.

**Timing Diagram for the FSM:**


![Sampler with GPIO](https://github.com/MysEcho/FPGA-based-DAQ-in-FADS/assets/135346641/1831004d-f633-49fc-93b7-32a1b99875a1)

**Input Waveform Generation:**


![5](https://github.com/MysEcho/FPGA-based-DAQ-in-FADS/assets/135346641/83e56db5-d54d-4595-8898-15ea0b5b4353)


**Input Waveform(Burst Gaussian pulses):**

![Burst mod sin2](https://github.com/MysEcho/FPGA-based-DAQ-in-FADS/assets/135346641/4cd03f0e-d69e-4aa2-a73b-ccd87055fd1f)



