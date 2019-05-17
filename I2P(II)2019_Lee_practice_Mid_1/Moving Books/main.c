#include <stdio.h>
#include <stdlib.h>

typedef struct _book{
    int num;
    struct _book* next;
    struct _book* prev;
}Book;

Book* books[10005];

Book* move_on (Book* a, Book* b, Book* head){
    if (a == NULL || b == NULL || a == b)
        return head;

    if (a == head){
        head = head->next;
        head->prev = NULL;
    }
    else if (a->next == NULL){
        a->prev->next = NULL;
    }
    else {
        a->prev->next = a->next;
        a->next->prev = a->prev;
    }

    if (b->next == NULL) {
        b->next = a;
        a->prev = b;
        a->next = NULL;
    }
    else {
        a->prev = b;
        a->next = b->next;
        b->next->prev = a;
        b->next = a;
    }
    return head;
}

Book* move_under (Book* a, Book* b, Book* head){
    if (a == NULL || b == NULL || a == b)
        return head;

    if (a == head){
        head = head->next;
        head->prev = NULL;
    }
    else if (a->next == NULL){
        a->prev->next = NULL;
    }
    else {
        a->prev->next = a->next;
        a->next->prev = a->prev;
    }

    if (b == head){
        b->prev = a;
        a->next = b;
        a->prev = NULL;
        head = a;
    }
    else {
        a->next = b;
        a->prev = b->prev;
        b->prev->next = a;
        b->prev = a;
    }
    return head;
}

Book* removebook (Book* head, Book** a){
    if ((*a) == NULL)
        return head;

    if ((*a) == head){
        if (head->next == NULL){
            head = NULL;
            free (*a);
            *a = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
            free (*a);
            *a = NULL;
        }
    }
    else if ((*a)->next == NULL){
        (*a)->prev->next = NULL;
        free (*a);
        *a = NULL;
    }
    else {
        (*a)->prev->next = (*a)->next;
        (*a)->next->prev = (*a)->prev;
        free (*a);
        *a = NULL;
    }
    return head;
}

int main()
{
    int n, i, p1, p2;
    char command[10], pos[10];
    scanf ("%d", &n);
    Book* head = (Book*) malloc (sizeof(Book));
    head->num = 0;
    head->next = NULL;
    head->prev = NULL;
    books[0] = head;
    Book* cur = head;
    for (i = 1; i < n; i++){
        Book* a = (Book*) malloc (sizeof(Book));
        a->num = i;
        a->next = NULL;
        a->prev = cur;
        cur->next = a;
        cur = cur->next;
        books[i] = a;
    }
    scanf ("%s", command);
    while (command[0] != 'e'){
        if (command[0] == 'm'){
            scanf ("%d %s %d", &p1, pos, &p2);
            if (p1 < n && p2 < n){
                if (pos[0] == 'u')
                    head = move_under (books[p1], books[p2], head);
                else
                    head = move_on (books[p1], books[p2], head);
            }
        }
        else if (command[0] == 'r'){
            scanf ("%d", &p1);
            if (p1 < n)
                head = removebook (head, &books[p1]);
        }
        scanf ("%s", command);
    }
    while (head != NULL){
        printf ("%d ", head->num);
        head = head->next;
    }
    printf ("\n");
    return 0;
}
