#include <stdio.h>

#define MAX 10

// First Fit Allocation
void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    // Initialize allocation array
    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    // Allocate memory using First Fit
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Display allocation
    printf("\nFirst-Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n", i + 1, processSize[i]);
    }
}

// Best Fit Allocation
void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    // Initialize allocation array
    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    // Allocate memory using Best Fit
    for (int i = 0; i < processes; i++) {
        int best = -1;

        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (best == -1 || blockSize[j] < blockSize[best]) {
                    best = j;
                }
            }
        }

        if (best != -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    // Display allocation
    printf("\nBest-Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n", i + 1, processSize[i]);
    }
}

// Worst Fit Allocation
void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    // Initialize allocation array
    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    // Allocate memory using Worst Fit
    for (int i = 0; i < processes; i++) {
        int worst = -1;

        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worst == -1 || blockSize[j] > blockSize[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }

    // Display allocation
    printf("\nWorst-Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",  i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",  i + 1, processSize[i]);
    }
}

int main() {
    int blockSize[MAX], processSize[MAX];
    int originalBlockSize[MAX];
    int blocks, processes, choice;

    // Input number of blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    // Input block sizes
    printf("Enter size of each block:\n");
    for (int i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        originalBlockSize[i] = blockSize[i];
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &processes);

    // Input process sizes
    printf("Enter size of each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Menu
    printf("\nMemory Allocation Techniques:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Restore original block sizes before each method
    for (int i = 0; i < blocks; i++)
        blockSize[i] = originalBlockSize[i];

    // Execute selected method
    switch (choice) {
        case 1:
            firstFit(blockSize, blocks, processSize, processes);
            break;

        case 2:
            bestFit(blockSize, blocks, processSize, processes);
            break;

        case 3:
            worstFit(blockSize, blocks, processSize, processes);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}