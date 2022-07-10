#include<iostream>
using namespace std;
///////////////////////////////////////
//             STRUCTURE             //
///////////////////////////////////////
struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};
///////////////////////////////////////
typedef struct Node NODE;
typedef struct Node * PNODE;
///////////////////////////////////////
//               CLASS               //
///////////////////////////////////////
class DoublyCiculerLL
{
    private :
        PNODE Head;
        PNODE Tail;
    public :
        DoublyCiculerLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);
        inline void Display();
        inline int Count();
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
};
///////////////////////////////////////
DoublyCiculerLL::DoublyCiculerLL()
{
    Head = NULL;
    Tail = NULL;
}
///////////////////////////////////////
void DoublyCiculerLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(Head == NULL && Tail == NULL)
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
}
///////////////////////////////////////
void DoublyCiculerLL::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return;
    }
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(Head == NULL && Tail == NULL)
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
}
///////////////////////////////////////
void DoublyCiculerLL::Display()
{
    PNODE Temp = Head;
    do
    {
        cout<<Temp->data<<"->";
        Temp = Temp->next;
    }while(Temp!=Head);
    cout<<"\n";
}
///////////////////////////////////////
int DoublyCiculerLL::Count()
{
    int iCnt =0;
    PNODE Temp = Head;
    do
    {
        iCnt++;
        Temp = Temp->next;
    }while(Temp!=Head);
    return iCnt;
}
///////////////////////////////////////
void DoublyCiculerLL::DeleteFirst()
{
    PNODE Temp = NULL;

    if(Head==NULL&&Tail==NULL)
    {
        return;
    }
    if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Temp = Head;
        Head = Head->next;
        delete Temp;
    }
    Tail->next = Head;
    Head->prev = Tail;
}
///////////////////////////////////////
void DoublyCiculerLL::DeleteLast()
{
    PNODE Temp = NULL;

    if(Head==NULL&&Tail==NULL)
    {
        return;
    }
    if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Temp = Tail;
        Tail = Tail->prev;
        delete Temp;
    }
    Tail->next = Head;
    Head->prev = Tail;
}
///////////////////////////////////////
void DoublyCiculerLL::InsertAtPos(int no, int pos)
{
    PNODE newn = NULL;
    newn = new NODE;
    int iSize = Count();
    if(newn == NULL)
    {
        return;
    }
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(pos < 1 || pos > (iSize+1))
    {
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == (iSize+1) )
    {
        InsertLast(no);
    }
    else
    {
        int iCnt = 0;
        PNODE Temp = Head;
        for(iCnt = 1; iCnt<(pos-1); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next=Temp->next;
        Temp->next->prev = newn;
        newn->prev = Temp;
        Temp->next = newn;
    }
}
///////////////////////////////////////
void DoublyCiculerLL::DeleteAtPos(int pos)
{
    int iSize = Count();
    if(pos<1||pos>iSize)
    {
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = NULL;
        Temp = Head;
        int iCnt = 0;
        for( iCnt = 1 ; iCnt<(pos - 1); iCnt++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete (Temp->next->prev);
        Temp->next->prev = Temp;
    }
}
///////////////////////////////////////
//               MAIN                //
///////////////////////////////////////
int main()
{
    DoublyCiculerLL obj;
    int iRet = 0;

    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertFirst(1);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number Nodes in linked list are : "<<iRet<<endl;
/////////////////////////////////////////////
    obj.InsertLast(1);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number Nodes in linked list are : "<<iRet<<endl;
/////////////////////////////////////////////
    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number Nodes in linked list are : "<<iRet<<endl;
/////////////////////////////////////////////
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number Nodes in linked list are : "<<iRet<<endl;
/////////////////////////////////////////////
    obj.InsertAtPos(1,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number Nodes in linked list are : "<<iRet<<endl;
/////////////////////////////////////////////
    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number Nodes in linked list are : "<<iRet<<endl;
    return 0;
}