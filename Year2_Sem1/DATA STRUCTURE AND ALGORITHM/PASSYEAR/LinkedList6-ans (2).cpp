#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int data;
        Node *next; // next is the Node class

        Node(int d) { 
            data = d; 
            next = NULL;
        }
        ~Node() { cout << "Destroy node " << data << "\n"; }
};


Node *findNode(int val, Node *h) {
    //cout << "h->data = " << h->data << "\n";
    Node *nd = h;

    while (nd != NULL) {
        if (nd->data == val) return nd;
        nd = nd->next;
    }

    return NULL;
}

void insertNode(int val, Node *h) {
    cout << "Try to insert node " << val << "\n";
    Node *nd = h, *prev;
    while (nd != NULL) {
        if (nd->data > val) {
            Node *nn = new Node(val);
            prev->next = nn;
            nn->next = nd;
            break;
        }
        prev = nd;
        nd = nd->next;
    }
}

void insertNodeFirst(int val, Node *&h) {
    cout << "Try to insert " << val << " as first node\n";
    Node *nn = new Node(val);
    nn->next = h;
    h = nn;

    cout << "nn->next->data = " << nn->next->data << "\n";
    cout << "h->data = " << h->data << "\n";
}

void insertNodeLast(int val, Node *&L) {
    cout << "Try to insert " << val << " as last node\n";
    Node *nn = new Node(val);
    L->next = nn;
    L = nn;
}

void deleteNode(int val, Node *h) {
    cout << "Try to delete node " << val << "\n";

    Node *nd = h, *prev = NULL;
    bool deleted = false;

    while (nd != NULL) {
        if (nd->data == val) {
            prev->next = nd->next;
            delete nd;
            deleted = true;
            break;
        }

        prev = nd;
        nd = nd->next;
    }

    if (!deleted) cout << "Can't found node " << 30 << " to delete\n";
}

void displayList(Node *h) {
    cout << "Print all nodes:\n";
    Node *nd = h;
    while (nd != NULL) {
        cout << nd->data << " ";
        nd = nd->next;
    }
    cout << "\n";
}

void deleteList(Node *h) {
    cout << "Delete all nodes:\n";
    Node *nd = h, *prev = NULL;
    while (nd != NULL) {
        prev = nd;
        nd = nd->next;
        delete prev;
    }
}


// Main function section
int main() {
    int num;
    Node *head = NULL, *prevNode = NULL, *last = NULL;

    /*
    construct linked list: 
    head -> 10 -> 20 -> 30 -> 40 -> 50 -> NULL
                                     ^
                                     |
                                    last
    */
    for (int i = 1; i < 6; i++) {
        Node *nn = new Node(i * 10);
        if (head == NULL) {
            head = nn;
        } else {
            last->next = nn;
        }

        last = nn;
    }
    displayList(head);

    Node *nodeFound = findNode(30, head);
    if (nodeFound != NULL) 
       cout << "Found node " << nodeFound->data << " in the list\n";
    else 
       cout << "Not found node 30 in the list\n";

    deleteNode(30, head);
    displayList(head);
    deleteNode(30, head);
    //deleteNode(10); // ???
    //deleteNode(50); // ???
    cout << "\n";

    // insert node 25 between 20 and 40
    insertNode(25, head);
    displayList(head);
    //insertNode(0, head); // ???
    //insertNode(55, head); // ???
    cout << "\n";

    // insert node 5
    insertNodeFirst(5, head);
    displayList(head);
    cout << "\n";

    // insert node 60
    insertNodeLast(60, last);
    displayList(head);
    cout << "\n";

    deleteList(head);
}