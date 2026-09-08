#ifndef ISSUE_H
#define ISSUE_H
#include <stdio.h>
#include <string.h>

struct Issue {
    int id;
    char title[100];
    char description [500];
    char priority[20];
    char status[20];
    char assigned[50];
};

void createIssue(struct Issue **issue, int *issueCount);

void viewIssues(struct Issue *issue, int issueCount);

void updateIssue(struct Issue *issue, int issueCount);

void closeIssue(struct Issue *issue, int issueCount);

void deleteIssue(struct Issue *issue, int *issueCount);

void searchIssue(struct Issue *issue, int issueCount);
#endif