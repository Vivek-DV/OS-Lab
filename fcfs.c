#include<stdio.h>

struct fcfs{
    int id, at, bt, ct, wt, tat;
} pro[100];

int main() {
    int n, i, j;
    int tbt = 0;
    float twt = 0, ttat = 0;
    
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter id, AT and BT of process %d\n", i + 1);
        scanf("%d%d%d", &pro[i].id, &pro[i].at, &pro[i].bt);
    }
    
    // Sorting processes based on arrival time using Bubble Sort
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(pro[j].at > pro[j + 1].at) {
                struct fcfs temp = pro[j];
                pro[j] = pro[j + 1];
                pro[j + 1] = temp;
            }
        }
    }
    
    // Calculating completion time, waiting time, and turnaround time
    for(i = 0; i < n; i++) {
        pro[i].ct = tbt + pro[i].bt;
        pro[i].tat = pro[i].ct - pro[i].at;
        pro[i].wt = pro[i].tat - pro[i].bt;
        tbt += pro[i].bt;
        twt += pro[i].wt;
        ttat += pro[i].tat;
    }
    
    float avg_wt = twt / n;
    float avg_tat = ttat / n;
    
    printf("Average wt: %f\nAverage tat: %f\n", avg_wt, avg_tat);
    printf("ID\tAT\tBT\tCT\tWT\tTAT\n");
    
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pro[i].id, pro[i].at, pro[i].bt, pro[i].ct, pro[i].wt, pro[i].tat);
    }
    
    return 0;
}
