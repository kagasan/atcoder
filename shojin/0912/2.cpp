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

char R[555][555];
char B[555][555];

int main(){

    ll H, W;
    cin >> H >> W;
    rep(y, 555)rep(x, 555){
        R[y][x] = '.';
        B[y][x] = '.';
        if(y % 2)R[y][x] = '#';
        else B[y][x] = '#';
    }
    rep(y, 555){
        R[y][1] = '#';
        B[y][W] = '#';
        R[y][W] = '.';
        B[y][1] = '.';
    }
    rep1(y, H)rep1(x, W){
        char c;
        cin >> c;
        if(c == '.')continue;
        R[y][x] = '#';
        B[y][x] = '#';
    }
    rep1(y, H){
        rep1(x, W)cout << R[y][x];
        cout << endl;
    }
    cout << endl;
    rep1(y, H){
        rep1(x, W)cout << B[y][x];
        cout << endl;
    }

    return 0;
}