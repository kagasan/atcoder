#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){
    
   string s;
   cin >> s;
   ll flg = 0;
   for(ll i = 2; i + 1 < s.size(); i++){
       ll f = 1;
       if(s[0] != 'A')f = 0;
       if(s[i] != 'C')f = 0;
       for(ll j = 1; j < s.size(); j++){
           if(i == j)continue;
           if('A' <= s[j] && s[j] <= 'Z')f = 0;
       }
       if(f)flg = 1;
   }
   if(flg)cout << "AC" << endl;
   else cout << "WA" << endl;
    
    return 0;
}