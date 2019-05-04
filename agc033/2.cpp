#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll H, W, N;
ll sr, sc;
string S, T;

int main(){
    cin >> H >> W >> N;
    cin >> sr >> sc;
    cin >> S;
    cin >> T;
    string ans = "YES";
    ll l = 1, r = W + 1;
    for(int i = N - 1; i >= 0; i--){
        if(T[i] == 'L')r = min(r + 1, W + 1);
        if(T[i] == 'R')l = max(l - 1, 1LL);
        if(S[i] == 'L')l = min(l + 1, W + 1);
        if(S[i] == 'R')r = max(r - 1, 1LL);
        if(r == l)ans = "NO";
    }
    if(sc < l || r <= sc)ans = "NO";
    ll u = 1, d = H + 1;
    for(int i = N - 1; i >= 0; i--){
        if(T[i] == 'U')d = min(d + 1, H + 1);
        if(T[i] == 'D')u = max(u - 1, 1LL);
        if(S[i] == 'U')u = min(u + 1, H + 1);
        if(S[i] == 'D')d = max(d - 1, 1LL);
        if(u == d)ans = "NO";
    }
    if(sr < u || d <= sr)ans = "NO";

    cout << ans << endl;

    return 0;
}
