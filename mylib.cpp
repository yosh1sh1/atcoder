#include <bits/stdc++.h>

#define MAX_NCR_SIZE 100

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

using namespace std;

/* global */
const int MOD = 1e9 + 7;
const int MAX = 510000;
int nCr[MAX_NCR_SIZE][MAX_NCR_SIZE];
ll fac[MAX], finv[MAX], inv[MAX];

/* greatest common divisor */
template <typename T> // ll or int
T gcd(T x, T y) {
	T mod = x % y;
	if (mod == 0)
		return y;
	else
		return gcd(y, mod);
}

/*
	template <>
	float gcd(float x, float y) {
	return (float)lcm<ll>((ll)x, (ll)y);
	}
	template <>
	double gcd(double x, double y) {
	return (double)lcm<ll>((ll)x, (ll)y);
	}
*/

/* least common multiple */
template <typename T> // ll or int
T lcm(T x, T y) {
	T res = 0;
	T gcd_v = gcd(x, y);

	res = x / gcd_v * y;

	return res;
}

void comb_in_g(int n, int k)
{
	/* globalの配列に格納 */

	if (n > MAX_NCR_SIZE)
		n = MAX_NCR_SIZE - 1;
	if (k > MAX_NCR_SIZE)
		k = MAX_NCR_SIZE - 1;

	rep (i, 0, n + 1) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
	}

	rep (j, 1, n + 1) {
		rep (k, 1, j) {
			nCr[j][k] = (nCr[j - 1][k - 1] + nCr[j - 1][k]);
		}
	}
}

/* 組合せ */
ll comb(ll n, ll k)
{
	if (n < k || n < 0 || k < 0)
		return -1;

	ll res = 1;
	for (ll i = 1; i <= k; i++) {
		res *= n--;
		res /= i;
	}

	return res;
}


// nCr inv
// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// a^n mod
ll modpow(ll a, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}

	return res;
}

class UnionFind {
public:
	vector<int> tree;

	UnionFind(int n) : tree(n) {
		rep (i, 0, n)
			tree[i] = i;
	}

	int root(int x) { // データxの根を取得
		if (tree[x] == x)
			return x;
		else
			return tree[x] = root(tree[x]); // 根に直接つなぎ直す
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x);
		int ry = root(y);

		if (rx == ry)
			return ;
		else
			tree[rx] = ry;
	}

	bool same(int x, int y) { // データxとデータyの根が同じか判定
		return (root(x) == root(y));
	}
};

int main()
{
	int a, b;
	cin >> a >> b;

	cout << "gcd is " << gcd(a, b) << endl;
	cout << "lcm is " << lcm(a, b) << endl;

	//	comb_in_g(a, b);
	//	cout << nCr[a][b] << endl;

	// cout << comb(a, b) << endl;

	return 0;
}
