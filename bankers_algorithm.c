#include<stdio.h>

int main() {
    int i, j, k, n, r, ind = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &r);
    
    int alloc[20][20], max[20][20], need[n][r], avail[r];
    
    printf("Enter allocation matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("Enter max matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter available matrix:\n");
    for(i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }
    
    // Calculate need matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    printf("Need matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    int finish[n], safesequence[n], work[r];
    
    for(i = 0; i < r; i++) {
        work[i] = avail[i];
    }
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }
    
    // Check for safe sequence
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 0;
                for(j = 0; j < r; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    safesequence[ind++] = i;
                    for(j = 0; j < r; j++) {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                }
            }
        }
    }
    
    // Check if safe sequence found
    if(ind == n) {
        printf("Safe sequence:");
        for(i = 0; i < n; i++) {
            printf(" P%d", safesequence[i]);
        }
        printf("\n");
    } else {
        printf("No safe sequence found.\n");
    }

    return 0;
}

