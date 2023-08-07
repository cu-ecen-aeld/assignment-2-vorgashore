#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>


int main (int argc, char *argv[]) {
    
    openlog(NULL, 0, LOG_USER);
    
    if (argc != 3) {
        printf("Usage: %s <filename> <content>\n", argv[0]);
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
        return 1;
    }

    FILE *file;
    char *filename = argv[1];
    char *content = argv[2];

    // Open the file in a write mode
    file = fopen(filename, "w");

    if (file == NULL) {
        // perror("Error opening file");
        syslog(LOG_ERR, "Error opening file %s", filename);
        return 2;
    }

    // Write content to the file
    syslog(LOG_DEBUG, "Writing %s to file %s...", content, filename);
    fputs(content, file);

    printf("File \"%s\" created and content written.\n", filename);
    syslog(LOG_DEBUG, "Writing operation has been successfull");

    return 0;
}