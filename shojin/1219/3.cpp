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
class bit1d{
  public:
  vector<ll>v;
  ll num;
  bit1d(ll NUM = 0){
      num = NUM + 5;
      v = vector<ll>(num + 5, 0);
  }
  void add(ll idx, ll x){
      if(idx == 0)return;
      while(idx <= num){
          v[idx] = (v[idx] + x) % MOD;
          idx += idx & -idx;
      }
  }
  ll sum_of_1_to_idx(ll idx){
      if(idx <= 0)return 0;
      ll s = 0;
      while(idx > 0){
          s = (v[idx] + s) % MOD;
          idx -= idx & -idx;
      }
      return s;
  }
  ll sum(ll l, ll r){
      return sum_of_1_to_idx(r) - sum_of_1_to_idx(l - 1);
  }
};

int main(){

    bit1d A(100000);
    bit1d B(100000);
    bit1d C(100000);
    bit1d D(100000);
    
    ll N;
    cin >> N;
    vector<ll>v(N);
    rep(i, N)cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 0;
    rep(i, N){
        ll d = v[i];
        A.add(d, 1);
        B.add(d, A.sum_of_1_to_idx(d / 2));
        C.add(d, B.sum_of_1_to_idx(d / 2));
        ans = (ans + C.sum_of_1_to_idx(d / 2)) % MOD;
    }
    cout << ans << endl;

    return 0;
}