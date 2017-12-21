#include<iostream>
using namespace std;
#define MAX 50
int non_tailfact(int n, int result);
int fact_aux(int );
int non_tailfib(int n, int next, int result);
int fib_aux(int );
void towerofhanoi(int, char, char, char);
int arr[MAX];
void quicksort(int arr[], int, int);
int main()
{
    int choice, num, i, j;
    while(1)
    {
        cout << "1. factorial" << endl
             << "2. fibnacci" << endl
             << "3. tower of hanoi" << endl
             << "4. quick sort" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> num;
            cout << "factorial is: " << fact_aux(num);
            break;
        case 2:
            cout << "Enter number of terms required: ";
            cin >> num;
            cout << "sum of fibnacci series is: " << fib_aux(num);
            break;
        case 3:
            cout << "Enter number of disc required: ";
            cin >> num;
            towerofhanoi(num, 'a', 'b', 'c');
            break;
        case 4:
            cout << "Enter number of elements: ";
            cin >> num;
            cout << "Enter elements: " << endl;
            for(i=0; i<num ;i++)
                cin >> arr[i];
            quicksort(arr, 0, num-1);
            cout << "\n";
            for(i=0; i<num; i++)
                cout << arr[i] << " ";
            cout << endl;
                break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
}

int non_tailfact(int n, int result)
{
    if(n==1)
        return result;
    return non_tailfact(n-1, n*result);
}
int fact_aux(int num)
{
    return non_tailfact(num, 1);
}
int non_tailfib(int n, int next, int result)
{
    if(n==0)
        return next;
    if(n==1)
        return result;
    return non_tailfib(n-1, result, next+result);
}
int fib_aux(int n)
{
    return non_tailfib(n, 0, 1);
}

void towerofhanoi(int n, char source, char temp, char target)
{
    if(n == 1)
        cout << "Move " << n << " from " << source << " to " << target << endl;
    else
    {
        towerofhanoi(n-1, source, target, temp);
        cout << "Move " << n << " from " << source << " to " << target << endl;
        towerofhanoi(n-1, temp, source, target);
    }
    return;
}

void quicksort(int arr[], int low, int high)
{
    int i, j, pivot, temp, loc;
    if(low<high)
    {
        pivot = arr[low];
        i=low;
        for(j=low; j<=high; j++)
        {
            if(arr[j]<pivot)
            {
                i=i+1;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        loc=i;
        temp=arr[loc];
        arr[loc]=arr[low];
        arr[low]=temp;

        quicksort(arr, low, loc-1);
        quicksort(arr, loc+1, high);
    }
    cout << "\n";
    return;
}
