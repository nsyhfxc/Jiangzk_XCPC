#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    string s = "012345";
    string s2 = "123";
    string s3 = "678";
    string temp;
    int pos = s.find(s2);
    if(pos == string::npos) {
        cout << s << endl;
    } else {
        temp += s.substr(0, pos);
        temp += s3;
        for(int i = pos + s2.size(); i < s.size(); i++) {
            temp += s[i];
        }
        cout << temp << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
