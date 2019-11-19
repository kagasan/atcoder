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

// 1indexed1dimention[l,r]
class imos1d{
  public:
  vector<ll>t, v;
  ll num;
  ll flg;
  imos1d(ll NUM = 0){
      flg = 0;
      num = NUM + 10;
      v = vector<ll>(num, 0);
      t = vector<ll>(num, 0);
  }
  void add(ll idx, ll x){
      flg = 0;
      t[idx] += x;
  }
  void make(){
      flg = 1;
      for(ll i = 1; i < num; i++)v[i] = v[i - 1] + t[i];
  }
  ll sum(ll l, ll r){
      if(!flg)make();
      return v[r] - v[l - 1];
  }
};

int main(){

	ll N;
	cin >> N;
	string s;
	cin >> s;
	s = "*" + s;
	imos1d M(1010101);
	rep1(i, N)if(s[i] == 'M')M.add(i, 1);
	ll Q;
	cin >> Q;
	rep(q, Q){
		ll k;
		cin >> k;
		ll ans = 0;
		vector<ll>D(1010101, 0);
		vector<ll>DM(1010101, 0);
		rep1(i, N){
			D[i] = D[i - 1];
			DM[i] = DM[i - 1];
			ll pre = i - k;
			if(pre >= 1 && s[pre] == 'D'){
				D[i]--;
				DM[i] -= M.sum(pre, i - 1);
			}
			if(s[i] == 'D')D[i]++;
			if(s[i] == 'M')DM[i] += D[i];
			if(s[i] == 'C')ans += DM[i];			
		}
		cout << ans << endl;
	}

    return 0;
}