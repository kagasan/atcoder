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

ll flg[1010];

int main(){

	ll N, M;
	cin >> N >> M;
	
	rep(i, M){
		ll a, b;
		cin >> a >> b;
		for(ll i = a; i < b; i++)flg[i] = 1;
	}
	ll ans = N + 1;
	for(ll i = 1; i <= N; i++)ans += 2 * flg[i];
	cout << ans << endl;

    return 0;
}