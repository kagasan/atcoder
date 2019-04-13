#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    string s1 = s;
    string s2 = s;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(i&1){
            s1[i] = '1';
            s2[i] = '0';
        }
        else{
            s1[i] = '0';
            s2[i] = '1';
        }
        if(s[i] != s1[i])ans1++;
        if(s[i] != s2[i])ans2++;
    }
    cout << min(ans1, ans2) << endl;

    return 0;
}