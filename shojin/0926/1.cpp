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

string solve(){
    string s;
    cin >> s;
    ll O = 0, X = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == 'O'){
            X = 0;
            O++;
            if(O == 3)return "East";
        }
        if(s[i] == 'X'){
            O = 0;
            X++;
            if(X == 3)return "West";
        }
    }
    return "NA";
}

int main(){

    cout << solve() << endl;

    return 0;
}