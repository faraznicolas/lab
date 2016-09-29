#include "analisis.h"


int  analisis (int ad ,char * buff){

	int file,file2,leido,op=-1;
	char buff2[1024];
	char buffer[2048];	
	char error404[22]="ERROR 404  Not Found";
	char ok200[8]="2OO OK";
	char eis500[27]="500 Internal Server Error";
	char* cadena;
	memset(buffer,0,sizeof buffer);
	puts(buff);
	strcpy(buff2,buff);
	cadena=strtok(buff2,"/");
	cadena=strtok(NULL," ");
	puts(cadena);
	if (!strcmp(cadena,"nico.html")){
		op=2;
	}	
	if (!strcmp(cadena,"nico.txt")){
                op=3;
        }
	if (!strcmp(cadena,"nico.jpeg")){
                op=4;
        }
	if (!strcmp(cadena,"nico.pdf")){
                op=1;
        }
	if (buff2[5]==' '){
		op=5;	
        }	
	switch(op){
		case 2:
			file=open ("archivo2.txt",O_RDONLY,NULL);
			while ((leido=read(file,buffer,sizeof buffer)) > 0){
				write (ad,buffer,leido);
			}
			if (file < 0){
				write (ad,eis500,27);
				return 0;
			}
			file2 = open("nico2.html",O_RDONLY,NULL);
			while ((leido=read(file2,buffer,sizeof buffer))>0){
				write (ad,buffer,leido);
			}
			if (file2 < 0){
				write (ad,eis500,27);
				return 0;
			}

			close (file2);
			close(file);
		break;
		case 3:
			file=open ("archivo3.txt",O_RDONLY,NULL);
			while ((leido=read(file,buffer,sizeof buffer)) > 0){
				write (ad,buffer,leido);
			}
			if (file < 0){
				write (ad,eis500,27);
				return 0;
				}
			file2 = open("nico3.txt",O_RDONLY,NULL);
			while ((leido=read(file2,buffer,sizeof buffer))>0){
				write (ad,buffer,leido);
			}
			if (file2 < 0){
				write (ad,eis500,27);
				return 0;
			}
			close (file2);
			close(file);
		break;
		case 1:
			file=open ("archivo1.txt",O_RDONLY,NULL);
			while ((leido=read(file,buffer,sizeof buffer)) > 0){
				write (ad,buffer,leido);
			}
			if (file < 0){
				write (ad,eis500,27);
				return 0;
			}
			file2 = open("nico1.pdf",O_RDONLY,NULL);
			while ((leido=read(file2,buffer,sizeof buffer))>0){
				write (ad,buffer,leido);
			}
			if (file2 < 0){
				write (ad,eis500,27);
				return 0;
			}
			close (file2);
			close(file);
		break; 
		case 4:
			file=open ("archivo4.txt",O_RDONLY,NULL);
			while ((leido=read(file,buffer,sizeof buffer)) > 0){
				write (ad,buffer,leido);
			}
			if (file < 0){
				write (ad,eis500,27);
				return 0;
			}
			file2 = open("nico4.jpeg",O_RDONLY,NULL);
			while ((leido=read(file2,buffer,sizeof buffer))>0){
				write (ad,buffer,leido);
			}
			if (file2 < 0){
				write (ad,eis500,27);
				return 0;
			}
			close (file2);
			close(file);
		break;
		case 5:
			write (ad,ok200,8);
		break;
		default:
			write (ad,error404,22);	
		break;
	}
	return 0;
}
