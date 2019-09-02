#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    string s, t;
    cin >> s >> t;
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++)if(s[i] == t[i])ans++;
    cout << ans << endl;

    return 0;
}