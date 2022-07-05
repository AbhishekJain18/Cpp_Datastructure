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
class SinglyLirLL
{
    private:
        PNODE Head;
        int Count;
    public:
        SinglyLirLL();
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
SinglyLirLL::SinglyLirLL()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
void SinglyLirLL::Display()
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
int SinglyLirLL::CountNode()
{
    return Count;
}
///////////////////////////////////
void SinglyLirLL::InsertFirst(int No)
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
        newn->next = Head;
        Head = newn;
    }
    Count++;
}
///////////////////////////////////
void SinglyLirLL::InsertLast(int No)
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
void SinglyLirLL::InsertAtPos(int No,int Pos)
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
        Count++;
    }

}
///////////////////////////////////
void SinglyLirLL::DeleteFirst()
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
void SinglyLirLL::DeleteLast()
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
void SinglyLirLL::DeleteAtPos(int Pos)
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
        Count--;
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    SinglyLirLL obj;
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