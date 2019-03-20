//
// Created by KP on 19-03-2019.
//

#include<bits/stdc++.h>
#define pi 3.14159265358979323846264338327950288

using namespace std;

typedef complex<double> cmp;

vector<cmp> FFT(vector<cmp> &A)
{
    int n = A.size();

    if( n==1 )
        return vector<cmp>(1,A[0]);

    vector<cmp> W(n);
    for( auto i=0;i<n;i++)
    {
        double pre_val = 2*pi*i/n;
        W[i] = cmp(cos(pre_val),sin(pre_val));
    }

    vector<cmp> A_even(n/2) , A_odd(n/2);
    for(auto i=0;i<n/2;i++)
    {
        A_even[i] = A[i*2];
        A_odd[i] = A[i*2 + 1];
    }

    vector<cmp> y_even = FFT(A_even);
    vector<cmp> y_odd = FFT(A_odd);

    vector<cmp> y(n);

    for(auto k=0;k<n/2;k++)
    {
        y[k] = y_even[k] + W[k]*y_odd[k];
        y[k+n/2] = y_even[k] - W[k]*y_odd[k];
    }

    return y;
}

int main()
{
    vector<cmp> A;
    int n,val;

    cout<<"\n Enter the Size : ";
    cin>>n;
    cout<<"\n Enter the Coefficients : ";
    for(auto i=0;i<n;i++)
    {
        cin>>val;
        A.push_back(val);
    }

    vector<cmp> B = FFT(A);

    for(auto i=0;i<n;i++)
        cout<<B[i]<<endl;

    return 0;
}
