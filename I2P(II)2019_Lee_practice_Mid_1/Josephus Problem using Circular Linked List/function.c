#include <stdlib.h>
#include <stdio.h>
#include "function.h"

Node* create(int n){
    if (n == 0)
        return NULL;
    Node* head = (Node*) malloc (sizeof (Node));
    head->data = 1;
    Node* cur = head;
    int i;
    for (i = 1; i < n; i++){
        cur->next = (Node*) malloc(sizeof(Node));
        cur = cur->next;
        cur->data = i + 1;
    }
    cur->next = head;
    return head;
}

void josephus(int m,Node *head){
    if (head->next == head)
        printf("%d\n", head->data);
    else {
        int i = m;
        while (i - 2 > 0){
            head = head->next;
            i--;
        }
        Node* freenode = head->next;
        printf ("%d ", head->next->data);
        head->next = freenode->next;
        free (freenode);
        josephus(m, head->next);
    }
}
