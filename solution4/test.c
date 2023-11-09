#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(char str){
    printf("%c\n", str);
    return 0;
}

int main(int argc, char * argv[]){
    for(int i=1; i<argc; i++){
        char * str = argv[i];
        int num = 1+1;
        char c = str[1+1];
        test(c);
    }
    return 0;
}

