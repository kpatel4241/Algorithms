//
// Created by KP on 01-04-2019.
//

#include<bits/stdc++.h>
#define MAX_SIZE 5

using namespace std;


void _prims_algo(int visited_v[] ,int G[][MAX_SIZE] )
{
    int x , y , no_edges = 0 ;;
    cout<<" Edge "<<" : "<<" Weight "<<endl;

    while(no_edges < MAX_SIZE-1)
    {
        int min = INT_MAX;
        x=0;
        y=0;

        for(int i=0;i<MAX_SIZE;i++)
        {
            if(visited_v[i])
            {
                for(int j=0;j<MAX_SIZE;j++)
                {
                    if(! visited_v[j] && G[i][j])
                    {
                        if(min>G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout<< x << "-" <<y<< " : "<<G[x][y]<<endl;
        visited_v[y] = 1;
        no_edges++;
    }
}


int main()
{
    int G[MAX_SIZE][MAX_SIZE];
    cout<<"\n Enter the Adjancy Matrix : \n";
    for(int i=0;i<MAX_SIZE;i++)
    {
        for(int j=0;j<MAX_SIZE;j++)
        {
            cin>>G[i][j];
        }
    }

    int visited_v[MAX_SIZE];

    memset(visited_v , 0 ,sizeof(visited_v));

    visited_v[0] = 1;

    _prims_algo(visited_v , G );

    return 0;
}