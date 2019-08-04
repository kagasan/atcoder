#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll R[101010][2];
ll L[101010][2];
ll ans[101010];

int main(){

    string s;
    cin >> s;
    ll N = s.size();
    s = "@" + s + "@";
    for(ll i = 1, p; i <= N; i++){
        if(s[i] == 'R')p = i;
        else R[p][(i - p) % 2]++;
    }
    for(ll i = N, p; i >= 1; i--){
        if(s[i] == 'L')p = i;
        else L[p][(p - i) % 2]++;
    }
    for(ll i = 1; i <= N; i++){
        ans[i] += R[i][0] + L[i][0];
        ans[i + 1] += R[i][1];
        ans[i - 1] += L[i][1];
    }
    for(ll i = 1; i <= N; i++){
        cout << ans[i];
        if(i == N)cout << endl;
        else cout << " ";
    }

    return 0;
}