#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_hash_opt.h"

unsigned long int hash_function(char *str)
{
    unsigned long int hash = 5381;
    int c;

    while((c = *str++)) {
        hash += (hash << 5) + c;
    }

    return (hash % HASH_TABLE_SIZE);
}

entry *findName(char lastName[], entry **pTable)
{
    unsigned long int index = hash_function(lastName);
    entry *pHead = pTable[index];

    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0) {
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry **head)
{
    /* allocate memory for the new entry and put lastName */
    entry *temp = *head;
    if((*head)) {
        while(temp->pNext)
            temp = temp->pNext;
    } else {
        if ( !((*head) = (entry *) malloc(sizeof(entry))) ) {
            printf("ERROR : memory overflow\n");
            exit(0);
        }
        temp = (*head);
    }
    strcpy(temp->lastName, lastName);
    temp->pNext = NULL;
    return temp;
}
