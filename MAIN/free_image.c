#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <string.h>
#include "milib.h"



void free_image(ALLEGRO_BITMAP **image, const int maxFrame){ 
	
	int i;
	
	for (i=0 ; i<maxFrame ; i++)
		{
			al_destroy_bitmap(image[i]);
			
		}
	return;
	}
