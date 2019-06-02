#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int ok = 15;
    for(int i = 0; i < s.size(); i++)if(s[i] == 'x')ok--;
    if(ok >= 8)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
