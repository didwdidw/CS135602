#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;


void create_tree(Node **root, int n){
    int num, i;
    Node* cur;
    if (n == 0)
        return;
    *root = (Node*) malloc(sizeof(Node));
    scanf ("%d", &num);
    (*root)->data = num;
    (*root)->left = NULL;
    (*root)->right = NULL;

    for (i = 1; i < n; i++){
        cur = *root;
        scanf("%d", &num);
        while (1){
            if (num > cur->data){
                if (cur->right == NULL){
                    cur->right = (Node*) malloc(sizeof(Node));
                    cur->right->data = num;
                    cur->right->left = NULL;
                    cur->right->right = NULL;
                    break;
                }
                else {
                    cur = cur->right;
                }
            }
            else if (num < cur->data){
                if (cur->left == NULL){
                    cur->left = (Node*) malloc(sizeof(Node));
                    cur->left->data = num;
                    cur->left->left = NULL;
                    cur->left->right = NULL;
                    break;
                }
                else {
                    cur = cur->left;
                }
            }
            else
                break;
        }
    }
}

void showPreorder (Node* root){
    if (root != NULL){
        printf (" %d", root->data);
        showPreorder (root->left);
        showPreorder (root->right);
    }
}

void showInorder (Node* root){
    if (root != NULL){
        showInorder (root->left);
        printf (" %d", root->data);
        showInorder (root->right);
    }
}

void showPostorder (Node* root){
    if (root != NULL){
        showPostorder (root->left);
        showPostorder (root->right);
        printf (" %d", root->data);
    }
}

void print_tree(Node *root){
    printf ("preorder:");
    showPreorder (root);
    printf ("\n");
    printf ("inorder:");
    showInorder (root);
    printf ("\n");
    printf ("postorder:");
    showPostorder (root);
    printf ("\n");
}

void destroyTree(Node *root)
{
  if(root != NULL)
  {
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
  }
}

int main(void)
{
  int n;
  Node *root = NULL;
  scanf("%d",&n);
  create_tree(&root, n);
  print_tree(root);
  destroyTree(root);
  return 0;
}

