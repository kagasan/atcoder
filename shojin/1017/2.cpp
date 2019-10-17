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

P p_plus(P a, P b){
    return P(a.first + b.first, a.second + b.second);
}
P p_minus(P a, P b){
    return P(a.first - b.first, a.second - b.second);
}

int main(){

    ll m;
    cin >> m;
    vector<P>s(m);
    rep(i, m){
        cin >> s[i].first >> s[i].second;
    }   
    ll n;
    cin >> n;
    vector<P>v(n);
    set<P>S;
    rep(i, n){
        cin >> v[i].first >> v[i].second;
        S.insert(v[i]);
    } 
    rep(i, n){
        P c = p_minus(v[i], s[0]);
        ll flg = 1;
        rep(j, m){
            P b = p_plus(s[j], c);
            if(S.find(b) == S.end()){
                flg = 0;
                break;
            }
        }
        if(flg){
            cout << c.first << " " << c.second << endl;
            break;
        }
    }

    return 0;
}