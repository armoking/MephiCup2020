#include<bits/stdc++.h> 
#define all(x) begin(x),end(x)
#define make_unique(x) sort(all(x)); x.erase(unique(all(x)), end(x))

using namespace std;


const int T_LIFE = 100;
const int T_SPACE = 1000;

bool dp[1 << 8][T_LIFE + 1][T_SPACE + 1];
int precalc[1 << 8][T_SPACE + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j <= T_SPACE; j++) {
            precalc[i][j] = -1;
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> indexes;
        int x_start = 0;
        int y_start = 0;
        for (int i = 0; i < n; i++) {
            if (((mask >> i) & 1) == 1) {
                x_start++;
                y_start += a[i];
                indexes.push_back(i);
            }
        }
        if (y_start > T_SPACE) {
			continue;
		}
        dp[mask][x_start][y_start] = true;
        for (int i : indexes) {
            for (int x = 0; x <= T_LIFE; x++) { 
                for (int y = 0; y <= T_SPACE; y++) {
                    int nx = x + 1;
                    int ny = y + a[i];
                    if (nx <= T_LIFE && ny <= T_SPACE) {
                        dp[mask][nx][ny] |= dp[mask][x][y];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int x = 0; x <= T_LIFE; x++) {
            for (int y = x; y <= T_SPACE; y++) {
                if (dp[mask][x][y] && precalc[mask][y-x] == -1) {
                    precalc[mask][y - x] = x;
                }
            }
        }
    }
    
    int tmp = (1 << n) - 1;
    int cnt = 0;
    for (int x1 = 1; x1 <= T_LIFE; x1++) {
        for (int y1 = x1; y1 <= T_SPACE; y1++) {
            for (int mask1 = 0; mask1 < (1 << n); mask1++) {
                if (dp[mask1][x1][y1]) { 
                    int mask2 = tmp ^ mask1;
                    int dlt = y1 - x1;
                    int x2 = precalc[mask2][dlt];
                    if (x2 != -1) {
                        int y2 = x2 + y1 - x1;
                        if (x1 >= x2 && y1 >= y2) {
                            cout << x1 << ' ' << y1 << '\n';
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (cnt == 0) {
        cout << -1 << '\n';
    }
}
