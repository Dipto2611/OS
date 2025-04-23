#include <stdio.h> 
struct RR { 
    int pro; 
    int at; 
    int bt; 
    int ct; 
    int tat; 
    int wt; 
    int rt; 
    int rem_bt; 
}; 
int main() { 
    int n, q; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    struct RR p[n]; 
    for (int i = 0; i < n; i++) { 
        p[i].pro = i + 1; 
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1); 
        scanf("%d %d", &p[i].at, &p[i].bt); 
        p[i].rem_bt = p[i].bt; 
        p[i].rt = -1; 
    } 
    printf("Enter time quantum: "); 
    scanf("%d", &q); 
    int t = 0; 
    int remaining_processes = n; 
    int idx = 0; 
    while (remaining_processes > 0) { 
        if (p[idx].rem_bt > 0 && p[idx].at <= t) { 
            if (p[idx].rt == -1) { 
                p[idx].rt = t - p[idx].at; 
            } 
            int time_slice = (p[idx].rem_bt <= q) ? p[idx].rem_bt : q; 
            t += time_slice; 
            p[idx].rem_bt -= time_slice; 
            if (p[idx].rem_bt == 0) { 
                p[idx].ct = t; 
                p[idx].tat = p[idx].ct - p[idx].at; 
                p[idx].wt = p[idx].tat - p[idx].bt; 
                remaining_processes--; 
            } 
        } 
        idx = (idx + 1) % n; 
    } 
    printf("\nProcess ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Response Time\n"); 
    for (int i = 0; i < n; i++) { 
     printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
   p[i].pro, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt); 
} 
float avgtat = 0, avgwt = 0; 
for (int i = 0; i < n; i++) { 
avgtat += p[i].tat; 
avgwt += p[i].wt; 
} 
printf("Average Turnaround Time: %.2f\n", avgtat / n); 
printf("Average Waiting Time: %.2f\n", avgwt / n); 
return 0; 
}