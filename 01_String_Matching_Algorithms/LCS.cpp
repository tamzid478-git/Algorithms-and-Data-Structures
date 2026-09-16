#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1="abcde";
    string s2="cdef";
    vector<vector<int>>v(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                v[i][j]=v[i-1][j-1]+1;
                
            }
            else
            {
                v[i][j]=max(v[i][j-1],v[i-1][j]);
            }
        }
    }
    cout<<v[s1.size()][s2.size()]<<endl;
    vector<char>ans;
    int i=s1.size(),j=s2.size();
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;

        }
        else
        {
            if(v[i-1][j]>v[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x : ans)
    {
        cout<<x;
    }
    return 0;
}
//complexity: O(nm)+O(n+m) 
//sept 16 ,2026 .
