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
class Stack
{
    private:
        PNODE Head;
        int Count;
    public:
        Stack();
        void Display();
        int CountNode();
        void Push(int);
        void Pop();
};
///////////////////////////////////
Stack::Stack()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
void Stack::Display()
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
int Stack::CountNode()
{
    return Count;
}
///////////////////////////////////
void Stack::Push(int No)
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
void Stack::Pop()
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
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next = NULL;
    }
    Count--;
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    Stack obj;
    int iRet = 0;

    obj.Push(11);
    obj.Push(21);
    obj.Push(51);
    obj.Push(101);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.Pop();
    obj.Pop();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;
    
	return 0;
 }