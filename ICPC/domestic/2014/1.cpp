#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int calc(int p, int x){
    return p * (100 + x) / 100;
}

int main(){

    for(int x, y, s; cin >> x >> y >> s, x;){
        int ans = 0;
        for(int a = 1; a <= 1000; a++){
            for(int b = 1; b <= 1000; b++){
                if(calc(a, x) + calc(b, x) == s){
                    ans = max(ans, calc(a, y) + calc(b, y));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}