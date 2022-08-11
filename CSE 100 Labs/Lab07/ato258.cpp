#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}

	Node(int n) {
		data = n;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void append (int n) {
		if (head == NULL) {
			head = new Node(n);
			tail = head;
		}
		else {
			Node* newNode = new Node(n); 
			tail->next = newNode;
			tail = tail->next;
		}
	}

	void prepend(int n) {
		Node* current = new Node(n);
		current->next = head;
		head = current;
	}

	bool search(int n) {
		Node* current = head;
		while (current != NULL) {
			if (current->data == n) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

    int get_index(int n) {
        Node* current = head;
        int index = 0;
        
        while (current != NULL) {
            if (current->data == n) {
                return index;
            }
            index++;
            current = current->next;
        }
    }

    void remove(int n) {
        Node* prev = NULL;
        Node* current = head;

        if (current != NULL && current->data == n) {
            head = current->next;
            delete current;
            return;
        }

        else {
            while (current != NULL && current->data != n) {
                prev = current;
                current = current->next;
            }

            if (current == NULL) return;

            prev->next = current->next;

            delete current;
        }
    }

    void print() {
        Node *current = head;

        while (current != NULL) {
            cout << current->data << "->";
            current = current->next;
        }
    }
};

struct HashTable {
    int rows;
    LinkedList* table;

    HashTable(int n) {
        rows = n;
        table = new LinkedList[rows];
    }

    int hash(int key) {
        return key % rows;
    }

    void insert(int key) {
        int index = hash(key);
        table[index].prepend(key);
    }

    void search(int key) {
        int index = hash(key);
        if (table[index].search(key)) {
            cout << key << ":FOUND_AT" << index << "," << table[index].get_index(key) << ";\n";
        }
        else {
            cout << key << ":NOT_FOUND;\n";
        }
    }    

    void remove(int key) {
        int index = hash(key);
        if (table[index].search(key)) {
            table[index].remove(key);
            cout << key << ":DELETED;\n";
        }
        else {
            cout << key << ":DELETE_FAILED;\n";
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            cout << i << ":"; 
            table[i].print();
            cout << ";\n";
        }
    }
};

int main(int argc, char const *argv[]) {

    int hashSize = 0;
    int number =  0;
    bool repeat = true;

    string input = "";
    cin >> hashSize;

    HashTable table(hashSize);

    do {
        number = 0;
        cin >> input;
        //Create integer if required by function
        if (input[0] != 'o' || input[0] != 'e'){
            for (int i = 1; i < input.size(); i++) {
                int digit = input[i] - '0';
                number = 10 * number + digit;
            }
        }

        if(input[0] == 'i') {
            table.insert(number);
        }
        else if(input[0] == 'd') {
            table.remove(number);
        }
        else if(input[0] == 's') {
            table.search(number);
        }
        else if(input[0] == 'o') {
            table.print();
        }
        else if(input[0] == 'e') {
            repeat = false;
        }
        else {
            cout << "Wrong input" << endl;
        }
    } while(repeat);

  return 0;
}