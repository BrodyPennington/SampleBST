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
    // value isnt found
    if (node == nullptr) {
        // return that the node wasnt found
        return false;
    }
    // if value is less than parent node, move left down the subtree
    if (val < node->data) {
        // call remove function on the left child
        return remove(node->left, val);
    }
    // if value is greater than parent node, move right down the subtree
    if (val > node->data) {
        // call remove function on the right child
        return remove(node->right, val);
    }
    
    // value was found, now determine how many children it has (0, 1 or 2) and store it in deg.
    int deg = node->degree();

    // temporarily point to the left child of the value being deleted.
    Node *tmp = node->left;
    
    // delete based on the node's degree
    switch (deg) {
    // case 0: node doesnt have children (leaf node)
    case 0:
        // free the memory
        delete node;
        // set the pointer to null since it has been deleted
        node = nullptr;
        break;

    // case 1: node has 1 child
    case 1:
        // check if right child exists
        if (node->right) {
            // if right child exists, point tmp to right child
            tmp = node->right;
        }
        // delete the current node
        delete node;
        // move the right child to the deleted node's position
        node = tmp;
        break;

    // case 2: node has two children
    case 2:
        // go to the rightmost node in the left subtree
        while (tmp->right) {
            // keep moving to the rightmost child until the end is reached
            tmp = tmp->right;
        }
        /* replace the value in the node to currently be deleted with 
        the the value of the rightmost node in the left subtree
        */
        node->data = tmp->data;
        // remove the rightmost node from the left subtree recursively by calling remove function.
        remove(node->left, node->data);
        break;
    
    // safeguard
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