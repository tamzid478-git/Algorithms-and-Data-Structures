#include <bits/stdc++.h>
using namespace std;

vector<int> V[(unsigned int)(1e5)];
int isVisited[(unsigned int)(1e5)];

void DFS(int Src)
{
    cout << Src << " ";
    isVisited[Src] = true;
    for (auto Child : V[Src])
    {
        if (!isVisited[Child])
        {
            DFS(Child);
        }
    }
}

int main()
{
    int N, E;
    cout << "Enter The Number of Nodes and Edges: ";
    cin >> N >> E;
    while (E--)
    {
        int A, B;
        cin >> A >> B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    memset(isVisited, false, sizeof(isVisited));
    cout << "DFS Will Be: ";
    DFS(0);
    return 0;
}

/*
input:
4 4
0 1
0 2
1 3
2 3

output:

DFS Will Be: 0 1 3 2 

*/
