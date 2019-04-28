#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

class RMQ{
    public:
    int N;
    ll MIN;
    vector<ll>dat;
    RMQ(int n, ll x){
        N = 1;
        while(N < n)N *= 2;
        dat = vector<ll>(2 * N);
        for(int i = 0; i < 2 * N - 1; i++)dat[i] = x;
        MIN = -1;
    }
    void update(int k, ll x){
        k += N - 1;
        dat[k] = x;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    // [a, b)
    ll query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l)return MIN;
        if(a <= l && r <= b)return dat[k];
        else{
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
    ll query(int a, int b){
        return query(a, b, 0, 0, N);
    }
};

void solve(int t){
    ll N, K;
    cin >> N >> K;
    RMQ C(N, 0), D(N, 0);
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        C.update(i, c);
    }
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        D.update(i, c);
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(abs(C.query(i, j + 1) - D.query(i, j + 1)) <= K)ans++;
        }
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }

    return 0;
}