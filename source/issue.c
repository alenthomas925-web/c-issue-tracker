#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "issue.h"

void createIssue(struct Issue **issue, int *issueCount)
{
    *issue = realloc(*issue, (*issueCount + 1) * sizeof(struct Issue));

    if (*issue == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    (*issue)[*issueCount].id = *issueCount + 1;

    printf("Enter issue title: ");
    scanf(" %[^\n]", (*issue)[*issueCount].title);

    printf("Enter issue description: ");
    scanf(" %[^\n]", (*issue)[*issueCount].description);

    printf("Enter priority (Low, Medium, High): ");
    scanf(" %19s", (*issue)[*issueCount].priority);

    strcpy((*issue)[*issueCount].status, "OPEN");

    printf("Enter assigned person: ");
    scanf(" %[^\n]", (*issue)[*issueCount].assigned);

    printf("Issue created with ID: %d\n", (*issue)[*issueCount].id);

    (*issueCount)++;
}

void viewIssues(struct Issue *issue, int issueCount)
{
    if (issueCount == 0) {
        printf("No issues found.\n");
        return;
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
}

void updateIssue(struct Issue *issue, int issueCount)
{
    int id;

    printf("Enter issue ID: ");
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
    } else {
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
}

void closeIssue(struct Issue *issue, int issueCount)
{
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
    } else {
        strcpy(foundIssue->status, "CLOSED");
        printf("Issue closed successfully.\n");
    }
}

void deleteIssue(struct Issue *issue, int *issueCount)
{
    int id;

    printf("Enter issue ID to delete: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < *issueCount; i++) {
        if (issue[i].id == id) {
            found = 1;

            for (int j = i; j < *issueCount - 1; j++) {
                issue[j] = issue[j + 1];
            }

            (*issueCount)--;

            printf("Issue deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Issue not found.\n");
    }
}

void searchIssue(struct Issue *issue, int issueCount)
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
}


