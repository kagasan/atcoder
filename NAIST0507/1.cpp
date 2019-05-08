#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int func(int x, int p){
    return x * (100 + p) / 100;
}

int main(){

    for(int x, y, s; cin >> x >> y >> s, x;){
        int ans = 0;
        for(int a = 1; a <= 1000; a++){
            for(int b = 1; b <= 1000; b++){
                if(func(a, x) + func(b, x) == s){
                    ans = max(ans, func(a, y) + func(b, y));
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}