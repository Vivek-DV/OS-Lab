#include <stdio.h>
#include <stdlib.h>



struct Page {
    int pageNumber;
    int frequency;
    int lastUsed;
};

void initializePages(struct Page pages[], int n) {
    for (int i = 0; i < n; i++) {
        pages[i].pageNumber = -1;
        pages[i].frequency = 0;
        pages[i].lastUsed = 0;
    }
}

void printFrames(struct Page frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i].pageNumber != -1) {
            printf("%d ", frames[i].pageNumber);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int findLRU(struct Page pages[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (pages[i].lastUsed < pages[minIndex].lastUsed) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findLFU(struct Page pages[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (pages[i].frequency < pages[minIndex].frequency) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int numPages;
    int numFrames;

    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &numPages);
   
    int referenceString[numPages];

    printf("Enter the reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &referenceString[i]);
    }
   
    printf("Enter the number of page frames: ");
    scanf("%d", &numFrames);

    struct Page frames[numFrames];
    initializePages(frames, numFrames);
   
    int totalFaultsFIFO=0;
    int totalFaultsLRU=0;
    int totalFaultsLFU=0;
   

    printf("\nFIFO:\n");
    int fifoPointer = 0;
    for (int i = 0; i < numPages; i++) {
        int page = referenceString[i];
        int j;
        for (j = 0; j < numFrames; j++) {
            if (frames[j].pageNumber == page) {
                break;
            }
        }
        if (j == numFrames) {
            frames[fifoPointer].pageNumber = page;
            fifoPointer = (fifoPointer + 1) % numFrames;
            totalFaultsFIFO++;
        }
        printFrames(frames, numFrames);
    }
    printf("Total page faults(FIFO): %d\n",totalFaultsFIFO);

    printf("\nLRU Page Replacement Algorithm:\n");
    initializePages(frames,numFrames);
    for (int i = 0; i < numPages; i++) {
        int page = referenceString[i];
        int j;
        for (j = 0; j < numFrames; j++) {
            if (frames[j].pageNumber == page) {
                frames[j].lastUsed = i;
                break;
            }
        }
        if (j == numFrames) {
            int lruIndex = findLRU(frames, numFrames);
            frames[lruIndex].pageNumber = page;
            frames[lruIndex].lastUsed = i;
            totalFaultsLRU++;
        }
        printFrames(frames, numFrames);
    }
    printf("Total page faults(LRU): %d\n",totalFaultsLRU);

    printf("\nLFU Page Replacement Algorithm:\n");
    initializePages(frames,numFrames);
    for (int i = 0; i < numPages; i++) {
        int page = referenceString[i];
        int j;
        for (j = 0; j < numFrames; j++) {
            if (frames[j].pageNumber == page) {
                frames[j].frequency++;
                break;
            }
        }
        if (j == numFrames) {
            int lfuIndex = findLFU(frames, numFrames);
            frames[lfuIndex].pageNumber = page;
            frames[lfuIndex].frequency = 1;
            totalFaultsLFU++;
        }
        printFrames(frames, numFrames);
    }
    printf("Total page faults(LFU): %d\n",totalFaultsLFU);

    return 0;
}
