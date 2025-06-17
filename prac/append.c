# include <stdio.h>

int main(){
    FILE *fp;

    fp = fopen("file.txt","w");

    fprintf(fp, "hello");
    fclose(fp);

    fp = fopen("file.txt","a");

    fprintf(fp, "\nhello guys");
    fclose(fp);
    
    if(ftell(fp) == EOF){
        printf("File appended successfully\n");
    }

}