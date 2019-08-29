#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll hoge[10101] = {1, 1};
ll pri[10101];
vector<ll>v;

int main(){
    for(ll i = 2; i < 10101; i++)pri[i] = 1;
    for(ll i = 2; i * i < 10101; i++){
        for(ll j = i + i; j < 10101; j += i)pri[j] = 0;
    }
    for(ll i = 2; i < 10101; i++){
        if(pri[i])v.push_back(i);
    }    
    for(ll i = 4; i <= 10000; i++){
        for(ll j = 0; j < v.size(); j++){
            ll pre = i - v[j];
            if(pre < 0)break;
            if(hoge[pre] == 0){
                hoge[i] = 1;
            }
        }
    }
    ll N;
    cin >> N;
    Say(hoge[N], "Win", "Lose");

    return 0;
}