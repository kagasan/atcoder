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

void solve(ll N, ll K){
    if(N == 0){
        cout << "J";
        return;
    }
    ll a = 1 << (N - 1);
    if(K <= a){
        for(ll i = 1; i <= a; i++)cout << "J";
        for(ll i = 1; i <= a; i++)cout << "O";
        return;
    }
    for(ll i = 1; i <= a; i++)cout << "I";
    solve(N - 1, K - a);
}

int main(){

    ll N, K;
    cin >> N >> K;
    solve(N, K);
    cout << endl;

    return 0;
}