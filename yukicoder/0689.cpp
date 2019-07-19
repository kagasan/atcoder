#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

vector<ll>ans;
void out(){
    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i + 1 == ans.size())cout << endl;
        else cout << " ";
    }
}

int main(){
    
    ll K;
    cin >> K;
    ll I = 1;
    for(;;){
        ll tmp = I + 1;
        if(tmp * (tmp - 1) / 2 > K)break;
        I++;
    }
    for(ll i = 0; i < I; i++)ans.push_back(1);
    K -= I * (I - 1) / 2;
    if(K >= 100){
        for(ll i = 0; i < 10; i++)ans.push_back(8);
        for(ll i = 0; i < 10; i++)ans.push_back(9);
        K -= 100;
    }
    ans.push_back(13);
    for(;K;K--)ans.push_back(24);

    out();
    return 0;
}