#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    char data;
    int value ;
    struct _Node* left;
    struct _Node* right;
}Node;

Node* buildtree (void){
    char c = getchar();
    Node* root = (Node*) malloc (sizeof (Node));
    root->data = c;
    if (c == '&' || c == '|'){
        root->left = buildtree();
        root->right = buildtree();
    }
    else {
        root->left = NULL;
        root->right = NULL;
    }
    return root;
}

int calculate (Node* root, int a, int b, int c, int d){
    if (root->data == '&')
        return calculate (root->left, a, b, c, d)& calculate (root->right, a, b, c, d);
    else if (root->data == '|')
        return calculate (root->left, a, b, c, d) | calculate (root->right, a, b, c, d);
    else {
        if (root->data == 'A')
            root->value = a;
        else if (root->data == 'B')
            root->value = b;
        else if (root->data == 'C')
            root->value = c;
        else
            root->value = d;
        return root->value;
    }
}

int main()
{
    Node* root = buildtree();
    int i, j, k, l;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            for (k = 0; k < 2; k++){
                for (l = 0; l < 2; l++){
                    printf ("%d %d %d %d %d\n", i, j, k, l, calculate(root, i, j, k, l));
                }
            }
        }
    }
    return 0;
}
