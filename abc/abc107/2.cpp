#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){
    
    ll H, W;
    cin >> H >> W;
    vector<string>vec;
    string str(W, '.');
    for(ll y = 0; y < H; y++){
        string s;
        cin >> s;
        if(s != str)vec.push_back(s);
    }    
    vector<ll>flg(W, 0);
    for(ll x = 0; x < W; x++){
        for(ll y = 0; y < vec.size(); y++){
            if(vec[y][x] == '#')flg[x] = 1;
        }
    }
    for(ll y = 0; y < vec.size(); y++){
        for(ll x = 0; x < W; x++){
            if(flg[x])cout << vec[y][x];
        }
        cout << endl;
    }
    
    return 0;
}