#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "score_funciones.h"

int imprimir_lista(struct score **INI){
	struct score *aux2;
	
	for(aux2=(*INI);aux2!=NULL;aux2=aux2->sig){
		printf("Score:%d\n",aux2->dato);
		}
	return 1;
		}


int guardar_lista(struct score **INI){
	struct score * pvar = *(INI);
	FILE *fp=fopen("score.dat","wb"); // sobreescribe lo anterior 
	
	do{
	fwrite(pvar,sizeof(struct score),1,fp);	
	pvar=pvar->sig;
	}while(pvar!=NULL);
	
	fclose(fp);
	return 1;
	}


int cargar_lista(struct score ** INI){
	struct score *pvar;
	pvar=(struct score *)malloc(sizeof(struct score));
	(*INI)=pvar;
	FILE *fp=fopen("score.dat","rb");
	if(!fp){
		(*INI)=NULL;
		return 0; // esto significa que no hay una lista guardada.
		}
	
	 while(1){
		 
			fread(pvar,sizeof(struct score),1,fp);
		if(pvar->sig!=NULL){
			pvar->sig=(struct score *)malloc(sizeof(struct score));// ESTO ES MUY IMPORTANTE, RESERVAR MEMORIA PARA EL P->SIG, PORQUE SINO ESCRIBE EN MEMORIA NO RESERVADA
			pvar=pvar->sig;
			}
		else {
			break;
			}
	}
	fclose(fp);
	return 1;
	}


int insert(struct score aux,struct score **INI){     // struct score aux = es la variable aux donde almacenamos nuestros datos para ser enlazado en la lista
	struct score *p,*q;
	p=(struct score *)malloc (sizeof(struct score));
	q=(*INI);
	(*p)=aux;
	if(!(*INI)){
		(*INI)=p;
		p->sig=NULL;
		}else{
			(*INI)=p;
			p->sig=q;
			}
	return 0;
	}


int ordenar_mayor_menor(struct score **INI){
	struct score *p,*q,aux;
	
	for(p=(*INI);p!=NULL;p=p->sig){
			
		for(q=p->sig;q!=NULL;q=q->sig){
			if(q->dato > p->dato ){   // el operador > define a la lista como ascendente 
				aux.dato=q->dato;
				q->dato=p->dato;
				p->dato=aux.dato;
				}
			
			
			}
		}
	return 1;
	}


void cargar_datos(struct score *aux){
	printf("Ingrese un numero\n");
	scanf("%d",&aux->dato);
	
	return;
	}
