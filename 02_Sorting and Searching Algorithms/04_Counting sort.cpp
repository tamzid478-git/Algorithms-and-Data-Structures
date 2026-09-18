
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>v(n+1);
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    int range=*max_element(v.begin()+1,v.end());
    vector<int>cnt(range+1);
    vector<int>result(n+1);
    for(int i=1;i<=n;i++)
    {
        cnt[v[i]]++;
    }
    for(int i=1;i<=range;i++)
    {
        cnt[i]=cnt[i-1]+cnt[i];
    }
    for(int i=n;i>=1;i--)
    {
        idx=cnt[v[i]]--;
        result[idx]=v[i];
    }
   
    for(int i=1;i<=n;i++)
    {
        cout<<result[i]<<" ";
    }


    return 0;
}
