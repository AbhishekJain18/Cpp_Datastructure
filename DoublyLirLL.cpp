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
class DoublyLirLL
{
    private:
        PNODE Head;
        int Count;
    public:
        DoublyLirLL();
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
DoublyLirLL::DoublyLirLL()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
void DoublyLirLL::Display()
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
int DoublyLirLL::CountNode()
{
    return Count;
}
///////////////////////////////////
void DoublyLirLL::InsertFirst(int No)
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
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Count++;
}
///////////////////////////////////
void DoublyLirLL::InsertLast(int No)
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
    }
    else
    {
        PNODE Temp = Head;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        newn->prev = Temp;
        Temp->next = newn;
    }
    Count++;
}
///////////////////////////////////
void DoublyLirLL::InsertAtPos(int No,int Pos)
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

}
///////////////////////////////////
void DoublyLirLL::DeleteFirst()
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
        Head = Head->next;
        delete (Head ->prev);
        Head->prev = NULL;
    }
    Count--;
}
///////////////////////////////////
void DoublyLirLL::DeleteLast()
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
void DoublyLirLL::DeleteAtPos(int Pos)
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
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////    
int main()
{
    DoublyLirLL obj;
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