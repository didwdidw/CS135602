#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* createList();
Node* reverse(Node*);
void printList(Node *head);
void freeList(Node*);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

    head = createList();
	head = reverse(head);
	printList(head);
	freeList(head);
	return 0;
}



void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
Node* createList(void){
    Node* head = (Node*) malloc (sizeof(Node));
    Node* cur;
    head->next = cur;
    int num;
    scanf ("%d", &num);
    if (num == -1)
        return NULL;
    head->next = NULL;
    head->data = num;
    cur = head;
    scanf ("%d", &num);
    while (num != -1){
        cur->next = (Node*) malloc (sizeof (Node));
        cur = cur->next;
        cur->data = num;
        cur->next = NULL;
        scanf ("%d", &num);
    }
    return head;
}
Node* reverse(Node* head){
    Node* pre = NULL;
    Node* cur = head;
    Node* next = cur->next;
    while (next != NULL){
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    cur->next = pre;
    return cur;
}

