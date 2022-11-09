all:  translate.c
	gcc -o translate translate.c


clean:
	rm translate