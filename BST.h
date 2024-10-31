#include <iostream>

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node() : data(0), left(nullptr), right(nullptr) {}
        Node(int data) : data(data), left(nullptr), right(nullptr) {}

        int degree() const; 

};

class BST {
    private:
        Node *root;

        void destroy(Node *&node); // ~BST
        void dup(Node *node); // BST(const BST &bst)

        bool insert(Node *&node, int val);
        bool remove(Node *&node, int val);
        bool search(Node *node, int val);

        void inorder(Node *node, std::ostream &os);
        void preorder(Node *node, std::ostream &os);
        void postorder(Node *node, std::ostream &os);

    public:
        
        BST() : root(nullptr) {}
        ~BST() {destroy(root);}
        BST(const BST &bst) {dup(bst.root);}

        bool insert(int val) {return insert(root, val);}
        bool remove(int val) {return remove(root, val);}
        bool search(int val) {return search(root, val);}
        bool find(int val) {return search(root, val);}

        void inorder(std::ostream &os) {inorder(root, os);}
        void preorder(std::ostream &os) {preorder(root, os);}
        void postorder(std::ostream &os) {postorder(root, os);}
};