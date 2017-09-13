#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct score{
	
	int dato;
	struct score *sig;
	};

int cargar_lista(struct score **);
int insert(struct score aux,struct score **);
int ordenar_mayor_menor(struct score **);
int guardar_lista(struct score **);
void cargar_datos(struct score *);
int imprimir_lista(struct score **);
