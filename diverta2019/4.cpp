#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll check(ll A, ll C){
    ll B = A / C - 1;
    if(B == 0)return 0;
    if((A / B) == (A % B))return B;
    return 0;
}

int main(){

    ll N;
    cin >> N;
    ll ans = 0; 
    for(ll i = 1; i * i <= N; i++){
        if(N % i)continue;
        ans += check(N, i);
        if(N / i > i)ans += check(N, N / i);
    }
    cout << ans << endl;

    return 0;
}