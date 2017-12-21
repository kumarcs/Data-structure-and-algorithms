#include<iostream>
using namespace std;
#define MAX 100
int arr[MAX], temp[MAX];
void insertionS(int n);
void selectionS(int n);
void mergesort(int, int);
void mergearr(int, int, int);
void quicksort(int, int);
int partition(int, int);
int flag=0;
int main()
{
    int choice, n, i, j;
    while(1){
    cout << endl;
    cout << "1. Enter array" << endl
         << "2. display" << endl
         << "3. insertion sort" << endl
         << "4. selection sort" << endl
         << "5. merge sort" << endl
         << "6. quick sort" << endl
         << "7. Exit" << endl
         << "Enter your choice: ";
         cin >> choice;
    switch(choice)
    {
    case 1:
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements: " << endl;
        for(i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        flag=1;  //indicates array initialized
        cout << "array initialized!!" << endl;
        break;
    case 2:
        cout << endl;
        for(i=0; i<n; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
        break;
    case 3:
        insertionS(n);
        break;
    case 4:
        selectionS(n);
        break;
    case 5:
        mergesort(0, n-1);
        break;
    case 6:
        quicksort(0, n-1);
        break;
    case 7:
        return 0;
    default:
        cout << "Wrong choice";
    }
    }
}

void insertionS(int n)
{
    if(!flag)
    {
        cout << "error!!" << endl;
        return;
    }
    int i, j, k, fswap;
    for(i=1; i<n; i++)
    {
        k=i;
        for(j=i-1; j>=0; j--)
        {
            if(arr[j]>arr[k])
            {
                fswap=arr[j];
                arr[j]=arr[k];
                arr[k]=fswap;
                k=j;
            }
        }
    }
}

void selectionS(int n)
{
    if(!flag)
    {
        cout << "error!!" << endl;
        return;
    }
    int i, j, k, temp, min;
    for(i=0; i<n-1; i++)
    {
        k=i+1;
        min = arr[k];
        for(j=i; j<n; j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                k=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
}

void mergesort(int left, int right)
{
    int mid;
    if(right>left)
    {
        mid=(right+left)/2;
        mergesort(left, mid);
        mergesort(mid+1, right);
        mergearr(left, mid+1, right);
    }
}

void mergearr(int left, int mid, int right)
{
    int i, left_end, size, temp_pos;
    left_end=mid-1;
    size=right-left+1;
    temp_pos=left;
    while((left<=left_end) && (mid<=right))
    {
        if(arr[left]<=arr[mid])
        {
            temp[temp_pos]=arr[left];
            temp_pos++;
            left++;
        }
        else
        {
            temp[temp_pos]=arr[mid];
            temp_pos++;
            mid++;
        }
    }
    while(left <= left_end)
    {
        temp[temp_pos]=arr[left];
        temp_pos++;
        left++;
    }
    while(mid<=right)
    {
        temp[temp_pos]=arr[mid];
        temp_pos++;
        mid++;
    }
    for(i=0; i<=size; i++)
    {
        arr[right]=temp[right];
        right--;
    }
}


//quick sort start
void quicksort(int low, int high)
{
    if(low < high)
    {
        int pivot = partition(low, high);
        quicksort(low, pivot-1);
        quicksort(pivot+1, high);
    }
}


int partition(int low, int high)
{
    int i=low;
    int pi = arr[low];
    for(int j=low; j<=high; j++)
    {
        if(arr[j]<pi)
        {
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }


    int temp=arr[low];
    arr[low]=arr[i];
    arr[i]=temp;
    return i;
}
