#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, x, y, a[N], k;
map<int, int> cnt;
bool first;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) //所有物品从1到n编号
    {
        scanf("%d", &x); //藏物品的数量
        a[i] = x;
    }
    cin >> k;
    while (k--) {
        cnt.clear();
        while (scanf("%d", &y), y) //物品的编号
        {
            cnt[a[y]]++; //物品的编号的个数
        }
        first = 1; // 第一个
        for (auto c: cnt) {
            if (first) //
            {
                cout << "B" << c.first << "-" << c.second;
                first = 0;
            } else cout << " " << "B" << c.first << "-" << c.second;
        }
        cout << endl;
    }
    return 0;
}
