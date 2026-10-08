#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUCKET_SIZE 512

void bktInput(int packetSize, int outputRate)
{
    int remaining = packetSize;

    if (packetSize > BUCKET_SIZE)
    {
        printf("\n\tBucket overflow");
        return;
    }

    while (remaining > outputRate)
    {
        printf("\n\t%d bytes outputted.", outputRate);
        remaining = remaining - outputRate;
        sleep(1);
    }

    if (remaining > 0)
    {
        printf("\n\tLast %d bytes sent", remaining);
    }

    printf("\n\tBucket output successful\n");
}

int main()
{
    int outputRate, packetSize;
    int i;

    srand(time(0));

    printf("Enter output rate : ");
    scanf("%d", &outputRate);

    for (i = 0; i < 5; i++)
    {
        packetSize = rand() % 1000;

        printf("\nPacket no %d", i);
        printf("\tPacket size = %d", packetSize);

        bktInput(packetSize, outputRate);
    }

    return 0;
}