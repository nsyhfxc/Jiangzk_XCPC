#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'
void solve() {
    u32 n, x, y;
    cin >> n >> x >> y;
    if(x == y) {
        cout << "1" << endl;
        return;
    } else if(x > y) {
        cout << "0" << endl;
        return;
    }else if(x < y){
    	cout << y - x + 1 << endl;
    	return;
	} 
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
