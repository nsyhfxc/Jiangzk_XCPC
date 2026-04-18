#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int sex, hei, wei;
    cin >> sex >> hei >> wei;
    if (sex == 1) {
        //身高
        if (hei < 130) {
            cout << "duo chi yu!" << " ";
        } else if (hei == 130) {
            cout << "wan mei!" << " ";
        } else if (hei > 130) {
            cout << "ni li hai!" << " ";
        }
        //体重
        if (wei < 27) {
            cout << "duo chi rou!" << endl;
        } else if (wei == 27) {
            cout << "wan mei!" << endl;
        } else if (wei > 27) {
            cout << "shao chi rou!" << endl;
        }
    } else if (sex == 0) {
        //身高
        if (hei < 129) {
            cout << "duo chi yu!" << " ";
        } else if (hei == 129) {
            cout << "wan mei!" << " ";
        } else if (hei > 129) {
            cout << "ni li hai!" << " ";
        }
        //体重
        if (wei < 25) {
            cout << "duo chi rou!" << endl;
        } else if (wei == 25) {
            cout << "wan mei!" << endl;
        } else if (wei > 25) {
            cout << "shao chi rou!" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
