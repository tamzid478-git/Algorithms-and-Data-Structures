#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{3, 2, 1, 4, 5};
    for (int i = 0; i < v.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
