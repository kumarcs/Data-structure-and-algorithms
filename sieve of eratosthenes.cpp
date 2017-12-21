#include<bits/stdc++.h>
using namespace std;
//finding next prime number whose xor with given number is greater or equal
void seiveofEratosthenes(bool arr[], long long int n)
{
   int i;
    for(i=2; i*i<=n; i++)
    {
        if(arr[i]==true)
        {
            for(int j=i*2; j<=n; j+=i)
                arr[j]=false;
        }
    }
}
int main()
{
    long long int cases;
    cin >> cases;
    while(cases--)
    {
        long long n, beg, num;
        cin >> n;
        beg=n;
        n=n+50;
        bool arr[n+1];
        memset(arr, true, sizeof(arr));
        seiveofEratosthenes(arr, n);
        for(int i=beg+1; i<=n; i++)
        {
            if(arr[i]==true)
            {
                num=beg^i;
                if((num)>=beg)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
