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

ll N, v[10101], ans = 0;
void solve(ll l, ll r){
    chmax(ans, r - l - 1);
    if(v[l] != v[r])return;
    if(v[l] == 0 || v[r] == 0)return;
    ll n_l = l, n_r = r;
    while(v[l] == v[n_l])n_l--;
    while(v[r] == v[n_r])n_r++;
    if((l - n_l) + (n_r - r) >= 4)solve(n_l, n_r);
}

int main(){

    cin >> N;
    rep1(i, N)cin >> v[i];
    rep1(i, N){
        ll tmp = v[i];
        rep1(j, 3){
            v[i] = j;
            solve(i - 1, i);
            solve(i, i + 1);
        }
        v[i] = tmp;
    }
    cout << N - ans << endl;

    return 0;
}