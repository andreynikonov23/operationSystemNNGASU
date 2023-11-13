#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char* argv[]){
    int length = strlen(argv[1]);
    int valid;
    for(int i=0; i<length; i++){
        char c = argv[1][i];
        if (c == '1'
            || c == '2'
            || c == '3'
            || c == '4'
            || c == '5'
            || c == '6'
            || c == '7'
            || c == '8'
            || c == '9'
            || c == '0'){
        } else{
            valid = 1;
        }
    }
    if (valid == 1){
        return 1;
    }
    return 0;
}

int main(int argc, char * argv[]){
    if(check(argv) == 1){
        printf("[ERROR] The option must be a number\n");
    } else{
        int myVar = atoi(argv[1]);
        printf("%d\n", myVar+1);
    }
    return 0;
}

