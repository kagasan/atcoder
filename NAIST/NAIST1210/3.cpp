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

ll solve(string s){
    ll ret = 0;
    for(ll i = 0, j = 0; i < s.size(); i++){
        if(s[i] == 'o')j++;
        else j = 0;
        chmax(ret, j);
    }
    return ret;
}

int main(){

    ll D;
    cin >> D;
    string s = "";
    rep(i, 20)s += "x";
    rep(i, 2){
        string t;
        cin >> t;
        s += t;
    }
    rep(i, 20)s += "x";
    ll ans = solve(s);
    rep(i, s.size()){
        string t = s;
        for(ll j = 0; j < D; j++){
            if(i + j >= t.size())break;
            if(t[i + j] == 'o')break;
            t[i + j] = 'o';
        }
        chmax(ans, solve(t));
    }

    cout << ans << endl;

    return 0;
}