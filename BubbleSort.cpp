#include<iostream>
using namespace std;

int  BubbleSort(int Arr[], int iSize)
{
    for(int Step=iSize-1 ; Step >=0; Step--)
    {
        for(int i = 0; i < Step; ++i)
        {
            if(Arr[i] > Arr[i+1])
            {
                int Temp = Arr[i];
                Arr[i] = Arr[i+1];
                Arr[i+1] = Temp;
            }
        }
    }

}

int main()
{
    int Arr[] = {10,4,43,5,57,91,45,9,7};

    BubbleSort(Arr,9);

    for(int i = 0; i < 9; i++)
    {
        cout<<Arr[i]<<" ";
    }

    return 0;
}