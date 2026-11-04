#include <stdio.h>

int main() {
    char data[100], result[200];
    int i, j = 0;

    printf("Enter the data: ");
    scanf("%s", data);

    result[j++] = 'F';   // Start Flag

    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == 'F' || data[i] == 'E')
            result[j++] = 'E';   // Escape Character

        result[j++] = data[i];
    }

    result[j++] = 'F';   // End Flag
    result[j] = '\0';

    printf("Frame after Character Stuffing: %s\n", result);

    return 0;
}

