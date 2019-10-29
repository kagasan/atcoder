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

ll t;
string n;

ll ans1, ans2;
vector<string>ans_v;

void solve(vector<string> v){
	// for(ll i = 0; i < v.size(); i++)cout << v[i] << ",";
	// cout << endl;
	ll sum = 0;
	for(ll i = 0; i < v.size(); i++){
		stringstream ss;
		ss << v[i];
		ll tmp;
		ss >> tmp;
		sum += tmp;
	}
	if(t < sum)return;
	if(ans1 == sum)ans2++;
	if(ans1 < sum){
		ans1 = sum;
		ans2 = 1;
		ans_v = v;
	}
}

int main(){

	for(;cin >> t >> n;){
		if(t == 0 && n == "0")break;
		ans1 = -1;
		ans2 = 0;
		for(ll i = 0; i < (1 << (n.size() - 1)); i++){
			vector<string>v;
			string tmp = "";
			for(ll j = 0; j < n.size(); j++){
				tmp += n[j];
				if(i & (1 << j)){
					v.push_back(tmp);
					tmp = "";
				}
			}
			if(tmp != "")v.push_back(tmp);
			solve(v);
		}
		if(ans1 < 0)cout << "error" << endl;
		else if(ans2 > 1)cout << "rejected" << endl;
		else{
			cout << ans1;
			rep(i, ans_v.size())if(ans_v[i].size())cout << " " << ans_v[i];
			cout << endl;
		}
	}

    return 0;
}