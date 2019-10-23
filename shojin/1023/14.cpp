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

    ll N, K;
    cin >> N >> K;
    ll ans = N;
    ll lst;
    cin >> lst;
    priority_queue<ll>Q;
    for(ll i = 1; i < N; i++){
        ll x;
        cin >> x;
        Q.push(x - (lst + 1));
        lst = x;
    }
    K--;
    for(ll i = 0; i < K && !Q.empty(); i++){
        Q.pop();
    }
    while(!Q.empty()){
        ans += Q.top();
        Q.pop();
    }
    cout << ans << endl;

    return 0;
}