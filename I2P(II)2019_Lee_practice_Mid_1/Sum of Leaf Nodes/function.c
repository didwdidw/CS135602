#include <stdlib.h>
#include "function.h"
int sum = 0;
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
    if (inorder_start > inorder_end)
        return NULL;

    Node* root = (Node*) malloc (sizeof(Node));
    if (inorder_start == inorder_end){
        root->data = *preorder;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        int i = 0;
        while (inorder[inorder_start + i] != preorder[0])
            i++;
        root->data = *preorder;
        root->left = buildTree (inorder, preorder + 1, inorder_start, inorder_start + i - 1);
        root->right = buildTree (inorder, preorder + i + 1, inorder_start + i + 1, inorder_end);
    }
    return root;
}
int flag = 0;
void caculateLeafNodesSum(Node* root){
    if(flag == 0) {
        flag = 1;
        if (root == NULL)
            return;
        else if (root->left == NULL && root->right == NULL)
            sum += root->data;
        else {
            caculateLeafNodesSum (root->left);
            caculateLeafNodesSum (root->right);
        }
        printf("%d\n", sum);
    }
    else {
        if (root == NULL)
            return;
        else if (root->left == NULL && root->right == NULL)
            sum += root->data;
        else {
            caculateLeafNodesSum (root->left);
            caculateLeafNodesSum (root->right);
        }
    }

}
