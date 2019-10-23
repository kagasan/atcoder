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

    string s;
    cin >> s;
    ll ans = 0;
    vector<P>v;
    v.push_back(P('K', 0));
    for(ll i = 0; i < s.size(); i++){
        if(v[v.size()-1].first == s[i])v[v.size()-1].second++;
        else v.push_back(P(s[i], 1));
    }
    for(ll i = 1; i + 1 < v.size(); i++){
        if(v[i - 1].first == 'J' && v[i].first == 'O' && v[i + 1].first == 'I'){
            if(v[i - 1].second >= v[i].second && v[i + 1].second >= v[i].second){
                chmax(ans, v[i].second);
            }
        }
    }
    cout << ans << endl;

    return 0;
}