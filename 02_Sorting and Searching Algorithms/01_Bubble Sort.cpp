#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>v{2,5,4,3,1};
    int sz=v.size();
    for(int i=0;i<sz;i++)
    {
        int flag=0;
        for(int j=0;j<sz-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                flag=1;
            }
        }
        if(flag==0) //means already sorted
        break;
    }
    for(int i=0;i<sz;i++)
    {
        cout<<v[i]<<' ';
    }
    return 0;
}

//complexity O(n^2) ...

//Sept 16,2026.
