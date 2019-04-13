#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

//0-indexed RMQ
class RMQ{
    public:
    int N;
    ll MAX;
    vector<ll>dat;
    RMQ(int n, ll x){
        N = 1;
        while(N < n)N *= 2;
        dat = vector<ll>(2 * N);
        for(int i = 0; i < 2 * N - 1; i++)dat[i] = x;
        MAX = (1ll) << 62;
    }
    void update(int k, ll x){
        k += N - 1;
        dat[k] = x;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    // [a, b)
    ll query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l)return MAX;
        if(a <= l && r <= b)return dat[k];
        else{
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    ll query(int a, int b){
        return query(a, b, 0, 0, N);
    }
};

int main(){

    int N, K;
    cin >> N >> K;
    RMQ rmq(N, 0);
    for(int i = 0; i < N; i++){
        ll A;
        cin >> A;
        rmq.update(i, A);
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        int l = max(0, i - K);
        int r = i;
        ans += rmq.query(l, r);
    }
    cout << ans << endl;
    
    return 0;
}