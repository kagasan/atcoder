#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    ll mn = min(A, min(B, min(C, min(D, E))));
    ll ans = N / mn + 5;
    if(N % mn == 0)ans--;
    cout << ans << endl;

    return 0;
}