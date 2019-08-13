#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    ll ans = 0;
    map<string, ll>cnt;
    for(ll i = 0; i < N; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans += cnt[s];
        cnt[s]++;
    }
    cout << ans << endl;

    return 0;
}