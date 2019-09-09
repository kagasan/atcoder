#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll ans = 0;
    string s, t = "";
    cin >> s;
    for(ll i = 0; i < s.size(); i++)if(s[i] != '-')t += s[i];
    for(ll i = 0; i + 2 < t.size(); i++)if(t[i] == 'm' && t[i + 1] == 'i' && t[i + 2] == 'n')ans++;
    cout << ans << endl;

    return 0;
}