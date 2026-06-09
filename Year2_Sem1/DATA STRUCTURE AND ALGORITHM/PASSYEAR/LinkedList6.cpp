#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int data;
        Node *next; // next is the Node class

        Node(int d) { data = d; }

        ~Node() { cout << "Destroy node " << data << "\n"; }
};


Node *findNode(int val, Node *h) {
    return NULL;
}

void insertNode(int val, Node *h) {
    cout << "Try to insert node " << val << "\n";
}

void insertNodeFirst(int val, Node *h) {
    cout << "Try to insert " << val << " as first node\n";
}

void insertNodeLast(int val, Node *h) {
    cout << "Try to insert " << val << " as last node\n";
}

void deleteNode(int val, Node *h) {
    cout << "Try to delete node " << val << "\n";

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
        //Node *nn = new Node(i * 10);
    }
    displayList(head);

    if (findNode(30, head)) 
       cout << "Found node 30 in the list\n";
    else 
       cout << "Not found node 30 in the list\n";

    deleteNode(30, head);
    displayList(head);
    deleteNode(30, head);
    cout << "\n";

    // insert node 25 between 20 and 40
    insertNode(25, head);
    displayList(head);
    cout << "\n";

    // insert node 5
    insertNodeFirst(5, head);
    displayList(head);
    cout << "\n";

    // insert nod 60
    insertNodeLast(60, head);
    displayList(head);
    cout << "\n";

    deleteList(head);
}