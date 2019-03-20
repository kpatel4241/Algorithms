//
// Created by KP on 20-03-2019.
//

// Maximum Value Contiguous Subsequence Program.

#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Here I'am using the Brute Force Approch to see all possible sums & select the one which has max value.
// Time Complexity = O(n^2).
// Space Complecity = O(1).

ll int max_val_contiguous(ll int A[] ,ll int n)
{
    ll int max_sum = 0;

    for(auto i=0;i<n;i++)
    {
        ll int curr_sum = 0;
        for(auto j=i;j<n;j++)
        {
            curr_sum += A[j];

            if(curr_sum > max_sum)
                max_sum = curr_sum;
        }
    }
    return  max_sum;
}

// Here I'am using Dynamic Programming Approch.
// Time Complexity = O(n).
// Space Complexity = O(n).

ll int max_contiguous_val_DP(ll int A[] ,ll int n)
{
    ll int M[n], max_sum=0;

    if(A[0] > 0)
        M[0] = A[0];
    else
        M[0]=0;

    for(auto i=0;i<n;i++)
    {
        if(M[i-1] + A[i] > 0)
            M[i] = M[i-1] + A[i];
        else
            M[i] = 0;
    }

    for(auto i=0;i<n;i++)
    {
        if(M[i] > max_sum)
            max_sum = M[i];
    }

    return max_sum;
}


int main()
{
    int n;
    cout<<"\n Enter the Size of Array : ";
    cin>>n;

    int A[n];
    cout<<"\n Enter the Elements : ";
    for(auto i=0;i<n;i++)
        cin>>A[i];

    int max_sum = max_val_contiguous(A,n);
    int max_sum_DP = max_contiguous_val_DP(A,n);

    cout<<"\n Max. Contigeous Value using Brute_Force Approch = "<<max_sum<<endl;
    // cout<<"\n Max. Contigeous Value using DP Approch = "<<max_sum_DP<<endl;

    return 0;
}


/* This is for when you are dealing with large amount of date with files.
int main()
{
    clock_t t1;
    t1 = clock();

    ll int n = 0;
    ll int A[100000];

    ifstream fin("num_list.txt",ios::in);
    if (fin.is_open())
    {
        while ( true)
        {
            int x;
            fin >> x;
            if (fin.eof())
                break;
            A[n++] = x;
        }
        fin.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    ll int max_sum = max_val_contiguous(A,n);
    ll int max_sum_DP = max_contiguous_val_DP(A,n);

    // cout<<"\n Max. Contigeous Value using Brute_Force Approch = "<<max_sum<<endl;
    cout<<"\n Max. Contigeous Value using DP Approch = "<<max_sum_DP<<endl;


    t1 = clock() - t1;
    cout<<"\n Total Execution Time = "<<(float)t1/CLOCKS_PER_SEC<<endl;

    return 0;
}

*/