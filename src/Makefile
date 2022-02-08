CC = gcc

obj = main.o lex.yy.o parser.o

pascal: $(obj)
	$(CC) $(obj) -o pascal -lm

main.o: main.c  
	$(CC) -c main.c

lex.yy.o: lexico.l
	flex lexico.l
	$(CC) -c lex.yy.c

parser.o: parser.c  
	$(CC) -c parser.c

clean: 
	rm $(obj) pascal lex.yy.c