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

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head) {
    while (head != NULL){
        cout<< head->data << ' ';
        head = head->next;
    }
}


SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);
    // Nếu danh sách rỗng hoặc nút đầu tiên có giá trị lớn hơn x
    // thì chèn nút mới tại đầu danh sách
    if (head == nullptr || head->data > x) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Tìm vị trí để chèn nút mới
    SinglyLinkedListNode* curr = head;
    while (curr->next != nullptr && curr->next->data <= x) {
        curr = curr->next;
    }

    // Chèn nút mới vào danh sách
    newNode->next = curr->next;
    curr->next = newNode;

    return head;

}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    cin >> x;
    llist->head = insertSortedLinkedList(llist->head, x);
    printLinkedList(llist->head);

    return 0;
}