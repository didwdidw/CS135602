#include <stdexcept>
#include "function.h"
using namespace std;

void List::InsertHead(int data){
    if (cnt == 0){
        head = new ListNode(data);
        head->next = NULL;
        head->prev = NULL;
        middle = head;
        tail = head;
        cnt = 1;
        pos = 1;
    }
    else {
        head->prev = new ListNode(data);
        head->prev->next = head;
        head->prev->prev = NULL;
        head = head->prev;
        cnt++;
        pos++;
        if (pos != cnt/2 + 1) {
            middle = middle->prev;
            pos--;
        }
    }
}

void List::InsertTail(int data){
    if (cnt == 0){
        head = new ListNode(data);
        head->next = NULL;
        head->prev = NULL;
        middle = head;
        tail = head;
        cnt = 1;
        pos = 1;
    }
    else {
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail->next->next = NULL;
        tail = tail->next;
        cnt ++;
        if (pos != cnt/2 + 1) {
            middle = middle->next;
            pos++;
        }
    }
}


int  List::RemoveHead(){
    if (cnt == 0)
        throw out_of_range("");
    if (cnt == 1) {
        int num = head->data;
        delete head;
        head = NULL;
        middle = NULL;
        tail = NULL;
        cnt = 0;
        pos = 0;
        return num;
    }
    else {
        int num = head->data;
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        cnt --;
        pos--;
        if (pos != cnt/2 + 1) {
            pos++;
            middle = middle->next;
        }
        return num;
    }
}

int  List::RemoveTail(){
    if (cnt == 0)
        throw out_of_range("");
    if (cnt == 1) {
        int num = tail->data;
        delete tail;
        head = NULL;
        middle = NULL;
        tail = NULL;
        cnt = 0;
        pos = 0;
        return num;
    }
    else {
        int num = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
        cnt --;
        if (pos != cnt/2 + 1) {
            pos--;
            middle = middle->prev;
        }
        return num;
    }
}

void List::Swap() {
    if (cnt == 0 || cnt == 1)
        return ;
    if (cnt == 2) {
        head->prev = tail;
        tail->next = head;
        head = tail;
        tail = tail->prev;
        middle = tail;
        head->prev = NULL;
        tail->next = NULL;
    }
    else {
        head->prev = tail;
        tail->next = head;
        ListNode* newNode = head;
        head = middle;
        tail = middle->prev;
        if (cnt%2)
            middle = newNode->prev;
        else
            middle = newNode;
        head->prev = NULL;
        tail->next = NULL;
    }

}

int  List::getSize(){
    return cnt;
}

int  List::getMiddle(){
    return pos;
}
