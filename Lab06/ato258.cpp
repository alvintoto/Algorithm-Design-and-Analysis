#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int key;   // Value of the node
    Node *left;   // Pointer to the left node
    Node *right;  // Pointer to the right node
    Node *p; // Pointer to the parent node

    Node(int n) {
        key = n;
        left = NULL;
        right = NULL;
        p = NULL;
    }
};

struct BST {
    Node *root;

    BST() {
        root = NULL;
    }

    void insert(int val) {
        Node *new_node = new Node(val);
        Node *copy = root;
        Node *temp = NULL;

        while (copy != NULL) {
            temp = copy;
            if (new_node->key < copy->key) {
                copy = copy->left;
            }
            else {
                copy = copy->right;
            }
        }

        new_node->p = temp;

        if (temp == NULL) {
            root = new_node;
        }
        else if (new_node->key < temp->key) {
            temp->left = new_node;
        }
        else {
            temp->right = new_node;
        }
    }

    void preorder(Node *root) {
        if (root != NULL) {
            cout << root->key << endl;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << endl;
        }
    }

    void inorder(Node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << endl;
            inorder(root->right);
        }
    }

    Node *minimum(Node *root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node *search (Node *root, int val) {
        if (root == NULL || val == root->key) {
            return root;
        }
        if (val < root->key) {
            return search(root->left, val);
        }
        else {
            return search(root->right, val);
        }
    }

    void transplant(Node *a, Node *b) {
        if (a->p == NULL) {
            root = b;
        }
        else if (a == a->p->left) {
            a->p->left = b;
        }
        else {
            a->p->right = b;
        }

        if (b != NULL) {
            b->p = a->p;
        }
    }

    void remove(int val) {
        Node *temp = NULL;
        Node *to_delete = search(root, val);

        if (to_delete->left == NULL) {
            transplant(to_delete, to_delete->right);
        }
        else if (to_delete->right == NULL) {
            transplant(to_delete, to_delete->left);
        }
        else {
            temp = minimum(to_delete->right);
            if (temp->p != to_delete) {
                transplant(temp, temp->right);
                temp->right = to_delete->right;
                temp->right->p = temp;
            }
            transplant(to_delete, temp);
            temp->left = to_delete->left;
            temp->left->p = temp;
        }
    }
};

int main(int argc,char **argv) {
    BST tree;

    // Using a fixed size buffer for reading content is not always safe, 
    // but ok here because we know how our input has to be:
    char line[100];

    // Main loop
    while ( std::cin.getline(line,100) ) {
        string str(line);
        if ( str.size()==0 ) continue; 
        if ( str[0]=='e' ) return 1;

    // Use cerr if you want to always print to the console, because cout
    // will be redirected to the output file when calling the Grade script:
    // cerr<<line<<endl;

    if ( str[0]=='o' ) {
        if ( str.substr(0,3)=="oin" ) {   
            tree.inorder(tree.root);
        }
        else if ( str.substr(0,4)=="opre" ) {
            tree.preorder(tree.root);
        }
        else if (str.substr(0,5) == "opost") {
            tree.postorder(tree.root);
        }
    }
    else { 
        int key;
        stringstream convert_stm(str.substr(1,str.size()-1));
        if ( !(convert_stm>>key) ) key = -1; // invalid

        if (str.substr(0,1) == "i") tree.insert(key);
        else if (str.substr(0,1) == "d") tree.remove(key);
        }
    }
    
  return 1;
}