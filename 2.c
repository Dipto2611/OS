#include <stdio.h>
int main()
{
    FILE *file;
    file = fopen("example.txt", "w");
    if (file == NULL)
    {
        printf("error opening file!\n");
        return 1;
    }
    printf("file opened successfully\n");
    fprintf(file, "hello world !\n");
    printf("data written to file successfully\n");
    fclose(file);
    printf("file closed successfully \n");
   
    return 0;
}