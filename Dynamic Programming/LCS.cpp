// PROGRAM FOR LONGEST COMMON SUBSEQUENCE USING DP STRATIGY.

#include<bits/stdc++.h>

using namespace std;

// IN THIS ALGORITHM I'AM USING BOTTOM-UP APPROCH OF DYNAMIC PROGRAMMING.

// Time Complexity = O(mn)
//Space Complexity = O(mn)

int LCS_length(string X , int m , string Y , int n)
{
    int LCS[m+1][n+1];

    for(auto i=0;i<=n;i++)
        LCS[i][n] = 0;

    for(auto j=0;j<=m;j++)
        LCS[m][j] = 0;

    for(auto i=m-1;i>=0;i--)
    {
        for(auto j=n-1;j>=0;j--)
        {
            LCS[i][j] = LCS[i+1][j+1];

            if(X[i] == Y[j])
                LCS[i][j]++;
            if(LCS[i][j+1] > LCS[i][j])
                LCS[i][j] = LCS[i][j+1];
            if(LCS[i+1][j] > LCS[i][j])
                LCS[i][j] = LCS[i+1][j];
        }
    }

    return LCS[0][0];
}


int main()
{
    string str1,str2;

    cout<<"\n Enter the String_1 : ";
    cin>>str1;

    cout<<"\n Enter the String_2 : ";
    cin>>str2;

    int m = str1.length();
    int n = str2.length();

    int LCS_len = LCS_length(str1,m,str2,n);

    cout<<"\n LCS_Length = "<<LCS_len<<endl;

    return 0;
}
