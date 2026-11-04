#include<stdio.h>

int main() {
    int windowSize, totalFrames, i;
    int frames[50];

    // Prompt the user for the sliding window size
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    // Prompt the user for the number of frames to transmit
    printf("\nEnter number of frames to transmit: ");
    scanf("%d", &totalFrames);

    // Prompt the user to enter all the frames
    printf("\nEnter %d frames: ", totalFrames);
      for(i = 1; i <= totalFrames; i++) {
        scanf("%d", &frames[i]);
    }

    // Display the transmission process
    printf("\nSliding Window Protocol Simulation (Assuming No Frame Loss/Corruption)\n");
    printf("Sender sends %d frames at a time and waits for acknowledgement.\n\n", windowSize);

    for(i = 1; i <= totalFrames; i++) {
        // Send frame
        printf("%d ", frames[i]);

        // Check if the window is full
        if(i % windowSize == 0) {
            printf("\nAcknowledgement of above frames is received by sender\n\n");
        }
    }

    // If remaining frames are less than window size
    if(totalFrames % windowSize != 0) {
        printf("\nAcknowledgement of above frames is received by sender\n");
    }

    return 0;
}


