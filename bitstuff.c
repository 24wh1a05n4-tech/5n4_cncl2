
#include <stdio.h>

int main() {
    char bits[200], result[300];
    int i, j = 0, count = 0;
    printf("Enter the bit stream: ");
        scanf("%s", bits);

        for (i = 0; bits[i] != '\0'; i++) {
            result[j++] = bits[i];

            if (bits[i] == '1') {
                count++;

                if (count == 5) {
                    result[j++] = '0';   // Stuff a 0
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        result[j] = '\0';

        printf("Bit stream after Bit Stuffing: %s\n", result);

        return 0;
}
