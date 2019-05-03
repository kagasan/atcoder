# 組み合わせ色々
## 並び替え
N種の要素を並び替えてできる全通り．
N! = N * (N - 1) * ... * 2 * 1
```
N = 4の時は4!で24通り
0123
0132
0213
0231
0312
0321
1023
1032
1203
1230
1302
1320
2013
2031
2103
2130
2301
2310
3012
3021
3102
3120
3201
3210
```
↑のを出力するコード
```cpp
// 全通りを調べる
vector<int>v = {0, 1, 2, 3};
do{
    for(int i = 0; i < 4; i++)cout << v[i];
    cout << endl;
}while(next_permutation(v.begin(), v.end()));
```
階乗を一気に求める
```cpp
class Factorial{
    public:
    vector<ll>f;
    ll mod;
    Factorial(ll n, ll mod = 1000000007){
        f = vector<ll>(n + 1);
        f[0] = 1;
        for(ll i = 1; i <= n; i++){
            f[i] = f[i - 1] * i % mod;
        }
    }
    ll value(ll idx){
        return f[idx];
    }
};
Factorial fact(5);
for(int i = 0; i <= 5; i++){
    cout << i << " : " << fact.value(i) << endl;
}
// 0 : 1
// 1 : 1
// 2 : 2
// 3 : 6
// 4 : 24
// 5 : 120
```

## 順列
n種の要素からk個の要素を取り出して並べる全通り  
nPk = n! / (n - k)!  
後ろn-k個分を打ち消すイメージ．
```
4P2 = 24 / 2 = 12
01
02
03
10
12
13
20
21
23
30
31
32
```

## 組み合わせ
n種の要素からk個の要素を取り出して並びを気にしない全通り  
nCk = nPk / k! = n! / (n - k)! / k!  
前k個分の並びを打ち消すイメージ
```
4C2 = 24 / 2 / 2 = 6
01
02
03
12
13
23
```

## 重複組み合わせ
n種の要素からk個の要素を取り出して並びを気にしない全通り  
ただし，同じ要素を複数回取り出せる  
nHk = (n + k - 1)! / k! / (n - 1)!
```
4H2 = (4 + 2 - 1)! / 2! / (4 - 1)!  
= 5! / 2! / 3! = 120 / 2 / 6 = 10
00
01
02
03
11
12
13
22
23
33
```

## 実装
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

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
    
    Combination cmb(10);
    cout << cmb.factrial(4) << endl;
    cout << cmb.nPk(4, 2) << endl;
    cout << cmb.nCk(4, 2) << endl;
    cout << cmb.nHk(4, 2) << endl;

    return 0;
}
// 24
// 12
// 6
// 10
```