build:
	./pre_build.sh && gcc -pedantic-errors -Wall -Wextra -Wsign-conversion -std=c99 -o ./2D_shot_them_up `sdl2-config --cflags --libs` -lSDL2_image ./includes/*.c
run:
	./2D_shot_them_up
clean:
	rm ./2D_shot_them_up
