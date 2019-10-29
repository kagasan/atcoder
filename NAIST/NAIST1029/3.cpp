#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll A[10100], B[10100], C[10100];

int main(){
	for(ll n, m; cin >> n >> m, n;){
		vector<P>path[105];
		rep(i, m){
			cin >> A[i] >> B[i] >> C[i];
			path[A[i]].push_back(P(C[i], B[i]));
			path[B[i]].push_back(P(C[i], A[i]));
		}
		ll ans = INF;
		rep(i, m){
			vector<ll>flg(n + 1, INF);
			priority_queue<P>Q;
			Q.push(P(C[i], B[i]));
			while(!Q.empty()){
				ll w = Q.top().first;
				ll idx = Q.top().second;
				Q.pop();
				if(flg[idx] != INF)continue;
				flg[idx] = w;
				rep(j, path[idx].size()){
					ll to = path[idx][j].second;
					if(flg[to] != INF)continue;
					if(path[idx][j].first > C[i])continue;
					Q.push(path[idx][j]);
				}
			}
			ll tmp = INF;
			rep1(j, n){
				if(flg[j] == INF)tmp = -1;
				chmin(tmp, flg[j]);
			}
			if(tmp > 0)chmin(ans, C[i] - tmp);
		}
		if(ans == INF)cout << -1 << endl;
		else cout << ans << endl;
	}

    return 0;
}