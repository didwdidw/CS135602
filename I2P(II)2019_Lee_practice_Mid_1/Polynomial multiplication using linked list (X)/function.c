#include <stdlib.h>
#include <stdio.h>
#include "function.h"

void printNode(Node* head){
    if (head == NULL)
        return;
    else {
        if (head->data != 0)
            printf (" %ld %d", head->data, head->power);
        printNode (head->next);
    }
}

Node* create(){
    Node *root;
    long data;
    int power;
    scanf ("%ld %d", &data, &power);
    root = (Node*) malloc (sizeof(Node));
    root->data = data;
    root->power = power;
    root->next = NULL;
    root->prev = NULL;
    if (power == 0){

    }
    else {
        root->next = create();
        root->next->prev = root;
    }
    return root;
}

void destroy(Node *node){
    if (node != NULL){
        destroy (node->next);
        free (node);
    }
}

Node* multiple(Node* p1, Node* p2){
    Node* head = NULL; // multiplied polynomial
    Node* t1, *t2, *t3, *t4; // temp variables
    long data;
    int power;  // the result of each multiplication of factors

    for (t1 = p1; t1 != NULL; t1 = t1->next){
        for (t2 = p2; t2 != NULL; t2 = t2->next){
            data = t1->data * t2->data;
            power = t1->power + t2->power;

            // insert the result to head
            if (head == NULL){
                head = (Node*) malloc (sizeof(Node));
                head->data = data;
                head->power = power;
                head->next = NULL;
                head->prev = NULL;
            }
            else {
                for (t3 = head; t3 != NULL; t3 = t3->next){
                    if (t3->power == power){
                        t3->data += data;
                        break;
                    }

                    else if (t3->power < power){
                        t4 = (Node*) malloc (sizeof(Node));
                        t4->data = data;
                        t4->power = power;
                        t4->next = t3;
                        t4->prev = t3->prev;
                        t3->prev->next = t4;
                        t3->prev = t4;
                        break;
                    }

                    else {
                        if (t3->next == NULL){
                            t4 = (Node*) malloc (sizeof(Node));
                            t4->data = data;
                            t4->power = power;
                            t4->next = NULL;
                            t4->prev = t3;
                            t3->next = t4;
                            break;
                        }
                    }
                }
            }
        }
    }
    return head;
}
