#include <iostream>
using namespace std;

typedef struct Node
{
    char content;
    Node *next;
}Node;

void printing(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->content<<" ";
        temp = temp->next;
    }
    cout << endl;
}

Node *creating(Node *head, int n)
{
    Node *temp = NULL;
    head = new Node;
    cin >> head->content;
    head->next = NULL;
    temp = head;
    for(int i = 1 ; i < n;i++)
    {
        Node *newNode = new Node;
        cin >> newNode->content;
        newNode->next = NULL;
        temp->next = newNode;
        temp =temp->next;
    }
    return head;
}
void sorting_char(char array[], int count)
{
    for(int i =count -1; i >= 0;i--)
    {
        int max = 0;
        for(int j =1; j <= i;j++)
        {
            if(array[max] < array[j])
                max = j;
        }
        if(max != i)
        {
            char temp = array[max];
            array[max] = array[i];
            array[i] =temp;
        }
    }
}
void change_to_opposite(char array[], int count)
{
    for(int i =0; i < count;i++)
    {
        if(array[i] >='a' && array[i] <= 'z')
            array[i] = 'z'- (array[i] %'a');
        else if (array[i] >= 'A' && array[i] <= 'Z')
            array[i] = 'Z'- (array[i] %'A');
    }
    sorting_char(array, count);
    for(int i =0; i <count ;i++)
    {
        cout << array[i]<<" ";
    }
    cout << endl;
}
void josephus(Node *head , int m, int n)
{
    char array[100]={};
    Node*temp = head;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    int count = 0;
    while(count !=n)
    {
        cout << temp->next->next->content<<" ";
        array[count] = temp->next->next->content;
        temp->next->next = temp->next->next->next;
        temp = temp->next->next;
        count++;
    }
    cout << endl;
    change_to_opposite(array, count);
}

int main()
{
    int n , m;
    Node *head = NULL;
    cin >> n >> m;
    head = creating(head, n);
    josephus(head, m,n);
    return 0;
}
