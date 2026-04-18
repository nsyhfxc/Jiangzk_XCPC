#include<bits/stdc++.h>
using namespace std;
int a, b, ret;
// 单选1 结果为8
int func(int n) {
    if (n <= 1) {
        return 1;
    }
    a = b = 1;
    for (int i = 2; i <= n; i++) {
        ret = a + b;
        b = a;
        a = ret;
    }
    return ret;
}

int main() {
    cout << func(5) << endl;
}
