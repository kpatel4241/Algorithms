//
// Created by KP on 19-03-2019.
//

#include<bits/stdc++.h>
#define pi -3.14159265358979323846264338327950288

using namespace std;

typedef complex<double> cmp;

vector<cmp> inverse_FFT(vector<cmp> &Y)
{
    int n = Y.size();

    if( n==1 )
        return vector<cmp>(1,Y[0]);

    vector<cmp> W(n);
    for( auto i=0;i<n;i++)
    {
        double pre_val = 2*pi*i/n;
        W[i] = cmp(cos(pre_val),sin(pre_val));
    }

    vector<cmp> Y_even(n/2) , Y_odd(n/2);
    for(auto i=0;i<n/2;i++)
    {
        Y_even[i] = Y[i*2];
        Y_odd[i] = Y[i*2 + 1];
    }

    vector<cmp> A_even = inverse_FFT(Y_even);
    vector<cmp> A_odd = inverse_FFT(Y_odd);

    vector<cmp> A(n);

    for(auto k=0;k<n/2;k++)
    {
        A[k] = (A_even[k] + W[k]*A_odd[k]);
        A[k+n/2] = (A_even[k] - W[k]*A_odd[k]);
    }

    return A;
}


int main()
{
    vector<cmp> Y;
    int n,val;
    cmp N(n,n);

    cout<<"\n Enter the Size : ";
    cin>>n;
    cout<<"\n Enter the Coefficients : ";
    for(auto i=0;i<n;i++)
    {
        cin>>val;
        Y.push_back(val);
    }

    vector<cmp> A = inverse_FFT(Y);

    for(auto i=0;i<n;i++)
        cout<<A[i]/N<<endl;

    return 0;
}
