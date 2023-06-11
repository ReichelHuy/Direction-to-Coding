#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void insertAfter(Node* prev, int data) {
    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteNode(Node* prev, Node* nodeToDelete) {
    prev->next = nodeToDelete->next;
    delete nodeToDelete;
}

void moveToFront(Node* head, int x, int y) {
    if (x == y) {
        return;
    }
    Node* prevX = NULL;
    Node* prevY = NULL;
    Node* cur = head;
    while (cur->next != head) {
        if (cur->data == x) {
            break;
        }
        prevX = cur;
        cur = cur->next;
    }
    cur = head;
    while (cur->next != head) {
        if (cur->data == y) {
            break;
        }
        prevY = cur;
        cur = cur->next;
    }
    if (prevX == NULL) {
        prevX = head;
        while (prevX->next != head) {
            prevX = prevX->next;
        }
        head = head->next;
        prevX->next = head;
    } else {
        deleteNode(prevX, prevX->next);
    }
    insertAfter(prevY, x);
}

void printList(Node* head) {
    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
}

int main() {
    int n, q;
    cin >> n >> q;
    Node* head = new Node(1);
    Node* cur = head;
    for (int i = 2; i <= n; i++) {
        cur->next = new Node(i);
        cur = cur->next;
    }
    cur->next = head;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        moveToFront(head, x, y);
    }
    printList(head);
    return 0;
}