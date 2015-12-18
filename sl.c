#include <stdio.h>
#include <stdlib.h>
#include "stringtable.h"

int main(int argc, char **argv){

    char *stringtable = malloc(1000);
    *stringtable = 0;

    st_num(stringtable, 1000, "foo");
    st_num(stringtable, 1000, "Hello there!");
    st_num(stringtable, 1000, "bar");

    int n1 = st_num(stringtable, 1000, "bar");
    int n2 = st_num(stringtable, 1000, "bad");

    printf("Num of 'bar': %d\nNum of 'bad': %d\n", n1, n2);
    st_print(stringtable, 1000);

    return 0;
}
