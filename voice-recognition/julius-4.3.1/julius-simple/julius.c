#include<stdio.h>
int main(void){
	system("padsp ./julius-simple -plugindir . -C ~/work/sawada/voice-recognition/dictation-kit-v4.3.1-linux/tabaco.jconf -nostrip > ~/work/sawada/voice-recognition/julius-4.3.1/julius-simple/satukitei.txt");
	system("tail -n 1 satukitei.txt");
}
