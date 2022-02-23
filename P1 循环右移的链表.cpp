#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}Node;
void printing(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node * creatinglist(Node *head)
{
    Node *temp =NULL;
    head = new Node;
    cin >> head->data;
    head->next = NULL;
    temp = head;
    int count =1;
    while(count != 0)
    {
        Node *newNode = new Node;
        cin >> newNode->data;
        newNode->next = NULL;
        if(newNode->data == -1)
        {
            count = 0;
            break;
        }
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
Node *posisition(Node *head, int number)
{
    // make a loop first
    Node*temp = head;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    for(int i =0; i < number;i++)
    {
        temp= temp->next;
    }
    Node *cur = temp->next;
    temp->next = NULL;
    head = cur;
    return head;
}
int main()
{
    int number;
    cin >> number;
    Node *head = NULL;
    head = creatinglist(head);
    head = posisition(head, number);
    printing(head);
    return 0;
}
