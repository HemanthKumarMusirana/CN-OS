#include <stdio.h>

int main() {
    int memorySize, pageSize;
    int totalPages, numProcesses, remainingPages;
    int pagesRequired[20], frameTable[20][20];
    int i, j;

    int processNum, pageNum, offset, physicalAddress;

    // Input memory size and page size
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);

    printf("Enter the page size: ");
    scanf("%d", &pageSize);

    // Total pages available
    totalPages = memorySize / pageSize;
    remainingPages = totalPages;

    printf("The number of pages available in memory = %d\n", totalPages);

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // For each process: input pages required
    for (i = 1; i <= numProcesses; i++) {

        printf("\nEnter number of pages required for P[%d]: ", i);
        scanf("%d", &pagesRequired[i]);

        // Check if enough pages available
        if (pagesRequired[i] > remainingPages) {
            printf("Memory is Full!\n");
            break;
        }

        remainingPages -= pagesRequired[i];

        // Input page table (frame numbers)
        printf("Enter page table (frame numbers) for P[%d]: ", i);
        for (j = 0; j < pagesRequired[i]; j++) {
            scanf("%d", &frameTable[i][j]);
        }
    }

    // Logical → Physical address translation
    printf("\nEnter Logical Address to find Physical Address\n");
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &processNum, &pageNum, &offset);

    // Validations
    if (processNum > numProcesses ||
        pageNum >= pagesRequired[processNum] ||
        offset >= pageSize) {

        printf("Invalid Process or Page Number or Offset\n");
    }
    else {
        physicalAddress = frameTable[processNum][pageNum] * pageSize + offset;
        printf("The Physical Address = %d\n", physicalAddress);
    }

    return 0;
}
