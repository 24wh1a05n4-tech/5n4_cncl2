#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUCKET_CAPACITY 10  // Maximum number of tokens the bucket can hold
#define REFILL_RATE 2      // Number of tokens added per second

int main() {
    int tokens = 0;         // Initial tokens in the bucket
    int num_packets;        // Number of packets to simulate
    
    printf("--- Token Bucket Algorithm Simulation ---\n");
    printf("Bucket Capacity: %d tokens\n", BUCKET_CAPACITY);
    printf("Refill Rate: %d tokens/second\n\n", REFILL_RATE);

    printf("Enter the number of incoming packets: ");
    if (scanf("%d", &num_packets) != 1 || num_packets <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Array to store the size of each incoming packet
    int *packet_sizes = (int *)malloc(num_packets * sizeof(int));
    
    printf("Enter the sizes for %d packets:\n", num_packets);
    for (int i = 0; i < num_packets; i++) {
        printf("Packet %d size: ", i + 1);
        scanf("%d", &packet_sizes[i]);
    }

    printf("\n--- Starting Transmission Simulation ---\n");

    for (int i = 0; i < num_packets; i++) {
        // 1. Simulate time lapse (1 second) and add new tokens
        printf("\n[Time Step] 1 second passes... Adding %d tokens.\n", REFILL_RATE);
        tokens += REFILL_RATE;
        
        if (tokens > BUCKET_CAPACITY) {
            tokens = BUCKET_CAPACITY;
            printf("Bucket is full! Excess tokens discarded.\n");
        }
        printf("Current tokens in bucket: %d\n", tokens);

        // 2. Process the current packet
        int required_tokens = packet_sizes[i];
        printf("Incoming Packet %d (Size: %d tokens)\n", i + 1, required_tokens);

        if (required_tokens <= tokens) {
            // Sufficient tokens available
            tokens -= required_tokens;
            printf("Result: SUCCESS. Packet transmitted. Remaining tokens: %d\n", tokens);
        } else {
            // Insufficient tokens
            printf("Result: DROPPED/DELAYED. Not enough tokens (Required: %d, Available: %d)\n", 
                   required_tokens, tokens);
        }

        // Sleep for 1 second to simulate the real-time gap between packets
        sleep(1);
    }

    printf("\n--- Simulation Complete ---\n");
    free(packet_sizes);
    return 0;
}
