#include <bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
vector<pair<int,int>>v[mx]; //node1,node2,wight rakar jonno
long long int dist[mx];     //weight rakhar jonno
void dijkstra(int source,int n)
{
    for(int i=1;i<=n;i++)   //shobgular distance k infinite kore dilam 
    {
        dist[i]=1e18;
    }
    dist[source]=0; //source to source  er distace 0
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
    pq.push({0,source});
    while(!pq.empty())
    {
        long long int current_node=pq.top().second;     //weight
        int current_dist=pq.top().first;                //node
        pq.pop();
        if(dist[current_node]<current_dist)             //ekta node er shortest path ber korar por bor man jate ar check na hoy 
        continue;

        for(auto x : v[current_node])   //current node er adjacent node check 
        {
            int neighbour_node=x.first;     //node
            int neighbour_dist=x.second;      //weight
            if(current_dist+neighbour_dist<dist[neighbour_node])   
            {
                dist[neighbour_node]=current_dist+neighbour_dist;
                pq.push({dist[neighbour_node],neighbour_node});

            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int node1,node2,weight;
        cin>>node1>>node2>>weight;
        v[node1].push_back({node2,weight});
        v[node2].push_back({node1,weight}); //jokon directed graph ehobe tokon eta hobe na..

    }
    dijkstra(1,n);      //source and n er man send korlam function e 
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
