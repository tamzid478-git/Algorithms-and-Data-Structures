#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 110;
ll dist[mx];
const ll inf = 1e18;
vector<pair<int, int>> v[mx];
void dijkstra(int source, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = inf;
    }
    dist[source] = 0;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, 0, source}); 
    while (!pq.empty())
    {
        int stops = pq.top()[0];
        ll current_dist = pq.top()[1];
        int current_node = pq.top()[2];
        pq.pop();
        for (auto x : v[current_node])
        {
            if (current_dist + x.second < dist[x.first] && stops <= k)
            {
                dist[x.first] = current_dist + x.second;
                pq.push({stops + 1, dist[x.first], x.first});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        v[node1].push_back({node2, cost});
    }
    int source, dest, k;
    cin >> source >> dest >> k;
    dijkstra(source, n, k);
    if (dist[dest] == inf)

        cout << "-1";
    else
        cout << dist[dest];
    return 0;
}
