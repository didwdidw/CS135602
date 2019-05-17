 #include "function.h"

OWList::OWList() {
    firstPtr = NULL;
    lastPtr = NULL;
}

OWList::~OWList() {
    ListNode *pre, *cur = firstPtr;
    while (cur != NULL) {
        pre = cur;
        cur = cur->nextPtr;
        delete pre;
    }
}

void OWList::insertAtFront( const int &value ) {

    if (firstPtr == NULL) {
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
    }
    else {
        ListNode* a = new ListNode(value);
        a->nextPtr = firstPtr;
        firstPtr = a;
    }
}

void OWList::removeFromFront() {
    if (firstPtr == NULL)
        return;

    if (firstPtr == lastPtr) {
        delete firstPtr;
        firstPtr = NULL;
        lastPtr = NULL;
    }
    else {
        ListNode* cur = firstPtr;
        firstPtr = firstPtr->nextPtr;
        delete cur;
    }
}

bool OWList::isEmpty() const {
    if (firstPtr == NULL)
        return true;
    else
        return false;
}

void OWList::print() const {
    ListNode* cur = firstPtr;
    while (cur->nextPtr != NULL) {
        std::cout << cur->data << " ";
        cur = cur->nextPtr;
    }
    std::cout << cur->data;
}

void TWList:: insertAtBack( const int &value ) {
    if (firstPtr == NULL) {
        firstPtr = new  ListNode(value);
        lastPtr = firstPtr;
    }
    else {
        lastPtr->nextPtr = new ListNode(value);
        lastPtr = lastPtr->nextPtr;
    }
}

void TWList:: removeFromBack() {
    if (firstPtr == NULL)
        return;

    if (firstPtr == lastPtr) {
        delete firstPtr;
        firstPtr = NULL;
        lastPtr = NULL;
    }
    else {
        ListNode* cur = firstPtr;
        while (cur->nextPtr != lastPtr)
            cur = cur->nextPtr;
        delete lastPtr;
        lastPtr = cur;
        lastPtr->nextPtr = NULL;
    }
}
