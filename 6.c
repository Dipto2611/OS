#include <stdio.h> 
 
struct SRTF { 
    int pro;    
    int at;     
    int bt;     
    int ct;     
    int tat;    
    int wt;     
    int rt;     
}; 
 
int main() { 
    int n; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    int temp[n]; 
    struct SRTF p[n]; 
    for (int i = 0; i < n; i++) { 
        p[i].pro = i + 1;  
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1); 
        scanf("%d %d", &p[i].at, &p[i].bt); 
         temp[i]=p[i].bt; 
    } 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (p[i].at > p[j].at || (p[i].at == p[j].at && p[i].bt > p[j].bt)) { 
                struct SRTF temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp; 
            } 
        } 
    } 
 
    int current_time = 0; 
    int completed = 0; 
    int min_bt_index = -1; 
    int remaining_processes = n; 
 
    printf("\nGANTT Chart: \n"); 
 
    while (completed < n) { 
        min_bt_index = -1; 
        int min_bt = 9999; 
        for (int i = 0; i < n; i++) { 
            if (p[i].at <= current_time && p[i].bt > 0 && p[i].bt < min_bt) { 
                min_bt = p[i].bt; 
                min_bt_index = i; 
            } 
        } 
 
        if (min_bt_index == -1) { 
            printf("Idle(%d-%d) ", current_time, current_time + 1); 
            current_time++; 
            continue; 
        } 
 
        printf("P%d(%d-%d) ", p[min_bt_index].pro, current_time, current_time + 
p[min_bt_index].bt); 
        current_time += p[min_bt_index].bt;  
 
        p[min_bt_index].ct = current_time;  
        p[min_bt_index].tat = p[min_bt_index].ct - p[min_bt_index].at;  
        p[min_bt_index].wt = p[min_bt_index].tat - p[min_bt_index].bt; 
        p[min_bt_index].rt = p[min_bt_index].wt;  
        p[min_bt_index].bt=0; 
        completed++; 
    } 
 
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n"); 
 
    float avgtat = 0.0, avgwt = 0.0; 
    for (int i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pro, p[i].at, temp[i], p[i].ct, 
p[i].tat, p[i].wt, p[i].rt); 
        avgtat += p[i].tat; 
        avgwt += p[i].wt; 
    } 
 
    printf("\nAverage Turnaround Time = %.2f\nAverage Waiting Time = %.2f\n", avgtat / 
n, avgwt / n); 
    return 0; 
}