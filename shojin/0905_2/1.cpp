#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll x = 0, y = 0;
    string s;
    cin >> s;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == 'N')y++;
        if(s[i] == 'S')y--;
        if(s[i] == 'W')x++;
        if(s[i] == 'E')x--;
    }
    printf("%.10f\n", hypot(x, y));

    return 0;
}