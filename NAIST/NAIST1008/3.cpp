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

ll x, y, z;
ll L(char s, ll t){
	return t - 1;
}
ll R(char s, ll t){
	if(s == 'A')return x - t;
	if(s == 'B')return y - t;
	return z - t;
}

int main(){

	cin >> x >> y >> z;
	char s0, s1;
	ll t0, t1;
	cin >> s0 >> t0;
	cin >> s1 >> t1;
	ll ans = 1145141919810893;

	ll tmp = min(x, min(y, z)) - 1;
	chmin(ans, 2 + tmp + L(s0, t0) + R(s1, t1));
	chmin(ans, 2 + tmp + R(s0, t0) + L(s1, t1));
	chmin(ans, 1 + L(s0, t0) + L(s1, t1));
	chmin(ans, 1 + R(s0, t0) + R(s1, t1));
	if(s0 == s1)chmin(ans, abs(t0 - t1));

	cout << ans << endl;

    return 0;
}