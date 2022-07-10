//implementation of binary search
#include<iostream>
using namespace std;

bool BinarySearch(int Arr[], int iSize, int iNo)
{
    int Start = 0;
    int end = iSize - 1;
    int mid = 0;
    while(Start <= end)
    {
        mid = Start - ((Start - end) / 2);  //// it acts like incrementation or decrementation
        if(iNo == Arr[mid])
        {
            return true;
        }
        else if(iNo < Arr[mid])
        {
            end = mid - 1;
        }
        else if(iNo > Arr[mid])
        {
            Start = mid + 1;
        }
    }

    return false;
}

bool BinarySearchR(int Arr[], int Start, int end, int iNo)
{
    int mid =  Start - ((Start - end) / 2);
    if(Start > end)
    {
        return false;
    }
    else if (Arr[mid] == iNo)
    {
        return true;
    }
    else if(Arr[mid] < iNo)
    {
        BinarySearchR(Arr,mid+1,end,iNo);
    }
    else
    {
        BinarySearchR(Arr,Start,mid-1,iNo);
    }
}

int main()
{
    int Arr[] ={2,4,5,8,14,43,56,73,81,99};
    int Targate = 91;
    bool bRet = false;

    bRet = BinarySearchR(Arr,0,9,Targate);

    if(bRet == true)
    {
        cout<<"Element found in Array.";
    }
    else
    {
        cout<<"Element Not in Array.";
    }

    return 0;
}
