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

int main(){

    ll N;
	cin >> N;
	
	vector<ll>X(N), Y(N);
	map<P, ll>cnt;
	rep(i, N){
		cin >> X[i] >> Y[i];
		ll w;
		cin >> w;
		cnt[P(X[i], Y[i])] = w;		
	}
	ll ans = 0;

	rep(i, N){
		ll x = X[i];
		ll y = Y[i];
		chmax(ans, cnt[P(x, y)] + cnt[P(x + 1, y)] + cnt[P(x, y + 1)] + cnt[P(x + 1, y + 1)]);
		chmax(ans, cnt[P(x, y)] + cnt[P(x + 1, y)] + cnt[P(x, y - 1)] + cnt[P(x + 1, y - 1)]);
	}
	cout << ans << " / 1" << endl;

    return 0;
}