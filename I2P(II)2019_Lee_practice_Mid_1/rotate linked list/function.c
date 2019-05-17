#include <stdlib.h>
#include <stdio.h>
#include "function.h"

void rotateList(Node** head,int k){
    Node* cur = *head;
    int i;
    for (i = 1; i < k; i++)
        cur = cur->next;
    Node* end = cur;
    if (cur->next == NULL)
        return;
    Node* start = cur->next;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = *head;
    end->next = NULL;
    *head = start;
}
