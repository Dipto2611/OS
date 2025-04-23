#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("example.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "this is an appended line\n");
    fclose(file);
    printf("Data appended to file successfully.\n");

    char buffer[255];
    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading!\n");
        return 1;
    }

    while (fscanf(file, "%s", buffer) != EOF)
    {
        printf("%s ", buffer);
    }

    fclose(file);
    return 0;
}
