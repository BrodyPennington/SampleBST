#include "BST.h"
#include <iostream>      

int Node::degree() const {
    int deg = 0;
    if (left) deg++;
    if (right) deg++;
    return deg;
}
void BST::destroy(Node *&node) {
    if (node == nullptr) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
    node = nullptr;
}// ~BST
void BST::dup(Node *node) {
    if (node == nullptr) {
        return;
    }  

    insert(node->data);
    dup(node->left);
    dup(node->right);

} // BST(const BST &bst)

bool BST::insert(Node *&node, int val) {
    // if node == nullptr, node = new node, return true.
    if(node == nullptr) {
        node = new Node(val);
        return true;
    }
    // if val < node, return insert(left, val);
    if (val < node->data) {
        return insert(node->left, val);
    }
    // if val > node, return insert(right, val);
    if (val > node->data) {
        return insert(node->right, val);
    }

    return false;
}

bool BST::remove(Node*& node, int val) {
    if (node == nullptr) {
        return false;
    }

    if (val < node->data) {
        return remove(node->left, val);
    }

    if (val > node->data) {
        return remove(node->right, val);
    }
    

    int deg = node->degree();
    Node *tmp = node->left;
    
    switch (deg)
    {
    case 0:
        delete node;
        node = nullptr;
        break;
    case 1:
        if (node->right) {
            tmp = node->right;
        }
        delete node;
        node = tmp;
        break;
    case 2:
        while (tmp->right) {
            tmp = tmp->right;
        }
        node->data = tmp->data;
        remove(node->left, node->data);
        break;
    default:
        break;
    }

    return true;
}

bool BST::search(Node *node, int val) {
    if (node == nullptr) {
        return false;
    }

    if (val < node->data) {
        return search(node->left, val);
    }

    if (val > node->data) {
        return search(node->right, val);
    }

    return true;
}

void BST::inorder(Node *node, std::ostream &os) {
    if (node == nullptr) {
        return;
    }

    inorder(node->left, os);
    os << node->data << " ";
    inorder(node->right, os);
}

void BST::preorder(Node *node, std::ostream &os) {
    if (node == nullptr) {
        return;
    }
    os << node->data << " ";    // N
    preorder(node->left, os);   // L
    preorder(node->right, os);  // R

}

void BST::postorder(Node *node, std::ostream &os) {
    if (node == nullptr) {
        return;
    }

    postorder(node->left, os);  // L
    postorder(node->right, os); // R
    os << node->data << " ";    // N
}