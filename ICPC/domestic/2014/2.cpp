#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    for(int h; cin >> h, h; ){
        int ans = 0;
        vector<string>vec(h, "XXXXX");
        for(int y = h - 1; y >= 0; y--){
            for(int x = 0; x < 5; x++){
                cin >> vec[y][x];
            }
        }
        for(;;){
            int tmp = 0;
            vector<string>flg = vec;
            for(int y = 0; y < h; y++){
                for(int x = 0; x < 3; x++){
                    if(vec[y][x] == vec[y][x + 1] && vec[y][x + 1] == vec[y][x + 2]){
                        flg[y][x] = 'F';
                        flg[y][x + 1] = 'F';
                        flg[y][x + 2] = 'F';
                    }
                }
            }
            for(int x = 0; x < 5; x++){
                queue<char>Q;
                for(int y = 0; y < h; y++){
                    if(flg[y][x] == 'F'){
                        tmp += vec[y][x] - '0';
                    }
                    else{
                        Q.push(vec[y][x]);
                    }
                }
                for(int y = 0; y < h; y++){
                    vec[y][x] = '0';
                    if(!Q.empty()){
                        vec[y][x] = Q.front();
                        Q.pop();
                    }
                }
            }
            if(tmp)ans += tmp;
            else break;
        }
        cout << ans << endl;
    }

    return 0;
}