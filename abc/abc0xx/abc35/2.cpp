#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    
    string s;
    cin >> s;
    ll x = 0, y = 0, cnt = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == 'L')x--;
        if(s[i] == 'R')x++;
        if(s[i] == 'U')y++;
        if(s[i] == 'D')y--;
        if(s[i] == '?')cnt++;
    }
    ll m = abs(x) + abs(y);
    ll T;
    cin >> T;
    if(T == 1){
        cout << m + cnt << endl;
    }
    else{
        for(ll i = 0; i < cnt; i++){
            if(m > 0)m--;
            else m++;
        }
        cout << m << endl;
    }
    return 0;
}
