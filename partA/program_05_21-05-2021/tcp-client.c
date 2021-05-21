#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>

int main() {
    FILE *fp;
    int sock,bytes_recv;
    struct sockaddr_in server_addr;
    char recv_data[1024],send_data[1024], file_name[50], ch;
    struct hostent *host;
    host=gethostbyname("127.0.0.1");
    if((sock=socket(AF_INET,SOCK_STREAM,0))==-1) {
        perror("socket");
        exit(1);
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(53433);
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(sock,(struct sockaddr *)&server_addr,sizeof(struct sockaddr))==-1) {
        perror("connect");
        exit(1);
    }
    printf("Enter Filename\n");
    gets(file_name);

    if(strcmp(file_name,"q")!=0) {
        send(sock,file_name,strlen(file_name),0);
    }

    while((bytes_recv=recv(sock,recv_data,1024,0))>0) {
        recv_data[bytes_recv]='\0';
        printf("%s\n", recv_data);
    }
    close(sock);
    return 0;
}