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
    vector<string>v;
    rep(i, s.size()){
        if(s[i] == '*')v.push_back("+");
        else if(s[i] == '+')v.push_back("*");
        else if(v.empty())v.push_back(string(1, s[i]));
        else if(v[v.size() - 1] != "+" && v[v.size() - 1] != "*"){
            v[v.size() - 1] += s[i];
        }
        else{
            v.push_back(string(1, s[i]));
        }
    }
    ll ans = 0;
    for(ll i = 0; i < v.size(); i += 2){
        ll tmp;
        stringstream ss;
        ss << v[i];
        ss >> tmp;
        if(i == 0)ans = tmp;
        else if(v[i - 1] == "+")ans += tmp;
        else ans *= tmp;
    }
    cout << ans << endl;

    return 0;
}