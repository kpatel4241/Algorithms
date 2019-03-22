//
// Created by KP on 22-03-2019.
//
// LONGEST INCREASING SUBSEQUENCE PROGRAM.

#include<bits/stdc++.h>

using namespace std;

int Table[1024];

// Time Complexcity = O(n^2).
// Space Complexcity = O(n).

// L(i) represents optimal subsequence which is starting at position A[1] and ending at A[i].
int long_inc_subseq_1(int A[] , int n)
{
    int i,j,max=0;

    for(i=0;i<n;i++)
        Table[i] = 1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(A[j]<A[i] && Table[i]<Table[j]+1)
                Table[i] = Table[j]+1;
        }
    }

    for(i=0;i<n;i++)
    {
        if(max<Table[i])
            max = Table[i];
    }
    return max;
}


// L(i) represents optimal subsequence which is starting at position A[i] and ending at A[n].
int long_inc_subseq_2(int A[] , int n)
{
    int i,j,max=0;

    for(i=0;i<n;i++)
        Table[i] = 1;

    for(i=n-1;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]<A[j] && Table[i]<Table[j]+1)
                Table[i] = Table[j]+1;
        }
    }

    for(i=0;i<n;i++)
    {
        if(max<Table[i])
            max = Table[i];
    }
    return max;
}


int main()
{
    int n;

    cout<<"\n Enter the Size : ";
    cin>>n;

    int A[n];
    cout<<"\n Enter the Elements : ";
    for(auto i=0;i<n;i++)
        cin>>A[i];

    int _lis1_ = long_inc_subseq_1(A,n);
    int _lis2_ = long_inc_subseq_2(A,n);

    cout<<"\n Length of Longest Increasing Subsequence = "<<_lis1_<<endl;
    cout<<"\n Length of Longest Increasing Subsequence = "<<_lis2_<<endl;

    return 0;

}