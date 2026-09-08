#include <stdio.h>
#include <stdlib.h>
#include "issue.h"
#include "file.h"

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
            createIssue(&issue, &issueCount);
            break;
        case 2:
            viewIssues(issue, issueCount);
            break;
        case 3: {
            updateIssue(issue, issueCount);
            break;
        }
        case 4: {
            closeIssue(issue, issueCount);
            break;
        }
        case 5: {
            deleteIssue(issue, &issueCount);
            break;
        }
        case 6:
        {
            searchIssue(issue, issueCount);
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