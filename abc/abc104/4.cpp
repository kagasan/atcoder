#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll tri[101010];

ll hoge(ll a, ll b, ll c, ll d){
    a = (a * b) % MOD;
    c = (c * d) % MOD;
    return (a * c) % MOD;
}

ll calc(ll A, ll L, ll C, ll R){
    ll tmp = 0;
    tmp = (tmp + hoge(A, C, tri[L], tri[R])) % MOD;
    if(R)tmp = (tmp + hoge(A, R, tri[L], tri[R - 1])) % MOD;
    if(L)tmp = (tmp + hoge(L, C, tri[L - 1], tri[R])) % MOD;
    if(L && R)tmp = (tmp + hoge(L, R, tri[L - 1], tri[R - 1])) % MOD;
    return tmp;
}

int main(){

    tri[0] = 1;
    for(ll i = 1; i < 101000; i++){
        tri[i] = tri[i - 1] * 3 % MOD;
    }

    string s;
    cin >> s;
    s = "@" + s + "@";
    ll sz = s.size();
    vector<ll>A(sz, 0);
    vector<ll>L(sz, 0);
    vector<ll>C(sz, 0);
    vector<ll>R(sz, 0);
    for(ll i = 1; i < s.size(); i++){
        A[i] = A[i - 1];
        L[i] = L[i - 1];
        if(s[i] == 'A')A[i]++;
        if(s[i] == '?')L[i]++;
    }
    for(ll i = s.size() - 2; i >= 0; i--){
        C[i] = C[i + 1];
        R[i] = R[i + 1];
        if(s[i] == 'C')C[i]++;
        if(s[i] == '?')R[i]++;
    }
    ll ans = 0;
    for(ll i = 1; i + 1 < s.size(); i++){
        if(s[i] == 'A' || s[i] == 'C')continue;
        ans = (ans + calc(A[i - 1], L[i - 1], C[i + 1], R[i + 1])) % MOD;
    }
    cout << ans << endl;

    return 0;
}
