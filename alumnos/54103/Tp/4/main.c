#include "argumento.h"
#include "puerto.h"
#include "analisis.h"

#define BACKLONG 2000

int main (int argc , char** argv){

	int port;
	int sd, bd,ad,pid;
	char buff[2048];
	argumento(argc , argv[1]);//analiso los parametros de entrada
	struct sockaddr_in server;
	struct sockaddr_in client;	
	port= puerto(argv[2]);//analiso que puerto debo usar para el servidor	
	memset(buff,0,sizeof buff);

	sd=socket(AF_INET,SOCK_STREAM,0);
	if (sd < 0){
		perror("fallo el socket");
		return -1;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr= INADDR_ANY;
	bzero(&(server.sin_zero),8);

	bd=bind (sd,(struct sockaddr*)&server, sizeof (server));
	if (bd < 0 ){
		perror("fallo el bind");
		return -1;	
	}

	listen (sd, BACKLONG);

	while ((ad=accept(sd,NULL,NULL)) > 0){
		if (ad < 0 ){
			perror("fallo el accept");
			return -1;
		}	
		pid = fork ();
		if ( pid == 0 ) {
			printf("Conectado:\n");
			printf("Cliente %s , Puerto %d\n",inet_ntoa(client.sin_addr), client.sin_port);
			read(ad,buff,sizeof buff);
			analisis(ad,buff);//analiso que archivo me pide y si lo puedo abrir lo mustro  por el navegador
			close(ad);		
			return 0;		
		}
		close (ad);
	}
	return 0;

}
