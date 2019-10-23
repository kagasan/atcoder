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

    ll N, M;
    cin >> N >> M;
    imos1d d(N);
    for(ll i = 2; i <= N; i++){
        ll x;
        cin >> x;
        d.add(i, x);
    }
    d.make();
    ll pos = 1, ans = 0;
    rep(i, M){
        ll x;
        cin >> x;
        ll tmp = abs(d.sum(1, pos) - d.sum(1, pos + x)) % 100000;
        ans = (ans + tmp) % 100000;
        pos += x;
    }
    cout << ans << endl;
    return 0;
}