#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    for(int T, D, L; cin >> T >> D >> L, T;){
        int ans = 0;
        int lst = 0;
        for(int t = 1; t <= T; t++){
            int x;
            cin >> x;
            if(x < L)continue;
            int nxt = min(T, t + D);
            int diff = nxt - max(t, lst);
            ans += diff;
            lst = nxt;
        }
        cout << ans << endl;
    }

    return 0;
}