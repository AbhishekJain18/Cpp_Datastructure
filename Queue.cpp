#include<iostream>
using namespace std;
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
struct Node
{
   int data;
   struct Node *next;
};
///////////////////////////////////
typedef struct Node NODE;
typedef struct Node * PNODE;
///////////////////////////////////
//             CLASS             //
///////////////////////////////////
class Queue
{
    private:
        PNODE Head;
        int Count;
    public:
        Queue();
        void Display();
        int CountNode();
        void Enqueue(int);
        void Dequeue();
};
///////////////////////////////////
Queue::Queue()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
void Queue::Display()
{
    PNODE Temp = Head;
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }
    cout<<"NULL\n";
}
///////////////////////////////////
int Queue::CountNode()
{
    return Count;
}
///////////////////////////////////
void Queue::Enqueue(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        PNODE Temp = Head;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
    Count++;
}
///////////////////////////////////
void Queue::Dequeue()
{
    if(Count == 0)
    {
        return;
    }
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE Temp = Head;
        Head = Temp->next;
        delete Temp;
    }
    Count--;
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    Queue obj;
    int iRet = 0;

    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.Dequeue();
    obj.Dequeue();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;
    
	return 0;
 }