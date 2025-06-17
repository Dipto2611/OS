#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, count = 0, i, j, k = 0, found;

    printf("Enter number of pages: "); //total no of pages entered
    scanf("%d", &n);

    printf("Enter page numbers: "); //particular pg no
    for (i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    } 

    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++){
        frames[i] = -1; //empty pg condn
    } 

    //condn for flag check
    for (i = 0; i < n; i++) {
        
        found = 0; //flag

        for (j = 0; j < f; j++) //f=no of frames
            if (frames[j] == pages[i])
                found = 1;

        if (!found) {
            frames[k] = pages[i]; 
            k = (k + 1) % f; //circular queue
            count++;
        }
    }

    printf("Total Page Faults: %d\n", count);
    return 0;
}
