//
// Created by KP on 07-04-2019.
//

#include<bits/stdc++.h>

using namespace std;

// Matrix Chain Multiplication OR Matrix Product Paranthesization.
// Time Complexity = O(n^3).
int matrix_chain_order(int P[] , int length)
{
    int n = length-1 , M[n][n] , S[n][n];

    for(int i=1;i<=n;i++)
        M[i][i] = 0;

    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j = i+l-1;
            M[i][j] = INT_MAX;

            for(int k=i;k<=j-1;k++)
            {
                int curr_cost = M[i][k] + M[k+1][j] + P[i-1]*P[k]*P[j];
                if(curr_cost < M[i][j])
                {
                    M[i][j] = curr_cost;
                    S[i][j] = k;
                }
            }
        }
    }
    return M[1][n-1];
}


int main()
{
    int n;
    cout<<"\n Enter the Size : ";
    cin>>n;

    int P[n];
    cout<<"\n Enter the Matrix Chain : ";
    for(int i=0;i<n;i++)
        cin>>P[i];

    int cost = matrix_chain_order(P , n);

    cout<<"\n Minimum no. of total multiplications = "<<cost<<endl;

    return 0;
}


/*
int main()
{
    int arr[] = {1, 2, 3, 4, 5 , 6 , 7 , 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Minimum number of multiplications = " << matrix_chain_order(arr, n);

    return 0;
}
*/
