#include "argumento.h"


void argumento( int argc, char*argv){
	
	assert(argc== 3);
	if (!strcmp(argv,"-p")){
		printf("Parametros correctos\n");		
	} else{	printf("Parametros incorrectos\n");
		exit (0); 
	}

}
