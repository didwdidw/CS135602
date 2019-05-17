#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;

int Max = 0, Sum = 0, Num = 0;

void inorder (Node* root){
    if (root != NULL){
        inorder(root->left);
        printf ("%d ", root->data);
        inorder(root->right);
    }
}

void getmax (Node* root, int cur){
    if (root == NULL){
        if (cur > Max)
            Max = cur;
    }
    else{
        getmax (root->left, cur+1);
        getmax (root->right, cur+1);
    }
}

void getsum (Node* root, int cur, int goal){
    if (root == NULL)
        return;
    if (cur == goal)
        Sum += root->data;
    else {
        getsum (root->left, cur+1, goal);
        getsum (root->right, cur+1, goal);
    }
}

void getnum (Node* root, int cur, int goal){
    if (root == NULL)
        return;
    if (cur == goal)
        Num ++;
    else {
        getnum (root->left, cur+1, goal);
        getnum (root->right, cur+1, goal);
    }
}

int main()
{
    int N, M, a, i;
    scanf ("%d", &N);
    Node* root = NULL;
    if (N > 0) {
        scanf("%d", &a);
        root = (Node*) malloc (sizeof (Node));
        root->data = a;
        root->left = NULL;
        root->right = NULL;
    }
    for (i = 1; i < N; i++){
        scanf ("%d", &a);
        Node* cur = root;
        while (1){
            if (a > cur->data){
                if (cur->right != NULL)
                    cur = cur->right;

                else{
                    cur->right = (Node*)malloc(sizeof(Node));
                    cur->right->data = a;
                    cur->right->left = NULL;
                    cur->right->right = NULL;
                    break;
                }
            }
            else if (a < cur->data) {
                if (cur->left != NULL)
                    cur = cur->left;

                else{
                    cur->left = (Node*)malloc(sizeof(Node));
                    cur->left->data = a;
                    cur->left->left = NULL;
                    cur->left->right = NULL;
                    break;
                }
            }
			else
				break;
        }
    }
    scanf ("%d", &M);
    char command[20];
    for (i = 0; i < M; i++){
        scanf ("%s", command);
        if (command[0] == 'P'){
            if (root == NULL)
                printf ("NULL");
            else
                inorder (root);
            printf ("\n");
        }

        else if (command[0] == 'G'){
            Max = 0;
            getmax (root, 0);
            printf ("%d\n", Max);
        }

        else if (command[0] == 'S'){
            int b;
            scanf ("%d", &b);
            if (b < 1)
                printf ("0\n");
            else {
                Sum = 0;
                getsum (root, 1, b);
                printf ("%d\n", Sum);
            }
        }

        else if (command[0] == 'A') {
            int b;
            scanf ("%d", &b);
            if (b < 1)
                printf ("0\n");
            else {
                Sum = 0;
                Num = 0;
                getsum (root, 1, b);
                getnum (root, 1, b);
                if (Num == 0)
                    printf ("0\n");
                else
                    printf ("%.3f\n",(float) Sum / (float) Num);
            }
        }
    }
    return 0;
}
