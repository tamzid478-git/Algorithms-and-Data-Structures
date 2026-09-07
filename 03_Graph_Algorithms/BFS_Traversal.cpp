#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> v[mx];
int level[mx];
void bfs(int source)
{
    memset(level, -1, sizeof(level));

    level[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto x : v[u])
        {
            if (level[x] == -1)
            {
                level[x] = level[u] + 1;
                q.push(x);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        for(int i=0;i<mx;i++)
        {
            v[i].clear();
        }
        int node, edge;
        cin >> node >> edge;
        for (int i = 1; i <= edge; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
      
        bfs(1);
        cout << level[node] << endl;
    }
    return 0;
}
/*
2       test case 
3 2     node =3,edge=2
1 2
2 3
4 4     node =4,edge=4
1 2
2 3
3 4
4 2
output:
2
2

*/
