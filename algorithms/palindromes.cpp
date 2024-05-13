#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string& s)
{
    int n = s.length();
    int l =0, r = 0;
    vector<int> ans(n, 1);

    for(int i=1;i<n;i++)
    {
        if(i<= r)
        {
            int j = r+l-i;

            if(j>=0 && j<n)
            {
                ans[i] = min(r-i, ans[j]);
            }
        }

        while(i-ans[i] >=0 && i+ans[i]<n && s[i - ans[i]] == s[i+ans[i]])
        {
            ans[i]++;
        }

        if(i + ans[i] > r)
        {
            l = i-ans[i];
            r = i+ans[i];
        }
    }

    return ans;
}

vector<vector<int>> manacher(string& s)
{
    int n = s.length();

    string t;

    for(auto c : s)
    {
        t += string("#") + c;
    }

    t+=string("#");

    vector<int> v = manacher_odd(t);

    assert(v.size() == 2*n+1);

    vector<vector<int>> ans(n, vector<int>(2,0));

    for(int i=0;i<n;i++)
    {
        ans[i][0] = (v[2*i]-1)/2;
        ans[i][1] = (v[2*i+1])/2;
    }

    return ans;
}

bool is_palindrome(vector<vector<int>>& arr, int l, int r)
{
    int size = r-l+1;

    int mid = (r+l)/2;

    if(size%2 !=0)
    {
        if(arr[mid][1] >= ((size/2)+1))
        {
            return true;
        }
    }
    else{
        if(arr[mid+1][0] >= (size/2))
        {
            return true;
        }
    }

    return false;
}