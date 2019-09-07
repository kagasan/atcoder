#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll f(ll N, ll x){
    if(x - 1 <= N)return x - 1;
    return x - 1 - 2 * (x - 1 - N);
}

int main(){
    
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for(ll A = 1; A * A <= K; A++){
        if(K % A)continue;
        ll B = K / A;
        ll tmp = max(0LL, f(N, A));
        tmp *= max(0LL, f(N, B));
        if(A == B)ans += tmp;
        else ans += 2 * tmp;
    }
    cout << ans << endl;

    return 0;
}