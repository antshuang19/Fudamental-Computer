#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data ;
    node *next;
}node ;
node * creating(node *head)
{
    node *temp =NULL;
    head = new node;
    cin >> head->data;
    head->next = NULL;
    temp = head;
    int count =1;
    while(count != 0)
    {
        node *newNode = new node;
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
void intersection (node *head, node *temp)
{
    for(node * i = head; i != NULL; i = i->next)
    {
        for(node *j = temp ; j != NULL; j = j->next)
        {
            if(i ->data == j->data)
            {
                cout << i->data<<" ";
            }
        }
    }
    cout <<"-1"<<endl;
}
void UNION ( node *head , node *temp)
{
    node *tmp = head;
    while(tmp->next!= NULL)
    {
        tmp = tmp->next;
    }
    for(node *i = temp ; i != NULL; i = i->next)
    {
        tmp = tmp->next;
        tmp = i;
    }
    for(node *i = head; i != NULL; i = i->next)
    {
        cout << i->data<<" ";
    }
}
void different (node *head , node *temp)
{
    int count=0;
    for(node * i = head; i != NULL; i = i->next)
    {
        count =1;
        for(node *j = temp ; j != NULL; j = j->next)
        {
            if(i ->data == j->data)
            {
                count =0;
            }
        }
        if(count == 1)
        {
            cout << i->data<<" ";
        }
    }
    cout <<"-1"<<endl;
}
int main()
{
    node *a =NULL, *b = NULL;
    a = creating(a);
    b = creating(b);
    intersection(a, b);
    // union + different(b,a)
    UNION(a, b);
    different(b, a);
    different(a, b);
    return 0;
}
