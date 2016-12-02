/* TCP client */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
int tcp_connect(const char* host, const char* serv);
int main(void){
	char* serverAddr = "127.0.0.1";/*IP address(or FQDN) of server*/
	char* port = "10500";/*port number(or name) of server*/
	int sockFd, n;
	char sendline[512]=""; 
	char recvline[512]="";
	/*connect to server*/
	if((sockFd=tcp_connect(serverAddr, port)) < 0){
		printf("ERROR at %s#%d\n",__FILE__,__LINE__);
		return -1;
	}
	/*put hello*/
	if((n=write(sockFd, sendline, strlen(sendline))) < 0){
		printf("ERROR at %s#%d\n",__FILE__,__LINE__);
		close(sockFd);
		return -1;
	}
	printf("%s\n",sendline);
	/*get response*/
	while(1){
		if((n = read(sockFd, recvline, sizeof(recvline))) < 0){
			printf("ERROR at %s#%d\n",__FILE__,__LINE__);
			close(sockFd);
			return -1;
		}
		printf("%s\n", recvline);
	}
	/*close connection*/
	close(sockFd);
	return 0;
}
/**********************************************************/
/* TCP Connection routine                                 */
/*  from UNIX NETWORK PROGRAMMING,Vol.1,Second Edition,   */
/*      By W. Richard Stevens, Published By Prentice Hall */
/*       ftp://ftp.kohala.com/pub/rstevens/unpv12e.tar.gz */
/**********************************************************/
int tcp_connect(const char *host, const char *serv){
	int sockFd, n;
	struct addrinfo hints, *res, *ressave;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if((n = getaddrinfo(host, serv, &hints, &res)) != 0){
		printf("tcp_connect error for %s %s: %s\n", host, serv, gai_strerror(n));
		return -1;
	}
	ressave = res;
	do{
		sockFd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if(sockFd < 0) continue;/*ignore this one*/
		if(connect(sockFd,res->ai_addr,res->ai_addrlen)==0)break;/*success*/
		close(sockFd);/*ignore this one*/
	}
	while((res = res->ai_next) != NULL);
	/*errno set from final connect()*/
	if(res == NULL){
		printf("tcp_connect error for %s %s\n", host, serv);
		return -1;
	}
	freeaddrinfo(ressave);
  	return(sockFd);
}
