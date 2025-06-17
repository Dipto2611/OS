#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id, at, bt, ct, tat, wt;
} process;

void calctime(process pr[], int n){
    int crt = 0, totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++){
        if(crt < pr[i].at)
            crt = pr[i].at;

        crt = crt + pr[i].bt;
        pr[i].ct = crt;
        pr[i].tat = pr[i].ct - pr[i].at;
        pr[i].wt = pr[i].tat - pr[i].bt;

        totalTAT += pr[i].tat;
        totalWT += pr[i].wt;
    }

    printf("\nAverage Turnaround Time: %f\n", (float)totalTAT / n);
    printf("Average Waiting Time: %f\n", (float)totalWT / n);
}

void printProcessDetails(process pr[], int n){
    
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pr[i].id, pr[i].at, pr[i].bt, pr[i].ct, pr[i].tat, pr[i].wt);
    }
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    process pr[n];

    for (int i = 0; i < n; i++){
        //pr[i].id = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &pr[i].at);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &pr[i].bt);
    }

    calctime(pr, n);
    printProcessDetails(pr, n);

    return 0;
}
