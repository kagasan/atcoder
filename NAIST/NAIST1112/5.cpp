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

    ll N, M;
    cin >> N >> M;
    vector<ll>v(N);
    rep(i, N)cin >> v[i];
    sort(v.begin(), v.end());
    ll cnt = 0, len = 1, num = 1;
    queue<ll>Q;
    Q.push(v[0]);
    for(ll i = 1; i < N; i++){
        while(!Q.empty() && Q.front() < v[i] - M){
            cnt++;
            Q.pop();
        }
        num = num * (len + 1 - cnt) % MOD;
        // cout << i << " : " << num << " " << cnt << endl;
        len++;
        Q.push(v[i]);
    }
    cout << num << endl;

    return 0;
}