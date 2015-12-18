
OBJECTS=stringtable.o sl.o

all: sl

%.o: %.c
	gcc -c $< -o $@ -std=gnu99

sl: ${OBJECTS}
	gcc -o sl ${OBJECTS} -std=gnu99

clean:
	rm -f *.o

