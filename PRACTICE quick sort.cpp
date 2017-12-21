#include<iostream>
using namespace std;
#define MAX 20

int lower[MAX];
int upper[MAX];
int top=-1;
int quick(int arr[], int beg, int last);

int main()
{
    int n, i, beg, last, loc;
    cout << "Enter no of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    if(n>1)
    {
        top=top+1;
        lower[top]=0;
        upper[top]=n-1;
    }

    while(top!=-1)
    {
        beg=lower[top];
        last=upper[top];
        top=top-1;

        loc=quick(arr, beg, last);
        if(beg < loc-1)
        {
            top=top+1;
            upper[top]=loc-1;
            lower[top]=beg;
        }
        if(last>loc+1)
        {
            top=top+1;
            upper[top]=last;
            lower[top]=loc+1;
        }
    }

    cout << "\n";
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " ";

    }
}

int quick(int arr[], int beg, int last)
{
    int i=beg, j, temp;
    int num = arr[beg];
    for(j=beg; j<=last; j++)
    {
        if(arr[j]<num)
        {
            i=i+1;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[i];
    arr[i]=arr[beg];
    arr[beg]=temp;

    return(i);
}
