#ifndef FILE_H
#define FILE_H
#include "issue.h"
#include <stdlib.h>
#include <stdio.h>
void saveIssues(struct Issue *issue, int issueCount);
int loadIssues(struct Issue **issue);

#endif