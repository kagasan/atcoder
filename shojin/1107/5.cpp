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

    ll N, x = 0 ,ans = 0, tmp = 0;
    cin >> N;
    vector<ll>v(N);    
    rep(i, N){
        cin >> v[i];
        x += v[i];
    }
    if(x % N){
        cout << -1 << endl;
        return 0;
    }
    x /= N;
    rep(i, N){
        tmp += v[i];
        if(tmp != (i + 1) * x)ans++;
    }
    cout << ans << endl;
    return 0;
}