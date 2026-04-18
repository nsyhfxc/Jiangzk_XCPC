#include<bits/stdc++.h>
using namespace std;

struct node {
    int num;
    int pcs;
    double val;
};

bool cmp(const node &a, const node &b) {
    if (a.val != b.val) {
        return a.val > b.val;
    }
    if (a.pcs != b.pcs) {
        return a.pcs > b.pcs;
    }
    return a.num < b.num;
}

int main() {
    int n;
    cin >> n;
    vector<node> arr(n + 1, {0, 0, 0});
    for (int i = 1; i <= n; i++) {
        double sum = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            arr[x].pcs++;
            arr[x].val += y;
            sum += y;
        }
        arr[i].val -= sum;
        arr[i].num = i;
    }
    sort(arr.begin() + 1, arr.end(), cmp);
    for (int i = 1; i <= n; i++) {
        printf("%d %.2lf\n", arr[i].num,arr[i].val / 100);
    }
    return 0;
}
