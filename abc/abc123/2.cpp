#include "bits/stdc++.h"
using namespace std;

typedef long long ll;


int main(){

    int ans = 10000;
    int m[5];
    for(int i = 0; i < 5; i++)cin >> m[i];
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            if(b == a)continue;
            for(int c = 0; c < 5; c++){
                if(c == a)continue;
                if(c == b)continue;
                for(int d = 0; d < 5; d++){
                    if(d == a)continue;
                    if(d == b)continue;
                    if(d == c)continue;
                    for(int e = 0; e < 5; e++){
                        if(e == a)continue;
                        if(e == b)continue;
                        if(e == c)continue;
                        if(e == d)continue;
                        int tmp = 0;
                        tmp += m[a];
                        if(tmp % 10 != 0)tmp = 10 * (1 + tmp / 10);
                        tmp += m[b];
                        if(tmp % 10 != 0)tmp = 10 * (1 + tmp / 10);
                        tmp += m[c];
                        if(tmp % 10 != 0)tmp = 10 * (1 + tmp / 10);
                        tmp += m[d];
                        if(tmp % 10 != 0)tmp = 10 * (1 + tmp / 10);
                        tmp += m[e];
                        ans = min(ans, tmp);
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}