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
    vector<ll>v;
    ll p = 0, m = 0;
    rrep(i, s.size()){
        if(s[i] == '+')p++;
        if(s[i] == '-')m++;
        if(s[i] == 'M'){
            v.push_back(p - m);
        }
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++){
        if(i < v.size() / 2)ans -= v[i];
        else ans += v[i];
    }
    cout << ans << endl;

    return 0;
}