#include<iostream>
using namespace std;
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
};
///////////////////////////////////
typedef struct Node NODE;
typedef struct Node * PNODE;
///////////////////////////////////
//             CLASS             //
///////////////////////////////////
class DoublyCirLL
{
    private:
        PNODE Head;
        PNODE Tail;
        int Count;
    public:
        DoublyCirLL();
        void Display();
        int CountNode();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};
///////////////////////////////////
DoublyCirLL::DoublyCirLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
///////////////////////////////////
void DoublyCirLL::Display()
{
    PNODE Temp = Head;
    do
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }while(Temp != Head);
    cout<<"REP\n";
}
///////////////////////////////////
int DoublyCirLL::CountNode()
{
    return Count;
}
///////////////////////////////////
void DoublyCirLL::InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count++;
}
///////////////////////////////////
void DoublyCirLL::InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->prev = Tail;
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count++;
}
///////////////////////////////////
void DoublyCirLL::InsertAtPos(int No,int Pos)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    if(Pos < 1 || Pos >(Count + 1))
    {
        return;
    }
    else if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == (Count + 1))
    {
        InsertLast(No);
    }
    else
    {
        PNODE Temp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        newn->prev = Temp;
        Temp->next = newn;
        Count++;
    }
    Tail->next = Head;
    Head->prev = Tail;
}
///////////////////////////////////
void DoublyCirLL::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete (Head ->prev);
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count--;
}
///////////////////////////////////
void DoublyCirLL::DeleteLast()
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
        Tail = Tail->prev;
        delete (Tail->next);
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count--;
}
///////////////////////////////////
void DoublyCirLL::DeleteAtPos(int Pos)
{
    if(Count == 0)
    {
        return;
    }
    if(Pos < 1 || Pos > Count)
    {
        return;
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete (Temp->next->prev);
        Temp->next->prev = NULL;
        Count--;
    }
    Tail->next = Head;
    Head->prev = Tail;
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    DoublyCirLL obj;
    int iRet = 0;

    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(51);
    obj.InsertLast(101);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.InsertAtPos(1,3);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

	return 0;
 }