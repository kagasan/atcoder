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

ll check(string s){
    for(ll i = 0; i < s.size(); i++){
        if(i % 2 == 0){
            if(' ' == s[i])return 0;
        }
        else{
            if(' ' != s[i])return 0;
        }
    }
    return 1;
}

int main(){

    string s;
    getline(cin, s);
    if(check(s))cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}