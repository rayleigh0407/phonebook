#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define HASH_OPT 1
#define HASH_TABLE_SIZE 393241

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
    struct __PHONE_BOOK_ENTRY *pRight;
    struct __PHONE_BOOK_ENTRY *pLeft;
} entry;

unsigned long int hash_function(char *str);
entry *findName(char lastName[], entry **pTable);
entry *append(char lastName[], entry **head);

#endif
