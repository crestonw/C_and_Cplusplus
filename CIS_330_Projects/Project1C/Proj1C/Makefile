lib: math330.h sin330.o cos330.o tan330.o arccos.o arcsin.o arctan.o exp330.o log330.o cli.o
	mkdir -p include
	cp math330.h include

cli.o: cli/cli.c
	mkdir -p lib
	ar r lib/libmath330.a sin330.o cos330.o tan330.o arccos.o arcsin.o arctan.o exp330.o log330.o 
	mkdir -p bin
	gcc -o bin/cli cli/cli.c -I./ -L./lib -lmath330 -lm
	chmod 755 bin/cli

sin330.o: trig/sin330.c math330.h
	gcc -c trig/sin330.c -I./

cos330.o: trig/cos330.c math330.h
	gcc -c trig/cos330.c -I./

tan330.o: trig/tan330.c math330.h
	gcc -c trig/tan330.c -I./

arccos.o: trig/arccos.c math330.h
	gcc -c trig/arccos.c -I./

arcsin.o: trig/arcsin.c math330.h
	gcc -c trig/arcsin.c -I./

arctan.o: trig/arctan.c math330.h
	gcc -c trig/arctan.c -I./

exp330.o: exp/exp330.c math330.h
	gcc -c exp/exp330.c -I./

log330.o: exp/log330.c math330.h
	gcc -c exp/log330.c -I./

