#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>
#include "milib.h"


int SELECCION_DE_PERSONAJES(ALLEGRO_DISPLAY *display,ALLEGRO_MOUSE_STATE * state_mouse){
 
   
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   bool redraw = true;
 

   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return 1;
   }
 

 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display((display));
      al_destroy_timer(timer);
      return 1;
   }
 
   al_register_event_source(event_queue, al_get_display_event_source((display)));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer);
 
   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
         al_get_mouse_state(&(*state_mouse));
         if(state_mouse->x > 0 && state_mouse->x < 20 && state_mouse->y > 300 && state_mouse->y < 320){ // Cuando el mouse esta sobre COMENZAR JUEGO
      
           if(state_mouse->buttons & 1){ // si hago click sobre COMENZAR JUEGO pasa al siguiente bucle 
			   
			  return 0;
			   
			   }
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         return 0;
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         al_clear_to_color(al_map_rgb(0,255,0));
         al_flip_display();
      }
   }
 
}
 
   return 1;
}
