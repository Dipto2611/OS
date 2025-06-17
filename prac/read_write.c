#include <stdio.h>

int main() {
    FILE *f = fopen("file.txt", "w");

    if (f == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }

    fprintf(f, "Hello World!\n");
    fclose(f);

    printf("Data written successfully.\n");
    return 0;
}
