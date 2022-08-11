#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char letter;
    unsigned frequency;
    Node *left;
    Node *right;
 
    Node(char letter, unsigned frequency) {
        this->letter = letter;
        this->frequency = frequency;
        left = NULL;
        right = NULL;
    }
};

struct compare {
    bool operator() (Node* left, Node* right) {
        return (left->frequency > right->frequency);
    }
};

string outputs[6];

void encode(Node* root, string s, char letters[]) {
    if (root == NULL) {
        return;
    }
 
    if (root->letter != ' ') {
        for (int i = 0; i < 6; ++i) {
            if (root->letter == letters[i]) {
                outputs[i] = s;
            }
        }
    }
    
    if (root->letter == ' ') {
        encode(root->left, s + "0", letters);
        encode(root->right, s + "1", letters);
    }
}

void huffman(char letters[], int frequencies[]) {
    Node *x;
    Node *y;
    Node *z;

    priority_queue<Node*, deque<Node*>, compare> pq;
 
    for (int i = 0; i < 6; ++i) {
        pq.push(new Node(letters[i], frequencies[i]));
    }
 
    while (pq.size() > 1) {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
 
        z = new Node(' ', x->frequency + y->frequency);
        z->left = x;
        z->right = y;
 
        pq.push(z);
    }

    encode(pq.top(), "", letters);

    for (int i = 0; i < 6; ++i) {
        cout << letters[i] << ":" << outputs[i] << endl;
    }
}

int main(int argc, char const *argv[]) {
    char *letters = new char[6];
    int *frequencies = new int[6];

    for (int i = 0; i < 6; ++i) {
        letters[i] = 'A' + i;
        cin >> frequencies[i];
    }    

    huffman(letters, frequencies);
} 