#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

class Combination{
    private:
    vector<ll>fact, inv;
    ll mod;
    
    public:
    ll modpow(ll x, ll n){
        ll res = 1;
        while(n > 0){
            if(n & 1)res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    ll modinv(ll x){
        ll y = mod, u = 1, v = 0;
        while(y){
            ll t = x / y;
            x -= t * y; swap(x, y);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if(u < 0)u += mod;
        return u;
    }
    Combination(ll num, ll _mod = 1000000007){
        fact = vector<ll>(2 * num + 10);
        inv = vector<ll>(2 * num + 10);
        mod = _mod;
        fact[0] = 1;
        inv[0] = modinv(fact[0]);
        for(ll i = 1; i < fact.size(); i++){
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = modinv(fact[i]);
        }
    }
    ll factrial(ll n){
        return fact[n];
    }
    ll nPk(ll n, ll k){
        return fact[n] * inv[n - k] % mod;
    }
    ll nCk(ll n, ll k){
        return nPk(n, k) * inv[k] % mod;
    }
    ll nHk(ll n, ll k){
        return nCk(n+k-1, k);
    }
};

int main(){

    ll N, M, K;
    cin >> N >> M >> K;
    Combination cmb(N * M);
    ll ans = 0;
    for(ll x = 1; x < M; x++){
        ll tmp = x * (M - x) % MOD;
        tmp = tmp * N % MOD;
        tmp = tmp * N % MOD;
        tmp = tmp * cmb.nCk(N * M - 2, K - 2) % MOD;
        ans = (ans + tmp) % MOD;
    }
    for(ll y = 1; y < N; y++){
        ll tmp = y * (N - y) % MOD;
        tmp = tmp * M % MOD;
        tmp = tmp * M % MOD;
        tmp = tmp * cmb.nCk(N * M - 2, K - 2) % MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;
    return 0;
}