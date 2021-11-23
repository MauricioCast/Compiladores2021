a.out: main.o lex.yy.o sintactico.tab.o
	gcc main.o lex.yy.o sintactico.tab.o -ll

main.o: main.c sintactico.tab.c
	gcc -c main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: lexico.l sintactico.tab.c
	flex lexico.l

sintactico.tab.o: sintactico.tab.c
	gcc -c sintactico.tab.c

sintactico.tab.c: sintactico.y
	bison -d sintactico.y

clean:
	rm -f a.out main.o sintactico.tab.* lex.yy.*

run: a.out
	./a.out