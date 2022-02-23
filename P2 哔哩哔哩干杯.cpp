#include<iostream>
#include <stdlib.h>
#include<stdlib.h>
using namespace std;
 
typedef struct VideoNode
 {
    int id;
    char label[20];
    int visit;
    int liked;
    int coins;
    int collection;
    int score;
    VideoNode* next;
}VideoNode;
char* strcopy(char* destination, const char* source);
int compare(char * str1, char * str2);
int search(VideoNode *head,int key);
void sorting(char *node1, char  *node2)
{
    char * temp = new char ;
    strcopy(temp, node1);
    strcopy(node1, node2);
    strcopy(node2, temp);
    free(temp);
}
VideoNode *bubblesorting (VideoNode *head)
{
    VideoNode *temp=NULL, *nextNode=NULL;
    temp =head;
    while(temp && temp->next)
    {
        nextNode = temp->next;
        while(nextNode)
        {
            if(temp->score <= nextNode->score)
            {
                int _temp =temp->score;
                temp->score = nextNode->score;
                nextNode->score = _temp;
                
                int _id =temp->id;
                temp->id =nextNode->id;
                nextNode->id =_id;
                
                int _visit =temp->visit;
                temp->visit =nextNode->visit;
                nextNode->visit =_visit;
                
                int _liked =temp->liked;
                temp->liked =nextNode->liked;
                nextNode->liked =_liked;
                
                int _coins = temp->coins;
                temp->coins =nextNode->coins;
                nextNode->coins = _coins;
                
                int _collection = temp->collection;
                temp->collection =temp->coins;
                temp->coins = _collection;
                sorting(temp->label,nextNode->label);
            }
            nextNode = nextNode->next;
        }
        temp = temp->next;
    }
    return head;
}
int value_score(VideoNode *temp)
{
    int score=0;
    score = 1 * temp->visit + 2 * temp->liked + 3 * temp->coins + 4 * temp->collection;
    return score;
}
void printing(VideoNode *head, char key[])
{
    VideoNode *temp =NULL;
    temp =head;
    while(temp != NULL)
    {
        if(compare(temp->label, key)==0)
        {
            cout << temp->id <<" "<<temp->score<<endl;
            temp = temp->next;
        }
        else if(compare(temp->label, key)!=0)
        {
            cout <<endl;
            temp = temp->next;
        }
    }
}
 
int main()
{
    int q , t,count=0,name,a,b,c;
    cin >> q;
    char label[20],key[20];
    VideoNode * head = NULL,*tmp = NULL,*newNode=NULL;
    for( int i =0; i < q; i++)
    {
        cin >> t;
        if(t == 0)
        {
            if(head == NULL)//input data for the first time
            {
                head = new VideoNode;
                cin >> head->id >> head-> liked >> head-> collection >> head->coins >> head-> label;
                head-> visit = 1;
                head->score =value_score(head);
            }
            else  //input not the first time
            {
                tmp = head;
                cin >> name >> a >>b>> c;
                for(int j = 0; j < count;j++)
                {
                    tmp = tmp->next;
                }
                if(search(tmp,name)==-1)
                {
                    newNode = new VideoNode;
                    cin >> newNode->label;
                    tmp->next = NULL;
                    newNode->visit =1;
                    newNode->id = name;
                    newNode->liked = a;
                    newNode->collection=b;
                    newNode->coins = c;
                    newNode->next =NULL;
                    newNode->score =value_score(newNode);
                    tmp->next = newNode;
                    tmp = newNode;
                    count += 1;
                    
                }
                else if (search(tmp,name)!= -1)
                {
                    cin >> key;
                    if(compare(tmp->label, key)==0)
                    {
                        tmp->liked = tmp->liked +a;
                        tmp->collection = tmp->collection+b;
                        tmp->coins = tmp->coins + c;
                        tmp->visit +=1;
                        tmp->score= value_score(tmp);
                    }
                }
            }
        }
        else if (t == 1)
        {
            cin >> label;
            printing(bubblesorting(head), label);
        }
    }
    return 0;
}
 
int compare(char * str1, char * str2)
{
    while((*str1 && *str2) && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
 
    return *str1 - *str2;
}
 
int search(VideoNode *head,int key)
{
    VideoNode *temp =  NULL;
    temp = head;
    if(temp->id == key)
        return 1;
    else
        return -1;
    
}
char* strcopy(char* destination, const char* source)
{
    if (destination == NULL)
        return NULL;
    char *ptr = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    *destination = '\0';
    return ptr;
}
