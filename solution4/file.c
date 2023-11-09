#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aFunc(char neighbour, char* opt, int index);
int bFunc(char* opt, int index);
int cFunc(char neighbour, char* opt, int index);
int isMassiveFinished(char * opt, int index);


int main(int argc, char* argv[]){
    char error[] = "[ERROR] Not valid argument";

    for(int i=1; i<argc; i++){
        char* opt = argv[i];

        if (opt[0] -= '-'){
            printf("%s\n", error);
        }
        int index = 1;
        char c = opt[index];

        if(c == 'a'){
            printf("a\n");
            if (isMassiveFinished(opt, index + 1) != 1){
                aFunc(opt[index + 1], opt, index +1);
            }
        }
        if(c == 'b'){
            printf("b\n");
            bFunc(opt, index + 1);
        }
        if(c == 'c'){
            printf("c\n");
            if (isMassiveFinished(opt, index + 1) != 1){
                cFunc(opt[index + 1], opt, index +1);
            }
        }
    }
    return 0;
}

int aFunc(char neighbour, char* opt, int index){
    printf("a\n");

    if (neighbour == 'a'){
        if (isMassiveFinished(opt, index + 1) != 1){
            aFunc(opt[index + 1], opt, index);
        }
    }
    if (neighbour == 'b'){
        if (isMassiveFinished(opt, index + 1) != 1){
            bFunc(opt, index + 1);
        }
    }
    if (neighbour == 'c'){
        if (isMassiveFinished(opt, index + 1) != 1){
            cFunc(opt[index + 1], opt, index);
        }
    }
    return 0;
}

int cFunc(char neighbour, char* opt, int index){
    printf("c\n");
    
    if (neighbour == 'a'){
        if (isMassiveFinished(opt, index + 1) != 1){
            aFunc(opt[index + 1], opt, index);
        }
    }
    if (neighbour == 'b'){
        if (isMassiveFinished(opt, index + 1) != 1){
            bFunc(opt, index + 1);
        }
    }
    if (neighbour == 'c'){
        if (isMassiveFinished(opt, index + 1) != 1){
            cFunc(opt[index + 1], opt, index);
        }
    }
    return 0;
}

int bFunc(char* opt, int index){
    printf ("b ");

    if (isMassiveFinished(opt, index + 1) == 1){
        printf("[ERROR] The -b option has no argument");
        return 1;
    }
    
    int start = index;
    size_t sizeOpt = sizeof(opt);
    int size = sizeOpt - start;
    char arg[size];
    for(int i=0; i<size; i++){
        arg[i] = opt[start];
        start++;
    }
    printf("with argument %s\n", arg);
    return 0;
}


int isMassiveFinished(char * opt, int index){
    int length = strlen(opt);
    if (index >= length){
        return 1;
    }
    return length;
}