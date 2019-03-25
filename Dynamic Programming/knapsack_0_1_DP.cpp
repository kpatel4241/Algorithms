//
// Created by KP on 25-03-2019.
//

// 0-1 Knapsack problem.

#include<bits/stdc++.h>

using namespace std;

struct Item
{
    int value,weight;
};


// This is the recursive approch .
// Time Complexity = O(2^n)

int knapsack_recursive(Item A[] , int max_capacity , int n)
{
    if(max_capacity == 0 || n == 0)
        return 0;

    if(A[n-1].weight > max_capacity)
        return knapsack_recursive(A , max_capacity , n-1);
    else
        return max(knapsack_recursive(A,max_capacity,n-1) , (A[n-1].value + knapsack_recursive(A,(max_capacity - A[n-1].weight) , n-1)));
}


// This one is the DP approch in bottom-up fashion.
// Time Complexity = O(n*ks_size)

int knapsack_DP(Item A[] , int n , int ks_size)
{
    int i,j;
    int knapsack[n+1][ks_size+1];

    for(j=0;j<=ks_size;j++)
        knapsack[0][j]=0;

    for(i=0;i<=n;i++)
        knapsack[i][0]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=ks_size;j++)
        {
            if(A[i-1].weight<=j)
            {
                knapsack[i][j]=max(knapsack[i-1][j],A[i-1].value+knapsack[i-1][j-A[i-1].weight]);
            }
            else
            {
                knapsack[i][j]=knapsack[i-1][j];
            }
        }
    }

    return knapsack[n][ks_size];
}


int main()
{
    int n,i,ks_size;
    cout<<"\n Enter the Size : ";
    cin>>n;

    Item A[n];
    cout<<"\n Enter the Value & Weight : ";
    for(i=0;i<n;i++)
        cin>>A[i].value>>A[i].weight;

    cout<<"\n Enter the Knapsack Size : ";
    cin>>ks_size;

    int max_val = knapsack_DP(A , n ,ks_size);

    cout<<"\n Max. value of items in knapsack = "<<max_val<<endl;

    return  0;
}