#include <stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;

    // Input: number of pages
    printf("Enter no. of pages\n");
    scanf("%d", &n);

    // Input: the reference string (page numbers)
    printf("Enter page no.\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    // Input: number of frames
    printf("Enter no. of frames\n");
    scanf("%d", &no);

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;  // j keeps track of which frame to replace next (FIFO)

    printf("\tRef String\tPage Frames\n");

    // Loop through each page in the reference string
    for (i = 1; i <= n; i++) {
        printf("%d\t\t", a[i]);

        avail = 0;  // Assume page is not available (miss)

        // Check if the current page is already in any frame
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i])
                avail = 1;  // Page found, it's a hit
        }

        // If the page is not found in any frame (page fault)
        if (avail == 0) {
            frame[j] = a[i];          // Replace the oldest page
            j = (j + 1) % no;         // Move pointer to next frame (circular)
            count++;                  // Increase page fault count

            // Print current frame status
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }

        printf("\n");  // New line after each page reference
    }

    // Print total number of page faults
    printf("Page Fault is %d", count);
    printf("\n\n");

    return 0;
}

