#include "function.h"
#include <string.h>

Array_BST::Array_BST() {
    memset (array, 0, sizeof(array));
}

void Array_BST::insert(const int & key) {
    int i = 1, h = 1;

    while (1) {
        if (array[i] == 0) {
            array[i] = key;
            if (h > Height)
                Height = h;
            return;
        }
        else if (key > array[i]) {
            i = i*2 + 1;
            h++;
        }
        else if (key < array[i]) {
            i = i*2;
            h++;
        }
        else
            return;
    }
}

bool Array_BST::search(const int & key) const {
    int i, k = pow(2, height());
    for (i = 1; i <= k-1; i++) {
        if (array[i] == key)
            return true;
    }
    return false;
}

List_BST::List_BST() {
    root = NULL;
}

void List_BST::insert(const int & key) {
    if (root == NULL) {
        root = createLeaf(key);
        Height = 1;
        return;
    }

    ListNode* cur = root;
    int h = 1;
    while (1) {
        if (key > cur->key) {
            if (cur->right == NULL) {
                cur->right = createLeaf(key);
                if (h+1 > Height)
                    Height = h+1;
                break;
            }
            else {
                cur = cur->right;
                h++;
            }
        }
        else if (key < cur->key) {
            if (cur->left == NULL) {
                cur->left = createLeaf(key);
                if (h+1 > Height)
                    Height = h+1;
                break;
            }
            else {
                cur = cur->left;
                h++;-
            }
        }
        else
            break;
    }
}

bool List_BST::search(const int & key) const {
    ListNode* cur = root;
    while (cur != NULL) {
        if (cur->key == key)
            return true;
        else if (cur->key > key)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return false;
}

ListNode* List_BST::createLeaf(int key) const {
    ListNode* p = new ListNode(key);
    return p;
}

void List_BST::deleteTree(ListNode *root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

