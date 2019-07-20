#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    ll ans = 0, sum = 0;
    map<ll, ll>cnt;
    cnt[0] = 1;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        sum += a;
        if(cnt[sum - N])ans++;
        cnt[sum] = 1;
    }
    cout << ans << endl;

    return 0;
}