#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Issue {
    int id;
    char title[100];
    char description [500];
    char priority[20];
    char status[20];
    char assigned[50];
};

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

int main () {
    int choice = 0;
    struct Issue *issue = NULL;
    int issueCount = 0;

    issueCount = loadIssues(&issue);

    while (choice != 7) {
        
    
    printf("==========\n   C Issue Tracker\n==========\n");

    printf("1. Create Issue\n2. View Issues\n3. Update Issue\n4. Close Issue\n5. Delete Issue\n6. Search Issue\n7. Save & Exit\n");

    printf("Select and option: (1-7): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            issue = realloc(issue, (issueCount +1) * sizeof(struct Issue));

            if (issue == NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }
            issue[issueCount].id = issueCount + 1;

            printf("Enter issue title: ");
            scanf(" %[^\n]", issue[issueCount].title);

            printf("Enter issue description: ");
            scanf(" %[^\n]", issue[issueCount] .description);
 
            printf("Enter priority (Low, Medium, High): ");
            scanf(" %19s", issue[issueCount].priority);

            strcpy(issue[issueCount].status, "OPEN");

            printf("Enter assigned person: ");
            scanf(" %[^\n]", issue[issueCount].assigned);

            printf("Issue created with ID: %d\n", issue[issueCount].id);
            printf("Title: %s\n", issue[issueCount].title);
            printf("Description: %s\n", issue[issueCount].description);
            printf("Priority: %s\n", issue[issueCount].priority);
            printf("Status: %s\n", issue[issueCount].status);
            printf("Assigned to: %s\n", issue[issueCount].assigned);

            issueCount++;
            break;
        case 2:
            if (issueCount == 0) {
                printf("No issues found. \n");
                break;
            }

            printf("\nView issues\n");

            for (int i = 0; i < issueCount; i++) {
                printf("ID: %d\n", issue[i].id);
                printf("Title: %s\n", issue[i].title);
                printf("Description: %s\n", issue[i].description);
                printf("Priority: %s\n", issue[i].priority);
                printf("Status: %s\n", issue[i].status);
                printf("Assigned to: %s\n", issue[i].assigned);
                printf("\n");
            }

            break;
        case 3: {
            int id;
            printf("Enter issue ID: \n");
            scanf("%d", &id);

            int found = 0;
            struct Issue *foundIssue = NULL;

            for (int i = 0; i < issueCount; i++) {
                if (issue[i].id == id) {
                    found = 1;
                    foundIssue = &issue[i];
                    break;
                }
            }
            if (!found) {
                printf("Issue not found.\n");
            }
            else {
                printf("Enter new title (current: %s): ", foundIssue->title);
                scanf(" %[^\n]", foundIssue->title);

                printf("Enter new description (current: %s): ", foundIssue->description);
                scanf(" %[^\n]", foundIssue->description);

                printf("Enter new priority (current: %s): ", foundIssue->priority);
                scanf(" %19s", foundIssue->priority);

                printf("Enter new status (current: %s): ", foundIssue->status);
                scanf(" %19s", foundIssue->status);

                printf("Enter new assigned person (current: %s): ", foundIssue->assigned);
                scanf(" %[^\n]", foundIssue->assigned);

                printf("Issue updated successfully.\n");
            }
            break;
        }
        case 4: {
            int id;
            printf("Enter issue ID to close: ");
            scanf("%d", &id);

            int found = 0;
            struct Issue *foundIssue = NULL;

            for (int i = 0; i < issueCount; i++) {
            if (issue[i].id == id) {
            found = 1;
            foundIssue = &issue[i];
            break;
            }
            }
            if (!found) {
            printf("Issue not found.\n");
            } 
            else {
            strcpy(foundIssue->status, "CLOSED");
            printf("Issue closed successfully.\n");
            }
            break;
        }
        case 5: {
            int id;
            printf("Enter issue ID to delete: ");
            scanf("%d", &id);

            int found = 0;

            for (int i = 0; i < issueCount; i++) {
                if (issue[i].id == id) {
                    found = 1;
                    for (int j = i; j < issueCount - 1; j++) {
                        issue[j] = issue[j + 1];
                    }
                issueCount--;
                printf("Issue deleted successfully.\n");
                break;
                }
                }

            if (!found) {
            printf("Issue not found.\n");
            }

            break;
        }
        case 6:
        {
            char searchTitle[100];

            printf("Enter issue title to search: ");
            scanf(" %[^\n]", searchTitle);
            
            int found = 0;

            for (int i = 0; i < issueCount; i++) {
            if (strcmp(issue[i].title, searchTitle) == 0) {
                printf("\nIssue found:\n");
                printf("ID: %d\n", issue[i].id);
                printf("Title: %s\n", issue[i].title);
                printf("Description: %s\n", issue[i].description);
                printf("Priority: %s\n", issue[i].priority);
                printf("Status: %s\n", issue[i].status);
                printf("Assigned to: %s\n", issue[i].assigned);

                found = 1;
            }
            }

            if (!found) {
            printf("No issue found with that title.\n");
            }

            break;
        }
        case 7:
            saveIssues(issue, issueCount);
            printf("Exiting...\n");
            break;
        }
    }
free(issue);
return 0;
}