
LIBS = funciones_game_play.c game_play.c free_image.c seleccion_de_personajes.c parametros.c menu.c -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_dialog
CFLAGS = -Wall

all: juego

juego: main.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)


rm:
	rm -f juego
