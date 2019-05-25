#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll calcDamage(const string &p){
    ll sum = 0, e = 1;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == 'C')e *= 2;
        else sum += e;
    }
    return sum;
}
int update(string &p){
    for(int i = p.size() - 1; i > 0; i--){
        if(p[i - 1] == 'C' && p[i] == 'S'){
            p[i - 1] = 'S';
            p[i] = 'C';
            return 1;
        }
    }
    return -1145141919;
}

int main(){

    ll T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        ll D;
        string P;
        cin >> D >> P;
        int ans = 0;
        while(ans >= 0 && calcDamage(P) > D){
            ans += update(P);
        }
        cout << "Case #" << t << ": ";
        if(ans < 0)cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}