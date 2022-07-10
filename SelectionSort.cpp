//this program demonstrate the concept of Selection sort
#include<iostream>
using namespace std;

void AscSelectionSort(int Arr[], int iSize)
{
    int min = 0;
    int Temp = 0;

    //in this approch smaller value comes at the start of array
    for(int i = 0; i < iSize-1; i++)
    {
        min = i;
        for(int j = i+1; j <= iSize; j++)
        {
            if(Arr[j] < Arr[min])
            {
                min = j;
            }
        }
        Temp = Arr[min];
        Arr[min] = Arr[i];
        Arr[i] = Temp;
    }
}
int AscSelectionSortM(int Arr[], int iSize)
{
    int max =0;
    int Temp = 0;

    //in this approch larger values are stored at the last
    for (int i = iSize-1; i >= 0; i--)
    {
        max = i;
        for(int j =0; j < i -1; j++)
        {
            if(Arr[j] > Arr[max])
            {
                max = j;
            }
        }
        Temp = Arr[max];
        Arr[max] = Arr[i];
        Arr[i] = Temp;
    }
}

int main()
{
    int Arr[] = {10,4,43,5,57,91,45,9,7};

    AscSelectionSort(Arr,9);

    for(int i = 0; i < 9; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
    AscSelectionSortM(Arr,8);

    for(int i = 0; i < 9; i++)
    {
        cout<<Arr[i]<<" ";
    }
    return 0;
}