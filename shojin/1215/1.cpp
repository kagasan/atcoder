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
          v[idx] += x;
          idx += idx & -idx;
      }
  }
  ll sum_of_1_to_idx(ll idx){
      if(idx <= 0)return 0;
      ll s = 0;
      while(idx > 0){
          s += v[idx];
          idx -= idx & -idx;
      }
      return s;
  }
  ll sum(ll l, ll r){
      return sum_of_1_to_idx(r) - sum_of_1_to_idx(l - 1);
  }
};

bit1d bit(5050);

int main(){

    ll N;
    cin >> N;

    vector<P>v;
    rep1(i, N){
        ll a;
        cin >> a;
        v.push_back(P(a, i));
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    stack<ll>S;
    ll lst = -1;
    rep(i, N){
        ll num = v[i].first;
        ll idx = v[i].second;
        if(lst != num){
            while(!S.empty()){
                bit.add(S.top(), 1);
                S.pop();
            }
        }
        lst = num;
        S.push(idx);
        if(idx == 1 || idx == N)continue;
        ans += bit.sum(1, idx - 1) * bit.sum(idx + 1, N);
    }
    cout << ans << endl;

    return 0;
}