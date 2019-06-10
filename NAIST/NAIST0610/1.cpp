#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    
    for(ll D, E; cin >> D >> E; ){
        if(D == 0)break;
        double ans = 19191919;
        for(ll x = 0; x <= D; x++){
            for(ll y = 0; y <= D; y++){
                if(x + y == D){
                    ans = min(ans, abs(hypot(x, y) - E));
                }
            }
        }
        printf("%.9f\n", ans);
    }
    
    return 0;    
}