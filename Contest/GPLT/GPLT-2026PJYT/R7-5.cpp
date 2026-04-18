#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    string s;
    int n;
    cin >> s >> n;
    while (n--) {
        int start, end;
        string sb, sa;
        cin >> start >> end >> sb >> sa;
        int len = end - start + 1;
        string cut = s.substr(start - 1, len);
        s.erase(start - 1, len);
        string tgt = sb + sa;
        auto pos = s.find(tgt);
        if (pos != string::npos) {
            s.insert(pos + sb.length(), cut);
        } else {
            s.append(cut);
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
