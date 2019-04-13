#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

// 1-indexed BIT
class BIT{
    public:
    vector<ll>bit;
    int N;
    void init(int n){
        N = n;
        bit = vector<ll>(N, 0);
    }
    // [1, n] = {}
    BIT(int n = 0){
        init(n);
    }
    // sum [1, i]
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, ll x){
        if(i == 0)return;
        while(i <= N){
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    ll N, K;
    cin >> N >> K;
    set<ll>S;
    S.insert(0);
    vector<ll>imos(N + 1, 0);
    for(int i = 1; i <= N; i++){
        ll A;
        cin >> A;
        // Kを引いて，和が非負の区間を数える問題にする
        ll B = A - K;
        imos[i] = imos[i - 1] + B;
        S.insert(imos[i]);
    }

    // 座標圧縮の気持ち
    map<ll, ll>M;
    int idx = 1;
    for(auto it = S.begin(); it != S.end(); it++){
        M[(*it)] = idx;
        idx++;
    }

    BIT bit(N + 2);
    bit.add(M[0], 1);
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        // 累積和の要素imos[i]について，
        // それより手前にあるimos[i]以下の数だけansを増やす
        ans += bit.sum(M[imos[i]]);
        bit.add(M[imos[i]], 1);
    }
    cout << ans << endl;

    return 0;
}