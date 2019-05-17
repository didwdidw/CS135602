#include <iostream>
using namespace std;

class ListNode{
private:
    int data;
    ListNode *next;
    ListNode *prev;
public:
    ListNode():data(0),next(NULL), prev(NULL){};
    ListNode(int a):data(a),next(NULL), prev(NULL){};

    friend class List;
};

class List {
private:
    ListNode* head;  // head of the doubly linked list
    ListNode* tail;  // tail of the doubly linked list
    ListNode* middle; // middle of the list
    int       cnt;   // total count of the elements in the list
    int       pos;   // the position of middle

    void reset(){
        head = NULL;
        tail = NULL;
        middle = NULL;
        cnt = 0;
        pos = 0;
    }

    void clean(){
        ListNode* temp;
        while(head!=NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    // constructor and destructor
    List(){
        reset();
    }

    ~List(){
        clean();
    }

    void InsertHead(int data);
    int  RemoveHead();
    void InsertTail(int data);
    int  RemoveTail();
    void Swap();
    int  getSize();
    int  getMiddle();

};

