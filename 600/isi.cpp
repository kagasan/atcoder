#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll H, W, A, B;
char mp[200][200];

int main(){
    
    cin >> H >> W >> A >> B;
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            cin >> mp[y][x];
        }
    }
    vector<ll>cnt(6, 0);
    for(int y = 0; ; y++){
        int y2 = H - 1 - y;
        if(y > y2)break;
        for(int x = 0; ; x++){
            int x2 = W - 1 - x;
            if(x > x2)break;
            int bit = 0;
            if(mp[y][x] == 'S')bit += 1;
            if(mp[y][x2] == 'S')bit += 2;
            if(mp[y2][x] == 'S')bit += 4;
            if(mp[y2][x2] == 'S')bit += 8;
            if(bit == 0)cnt[0]++;
            if(bit == 1 || bit == 2 || bit == 4 || bit == 6 || bit == 8 || bit == 9)cnt[1]++;
            if(bit == 3 || bit == 12)cnt[2]++;
            if(bit == 5 || bit == 10)cnt[3]++;
            if(bit == 7 || bit == 11 || bit == 13 || bit == 14)cnt[4]++;
            if(bit == 15)cnt[5]++;
        }
    }
    ll ans = 0;
    vector<ll>v;
    v = cnt;
    for(ll tmp = 0; v[0] * 4 < H * W; ){
        if(v[1]){
            v[0]++;
            v[1]--;
        }
        else if(v[2]){
            v[0]++;
            v[2]--;
        }
        else if(v[4]){
            v[3]++;
            v[4]--;
        }
        else if(v[3]){
            v[0]++;
            v[3]--;
        }
        else{
            tmp += v[5] * (max(A, B) + (A + B));            
            ans = max(ans, tmp);
            break;
        }
        if(v[1] == 0 && v[2] == 0 && v[4] == 0)tmp += A;
        if(v[1] == 0 && v[3] == 0 && v[4] == 0)tmp += B;
        ans = max(ans, tmp);
    }
    v = cnt;
    for(ll tmp = 0; v[0] * 4 < H * W; ){
        if(v[1]){
            v[0]++;
            v[1]--;
        }
        else if(v[3]){
            v[0]++;
            v[3]--;
        }
        else if(v[4]){
            v[2]++;
            v[4]--;
        }
        else if(v[2]){
            v[0]++;
            v[2]--;
        }
        else{
            tmp += v[5] * (max(A, B) + (A + B));
            ans = max(ans, tmp);
            break;            
        }
        if(v[1] == 0 && v[2] == 0 && v[4] == 0)tmp += A;
        if(v[1] == 0 && v[3] == 0 && v[4] == 0)tmp += B;
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}