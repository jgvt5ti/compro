#include <bits/stdc++.h>
using namespace std;

int main() {
	constexpr int n = 1001;
	long double a[n];
	a[1] = 1;
	for (int i = 1; i < n - 1; i++) {
		a[i + 1] = a[i] + 1 / a[i];
	}
	cout << setprecision(10) << fixed << a[n - 1] - (n - 1) * sqrt(2) << endl;
}