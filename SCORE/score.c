#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "score_funciones.h"


int main (int argc, char ** argv){
	
	struct score aux,*aux2;
	struct score * INI=NULL;
	int estado;
	
	
	
	cargar_lista(&INI);
imprimir_lista(&INI);
		while(1){
			
			cargar_datos(&aux);
			insert(aux,&INI);
			
			printf("Desea continua?\n");
			printf("0-NO\n");
			printf("1-Si\n");
			scanf("%d",&estado);
			
			if(!estado) break;
			}

	ordenar_mayor_menor(&INI); //ordeno "int dato" de la lista
	imprimir_lista(&INI);
	guardar_lista(&INI);
	
	for(aux2=INI,INI=INI->sig;INI!=NULL;INI=INI->sig){
		free(aux2);
		aux2=INI;
		}
	
	return 0;
	}
