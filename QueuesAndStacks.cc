#include <iostream>

using namespace std;

struct Node
{
    char data;
    struct Node *next;
}*queueHead = NULL,*stackHead = NULL ;

class Solution {

    public:
    void enqueueCharacter(char s)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = s;
        newNode->next = NULL;
        
        if (queueHead==NULL)
        {
            queueHead = newNode;
        }
        else
        {
            struct Node *tmp;
            tmp = queueHead;

            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }
    
    void pushCharacter(char s)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = s;
        newNode->next = NULL;
        
        struct Node *tmp;
        tmp = stackHead;
        if (stackHead==NULL)
        {
            stackHead = newNode;
        }
        else
        {
            newNode->next = stackHead;
            stackHead = newNode;
        }
    }

    char popCharacter()
    {
        struct Node *tmp = stackHead;
        char ctmp = tmp->data;
        if (tmp->next == NULL)
        {
            stackHead = NULL;
            free(tmp);
        }
        else
        {
            stackHead = tmp->next;
            free(tmp);
        }
        return ctmp;
    }
   
    char dequeueCharacter()
    {
        struct Node *tmp = queueHead;
        char ctmp = tmp->data;
        if (tmp->next == NULL)
        {
            queueHead = NULL;
            free(tmp);
        }
        else
        {
            queueHead = tmp->next;
            free(tmp);
        }
        return ctmp;
    }
};

