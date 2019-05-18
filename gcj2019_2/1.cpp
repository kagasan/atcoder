#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

typedef pair<ll, ll>P;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

ll C[333], J[333];

void solve(ll t){
    cout << "Case #" << t << ": ";
    ll N;
    cin >> N;
    set<P>S;
    for(ll i = 0; i < N; i++)cin >> C[i] >> J[i];
    for(ll i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ll A = J[j] - J[i];
            ll B = C[i] - C[j];
            if(A < 0 && B < 0){
                A = -A;
                B = -B;
            }
            if(A > 0 && B > 0){
                ll tmp = gcd(A, B);
                S.insert(P(A/ tmp, B / tmp));
            }
        }
    }
    cout << S.size() + 1 << endl;
}

int main(){

    ll T;
    cin >> T;
    for(ll t = 1; t <= T; t++){
        solve(t);
    }

    return 0;
}