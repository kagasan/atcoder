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

    ll N, W, H;
    cin >> N >> W >> H;
    map<P, ll>cnt;
    rep(n, N){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(ll y = y1; y <= y2; y++){
            for(ll x = x1; x <= x2; x++)cnt[P(x, y)]++;
        }
    }
    ll mx = 0, num = 0;
    for(map<P, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        ll v = (*it).second;
        if(mx == v)num++;
        else if(mx < v){
            num = 1;
            mx = v;
        }
    }
    cout << mx << endl;
    cout << num << endl;

    return 0;
}