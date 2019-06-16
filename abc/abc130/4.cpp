#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>A(N + 1, 0), B(N + 1, 0);
    for(ll i = 1; i <= N; i++){
        cin >> A[i];
        B[i] = B[i - 1] + A[i];
    }
    ll ans = 0;
    ll l = N;
    for(ll r = N; r >= 1; r--){
        while(l > 0){
            if(B[r] - B[l] >= K)break;
            l--;
        }
        if(B[r] - B[l] >= K)ans += (l + 1);
    }

    cout << ans << endl;

    return 0;
}
