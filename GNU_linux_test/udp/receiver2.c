#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>

int port = 6789;

int main(void)
{
	int sin_len;
	char message[256];
	int socket_descriptor;
	struct sockaddr_in sin;
	int bind_rc,close_rc;
	ssize_t recv_rc;

	printf("Waiting for data drom sender\n");

	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(port);
	sin_len = sizeof(sin);

	socket_descriptor = socket(AF_INET, SOCK_DGRAM,0);
	if(socket_descriptor == -1){
		perror("socket create");
		exit(EXIT_FAILURE);
	}
	bind_rc = bind(socket_descriptor, (struct sockaddr*)&sin,sizeof(sin));
	if(bind_rc == -1){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	while(1){
		
		recv_rc = recvfrom(socket_descriptor,message,
				sizeof(message),0,
				(struct sockaddr*)&sin,&sin_len);
		if(recv_rc == -1){
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}

		printf("Response from server: %s\n",message);

		if(strncmp(message,"stop",4) == 0){
			printf("Sender has told me to end the cpnnection\n");
			break;
		}
	}

	close_rc = close(socket_descriptor);
	if(close_rc == -1){
		perror("close");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}