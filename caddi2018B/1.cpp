#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++)if(s[i] == '2')ans++;
    cout << ans << endl;

    return 0;
}