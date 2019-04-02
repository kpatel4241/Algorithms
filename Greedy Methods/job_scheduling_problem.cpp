#include<bits/stdc++.h>

using namespace std;

struct Job
{
    int job_id;
    int dead_line;
    float profit;
};


bool comparasion(Job A , Job B)
{
    return(A.profit > B.profit);
}


// Time Complexity = O(n^2).
void job_scheduling(Job A[] , int n)
{
    int result[n];
    bool slot[n];

    for(auto i=0;i<n;i++)
        slot[i] = false;

    for(auto i=0;i<n;i++)
    {
        for(auto j=min(n,A[i].dead_line)-1 ; j>=0 ; j--)
        {
            if( slot[j] == false )
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for(auto i=0;i<n;i++)
    {
        if( slot[i] == true)
            cout<<A[result[i]].job_id<<" ";
        cout<<endl;
    }
}

/*
int main()
{
    int n;
    cout<<"\n Enter the Size : ";
    cin>>n;

    struct Job A[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter the Job-ID"<<i+1<<" : ";
        cin>>A[i].job_id;

        cout<<"\n Enter the Deadline"<<i+1<<" : ";
        cin>> A[i].dead_line;

        cout<<"\n Enter the Profit"<<i+1<<" : ";
        cin>>A[i].profit;
    }

    sort(A , A+n , comparasion);

    job_scheduling(A , n);

    return 0;

}
*/

int main() 
{ 
    Job A[] = { {'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}}; 
    int n = sizeof(A)/sizeof(A[0]); 

    sort(A , A+n , comparasion);

    job_scheduling(A , n);

    return 0;
} 
