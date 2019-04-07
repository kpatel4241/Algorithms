//
// Created by KP on 07-04-2019.
//

#include<bits/stdc++.h>
#define V 4

using namespace std;

// All pair shortest path == Floyed Warshell Algorithm.
// Time Complexity = O(n^3).
void floyed_warshell_algo(int G[][V])
{
    int dist[V][V];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j] = G[i][j];

    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);

                /*if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j]; */
            }
        }
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int source , G[V][V];
    cout<<"\n Enter the Adjancey Matrix of G : \n";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>G[i][j];

    floyed_warshell_algo(G);

    return 0;
}


/*
int main()
{
    int G[V][V] = {
            {0,3,INT_MAX,7},
            {8,0,2,INT_MAX},
            {5,INT_MAX,0,1},
            {2,INT_MAX,INT_MAX,0}
    };

    floyed_warshell_algo(G);

    return 0;
}
*/
