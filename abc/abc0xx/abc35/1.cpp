#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    
    ll W, H;
    cin >> W >> H;
    Say(W * 3 == H * 4, "4:3", "16:9");

    return 0;
}
