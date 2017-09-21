#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <string.h>
#include "milib.h"


int MENU(ALLEGRO_MOUSE_STATE * state_mouse,struct color *aux1,struct color *aux2,struct color *aux3){


		if(state_mouse->x > 20 && state_mouse->x < 210 && state_mouse->y > 300 && state_mouse->y < 320){ // Cuando el mouse esta sobre COMENZAR JUEGO
           aux1->RED=0;
           aux1->GREEN=0;
           aux1->BLUE=255;
           if(state_mouse->buttons & 1){ // si hago click sobre COMENZAR JUEGO pasa al siguiente bucle 
			   
			  return 1;
			   
			   }
                    
		  }
		else if(state_mouse->x > 320 && state_mouse->x < 405 && state_mouse->y > 300 && state_mouse->y < 320){ // Cuando el mouse esta sobre  PUNTOS
           aux2->RED=0;
           aux2->GREEN=0;
           aux2->BLUE=255; 
           if(state_mouse->buttons & 1){ //SI HAGO CLICK EN PUNTOS MUESTRA LOS PUNTOS
				return 2;
			   }            
		  }			  
		else if(state_mouse->x > 500 && state_mouse->x < 555 && state_mouse->y > 300 && state_mouse->y < 320){ // Cuando el mouse esta sobre SALIR
           aux3->RED=0;
           aux3->GREEN=0;
           aux3->BLUE=255;
           if(state_mouse->buttons & 1){ //con esto haces click en salir y sale del programa
				return -1;
			   }         
		  }else {
			  aux1->RED=255;
			  aux1->GREEN=255;
              aux1->BLUE=0;				
			  aux2->RED=255;
			  aux2->GREEN=255;
              aux2->BLUE=0;				
			  aux3->RED=255;
			  aux3->GREEN=255;
              aux3->BLUE=0;				
			  }
			  
	return 0; 		  
	}		  
//printf("pos x = %d  pos y = %d \n",state.x,state.y); // sirve para saber la posicion del mouse en el eje (x ,y)
