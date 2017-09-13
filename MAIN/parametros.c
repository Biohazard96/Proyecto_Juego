#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>


int crear_timer(ALLEGRO_TIMER **timer,const float FPS){
	
   (*timer) = al_create_timer(1.0 / FPS);
   if(!(*timer)) {
      fprintf(stderr, "Error al crear Timer!\n");
      return 0;
   }
   return 1;
}

int init_al(void){
	
	  if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return 0;
   }
	return 1;
	}
	
int crear_evento(ALLEGRO_EVENT_QUEUE **event_queue){
	   (*event_queue) = al_create_event_queue();
   if(!(*event_queue)) {
      fprintf(stderr, "failed to create event_queue!\n");
      return 0;
   }
	return 1;
	} 

int crear_display(ALLEGRO_DISPLAY ** display,int altura,int anchura){
		(*display) = al_create_display(altura, anchura);
   if(!(*display)) {
      fprintf(stderr, "failed to create display!\n");
      return 0;
   }
	
	return 1;
	
	}
