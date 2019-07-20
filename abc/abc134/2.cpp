#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N, D;
    cin >> N >> D;
    ll ans = 0;
    for(;N>0;ans++){
        N -= (2 * D + 1);
    }
    cout << ans << endl;

    return 0;
}