#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ifstream ifs("out.txt");

    ll N;
    ifs >> N;
    if(N == -1){
        cout << -1 << endl;
        return 0;
    }
    vector<ll>d(N);
    for(ll i = 0; i < N; i++)ifs >> d[i];
    for(string s;ifs >> s;){
        ll x = 0, y = 0;
        for(ll i = 0; i < s.size(); i++){
            if(s[i] == 'L')x -= d[i];
            if(s[i] == 'R')x += d[i];
            if(s[i] == 'D')y -= d[i];
            if(s[i] == 'U')y += d[i];
        }
        cout << x << ", " << y << endl;
    }

    return 0;
}
