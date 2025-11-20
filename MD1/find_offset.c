#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <offset>\n", argv[0]);
        return 1;
    }

    int offset = atoi(argv[1]);
    for (int i = 0; i < offset; i++) {
        putchar('A');
    }
    // "BBBBBBBB" in hex is 0x4242424242424242
    fputs("BBBBBBBB", stdout); 
    
    return 0;
}
