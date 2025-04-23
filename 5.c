#include <stdio.h> 
 
struct SRTF { 
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
    int n; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    struct SRTF p[n]; 
 
    for (int i = 0; i < n; i++) { 
        p[i].pro = i + 1;  
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1); 
        scanf("%d %d", &p[i].at, &p[i].bt); 
        p[i].rem_bt = p[i].bt;  
    } 
 
     
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (p[i].at > p[j].at) { 
                struct SRTF temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp; 
            } 
        } 
    } 
    int current_time = 0; 
    int completed = 0; 
    int prev = -1;  
    int min_remaining_bt = 9999; 
    int shortest = -1; 
    printf("\nGantt Chart: \n"); 
    while (completed < n) { 
        for (int i = 0; i < n; i++) { 
            if (p[i].at <= current_time && p[i].rem_bt > 0 && p[i].rem_bt < 
min_remaining_bt) { 
                min_remaining_bt = p[i].rem_bt; 
                shortest = i; 
            } 
        } 
        if (shortest == -1) { 
            printf("Idle(%d-%d) ", current_time, current_time + 1); 
            current_time++; 
            continue; 
        } 
        printf("P%d(%d-%d) ", p[shortest].pro, current_time, current_time + 1); 
        p[shortest].rem_bt--;  
        current_time++; 
        if (p[shortest].rem_bt == 0) { 
            p[shortest].ct = current_time; 
            p[shortest].tat = p[shortest].ct - p[shortest].at; 
            p[shortest].wt = p[shortest].tat - p[shortest].bt; 
            p[shortest].rt = p[shortest].wt; 
            completed++; 
        } 
        min_remaining_bt = 9999; 
    } 
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n"); 
    float avgtat = 0.0, avgwt = 0.0; 
    for (int i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pro, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt); 
        avgtat += p[i].tat; 
        avgwt += p[i].wt; 
    } 
    printf("\nAverage Turnaround Time = %.2f\nAverage Waiting Time = %.2f\n", avgtat / n, avgwt / n); 
    return 0; 
}