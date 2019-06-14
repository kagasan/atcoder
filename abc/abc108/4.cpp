#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<ll>F, T, W;
ll N;
void push(ll f, ll t, ll w){
    F.push_back(f);
    T.push_back(t);
    W.push_back(w);
}
void show(){
    cout << N << " " << F.size() << endl;
    for(ll i = 0; i < F.size(); i++){
        cout << F[i] << " " << T[i] << " " << W[i] << endl;
    }
}

int main(){

    ll L;
    cin >> L;
    ll mx[22] = {};
    for(ll i = 2; i <= 21; i++){
        mx[i] = (1LL << (i - 1)) - 1;
    }
    for(N = 1; ;N++)if(mx[N + 1] >= L)break;
    for(ll i = 1; i < N; i++){
        push(i, i + 1, 0);
        push(i, i + 1, 1 << (i - 1));
    }
    for(ll i = mx[N] + 1; i < L; i++){
        ll sz = L - i;
        ll from = 1;
        for(;;from++)if(i + mx[from + 1] >= L)break;
        push(from, N, i);
        i += mx[from];
    }
    show();
    
    return 0;
}
