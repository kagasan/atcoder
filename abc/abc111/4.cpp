#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll XYtoU(ll x, ll y){return x + y;};
ll XYtoV(ll x, ll y){return x - y;};

string s[4] = {"L", "R", "D", "U"};
ll du[4] = {-1, 1, -1, 1};
ll dv[4] = {-1, 1, 1, -1};

int main(){

    ll N;
    cin >> N;
    vector<ll>X(N), Y(N), U(N), V(N);
    ll flg = 0;
    for(ll i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
        U[i] = XYtoU(X[i], Y[i]);
        V[i] = XYtoV(X[i], Y[i]);
        if(abs(X[i] + Y[i]) % 2)flg |= 1;
        else flg |= 2;
    }
    if(flg == 3){
        cout << -1 << endl;
        return 0;
    }
    if(flg == 1){
        cout << 35 << endl;
        for(ll i = 34; i >= 0; i--){
            ll d = (1LL << i);
            cout << d;
            if(i == 0)cout << endl;
            else cout << " ";
        }
    }
    else{
        cout << 36 << endl;
        for(ll i = 34; i >= 0; i--){
            ll d = (1LL << i);
            cout << d << " ";
        }
        cout << 1 << endl;
    }
    for(ll i = 0; i < N; i++){
        if(flg == 2){
            U[i] = XYtoU(X[i] + 1, Y[i]);
            V[i] = XYtoV(X[i] + 1, Y[i]);
        }
        ll u = 0, v = 0;
        string ans = "";
        for(ll j = 34; j >= 0; j--){
            ll d = (1LL << j);
            ll k = 0;
            if(u < U[i] && v < V[i])k = 1;
            if(u > U[i] && v < V[i])k = 2;
            if(u < U[i] && v > V[i])k = 3;
            ans += s[k];
            u += d * du[k];
            v += d * dv[k];
        }
        if(flg == 2)ans += "L";
        cout << ans << endl;
    }
    return 0;
}

/*
u = x + y
v = x - y

(x, y) -> (u, v)
L : -d, 0 -> -d, -d
R : +d, 0 -> +d, +d
D : 0, -d -> -d, +d
U : 0, +d -> +d, -d
*/