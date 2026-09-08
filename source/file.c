#include "file.h"

void saveIssues(struct Issue *issue, int issueCount) {
    FILE *file = fopen("data/issues.dat", "wb");

    if (file == NULL) {
        printf("Could not open file for saving.\n");
        return;
    }

    fwrite(issue, sizeof(struct Issue), issueCount, file);

    fclose(file);

    printf("Issues saved successfully.\n");
}

int loadIssues(struct Issue **issue) {
    FILE *file = fopen("data/issues.dat", "rb");

    if (file == NULL) {
        return 0;
    }

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

        fread(*issue, sizeof(struct Issue), issueCount, file);
    }

    fclose(file);

    return issueCount;
}
