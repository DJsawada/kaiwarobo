#include<stdio.h>
int main(void){
	system("julius -plugindir -C ~/work/sawada/voice-recognition/julius-4.3.1/julius-simple/tabaco.jconf -charconv EUC-JP UTF-8 > ~/work/sawada/voice-recognition/julius-4.3.1/julius-simple");
	system("tail -n 1 satukitei.txt");
}
