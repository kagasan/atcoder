# コピペで使えるテク


# テンプレ
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    return 0;
}
```

# string
## vectorみたいに宣言
```cpp
string s(10, '0');
cout << s << endl;
// 0000000000
```
## 一部だけ取り出す
i番目からn文字
```cpp
string s1 = "0123456789";
string s2 = s1.substr(2, 5);
cout << s2 << endl;
// 23456
```
## reverse
```cpp
string s = "01234";
reverse(s.begin(), s.end());
cout << s << endl;
// 43210
```
## to_string
```cpp
string s = to_string(-100);
cout << s << endl;
// -100
```

# vector
## 宣言
要素数, 初期値
```cpp
vector<int>vec(3, 0);
vec[1] = 1;
vec.push_back(-1);
for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
}
// 0
// 1
// 0
// -1
```

## sort
昇順
```cpp
vector<int>v;
v.push_back(2);
v.push_back(3);
v.push_back(1);
v.push_back(4);
sort(v.begin(), v.end());
for(int i = 0; i < v.size(); i++)cout << v[i];
// 1234
```
降順
```cpp
vector<int>v;
v.push_back(2);
v.push_back(3);
v.push_back(1);
v.push_back(4);
sort(v.begin(), v.end(), greater<int>());
for(int i = 0; i < v.size(); i++)cout << v[i];
// 4321
```

# set
重複した要素を許さないデータ構造  
内部ではソートされて保存される
## 宣言
## 挿入
## 検索
## 以上の最小
## 以下の最大
## 超過の最小
## 未満の最大
