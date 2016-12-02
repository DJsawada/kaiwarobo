#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
	struct sockaddr_in server;
	int sock;
	char buf[512];
	int n;
	/*ソケットの作成*/
	sock = socket(AF_INET, SOCK_STREAM, 0);
	/*接続先指定用構造体の準備*/
	server.sin_family = AF_INET;
	server.sin_port = htons(10500);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	/*サーバに接続*/
	connect(sock, (struct sockaddr *)&server, sizeof(server));
	/*サーバからデータを受信*/
	while(1){
		memset(buf, 0, sizeof(buf));
		n = read(sock, buf, sizeof(buf));
		printf("%s\n",buf);
	}
	/*socketの終了*/
	close(sock);
	return 0;
}
