#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for(ll b = 1; b <= N; b++){
        ans += max(0LL, (N / b) * (b - K));
        if(N % b)ans += max(0LL, (N % b) - max(0LL, K - 1LL));
    }
    cout << ans << endl;

    return 0;
}
