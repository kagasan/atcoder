文字列処理テクニック
# 切り出し
```cpp
string s = "01234567";
cout << s.substr(0, 2) << endl; //01
cout << s.substr(2, 3) << endl; //234
```

# find
```cpp
bool str_find(string a, string b){return a.find(b) != string::npos;}
```
# replace
```cpp
bool replace(string &str, const string &from, const string &to){
    ll pos = str.find(from);
    if(pos == string::npos)return false;
    str.replace(pos, from.size(), to);
    return true;
}
```
# KMP

# ロリハ

# 回文判定
```cpp
bool kaibun(string s){
    for(ll i = 0, j = s.size() - 1; i <= j; i++, j--){
        if(s[i] != s[j])return false;
    }
    return true;
}
```
# 検索
