#include <bits/stdc++.h>
using namespace std;
//Build node;
struct node{
    int data;
    struct node *next;
};
//make node
node *makeNode(int data)
{
    node *newnode = new node(); // New node;
    newnode->data = data; // Set data
    newnode->next = NULL; // Create next node= NULL
    return newnode;
}
//duyet
void duyet(node *head) // Hàm này chỉ truyền tham trị chính là con trỏ, chứ không truyền tham chiếu
{
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
// count
int count(node *head)
{
    int dem =0;
    while (head != NULL){
        ++dem;
        head=head->next;
    }
    return dem;
}
// pushFront, gắn lên đầu
void pushFront(node **head, int x) // Đây mới là tham trị kiểu con trỏ
{
  node *newnode = makeNode(x);// node mới sẽ bằngg makenode(x), makenode sẽ thực hiện gán data, trả về cái node mới
  newnode->next = *head; // dia chi node tiếp theo là cái node cũ hơn! 
  *head=newnode;        //Cap nhat head
}
void pushFront2(node *&head, int x)
{
    node *newnode = makeNode(x);
    newnode -> next = head; // đã rải tham chiếu rồi
    head = newnode;
}
int main()
{
    node *head = NULL;
    for (int i=0; i<=5; i++)
    {
        pushFront(&head,i); // địa chỉ của con trỏ head
    }
    duyet(head);
    cout<< count(head);
    return 0;
}