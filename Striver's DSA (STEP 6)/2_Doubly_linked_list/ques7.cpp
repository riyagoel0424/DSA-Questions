// INORDER PREORDER POSTORDER

#include <iostream>
#include <iomanip>s
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}   // constructor
};

class BinaryTree { 
public:
    Node* root;

    BinaryTree(int rootValue) {
        root = new Node(rootValue);
    } 

    void insertLeft(Node* currentNode, int newValue) {         // left side of binary tree
        if (currentNode->left == nullptr) {
            currentNode->left = new Node(newValue); 
        } else {
            cout << "Left child already exists. Insert operation failed.\n";
        }
    }

    void insertRight(Node* currentNode, int newValue) {       // right side of binary tree
        if (currentNode->right == nullptr) {
            currentNode->right = new Node(newValue);
        } else {
            cout << "Right child already exists. Insert operation failed.\n";
        }
    }

    void print_tree(Node* node, int space = 10) {
        if (node == nullptr)
            return;

        space += 10;
        print_tree(node->right, space);
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << node->value << "\n";
        print_tree(node->left, space);
    }

    void print() {
        print_tree(root);
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }
};

int main() {
    BinaryTree bt(2);             
    bt.insertLeft(bt.root,4);     
    bt.insertRight(bt.root,1 );     
    bt.insertLeft(bt.root->left,3 ); 
    bt.insertRight(bt.root->left, 5); 

    cout << "Binary Tree Structure:\n";
    bt.print();

    cout << "Preorder Traversal: ";
    bt.preorder(bt.root);           
    cout << "\nInorder Traversal: ";
    bt.inorder(bt.root);            
    cout << "\nPostorder Traversal: ";
    bt.postorder(bt.root);          
    cout << endl;

    return 0;
}