#include <stdio.h>
#include <stdbool.h>  // Include for boolean type

#define MAX_P 5
#define MAX_R 3

int need[MAX_P][MAX_R];
int avail[MAX_R];
int allo[MAX_P][MAX_R];
int finish[MAX_P];

// Function to check if the system is in a safe state
bool is_safe() {
    int work[MAX_R];
    bool finish_all = false;

    // Initialize work vector with available resources
    for (int i = 0; i < MAX_R; i++) {
        work[i] = avail[i];
    }

    // Check if all processes are finished
    while (!finish_all) {
        bool found = false;
        finish_all = true;  // Assume all processes are finished

        for (int i = 0; i < MAX_P; i++) {
            if (!finish[i]) {
                // Check if the current process can be executed
                bool can_execute = true;
                for (int j = 0; j < MAX_R; j++) {
                    if (need[i][j] > work[j]) {
                        can_execute = false;
                        break;
                    }
                }

                if (can_execute) {
                    // Execute the process
                    finish[i] = true;
                    found = true;
                    for (int j = 0; j < MAX_R; j++) {
                        work[j] += allo[i][j];
                    }
                }
            }
        }

        // Check if all processes are finished
        for (int i = 0; i < MAX_P; i++) {
            if (!finish[i]) {
                finish_all = false;
                break;
            }
        }

        // If no process can be executed in a complete cycle, the system is unsafe
        if (!found && !finish_all) {
            return false;
        }
    }

    // If all processes are finished, the system is safe
    return true;
}

int main() {
    printf("Enter the allocation matrix :\n");
    for (int i = 0; i < MAX_P; i++) {
        for (int j = 0; j < MAX_R; j++) {
            scanf("%d", &allo[i][j]);
        }
    }

    printf("Enter the need matrix :\n");
    for (int i = 0; i < MAX_P; i++) {
        for (int j = 0; j < MAX_R; j++) {
            scanf("%d", &need[i][j]);
        }
    }

    printf("Enter the available matrix :\n");
    for (int i = 0; i < MAX_R; i++) {
        scanf("%d", &avail[i]);
    }

    // Check if the system is in a safe state
    if (is_safe()) {
        printf("System is in a safe state\n");
    } else {
        printf("System is in an unsafe state\n");
    }

    return 0;
}
