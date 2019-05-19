#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        char c;
        cin >> c;
        if(i != K)cout << c;
        else cout << char(c - 'A' + 'a');
    }
    cout << endl;

    return 0;
}