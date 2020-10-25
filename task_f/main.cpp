#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

void solve(string filename, vector<vector<ll>>& arr) {
	auto out = freopen((filename + ".a").c_str(), "w", stdout);
	for (auto& a : arr) {
		int n = a.size();
		vector<ll> pref = a;
		vector<ll> suff = a;
		for (int i = 1; i < n; i++) {
			pref[i] += pref[i - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			suff[i] += suff[i + 1];
		}
		ll ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans += pref[i - 1] * a[i] * suff[i + 1];
		}
		cout << ans << '\n';
	}
	fflush(out);
	fclose(out);
}


vector<vector<ll>> gen(int n, int l, int r, int tot) {
	int sz = tot / n;
	vector<vector<ll>> ans;
	for (int i = 0; i < sz; i++) {
		vector<ll> cur;
		for (int i = 0; i < n; i++) {
			int x = rand() % (r - l + 1);
			cur.push_back(x + l);
		}
		ans.push_back(cur);
	}
	
	return ans;
}


int main() {
    vector<vector<vector<ll>>> tests = {
		{
			{1LL, 1LL, 1LL},
			{1LL, 1LL, 1LL, 1LL, 1LL},
			{9LL, 8LL, 7LL},
			{1LL, 2LL, 3LL, 4LL, 5LL}
		}
	};
	// N / 2 * A * N / 2 * A * A * N
	// N^3 * A^3
	while (tests.size() < 100) {
		tests.push_back(gen(1e3, 0, 1e3, 2e6));
	}
	for (int i = 0; i < int(tests.size()); i++) {
		string test_number = to_string(i);
		while (test_number.size() < 2) test_number = "0" + test_number;
		
		auto out = freopen((test_number).c_str(), "w", stdout);
		cout << tests[i].size() << '\n';
		for (auto& v : tests[i]) {
			cout << v.size() << '\n';
			for (auto val : v) {
				cout << val << ' ';
			}
			cout << '\n';
		}
		fflush(out);
		fclose(out);
		
		solve(test_number, tests[i]);
	}
}
