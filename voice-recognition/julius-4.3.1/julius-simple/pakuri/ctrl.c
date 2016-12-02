#include <signal.h>
#include <stdio.h>
void sigcatch(int);
int main() {
	if (SIG_ERR == signal(SIGHUP, sigcatch)) {
		printf("failed to set signal handler.n");
		exit(1);
	}
	while (1) {
		sleep(1);
	}
	return 0;
}
void sigcatch(int sig) {
	printf("catch signal %dn", sig);
	exit(1);
}
