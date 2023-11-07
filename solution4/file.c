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
            aFunc(opt[index + 1], opt, index + 1);
        }
        if (o == 'b'){
            bFunc(opt, index + 1);
        }
        if (o == 'c'){
            cFunc(opt[index + 1], opt, index + 1);
        }
    }

    return 0;
}

int aFunc(char* neighbour, char* opt[], int* index){
    int i = index + 1;
    free(index);
    if (neighbour == 'a'){
        aFunc(opt[i], opt, i);
    }
    if (neighbour == 'b'){
        bFunc(opt, i);
    }
    if (neighbour == 'c'){
        cFunc(opt[i + 1], opt, i+1);
    }
}

int bFunc(char* opt[], int* index){

}

int cFunc(char* neighbour, char* opt[], int* index){
    int i = index + 1;
    free(index);
    if (neighbour == 'a'){
        aFunc(opt[i], opt, i);
    }
    if (neighbour == 'b'){
        bFunc(opt, i);
    }
    if (neighbour == 'c'){
        cFunc(opt[i], opt, i);
    }
}
