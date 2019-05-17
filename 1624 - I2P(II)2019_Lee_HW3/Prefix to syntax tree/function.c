#include <stdlib.h>
#include "function.h"


BTNode* EXPR(){
    BTNode* right = FACTOR();
    if (expr[pos] == '&' || expr[pos] == '|'){
        BTNode* root = makeNode (expr[pos]);
        pos --;
        root->right = right;
        root->left = EXPR();
        return root;
    }
    return right;
}

BTNode* FACTOR(){
    BTNode* root;
    if (expr[pos] == ')'){
        pos --;
        root = EXPR ();
        pos --;
    }
    else {
        root = makeNode (expr[pos]);
        pos --;
    }
    return root;
}

BTNode* makeNode(char c){
    BTNode* root = (BTNode*) malloc (sizeof(BTNode));
    int i;
    for (i = 0; i < 6; i++){
        if (c == sym[i]){
            root->data = i;
            break;
        }
    }
    root->left = NULL;
    root->right = NULL;
    return root;
}
