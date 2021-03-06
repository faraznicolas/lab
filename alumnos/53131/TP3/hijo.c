#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h> 
#include <sys/fcntl.h>     
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "hijo.h"
#include "parser.h"

void hijo (void **mem, sem_t **sem, int leido){

        int l=leido, i=0,j, fd, cant, cond=1, nol ;
        char proh[32]="", rep[32]="", c, buff[32]="",*msje=(char *) malloc(l*sizeof (char)), tmp2[1];      
        void *temp;

        if (!msje){
            puts ("malloc failed");
            exit (1);
        }
        fd=open ("./palabras.txt", O_RDONLY , 0444);
        msje=strncpy (msje, *mem, l*sizeof (char));
       
        while ((read(fd, &tmp2[1],1))>0){
            i=0;
            lseek (fd, -1, SEEK_CUR);
            do{
                  cant=read (fd, &buff[i], 1);
                  c=buff[i];
                  i++;
                }while (c!='\n');
            
            snprintf (&proh[0], i, "%s", &buff[0]); 
            //memset (&rep[0], '*', i);
            snprintf (rep, i, "***********************************") ;
            temp=msje;
            msje=parser(msje, &proh[0], &rep[0]);
		    free (temp);
        } 
        
        write (STDOUT_FILENO, msje, l);
        *mem=strcpy (*mem, msje);
        
        free (msje);
        
        sem_post(*sem);
        close (fd);
        //remove ("./palabras.txt");

        
    
 
}
