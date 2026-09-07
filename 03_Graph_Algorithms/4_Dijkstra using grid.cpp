#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long int shortest(vector<vector<int>> &v, int n)
{
    long long int dis[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = 1e18;
        }
    }

    dis[0][0] = v[0][0];
    priority_queue<pair<long long int, pair<int, int>>, vector<pair<long long int, pair<int, int>>>, greater<pair<long long int, pair<int, int>>>> pq;
    pq.push({dis[0][0], {0, 0}});
    while (!pq.empty())
    {
        int current_idx_i = pq.top().second.first;
        int current_idx_j = pq.top().second.second;
        long long int current_dis = pq.top().first;
        pq.pop();
        if(dis[current_idx_i][current_idx_j]<current_dis)
        continue;
    
        for (int i = 0; i < 4; i++)
        {
            int x1 = current_idx_i + dx[i];
            int y1 = current_idx_j + dy[i];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n)
            {
                if (current_dis + v[x1][y1] < dis[x1][y1])
                {
                    dis[x1][y1] = current_dis + v[x1][y1];
                    pq.push({dis[x1][y1], {x1, y1}});
                }
            }
        }
    }
    return dis[n - 1][n - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    // ekn input newa ses function cll korbo
    long long int ans = shortest(v, n);
    cout << ans;
    return 0;
}
