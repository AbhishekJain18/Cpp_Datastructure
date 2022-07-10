#include<iostream>
using namespace std;

void InsertionSort(int Arr[], int iSize)
{
    int i = 0, j = 0,Temp = 0;
    for(i = 1; i <= iSize - 1; i++)
    {
        Temp =  Arr[i];
        j = i;
        while(Arr[j-1] > Temp && j >= 1)
        {
            Arr[j] =Arr[j-1];
            j--;
        }
        Arr[j] = Temp;
    }
}

int main()
{
    int Arr[] = {4,5,10,43,57,91,45,9,7};

    InsertionSort(Arr,9);

    for(int i = 0; i < 9; i++)
    {
        cout<<Arr[i]<<" ";
    }

    return 0;
}