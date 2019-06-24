#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};

int main(){

    ll N, L;
    cin >> N >> L;
    ll ans = 1145141919;
    ll SUM = 0;
    for(ll i = 1; i <= N; i++)SUM += (L + i - 1);
    for(ll i = 1; i <= N; i++){
        ll sum = 0;
        for(ll j = 1; j <= N; j++){
            if(i == j)continue;
            sum += (L + j - 1);
        }
        if(abs(SUM - ans) > abs(SUM - sum))ans = sum;
    }
    cout << ans << endl;

    return 0;
}