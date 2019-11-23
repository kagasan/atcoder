#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

string str(P p){
    stringstream ss;
    ss << p.first << ", " << p.second;
    return ss.str();
}

P ab[10][10];
P hoge[10][70];
P add(P A, P B){
    return P(A.first + B.first + ab[A.second][B.second].first, ab[A.second][B.second].second);
}

void init(){
    rep(a, 10)rep(b, 10){
        if(a + b <= 9)ab[a][b] = P(1, a + b);
        else ab[a][b] = P(2, (a + b - 9));
    }
    rep(a, 10)hoge[a][0] = P(0, a);
    rep1(i, 68){
        rep(a, 10){
            hoge[a][i] = add(hoge[a][i - 1], hoge[a][i - 1]);
        }
    }
}

P calc(ll a, ll b){
    P tmp(0, 0);
    ll flg = 1;
    for(ll i = 0; b; i++){
        if((1LL << i) & b){
            if(flg){
                flg = 0;
                tmp = hoge[a][i];
            }
            else tmp = add(tmp, hoge[a][i]);
            b ^= (1LL << i);
        }
    }
    return tmp;
}

int main(){
    init();
    // rep(i, 10)cout << i << " : " << str(calc(9, i)) << endl;
    // cout << str(calc(9, 100)) << endl;
    // cout << str(calc(9, 10000)) << endl;
    // cout << str(calc(9, 1000000000LL)) << endl;
    // cout << str(calc(9, 10000000000LL)) << endl;
    // cout << str(calc(9, 100000000000LL)) << endl;
    // cout << str(calc(9, 1000000000000LL)) << endl;
    // cout << str(calc(9, 1000000000000000LL)) << endl;
    // return 0;
    ll M;
    cin >> M;
    P tmp(0, 0);
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        if(i == 0)tmp = calc(a, b);
        else tmp = add(tmp, calc(a, b));
    }
    cout << tmp.first << endl;


    return 0;
}