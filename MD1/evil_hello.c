#include <stdio.h>

int main(void){
	printf("Hello, Evil World!\n");
	char buffer[100];
    printf("Input:");
    fflush(stdout);
	//char buffer[10];
	//scanf("%s", buffer);
	read(0, buffer, 300);
    return 0;
}
