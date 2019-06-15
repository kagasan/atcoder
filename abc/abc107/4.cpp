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
    ll N;
    cin >> N;
    vector<ll>A(N), B(N + 1, 0);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    ll ng = 0, ok = N;
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        ll x = B[p];
        ll cnt = 0;
        ll sum = N + 5;
        BIT bit(N * 2 + 20);
        bit.add(sum, 1);
        for(ll i = 0; i < N; i++){
            if(A[i] <= x)sum++;
            else sum--;
            cnt += bit.sum(sum - 1);
            bit.add(sum, 1);
        }
        if(cnt > N * (N + 1) / 4)ok = p;
        else ng = p;
    }
    cout << B[ok] << endl;

    return 0;
}
