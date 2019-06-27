#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    s = "#" + s;

    for(char c = 'a'; c <= 'z'; c++){
        ll mnV = 101010;
        ll mnIdx = 101010;
        vector<ll>tmp(101010, 0);
        for(ll i = 1; i < s.size(); i++){
            if(s[i] == c)tmp[i] = tmp[i - 1] + 1;
            else tmp[i] = tmp[i - 1] - 1;
            if(mnV < tmp[i]){
                cout << mnIdx << " " << i << endl;
                return 0;
            }
            if(mnV > tmp[i - 1]){
                mnV = tmp[i - 1];
                mnIdx = i;
            }
        }
    }

    cout << "-1 -1" << std::endl;
    
    return 0;
}
