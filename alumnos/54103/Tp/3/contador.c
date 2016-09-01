#include "contador.h"

int *contador (int tam, char *ptr){

	int a=1, i;
	int c=0;
	int * aux;
	aux=calloc (20,1);
	
	for (i=0;i<30;i++){
		aux[i]=0;
	}	
	for (i=0; i<tam; i++){
		if(ptr[i]!= ' ' && ptr[i]!='\n' ){
			 c++;
		}else {	
			a++;
			aux[c]=aux[c]+1;
			c=0;
			}
		
	}

	return aux;

}

