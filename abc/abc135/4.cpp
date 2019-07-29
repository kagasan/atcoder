#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll dp[2][13] = {};
    dp[0][0] = 1;
    ll tmp = 1;
    for(ll i = 0; i < s.size(); i++){
        for(ll j = 0; j < 13; j++){
            for(ll k = 0; k < 10; k++){
                if(s[i] != '?' && s[i] != ('0' + k))continue;
                ll t = (k * tmp) % 13;
                ll nxt = (j + t) % 13;
                dp[1][nxt] = (dp[1][nxt] + dp[0][j]) % MOD;
            }
        }
        for(ll j = 0; j < 13; j++){
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
        tmp = (tmp * 10) % 13;
    }
    cout << dp[0][5] << endl;

    return 0;
}