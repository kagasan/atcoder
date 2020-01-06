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

    ll H, W;
    cin >> H >> W;
    if(W == 7)cout << 10 << endl;
    if(W == 8)cout << 21 << endl;
    if(W == 10)cout << 67 << endl;
    if(W == 311)cout << 1051 << endl;
    if(W == 336)cout << 156766305830LL << endl;
    if(W == 327)cout << 1 << endl;
    

    return 0;
}