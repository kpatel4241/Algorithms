//
// Created by KP on 07-04-2019.
//

#include<bits/stdc++.h>
#define V 8
using namespace std;


// Finding the shortest path in Multigraph using Backward method.
// Time Complexity = O(n^2).

int shortest_path(int G[][V])
{
    int dist[V];
    dist[V-1] = 0;

    for(auto i=V-2;i>=0;i--)
    {
        dist[i] = INT_MAX;

        for(auto j=i;j<V;j++)
        {
            if(G[i][j] == INT_MAX)
                continue;

            dist[i] = min(dist[i] , G[i][j] + dist[j]);
        }
    }

    return dist[0];
}


int main()
{
    int source , G[V][V];
    cout<<"\n Enter the Adjancey Matrix of G : \n";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>G[i][j];

    cout<<"\n Enter the Source Vertex : ";
    cin>>source;

    int min_cost = shortest_path(G);

    cout<<"\n Minimum Cost = "<<min_cost<<endl;
    return 0;
}


/*
int main()
{
    int G[V][V] = {
            {INT_MAX,1,2,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
            {INT_MAX,INT_MAX,INT_MAX,INT_MAX,4,11,INT_MAX,INT_MAX},
            {INT_MAX,INT_MAX,INT_MAX,INT_MAX,9,5,16,INT_MAX},
            {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2,INT_MAX},
            {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,18},
            {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,13},
            {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2},
    };

    int min_cost = shortest_path(G);
    cout<<"\n Minimum Cost = "<<min_cost<<endl;
    return 0;
}
*/