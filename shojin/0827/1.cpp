#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll parse(string s){
    ll h = 0, m = 0;
    for(ll i = 0, j = 0; i < s.size(); i++){
        if(s[i] == ':')j++;
        else if(j == 0)h = (h * 10) + (s[i] - '0');
        else m = (m * 10) + (s[i] - '0');
    }
    return m + h * 60;
}

int main(){

    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        string S, s;
        cin >> S;
        cin >> s;
        ll a = parse(S);
        ll b = parse(s);
        if(a > b)b += 24 * 60;
        ans += (b - a);
    }
    cout << ans << endl;

    return 0;
}