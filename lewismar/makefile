CLAGS = -Wall

default: qrconcat.o
	gcc -o anise anise.c -lqrencode -lzbar qrconcat.o
clean:
	rm anise && rm *.o
