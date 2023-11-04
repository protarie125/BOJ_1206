#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n;
vector<int> pts;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	pts = vector<int>(n);
	for (auto i = 0; i < n; ++i) {
		string s;
		cin >> s;

		s = s.substr(0, s.length() - 4) + s.substr(s.length() - 3);

		pts[i] = stoi(s);
	}

	auto ans = 0;
	for (auto a = 1; a <= 1000; ++a) {
		const auto maxPt = a * 10;
		auto ct = 0;
		for (const auto& x : pts) {
			for (auto p = 0; p <= maxPt; ++p) {
				if (x == (1000 * p) / a) {
					++ct;
					break;
				}
			}
		}

		if (ct == pts.size()) {
			ans = a;
			break;
		}
	}

	cout << ans;

	return 0;
}