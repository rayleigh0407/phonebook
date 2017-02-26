#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    e->data = (otherData *) malloc(sizeof(otherData));
    strcpy(e->lastName, lastName);
    /* put other data after this line */
    e->pNext = NULL;

    return e;
}
