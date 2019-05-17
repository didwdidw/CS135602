#include "function.h"

Josephus::Josephus() {
    head = NULL;
}

Josephus::Josephus(const int &num) {
    generatecircularlinkedList(num);
    generateFib(num);
    noOfPeople = num;
}

Josephus::~Josephus() {
    delete head;
    head = NULL;
}

void Josephus::generatecircularlinkedList(const int & num){
    head = new  Node(1);
    Node* cur = head;
    int i;
    for (i = 2; i <= num; i++){
        cur->next = new Node(i);
        cur = cur->next;
    }
    cur->next = head;
    head = cur;
}

void Josephus::generateFib(const int & num){
    sequence[0] = 1;
    sequence[1] = 1;
    int i;
    for (i = 2; i <= num; i++)
        sequence[i] = sequence[i-1] + sequence[i-2];
}

int Josephus::kill() {
    int i = 0, j, k;
    Node* todelete, *cur = head;
    while (noOfPeople != 1){
        k = sequence[i] % noOfPeople;
        if (k == 0)
            k = noOfPeople;
        for (j = 1; j < k; j++)
            cur = cur->next;
        todelete = cur->next;
        cur->next = cur->next->next;
        delete todelete;
        i++;
        noOfPeople--;
    }
    head = cur;
    return cur->number;
}
