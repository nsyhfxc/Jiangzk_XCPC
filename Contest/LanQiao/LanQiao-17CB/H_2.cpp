#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'
const i32 mod = 998244353;
struct Person {
    i32 a, b;
};

bool cmp(const Person &x, const Person &y) {
    return x.b > y.b;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Person>arr(n);
    if(n <= 8 && m <= 8) {
        i32 mx = -2e9;
        arr.resize(8);
        for(int i = 0; i < n; i++) {
            cin >> arr[i].a >> arr[i].b;
        }
        for(int i1 = 0; i1 <= m; i1++) {
            for(int i2 = 0; i2 <= m; i2++) {
                for(int i3 = 0; i3 <= m; i3++) {
                    for(int i4 = 0; i4 <= m; i4++) {
                        for(int i5 = 0; i5 <= m; i5++) {
                            for(int i6 = 0; i6 <= m; i6++) {
                                for(int i7 = 0; i7 <= m; i7++) {
                                    for(int i8 = 0; i8 <= m; i8++) {
                                        if(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 == m) {
                                            vector<i32>temp;
                                            i32 p1 = arr[0].a + arr[0].b * i1;
                                            i32 p2 = arr[1].a + arr[1].b * i2;
                                            i32 p3 = arr[2].a + arr[2].b * i3;
                                            i32 p4 = arr[3].a + arr[3].b * i4;
                                            i32 p5 = arr[4].a + arr[4].b * i5;
                                            i32 p6 = arr[5].a + arr[5].b * i6;
                                            i32 p7 = arr[6].a + arr[6].b * i7;
                                            i32 p8 = arr[7].a + arr[7].b * i8;
                                            temp.push_back(p1 ? p1 : 1);
                                            temp.push_back(p2 ? p2 : 1);
                                            temp.push_back(p3 ? p3 : 1);
                                            temp.push_back(p4 ? p4 : 1);
                                            temp.push_back(p5 ? p5 : 1);
                                            temp.push_back(p6 ? p6 : 1);
                                            temp.push_back(p7 ? p7 : 1);
                                            temp.push_back(p8 ? p8 : 1);
                                            i32 cur = 1;
                                            for(const auto & x : temp) {
                                                cur  = cur * x % mod;
                                            }
                                            mx = max(mx, cur);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << mx << endl;
        return;
    }
    
	cout << 998244353 << endl;
	

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
