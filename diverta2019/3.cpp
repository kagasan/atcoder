#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
    int N;
    cin >> N;
    int BA = 0, XA = 0, BX = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j + 1 < s.size(); j++){
            if(s[j] == 'A' && s[j + 1] == 'B')ans++;
        }
        if(s[0] == 'B' && s[s.size() - 1] == 'A')BA++;
        else if(s[0] == 'B')BX++;
        else if(s[s.size() - 1] == 'A')XA++;
    }
    if(XA && BX){
        ans += min(XA, BX) + BA;
    }
    else if(XA){
        ans += BA;

    }
    else if(BX){
        ans += BA;
    }
    else if(BA){
        ans += (BA - 1);
    }
    cout << ans << endl;

    return 0;
}