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

string s;
ll N, l, r, ans = 0;

ll l_shrink(){
	for(l = 1; l <= N;){
		if(s[l] == '<')l++;
		else break;
	}
	return l - 1;
}

ll r_shrink(){
	for(r = N; r >= 1;){
		if(s[r] == '>')r--;
		else break;
	}
	return N - r;
}

int main(){

	cin >> N;
	cin >> s;
	s = "@" + s + "@";
	ans = N + max(l_shrink(), r_shrink()) - l_shrink() - r_shrink();
	cout << ans << endl;

    return 0;
}