#include <stdio.h>

int main() {
    for (int i=0; i<50; i++){
        char buffer[256];
        FILE *file1 = fopen("test1.txt", "r");
        FILE *file2 = fopen("test2.txt", "w");

        while ((fgets(buffer, 256, file1)) != NULL)
        {
            fputs(buffer, file2);
        }
        fclose(file1);
        fclose(file2);
    }

    return 0;
}