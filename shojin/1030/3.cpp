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

    queue<ll>Q;
    rep(i, K){
        ll a, b;
        cin >> a >> b;
        Q.push(a);
    }

    vector<ll>v(N + 1, 0);
    rep1(i, N)cin >> v[i];
    
    while(!Q.empty()){
        swap(v[Q.front()], v[Q.front() + 1]);
        Q.pop();
    }
    rep(i, N)rep(j, N)if(v[j] > v[j + 1]){
        swap(v[j], v[j + 1]);
        Q.push(j);
    }
    
    cout << Q.size() << endl;
    while(!Q.empty()){
        cout << Q.front() << " " << Q.front() + 1 << endl;
        Q.pop();
    }

    return 0;
}