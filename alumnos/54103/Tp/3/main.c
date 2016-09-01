#include "partes.h"
#include "contador.h"

int main (int argc, char ** argv){

	int i,j,pid,tam,fd,leido,c=0,ccp=0;
	float p=0;
	char buff[1000];
	char *ptr;
	int  *inf;
	int *aux;
	sem_t *semaforo,*semaforo2;	

	//memoria compartida	
	ptr= mmap(NULL,1024,PROT_READ | PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	aux=mmap(NULL,30,PROT_READ | PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);

	//semaforo
	semaforo= mmap(NULL, sizeof (sem_t),PROT_READ | PROT_WRITE, MAP_SHARED| MAP_ANONYMOUS, -1,0);
	sem_init(semaforo,1,0);

	semaforo2= mmap(NULL, sizeof (sem_t),PROT_READ | PROT_WRITE, MAP_SHARED| MAP_ANONYMOUS, -1,0);
	sem_init(semaforo2,1,0);

	//leo el archivo
	fd=open( argv[1],O_RDWR, NULL );
	while ((leido=read (fd, buff, sizeof buff))> 0){
		tam=write (STDOUT_FILENO , buff, leido);
		c=tam+c;
	}
	close (fd);
	printf ("el numero de bytes  es %d\n",c);
	p = partes(c);
	printf ("el archivo hay que partirlo en %3.f\n",p);	

	//padre e hijo
	pid=fork();

	//HIJO
	if (pid==0){
		sem_wait(semaforo2);
		printf("Soy el Hijo\n");
		for(i=0;i<p;i++){
			printf("Recibi\n");
			printf("%s\n",ptr);
			inf = contador(1000,ptr);	
			for(j=0;j<30;j++){
				*(aux+j)+= inf[j];
			}
			printf("Termine \n");
			sem_post(semaforo);
			sem_wait(semaforo2);	
		}	
		sem_post(semaforo);
		return 0;
	}

	//PADRE
	fd=open(argv[1],O_RDWR,NULL);
	while ((leido=read (fd,buff,sizeof buff))>0){
		for (i=0;i<leido;i++){
			*(ptr+i)=buff[i];
		}
		printf("Mande\n");
		sem_post(semaforo2);
		sem_wait(semaforo);
		ccp++;
	}
	sem_post(semaforo2);
	sem_wait(semaforo);
	printf("Soy el Padre\n");
	printf("Mande %d mensajes\n",ccp);
	for (i=0;i<30;i++){
		if(aux[i]!=0 && i!=0){
			printf ("palabras de %d letras --->%d \n",i,aux[i]);
		}
	}
	return 0;
}
