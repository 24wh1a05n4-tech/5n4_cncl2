#include<stdio.h>
#include<string.h>

char data[20][20];
int n;

int main() {
    int i, j, ch;
    char tmp[20][30];

    printf("Enter the number of frames: ");
    scanf("%d", &n);
    getchar();

    // Input the frames
    for (i = 1; i <= n; i++) {
        printf("Frame %d: ", i);
        fgets(data[i], sizeof(data[i]), stdin);
        data[i][strcspn(data[i], "\n")] = '\0';
    }


    for (i = 1; i <= n; i++) {
        int len = strlen(data[i]);
        tmp[i][0] = len + '0';
        tmp[i][1] = '\0';
        strcat(tmp[i], data[i]);
    }

    // AT THE SENDER
    printf("\n\t\tAT THE SENDER:\n");
    printf("Data as frames:\n");
    for (i = 1; i <= n; i++) {
        printf("Frame %d: ", i);
        puts(tmp[i]);
    }

    printf("Data transmitted: ");
    for (i = 1; i <= n; i++) {
        printf("%s", tmp[i]);
    }
}





#include<stdio.h>
#include<string.h>

char data[20][20];
int n;

int main() {
    int i, j, ch;
    char tmp[20][30];

    printf("Enter the number of frames: ");
    scanf("%d", &n);
    getchar();

    // Input the frames
    for (i = 1; i <= n; i++) {
        printf("Frame %d: ", i);
        fgets(data[i], sizeof(data[i]), stdin);
        data[i][strcspn(data[i], "\n")] = '\0';
    }


    for (i = 1; i <= n; i++) {
        int len = strlen(data[i]);
        tmp[i][0] = len + '0';
        tmp[i][1] = '\0';
        strcat(tmp[i], data[i]);
    }

    // AT THE SENDER
    printf("\n\t\tAT THE SENDER:\n");
    printf("Data as frames:\n");
    for (i = 1; i <= n; i++) {
        printf("Frame %d: ", i);
        puts(tmp[i]);
    }

    printf("Data transmitted: ");
    for (i = 1; i <= n; i++) {
        printf("%s", tmp[i]);
    }

    // AT THE RECEIVER
    printf("\n\n\t\tAT THE RECEIVER:\n");
                                                                                                                                                                      
 for (i = 1; i <= n; i++) {
        ch = tmp[i][0] - '0';
        for (j = 0; j < ch; j++) {
            data[i][j] = tmp[i][j + 1];
        }
        data[i][j] = '\0';
    }

    printf("\nData after removing count characters: ");
    for (i = 1; i <= n; i++) {
        printf("%s", data[i]);
    }

    printf("\n\nData in frame form:\n");
    for (i = 1; i <= n; i++) {
        printf("Frame %d: ", i);
        puts(data[i]);
    }

    return 0;
}

       

