CC = gcc
OUT = jonsi.out
DIR1 = core
DIR2 = essentials
DIR1O = ./core/*.o
DIR2O = ./essentials/*.o

build: main.c
	$(MAKE) -C $(DIR1)
	$(MAKE) -C $(DIR2)
	$(CC) $(DIR1O) $(DIR2O) main.c -o $(OUT) 

debug: main.c
	$(MAKE) -C $(DIR1)
	$(MAKE) -C $(DIR2)
	$(CC) $(DIR10) $(DIR20) main.c -g -o $(OUT) 
