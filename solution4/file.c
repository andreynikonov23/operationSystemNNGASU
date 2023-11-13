#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aFunc(char neighbour, char* opt, int index);
int bArgFunc(char* opt, int index);
int bFunc(char* opt);
int cFunc(char neighbour, char* opt, int index);
int isMassiveFinished(char * opt, int index);


int main(int argc, char* argv[]){
    char error[] = "[ERROR] Not valid argument";
    int isArgument = 0;

    for(int i=1; i<argc; i++){
        char* opt = argv[i];

        if (isArgument == 1){
            if ('-' == opt[0]){
                printf("%s\n", error);
                return 1;
            }
            bFunc(opt);
            isArgument = 0;
        } else{
            if (opt[0] != '-'){
                printf("%s\n", error);
                return 1;
            }
        }

        int index = 1;
        char c = opt[index];

        if(c == 'a'){
            if (isMassiveFinished(opt, index + 1) != 1){
                aFunc(opt[index + 1], opt, index +1);
            } else {
                printf("a\n");
            }
        }
        if(c == 'b'){
            if (strlen(opt) > 2){
                bArgFunc(opt, index + 1);
            } else{
                isArgument = 1;
            }
        }
        if(c == 'c'){
            if (isMassiveFinished(opt, index + 1) != 1){
                cFunc(opt[index + 1], opt, index +1);
            } else{
                printf("c\n");
            }
        }
    }
    return 0;
}

int aFunc(char neighbour, char* opt, int index){
    printf("a\n");

    if (neighbour == 'a'){
            aFunc(opt[index + 1], opt, index);
    }
    if (neighbour == 'b'){
        bArgFunc(opt, index + 1);
    }
    if (neighbour == 'c'){
            cFunc(opt[index + 1], opt, index);
    }
    return 0;
}

int cFunc(char neighbour, char* opt, int index){
    printf("c\n");
    
    if (neighbour == 'a'){
        aFunc(opt[index + 1], opt, index);
        
    }
    if (neighbour == 'b'){
        bArgFunc(opt, index + 1);
    }
    if (neighbour == 'c'){
        cFunc(opt[index + 1], opt, index);
    }
    return 0;
}

int bArgFunc(char* opt, int index){
    printf ("b ");

    if (isMassiveFinished(opt, index) == 0){
        printf("[ERROR] The -b option has no argument\n");
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
    if (strcmp(arg, "") == 0){
        printf("[ERROR] Not valid argument");
        return 1;
    }
    printf("with argument %s\n", arg);
    return 0;
}

int bFunc(char* opt){
    printf("b with %s argument\n", opt);
    return 0;
}


int isMassiveFinished(char * opt, int index){
    int length = strlen(opt);
    if (index >= length){
        return 0;
    }
    return length;
}