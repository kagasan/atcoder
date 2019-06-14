#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    map<string, ll>cnt;
    ll N;
    cin >> N;
    string lst;
    cin >> lst;
    cnt[lst] = 1;
    ll flg = 1;
    for(ll i = 1; i < N; i++){
        string s;
        cin >> s;
        if(lst[lst.size() - 1] != s[0])flg = 0;
        if(cnt[s])flg = 0;
        cnt[s] = 1;
        lst = s;
    }
    if(flg)cout<<"Yes"<<endl;
    else cout << "No" << endl;

    return 0;
}