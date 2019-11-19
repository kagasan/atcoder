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

ll solve(string s){
	ll N = s.size();
	ll ans = N;
	rep(i, 1 << N){
		string t = "";
		rep(j, N){
			if(t == "")t += s[j];
			else if((1 << j) & i){
				if(t[t.size() - 1] == s[j])t = t.substr(0, t.size() - 1);
				else t = t + s[j];
			}
			else{
				if(t[0] == s[j])t = t.substr(1, t.size() - 1);
				else t = s[j] + t;
			}
		}
		chmin(ans, (ll)t.size());
	}
	return ans;
}

ll solve2(string s){
	ll cnt[256] = {};
	rep(i, s.size())cnt[s[i]] ^= 1;
	ll sum = 0;
	rep(i, 256)sum += cnt[i];
	return sum;
}

void N15(){
	ll N;
	cin >> N;
	string s;
	cin >> s;
	cout << solve(s) << endl;
}

void test(){
	ll N = 59049;
	// N = 3 * 3 * 3;
	rep(i, N){
		string s = "";
		for(ll j = i; j; j /= 3)s += ('A' + (j % 3));
		if(solve(s) != solve2(s)){
			cout << s << " : " << solve(s) << ", " << solve2(s) << endl;
		}
	}
}

int main(){

	ll N;
	cin >> N;
	string s;
	cin >> s;
	cout << solve2(s) << endl;

	// test();

    return 0;
}