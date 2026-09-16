#include <bits/stdc++.h>
using namespace std;
vector<int>lps_function(string pattern,int n)
{
    int prefix=0,suffix=1;
    int sz=pattern.size();
    vector<int>lps(sz,0);
    while(suffix<sz)
    {
        if(pattern[prefix]==pattern[suffix])
        {
            lps[suffix]=prefix+1;
            prefix++;
            suffix++;
        }
        else
        {
            if(prefix==0)
            {
                lps[suffix]=0;
                suffix++;
            }
            else 
            {
                prefix=lps[prefix-1];
            }
        }
    }
    return lps;
}
int kmp(string text,string pattern)
{
    vector<int>lps_vec=lps_function(pattern,(int)pattern.size());
    int text_idx=0,pattern_idx=0;
    int sz_text=text.size();
    int sz_pattern=pattern.size();
    int answer=-1;
    while(text_idx<sz_text && pattern_idx<sz_pattern)
    {
        if(text[text_idx]==pattern[pattern_idx])
        {
            text_idx++;
            pattern_idx++;
        }
        if(pattern_idx==sz_pattern)
        {
            return text_idx-pattern_idx;

        }
        else if(text_idx < sz_text && text[text_idx] != pattern[pattern_idx])    
        {
            if(pattern_idx==0)
            {
                text_idx++;

            }
            else
            {
                pattern_idx=lps_vec[pattern_idx-1];
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string text,pattern;
    cin>>text>>pattern;

    int ans=kmp(text,pattern);
    if(ans==-1)
    cout<<"pattern doesn't matched";
    else
    cout<<ans;
    return 0;
}
