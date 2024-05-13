#include <bits/stdc++.h>
using namespace std;                                    

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os <<  p.first << " " << p.second ;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { for (const T &x : v) os << x << " "; return os;}
void dbg_out() { cerr << "" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H ; dbg_out(T...); }
#ifdef SAGAR
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nge = ngelem(nums);
        vector<int> pge = pgelem(nums);
        vector<int> nle = nlelem(nums);
        vector<int> ple = plelem(nums);

        long long ans = 0;
        int n = nums.size();
        

        for(int i=0;i<n;i++){
            int ngnum = nge[i] - i -1;
            int pgnum = i - pge[i] - 1;

            long long max_sum = (ngnum + pgnum + 1 + ngnum*pgnum);

            int nlnum = nle[i] - i - 1;
            int plnum = i - ple[i] - 1;

            long long min_sum = (nlnum + plnum + 1 + nlnum*plnum);

            ans += (1ll*nums[i]*(max_sum - min_sum));
        }

        return ans;
    }

    vector<int> ngelem(vector<int>& nums){
        int n = nums.size();

        vector<int> nge(n);

        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i] > nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nge[i] = n;
            }
            else{
                nge[i] = s.top();
            }
            s.push(i);
        }

        return nge;
    }

    vector<int> pgelem(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i] >= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> nlelem(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i] < nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> plelem(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i] <= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }
};

int32_t main() {
    #ifdef SAGAR
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    #endif

    Solution s;

    vector<int> v {1, 3, 3};

    int ans = s.subArrayRanges(v);
}