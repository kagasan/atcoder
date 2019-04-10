#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

typedef pair<ll, ll> Pr;

void solve(int t){
    ll R, B, C;
    cin >> R >> B >> C;
    vector<ll>M(C), S(C), P(C);
    vector<Pr>vec;
    for(int i = 0; i < C; i++){
        cin >> M[i] >> S[i] >> P[i];
        vec.push_back(Pr(M[i], i));
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    ll ng = 0, ok = 0;
    for(ll i = 0, b = B; b > 0; i++){
        ll idx = vec[i].second;
        ll N = min(b, M[idx]);
        b -= N;
        ok = max(ok, S[idx] * N + P[idx]);
    }
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        vector<ll>cap;
        for(int i = 0; i < C; i++){
            cap.push_back(min(M[i], (p - P[i])/ S[i]));
        }
        sort(cap.begin(), cap.end());
        reverse(cap.begin(), cap.end());
        ll cnt = 0;
        for(int i = 0; i < R; i++){
            if(cap[i] < 0)continue;
            cnt += cap[i];
        }
        if(cnt >= B)ok = p;
        else ng = p;
    }
    cout << "Case #" << t << ": " << ok << endl;
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }

    return 0;
}