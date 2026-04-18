#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int nA, nB; //A,B酒量
    cin >> nA >> nB;
    int sA = nA,sB = nB;
    int n;
    cin >> n;
    int Ahan, Ahua, Bhan, Bhua;
    while (nA >= 0 && nB >= 0 && n--) {
        cin >> Ahan >> Ahua >> Bhan >> Bhua;
        int A = Ahua - Ahan - Bhan;
        int B = Bhua - Bhan - Ahan;
        if (A == 0 && B != 0) {
            nA--;
        } else if (A != 0 && B == 0) {
            nB--;
        }
    }
    if(nA < 0) {
        cout << "A" << endl << sB - nB;
    }
    else if(nB < 0) {
        cout << "B" << endl << sA - nA;
    }
    return 0;
}
