#include <iostream>
using namespace std;

// AVL TREE

class BTreeNode {
public:
    int* keys;
    BTreeNode** children;
    int t; 
    int n;
    bool leaf;
    BTreeNode(int t, bool leaf);
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
    void traverse();
    BTreeNode* search(int key);
    void remove(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
};

class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t);
    void insert(int key);
    void remove(int key);
    void traverse() {
        if (root) root->traverse();
    }
    BTreeNode* search(int key) {
        return root ? root->search(key) : nullptr;
    }
};

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int key) {
        this->key = key;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    AVLNode* root;

    AVLTree() {
        root = nullptr;
    }

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    AVLNode* insert(AVLNode* node, int key) {
        if (!node) return new AVLNode(key);
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* root, int key) {
        if (!root) return root;
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left || !root->right) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (!root) return root;
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    bool search(AVLNode* node, int key) {
        if (!node) return false;
        if (key < node->key) return search(node->left, key);
        if (key > node->key) return search(node->right, key);
        return true;
    }

    void traverse(AVLNode* node) {
        if (node) {
            traverse(node->left);
            cout << node->key << " ";
            traverse(node->right);
        }
    }
};

BTreeNode::BTreeNode(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;
    keys = new int[2 * t - 1];
    children = new BTreeNode*[2 * t];
    n = 0;
}

void BTreeNode::insertNonFull(int key) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        n++;
        cout << "Node inserted: " << key << endl;
    } else {
        while (i >= 0 && keys[i] > key) i--;
        if (children[i + 1]->n == (2 * t - 1)) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key) i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];
    children[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n++;
}

void BTreeNode::traverse() {
    for (int i = 0; i < n; i++) {
        if (!leaf) children[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!leaf) children[n]->traverse();
}

BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < n && key > keys[i]) i++;
    if (i < n && keys[i] == key) return this;
    if (leaf) return nullptr;
    return children[i]->search(key);
}

void BTreeNode::remove(int key) {
    int idx = 0;
    while (idx < n && keys[idx] < key) idx++;
    if (idx < n && keys[idx] == key) {
        if (leaf) {
            removeFromLeaf(idx);
        } else {
            removeFromNonLeaf(idx);
        }
    } else {
        if (leaf) {
            cout << "The key " << key << " does not exist in the tree.\n";
            return;
        }
        bool isLast = (idx == n);
        if (children[idx]->n < t) fill(idx);
        if (isLast && idx > n) children[idx - 1]->remove(key);
        else children[idx]->remove(key);
    }
}

void BTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < n; i++)
        keys[i - 1] = keys[i];
    n--;
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];
    if (children[idx]->n >= t) {
        int pred = getPredecessor(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->n >= t) {
        int succ = getSuccessor(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(key);
    }
}

int BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->leaf) cur = cur->children[cur->n];
    return cur->keys[cur->n - 1];
}

int BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->leaf) cur = cur->children[0];
    return cur->keys[0];
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->n >= t) borrowFromPrev(idx);
    else if (idx != n && children[idx + 1]->n >= t) borrowFromNext(idx);
    else {
        if (idx != n) merge(idx);
        else merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];
    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];
    if (!child->leaf) {
        for (int i = child->n; i >= 0; i--)
            child->children[i + 1] = child->children[i];
    }
    child->keys[0] = keys[idx - 1];
    if (!child->leaf) child->children[0] = sibling->children[sibling->n];
    keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n++;
    sibling->n--;
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys[child->n] = keys[idx];
    if (!child->leaf) child->children[child->n + 1] = sibling->children[0];
    keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; i++)
            sibling->children[i - 1] = sibling->children[i];
    }
    child->n++;
    sibling->n--;
}

void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys[t - 1] = keys[idx];
    for (int i = 0; i < sibling->n; i++)
        child->keys[i + t] = sibling->keys[i];
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->children[i + t] = sibling->children[i];
    }
    for (int i = idx + 1; i < n; i++)
        keys[i - 1] = keys[i];
    for (int i = idx + 2; i <= n; i++)
        children[i - 1] = children[i];
    child->n += sibling->n + 1;
    n--;
}

BTree::BTree(int t) {
    root = nullptr;
    this->t = t;
}

void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys[0] = key;
        root->n = 1;
        cout << "Node inserted: " << key << endl; 
    } else {
        if (root->n == (2 * t - 1)) {
            BTreeNode* s = new BTreeNode(t, false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < key) i++;
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

void BTree::remove(int key) {
    if (!root) {
        cout << "The tree is empty.\n";
        return;
    }
    root->remove(key);
    if (root->n == 0) {
        BTreeNode* tmp = root;
        if (root->leaf) root = nullptr;
        else root = root->children[0];
        delete tmp;
    }
}

int main() {
    int t = 5; 
    BTree bTree(t);

    int data[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int key : data) {
        bTree.insert(key);
    }

    cout << "In-order traversal of B-Tree: ";
    bTree.traverse();
    cout << endl;

    int search_key = 19;
    BTreeNode* found_node = bTree.search(search_key);
    cout << "Search for " << search_key << ": " << (found_node ? "Found" : "Not Found") << endl;

    int delete_key = 19;
    bTree.remove(delete_key);
    cout << "After deleting " << delete_key << ": ";
    bTree.traverse();
    cout << endl;

    AVLTree avlTree;
    for (int key : data) {
        avlTree.root = avlTree.insert(avlTree.root, key);
    }

    cout << "In-order traversal of AVL Tree: ";
    avlTree.traverse(avlTree.root);
    cout << endl;

    int avl_search_key = 19;
    cout << "Search for " << avl_search_key << ": " << (avlTree.search(avlTree.root, avl_search_key) ? "Found" : "Not Found") << endl;

    int avl_delete_key = 19;
    avlTree.root = avlTree.deleteNode(avlTree.root, avl_delete_key);
    cout << "After deleting " << avl_delete_key << ": ";
    avlTree.traverse(avlTree.root);
    cout << endl;

    return 0;
}