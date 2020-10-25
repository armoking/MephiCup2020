#include<bits/stdc++.h> 

using namespace std;

void print(long long dlt) {
    if (dlt == 0) {
        cout << "0\n";
    } else {
        cout << dlt / abs(dlt) << '\n';
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x3 > x4) swap(x3, x4);
    if (y3 > y4) swap(y3, y4);
    
    if (x1 == x2 && x3 == x4) {
        int first = 0;
        if (a <= x1 && x1 <= b) {
            first = 1;
        }   
        int second = 0;
        if (a <= x3 && x3 <= b) {
            second = 1;
        }
        print(first - second);
    } else if (x1 == x2) {
        if (a <= x1 && x1 <= b) {
            print(1);
        } else {
            print(-1);
        }
    } else if (x3 == x4) {
        if (a <= x3 && x3 <= b) {
            print(-1);
        } else {
            print(1);
        }
    } else {
        int FirstX = x2 - x1;
        int FirstY = y2 - y1;
        int SecondX = x4 - x3;
        int SecondY = y4 - y3;
        print(-FirstX * 1ll * SecondY + SecondX * 1ll * FirstY);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
