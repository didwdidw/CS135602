#include <stdio.h>
#include <stdlib.h>

typedef struct man {
    int id;
    struct man* next;
    struct man* prev;
} man;

man* head;
man* createList(int n);
int solveJosephus(int step);

int main(){

    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus(m));
    }

    return 0;
}

man* createList (int n){
    man* cur = (man*) malloc(sizeof (man));
    cur->id = 1;
    man* head = cur;
    int i;
    for (i = 2; i <= n; i++){
        cur->next = (man*)malloc(sizeof (man));
        cur->next->prev = cur;
        cur = cur->next;
        cur->id = i;
    }
    cur->next = head;
    head->prev = cur;
    return head;int solveJosephus(int step);
}

int solveJosephus(int step){
    int dir = 1, i;
    man* cur = head;
    while (cur->next != cur){
        if (dir == 1){
            for (i = 1; i < step; i++){
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            man* free_node = cur;
            cur = cur->prev;
            free (free_node);
        }
        else {
            for (i = 1; i < step; i++){
                cur = cur->prev;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            man* free_node = cur;
            cur = cur->next;
            free (free_node);
        }
        dir *= -1;
    }
    return cur->id ;
}
