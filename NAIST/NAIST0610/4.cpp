#include "bits/stdc++.h"
using namespace std;
typedef long long ll;



int main(){
    
    for(string s; cin >> s;){
        if(s == "#")break;
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll mp[10][10] = {};
        ll w = 0, h = 1;
        for(ll i = 0, y = 0, x = 0; i < s.size(); i++){
            if(s[i] == '/'){
                w = x;
                x = 0;
                y++;
                h++;
                continue;
            }
            if(s[i] == 'b'){
                mp[y][x] = 1;
                x++;
                continue;
            }
            int step = s[i] - '0';
            x += step;
        }
        a--;
        b--;
        c--;
        d--;
        swap(mp[a][b], mp[c][d]);
        stringstream ss;
        for(ll y = 0; y < h; y++){
            if(y)ss<<"/";
            for(ll x = 0; x < w; x++){
                if(mp[y][x])ss << "b";
                else{
                    ll cnt = 0;
                    for(;;){
                        cnt++;
                        if(x+1==w)break;
                        if(mp[y][x+1])break;
                        x++;
                    }
                    ss << cnt;
                }
            }
        }
        cout << ss.str() << endl;
    }
    
    return 0;    
}