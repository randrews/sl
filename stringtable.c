#include "stringtable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int st_num(char *table, int size, char *string){
    int index = 1; // Index into the buffer
    int count = table[0]; // Number of words in the stringtable
    int num = 0; // String number we're looking at
    int len = strlen(string); // Length of what we want to put in

    while(1){
        // Are we out of strings?
        if(num == count) break;

        // Is this string the right length?
        if(table[index] != len) {
            index += table[index] + 1;
            num++;
            continue;
        }

        // Same length, start comparing it with the given one:
        char match = 1;

        for(int n=0; n<len; n++){
            if(string[n] != table[index+n+1]) {
                match = 0;
                break;
            }
        }

        if(match) { // We found it, return the num
            return num;
        } else { // This isn't it, keep going
            index += table[index] + 1;
            num++;
        }
    }

    // Are we out of space?
    if(index + len + 1 >= size) return -1;

    // If not, copy it in:
    table[index++] = (char)len;
    int i=0;
    while(table[index++] = string[i++]);

    // Increment the number of stored strings
    table[0]++;

    return num;
}

void st_print(char *table, int size){
    int index = 1;
    int num = 0;
    int count = table[0];

    while(num < count) {
        int len = table[index++];
        printf("String %d, index %d: \"", num++, index);
        for(int start=index; index < start+len; index++)
            printf("%c", table[index]);
        printf("\"\n");
    }

    printf("--------------------------------\n");

    index = 0;
    while(table[index]) {
        char c = table[index];
        if(c > 32 && c < 127)
            printf("%d: %c\n", index++, c);
        else
            printf("%d: 0x%x\n", index++, c);
    }
}
