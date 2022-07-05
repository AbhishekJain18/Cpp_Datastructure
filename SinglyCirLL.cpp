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
class SinglyCirLL
{
    private:
        PNODE Head;
        PNODE Tail;
        int Count;
    public:
        SinglyCirLL();
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
SinglyCirLL::SinglyCirLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
///////////////////////////////////
void SinglyCirLL::Display()
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
int SinglyCirLL::CountNode()
{
    return Count;
}
///////////////////////////////////
void SinglyCirLL::InsertFirst(int No)
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
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    Count++;
}
///////////////////////////////////
void SinglyCirLL::InsertLast(int No)
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
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
    Count++;
}
///////////////////////////////////
void SinglyCirLL::InsertAtPos(int No,int Pos)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
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
        Temp->next = newn;
        Tail->next = Head;
        Count++;
    }
}
///////////////////////////////////
void SinglyCirLL::DeleteFirst()
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
        delete Tail->next;
        Tail->next = Head;
    }
    Tail->next = Head;
    Count--;
}
///////////////////////////////////
void SinglyCirLL::DeleteLast()
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
        PNODE Temp = Head;
        while(Temp->next->next != Head)
        {
            Temp = Temp->next;
        }
        delete Tail;
        Tail = Temp;
    }
    Tail->next = Head;
    Count--;
}
///////////////////////////////////
void SinglyCirLL::DeleteAtPos(int Pos)
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
        PNODE DelTemp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        DelTemp = Temp->next;
        Temp->next = DelTemp->next;
        delete DelTemp;
        Tail->next = Head;
        Count--;
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    SinglyCirLL obj;
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