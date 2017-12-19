#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<pthread.h>

#define IP_LEN 20
#define PORT 30000
#define BUFFER_LEN 256
#define MAX_CLIENTS 10

typedef struct client_info_t client_info_t;
struct client_info_t
{
	struct sockaddr_in client_addr;
	int comm_sock;
	const char *name;
	unsigned valid;
	char rec_buffer[BUFFER_LEN];
};
		
client_info_t client_info[MAX_CLIENTS];
unsigned num_clients = 0;


int alloc_client_info()
{
	for(int i=0; i<MAX_CLIENTS; i++)
	{
		if(client_info[i].valid == 0) 
			return i;
	}
	//All spots taken
	return -1;
}

void *communicate(void *arg)
{
	client_info_t *pclient_info = (client_info_t *)arg; 
	int bytes_recvd;
	
	while(1)
	{
		bytes_recvd = recv(pclient_info->comm_sock, pclient_info->rec_buffer, BUFFER_LEN, 0);
		if(bytes_recvd == -1)
		{
			perror("recv -1");
		}
		else if (!bytes_recvd)
		{
			printf("***Client with port %d disconnected\n",ntohs(pclient_info->client_addr.sin_port));
			pclient_info->valid = 0;	//free this client_info location
			break;
		}
		else
		{
			printf("bytes_recvd = %d\n",bytes_recvd);
			pclient_info->rec_buffer[bytes_recvd] = '\0';
			printf("Client with port %d sent data : %s\n",ntohs(pclient_info->client_addr.sin_port),pclient_info->rec_buffer);
		}
	}
	return NULL;
}
		
int main(int argc, char *argv[])
{
	
	struct sockaddr_in server, client;
	int sock, conn_sock, len, sock_opt = 1, index;
	char ip_addr[IP_LEN];
	client_info_t *pclient_info;
	
	pthread_t tid;


	if ((sock = socket(AF_INET,SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		return -1;
	}
	
	//Set Socket option to reuse port number
	if((setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&sock_opt,sizeof sock_opt)) == -1)
	{
		perror("setsockopt");
		return -1;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	//server.sin_addr.s_addr = INADDR_ANY;
	if((inet_pton(AF_INET,"127.0.0.1",&server.sin_addr)) == -1)
	{
		perror("inet_pton");
		return -1;
	}
	bzero(&server.sin_zero,8);
	
	if (bind(sock, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) == -1 )
	{
		perror("bind");
		return -1;
	}
	
	if(listen(sock,MAX_CLIENTS) == -1)
	{
		perror("listen");
		return -1;
	}
	
	while(1)
	{
		len = sizeof(struct sockaddr_in);
		if ((conn_sock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&len)) == -1)
		{
			perror("accept");
			return -1;
		}
		//We got a connection !
		inet_ntop(AF_INET,(void *)&client.sin_addr,ip_addr,IP_LEN);
		printf("Client connected with IP address %s and port %d\n",ip_addr,ntohs(client.sin_port));
		
		if((index = alloc_client_info()) == -1)
		{
			printf("ERROR: No space left! Max clients connected\n");
		}
		
		bzero(&(client_info[index]), sizeof client_info[index]);
		client_info[index].client_addr = client;
		client_info[index].comm_sock = conn_sock;
		client_info[index].name = '\0';		//set it afterwards
		client_info[index].valid = 1;
		
		num_clients++;
		
		if (0 != pthread_create(&tid,NULL,communicate,(void *)&(client_info[index])) )
		{
			printf("Error creating thread !\n");
			return -1;
		}
		
	}//END while(1)
	
}