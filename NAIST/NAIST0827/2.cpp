#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    ll A[111] = {};
    ll cnt[111] = {};
    ll ans = 1;
    for(ll i = 1; i <= N; i++)cin >> A[i];
    for(ll i = 1; i <= N; i++){
        if(A[i]){
            cnt[i] = cnt[i - 1] + 1;
            ans = max(ans, 1 + cnt[i]);
        }
        else cnt[i] = 0;
    }
    cout << ans << endl;
    
    return 0;    
}