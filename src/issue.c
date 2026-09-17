#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "issue.h"

void createIssue(struct Issue **issue, int *issueCount)
{
    //Reallocates memory for the issues array to accommodate a new issue.
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

   //Validates the priority input to ensure it is either "Low", "Medium", or "High".
    do {
    printf("Enter priority (Low, Medium, High): ");
    scanf(" %19s", (*issue)[*issueCount].priority);

    if (strcmp((*issue)[*issueCount].priority, "Low") != 0 &&
        strcmp((*issue)[*issueCount].priority, "Medium") != 0 &&
        strcmp((*issue)[*issueCount].priority, "High") != 0) {
        
        printf("Invalid priority. Please try again.\n");
    }

    } 
    while (strcmp((*issue)[*issueCount].priority, "Low") != 0 &&
         strcmp((*issue)[*issueCount].priority, "Medium") != 0 &&
         strcmp((*issue)[*issueCount].priority, "High") != 0);

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

    //Iterates through the issues array and prints the details of each issue.
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
    } else 
    //Prompts the user to update the details of the found issue, including title, description, priority, status, and assigned person.
    {
        printf("Enter new title (current: %s): ", foundIssue->title);
        scanf(" %[^\n]", foundIssue->title);

        printf("Enter new description (current: %s): ", foundIssue->description);
        scanf(" %[^\n]", foundIssue->description);

        printf("Enter new priority (current: %s): ", foundIssue->priority);
        do {
            scanf(" %19s", foundIssue->priority);

            if (strcmp(foundIssue->priority, "Low") != 0 &&
                strcmp(foundIssue->priority, "Medium") != 0 &&
                strcmp(foundIssue->priority, "High") != 0) {

                printf("Invalid priority. Please try again.\n");
            }

        } while (strcmp(foundIssue->priority, "Low") != 0 &&
                 strcmp(foundIssue->priority, "Medium") != 0 &&
                 strcmp(foundIssue->priority, "High") != 0);

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
    } else 
    //Updates the status of the found issue to "CLOSED" and prints a success message.
    {
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
    //Iterates through the issues array to find the issue with the specified ID. If found, it shifts the subsequent issues to fill the gap and decrements the issue count.
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

    //Iterates through the issues array to find issues with the specified title. If found, it prints the details of the matching issues.
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


