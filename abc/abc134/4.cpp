#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    vector<ll>v(N + 1, 0);
    for(ll i = 1; i <= N; i++)cin >> v[i];
    vector<ll>ans(N + 1, 0);
    for(ll i = N; i >= 1; i--){
        ll tmp = v[i];
        for(ll j = i + i; j <= N; j += i)tmp ^= ans[j];
        ans[i] = tmp;
    }
    vector<ll>hoge;
    for(ll i = 1; i <= N; i++)if(ans[i])hoge.push_back(i);
    cout << hoge.size() << endl;
    if(hoge.size()){
        for(ll i = 0; i < hoge.size(); i++){
            if(i)cout << " ";
            cout << hoge[i];
        }
        cout << endl;
    }

    return 0;
}