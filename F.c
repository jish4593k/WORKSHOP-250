#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold video information
typedef struct {
    char name[100];
    char views[20];
    char link[100];
} Video;

int main() {
    // Initialize the lists
    Video videos[1000];  // Assuming a maximum of 1000 videos
    int videoCount = 0;

    
    char thing_url[200];
    printf("Youtube Channel Link: ");
    fgets(thing_url, sizeof(thing_url), stdin);
    strtok(thing_url, "\n");  // Remove newline character

 
    if (strcmp(thing_url + strlen(thing_url) - 6, "videos") != 0) {
        if (thing_url[strlen(thing_url) - 1] == '/') {
            strcat(thing_url, "videos");
        } else {
            strcat(thing_url, "/videos");
        }
    }

 
    printf("Skipping web scraping part in C.\n");


    for (int i = 0; i < videoCount; i++) {
        for (int j = i + 1; j < videoCount; j++) {
            if (atoi(videos[j].views) > atoi(videos[i].views)) {
                // Swap videos[i] and videos[j]
                Video temp = videos[i];
                videos[i] = videos[j];
                videos[j] = temp;
            }
        }
    }

    
    FILE *file = fopen("output.csv", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    fprintf(file, "Name\tViews\tLink\n");


    for (int i = 0; i < videoCount; i++) {
        fprintf(file, "%s\t%s\t%s\n", videos[i].name, videos[i].views, videos[i].link);
    }

    fclose(file);


    printf("Total videos: %d\n", videoCount);

    return 0;
}
