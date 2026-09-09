#include "file.h"

void saveIssues(struct Issue *issue, int issueCount) {
    //Creates a binary file to save the issues in the data folder. If the data folder does not exist, it will create it.
    FILE *file = fopen("data/issues.dat", "wb");

    if (file == NULL) {
        printf("Could not open file for saving.\n");
        return;
    }
    //Writes the issues to the file in binary format.
    fwrite(issue, sizeof(struct Issue), issueCount, file);

    fclose(file);

    printf("Issues saved successfully.\n");
}

int loadIssues(struct Issue **issue) {
    //Creates a binary file to load the issues from the data folder. If the data folder does not exist, it will create it.
    FILE *file = fopen("data/issues.dat", "rb");

    if (file == NULL) {
        return 0;
    }
    //Calculates the number of issues in the file by dividing the file size by the size of the Issue struct.
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int issueCount = fileSize / sizeof(struct Issue);

    if (issueCount > 0) {
        *issue = malloc(issueCount * sizeof(struct Issue));

        if (*issue == NULL) {
            fclose(file);
            return 0;
        }

        //Reads the issues from the file in binary format.
        fread(*issue, sizeof(struct Issue), issueCount, file);
    }

    fclose(file);

    return issueCount;
}
