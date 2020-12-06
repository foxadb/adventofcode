#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 255
#define MAX_LENGTH 2048

int response(int length, int* numbers) {
    int result = -1;
    bool found = false;
    int foundI, foundJ;
    for (int i = 0; i < length && !found; i++) {
        for (int j = i; j < length && !found; j++) {
            if (numbers[i] + numbers[j] == 2020) {
                found = true;
                foundI = i;
                foundJ = j;
            }
        }
    }
    if (found) {
        result = numbers[foundI] * numbers[foundJ];
    }
    return result;
}

int main(int argc, char** argv) {
    int length = 0;
    int numbers[MAX_LENGTH];
    char buffer[BUFFER_SIZE];
    FILE* fp = fopen(argv[1], "r");
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        numbers[length] = (int)strtol(buffer, NULL, 10);
        length++;
    }
    fclose(fp);
    printf("%d\n", response(length, numbers));
    return 0;
}
