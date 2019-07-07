#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll L, R;
    cin >> L >> R;
    if(R - L >= 2020){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 2020;
    for(ll i = L; i <= R; i++){
        for(ll j = i + 1; j <= R; j++){
            ll tmp = (i % 2019) * (j % 2019) % 2019;
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}