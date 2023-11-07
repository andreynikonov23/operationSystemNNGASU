#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char const *argv[]){
    char error[] = "[ERROR] Not valid options";

    for (int i=1; i<argc; i++){
        //Option
        char opt[] = argv[i];
        
        //Basic case
        if (opt[0] != '-'){
            printf("%s", error);
        }

        int index = 1;
        char* o = opt[index];
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

int aFunc(char* neighbour, char* opt[], int* index){
    printf("a\n");
    int i = index + 1;
    free(index);
    if (neighbour == 'a'){
        if (isMassiveFinished(opt, i) != 1){
            aFunc(opt[i], opt, i);
        }
    }
    if (neighbour == 'b'){
        if (isMassiveFinished(opt, i) != 1){
            bFunc(opt, i);
        }
    }
    if (neighbour == 'c'){
        if (isMassiveFinished(opt, i) != 1){
            cFunc(opt[i], opt, i);
        }
    }
}

int bFunc(char* opt[], int* index){
    printf ("b ");
    int i = index + 1;
    free(index);

    if (isMassiveFinished(opt, i) == 1){
        printf("[ERROR] The -b option has no argument");
        return 1;
    }
    
    int start = index;
    int end = isMassiveFinished(opt, i) - 1;
}

int cFunc(char* neighbour, char* opt[], int* index){
    printf("c\n");
    int i = index + 1;
    free(index);
    if (neighbour == 'a'){
        if (isMassiveFinished(opt, i) != 1){
            aFunc(opt[i], opt, i);
        }
    }
    if (neighbour == 'b'){
        if (isMassiveFinished(opt, i) != 1){
            bFunc(opt, i);
        }
    }
    if (neighbour == 'c'){
        if (isMassiveFinished(opt, i) != 1){
            cFunc(opt[i], opt, i);
        }
    }
}

int isMassiveFinished(char* opt, int* index){
    size_t sizeOpt = sizeof(opt);
    if (index >= sizeOpt){
        return 1;
    }
    return sizeOpt;
}
