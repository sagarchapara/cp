// AUTHOR: AlperenT

#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5, INF = (long long)2e18 + 5;

long long t, n, k, arr[N], closest[N], mn, ans;

vector<pair<long long, long long>> v;

void solve(){
	ans = INF;

	cin >> n >> k;

	for(int i = 1; i <= n; i++) cin >> arr[i];

	arr[0] = -1;

	for(int i = 1; i <= n; i++){
		fill(closest + arr[i - 1] + 1, closest + arr[i] + 1, arr[i]);
	}

	fill(closest + arr[n] + 1, closest + N, INF);

	for(int mx = 1; mx <= 100000; mx++){
		v.clear();

		v.push_back({1, mx});

		for(int i = 2; i <= k; i++){
			v.push_back({v.back().second + 1, 1ll * (mx + 1) * i - 1});

			if(v.back().second > arr[n]) break;
		}

		if(v.back().second >= arr[n]){
			mn = INF;

			for(int i = 0; i < v.size(); i++){
				int nxt = closest[v[i].first];

				if(nxt <= v[i].second) mn = min(mn, nxt / (i + 1ll));
			}

			assert(mn <= mx);

			ans = min(ans, mx - mn);

		}
	}

	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	// cin >> t;
    int t = 1;
	while(t--){
		solve();
	}
}