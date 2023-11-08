#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>


int main(int argc, char const *argv[]){
    char error[] = "[ERROR] Not valid options";

    for (int i=1; i<argc; i++){
        //Option
        char opt[150];
        strcpy(opt, argv[i]);
        
        //Basic case
        if (opt[0] != '-'){
            printf("%s", error);
        }

        int index = 1;
        char o = opt[index];
        if (o == 'a'){
            if (isMassiveFinished(opt, index+1) != 1){
                aFunc(opt[index + 1], opt, index + 1);
            } else {
                printf("a\n");
            }
        }
        if (o == 'b'){
            if (isMassiveFinished(opt, index+1) != 1){
                bFunc(opt, index + 1);
            } else {
                printf("b\n");
            }
        }
        if (o == 'c'){
            if (isMassiveFinished(opt, index+1) != 1){
                cFunc(opt[index + 1], opt, index + 1);
            } else {
                printf("c\n");
            }
        }
    }

    return 0;
}

int aFunc(char neighbour, char* opt[], int index){
    printf("a\n");
    if (neighbour == 'a'){
        if (isMassiveFinished(opt, index + 1) != 1){
            aFunc(opt[index], opt, index + 1);
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

int bFunc(char* opt[], int index){
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

int cFunc(char neighbour, char* opt[], int index){
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

int isMassiveFinished(char * opt[], int index){
    size_t sizeOpt = sizeof(opt);
    int size = 0;
    for (int i=0; i<sizeOpt; i++){
        size++;
    }
    if (index >= size){
        return 1;
    }
    return size;
}
