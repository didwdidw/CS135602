#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

void do_I(Node **head,size_t pos,unsigned short val);
void do_E(Node **head,size_t begin_pos,size_t end_pos);
void do_P(Node  *head,size_t pos);
void do_R(Node **head,unsigned short val);
void do_S(Node  *head);

int main(void)
{
    Node* head = NULL;
    size_t N;
    scanf("%zu", &N);
    while(N--) {
        char op;
        unsigned short val;
        size_t pos,begin_pos,end_pos;
        scanf(" %c", &op);
        switch(op)
        {
            case 'I':
                scanf("%zu %hu", &pos, &val);
                do_I(&head, pos, val);
                break;
            case 'E':
                scanf("%zu %zu", &begin_pos, &end_pos);
                do_E(&head, begin_pos, end_pos);
                break;
            case 'P':
                scanf("%zu", &pos);
                do_P(head, pos);
                break;
            case 'R':
                scanf("%hu", &val);
                do_R(&head, val);
                break;
            case 'S':
                do_S(head);
                break;
        }
    }
    return 0;
}

void do_I(Node **head,size_t pos,unsigned short val){

    Node* cur = *head;

    if (*head == NULL){
        *head = (Node*) malloc (sizeof (Node));
        (*head)->val = val;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return;
    }
    if (pos == 0){
        *head = (Node*) malloc (sizeof (Node));
        (*head)->val = val;
        (*head)->next = cur;
        cur->prev = *head;
        (*head)->prev = NULL;
        return;
    }
    while (pos > 0 && cur->next != NULL){
        cur = cur->next;
        pos--;
    }
    if (pos > 0){
        cur->next = (Node*) malloc(sizeof(Node));
        cur->next->val = val;
        cur->next->next = NULL;
        cur->next->prev = cur;
    }
    else {
        Node* New = (Node*) malloc (sizeof(Node));
        New->next = cur;
        New->prev = cur->prev;
        New->val = val;
        cur->prev->next = New;
        cur->prev = New;
    }
    return;
}

void do_E(Node **head,size_t begin_pos,size_t end_pos){

    Node* begin;
    Node* freeNode;
    Node* cur = *head;
    size_t times = end_pos - begin_pos;

    if (*head == NULL)
        return;

    if (begin_pos == 0){
        while (times > 0 && cur->next != NULL){
            cur = cur->next;
            times--;
        }
        if (cur->next = NULL)
            *head = NULL;
        else {
            cur->next->prev = NULL;
            *head = cur->next;
        }
        return;
    }

    while (begin_pos > 0 && cur->next != NULL){
        cur = cur->next;
        begin_pos--;
    }

    if (cur->next == NULL && begin_pos > 0)
        return;

    begin = cur->prev;

    while (times > 0 && cur != NULL){
        freeNode = cur;
        cur = cur->next;
        free(freeNode);
        times--;
    }

    begin->next = cur;

    if (cur != NULL)
        cur->prev = begin;
}
void do_P(Node  *head,size_t pos){
    if (head == NULL)
        return;
    while (pos > 0 && head->next != NULL){
        head = head->next;
        pos--;
    }
    printf ("%d ", head->val);
    return;
}
void do_R(Node **head,unsigned short val){
    Node* cur;
    Node* freeNode;

    if (*head == NULL)
        return;

    while ((*head)->val == val){
        freeNode = *head;
        *head = (*head)->next;
        free(freeNode);
        if ((*head) == NULL)
            return;
        (*head)->prev = NULL;
    }

    cur = *head;

    while (cur->next != NULL){
        if (cur->val == val){
            freeNode = cur;
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            cur = cur->next;
            free(freeNode);
        }
        else
            cur = cur->next;
    }
    if (cur->val == val){
        cur->prev->next = NULL;
        free(cur);
    }
    return;
}
void do_S(Node  *head){
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    return;
}
