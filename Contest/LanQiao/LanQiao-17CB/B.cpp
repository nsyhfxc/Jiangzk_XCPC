#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'
i32 ksm(i32 a,i32 b,i32 p){
	i32 res = 1;
	while(b){
		if(b & 1){
			res = res * a % p;
		}
		a = a * a % p;
		b >>= 1; 
	}
	return res;
} 
void solve() {
	i32 x = 2;
	i32 y = 2026;
	const i32 mod = 998244353;
	cout << ksm(x,y,mod) - 1 << endl;
	return;
	// ans : 724090443 
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
