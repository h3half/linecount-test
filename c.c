#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countLines() {
    // Setup
    FILE* fileHandle = fopen("source.txt", "r");
    fseek(fileHandle, 0, SEEK_END);
    size_t flen = ftell(fileHandle);
    char *body = (char*)calloc(1, flen + 1);
    fseek(fileHandle, 0, SEEK_SET);
    fclose(fileHandle);

    // Count
    char *nb = body;
    int count = 0;
    while (nb = strchr(nb, '\n')) {
        ++count;
        ++nb;
    }

    free(body);
}

int main() {
    clock_t begin = clock();

    for (int i = 0; i < 100000; ++i) {
        countLines();
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%f\n", time_spent);

    return 0;
}
