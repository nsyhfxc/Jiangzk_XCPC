#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
int main() {
    i32 l,n;
    cin >> l >> n;
    i32 tot = pow(26, l);
    i32 tgt = tot - n;
    string result = "";
    for (int i = 0; i < l; ++i) {
        result += static_cast<char>('a' + (tgt % 26));
        tgt /= 26;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}
