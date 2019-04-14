#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    string s;
    cin >> s;

    // 現れる全ての文字は偶数個必要
    map<char, int>m;
    for(int i = 0; i < s.size(); i++)m[s[i]]++;
    for(int i = 0; i < s.size(); i++){
        if(m[s[i]] & 1){
            cout << 0 << endl;
            return 0;
        }
    }

    return 0;
}