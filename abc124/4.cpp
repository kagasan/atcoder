#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    s += '2';
    vector<int>color;
    vector<int>length;
    for(int c = 1, l = 0, i = 0; i < s.size(); i++){
        if(s[i] - '0' != c){
            color.push_back(c);
            length.push_back(l);
            c = s[i] - '0';
            l = 0;
        }
        l++;
    }
    if(color[color.size() - 1] == 0){
        color.push_back(1);
        length.push_back(0);
    }
    int mx = 1 + 2 * K;
    // cout << "mx : " << mx << endl;
    // for(int i = 0; i < color.size(); i++){
    //     cout << color[i] << " : " << length[i] << endl;
    // }
    int ans = 0;
    for(int l = 0, r = 0, sum = length[0]; l < length.size(); ){
        while(r + 1 < length.size() && r + 1 - l + 1 <= mx){
            r++;
            sum+=length[r];
        }
        ans = max(ans, sum);
        sum -= length[l];
        l++;
        sum -= length[l];
        l++;
    }

    cout << ans << endl;

    return 0;
}