#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    
    string a = "WBWBWWBWBWBW";
    string str = a + a + a;
    string b[12] = {
        "Do", "Do#", "Re", "Re#", "Mi",
        "Fa", "Fa#", "So", "So#", "La", "La#", "Si"
    };
    string s;
    cin >> s;
    for(ll i = 0; i < 15; i++){
        ll f = 1;
        for(ll j = 0; j < s.size(); j++){
            if(s[j] != str[i + j])f = 0;
        }
        if(f){
            cout << b[i] << endl;
            return 0;
        }
    }
    
    return 0;
}
