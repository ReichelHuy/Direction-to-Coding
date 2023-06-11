
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

};

void insert_node(SinglyLinkedList* llist, int llist_item) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(llist_item);

    if (!llist->head) {
        llist->head = node;
    } else {
        llist->tail->next = node;
    }

    llist->tail = node;
}


SinglyLinkedListNode* reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist->head;
    SinglyLinkedListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    llist->head = prev;
    return llist->head;
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* current = llist->head;
    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
}


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }


    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}