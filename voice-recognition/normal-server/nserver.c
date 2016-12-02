/*tcp server*/
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
int tcp_listen(char* port);
int main(void){
	char* port = "12345";
	int listenFd;
	int commFd;
	struct sockaddr_storage sa;
	socklen_t len = sizeof(sa);
	char recvline[100]="";
	char sendline[100]="itolab";
	int n;
	double i;
	/*prepare tcp listen port*/
	if((listenFd=tcp_listen(port)) < 0) return 0;
	/*service loop*/
	while(1){
	/*accept connection*/
	if((commFd=accept(listenFd, (struct sockaddr*)&sa, &len)) < 0){
		("ERROR at %s#%d: %s\n", __FILE__, __LINE__,strerror(errno));
		return 0;
	}
	/*read request*/
	if((n = read(commFd, recvline, sizeof(recvline))) < 0) {
		printf("ERROR at %s#%d\n",__FILE__,__LINE__);
		close(commFd);
		return -1;
	}
	printf("Receive:%s\n", recvline);      
	/*write response*/
	if((n=write(commFd, sendline, strlen(sendline))) < 0){
		printf("ERROR at %s#%d\n",__FILE__,__LINE__);
		close(commFd);
		return -1;
	}
	for(i=0;i<1000000000;i++){
	}
	printf("Send:%s\n", sendline);
	close(commFd);
	}
}
/***********************
 prepare tcp listen port
***********************/
int tcp_listen(char* port){
	struct addrinfo hints;
	struct addrinfo* res = NULL;
	int listenFd;
	int err;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol=0;
	hints.ai_flags = AI_PASSIVE|AI_ADDRCONFIG;
	if((err=getaddrinfo(NULL, port, &hints, &res)) != 0){
		printf("ERROR at %s#%d: %s\n", __FILE__, __LINE__, gai_strerror(err));
		return -1;
	}
	if((listenFd = socket(res->ai_family, res->ai_socktype,
	res->ai_protocol)) < 0){
		printf("ERROR at %s#%d: %s\n", __FILE__, __LINE__,strerror(errno));
		return -1;
	}
	int on=1;
	if(setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
		printf("ERROR at %s#%d: %s\n", __FILE__, __LINE__,strerror(errno));
		return -1;
	}
	if(bind(listenFd, res->ai_addr, res->ai_addrlen) < 0){
		printf("ERROR at %s#%d: %s\n", __FILE__, __LINE__,strerror(errno));
		return -1;
	}
	freeaddrinfo(res);
	if(listen(listenFd,SOMAXCONN)){
		printf("ERROR at %s#%d: %s\n", __FILE__, __LINE__,strerror(errno));
		return -1;
	}
	return listenFd;
}
