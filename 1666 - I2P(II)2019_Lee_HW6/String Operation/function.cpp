#include "function.h"

Str::Str(char* a) {
    head = new Char(a[0]);
    Char *cur = head;
    int i = 1;
    while (a[i] != '\0'){
        cur->next = new Char(a[i]);
        cur = cur->next;
        i++;
    }
    tail = cur;
}

Str::Str(const Str &a) {
    head = new Char((a.head)->text);
    Char *cur = head;
    Char *cur_a = a.head;
    while (cur_a != a.tail){
        cur_a = cur_a->next;
        cur->next = new Char(cur_a->text);
        cur = cur->next;
    }
    tail = cur;
}

bool Str::operator==( const Str & a ) const{
    int flag = 1;
    Char* cur = head;
    Char* cur_a = a.head;
    while (1) {
        if (cur == NULL && cur_a != NULL){
            flag = 0;
            break;
        }
        else if (cur != NULL && cur_a == NULL){
            flag = 0;
            break;
        }
        else if (cur == NULL && cur_a == NULL){
            break;
        }
        else if (cur->text != cur_a->text) {
            flag = 0;
            break;
        }
        else {
            cur = cur->next;
            cur_a = cur_a->next;
        }
    }
    return flag;
}
