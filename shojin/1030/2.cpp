#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1234567;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>v(N + 1, 0), w(N + 1, 0);
    rep1(i, N)v[i] = i;
    rep(i, K){
        ll x, y;
        cin >> x >> y;
        swap(v[x], v[y]);
    }
    rep1(i, N){
        ll x;
        cin >> x;
        rep1(j, N)if(v[j] == i)w[j] = x;
    }
    queue<ll>Q;
    rep(i, N)for(ll i = 1; i < N; i++)if(w[i] > w[i + 1]){
        swap(w[i], w[i + 1]);
        Q.push(i);
    }
    cout << Q.size() << endl;
    while(!Q.empty()){
        ll q = Q.front();
        Q.pop();
        cout << q << " " << q + 1 << endl;
    }
    return 0;
}