programme:main.o  scrolTest.o menu.o background.o evan.o scrolling.o mouvment.o animation.o objet.o enigme.o cbb.o ennemie.o cpp.o  enigf.o
	gcc main.o  scrolTest.o menu.o background.o evan.o scrolling.o mouvment.o animation.o objet.o cbb.o ennemie.o cpp.o  enigf.o  -o programme -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g 

enigf.o:enigf.c
	gcc -c enigf.c -g 
scrolTest.o:scrolTest.c
	gcc -c scrolTest.c -g 
menu.o:menu.c
	gcc -c menu.c -g
background.o:background.c 
	gcc -c background.c -g
evan.o:evan.c
	gcc -c evan.c -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -g
mouvment.o:mouvment.c
	gcc -c mouvment.c -g
animation.o:animation.c
	gcc -c animation.c -g
objet.o:objet.c
	gcc -c objet.c -g
cbb.o:cbb.c
	gcc -c cbb.c -g 

ennemie.o:ennemie.c
	gcc -c ennemie.c -g 
cpp.o:cpp.c
	gcc -c cpp.c -g 
clean:
	rm -fr *.o
mrproper:clean
	rm -f programme
