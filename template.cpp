/**
 * @file template.cpp
 * @author Cui2010
 * @brief A C++ template.
 * @version 0.2.0
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
 * Templates. To go to the bottom, hit:
 * 409G cc
 */

/**
 * THIS TEMPLATE IS WRITTEN BY CUI2010.
 * DO NOT COPY UNLESS AGREED.
 **/

// GCOJ Official file.
// TOP SECRET!!!

// Security Code: XXXXX
// XXXXX means blocked.
// User:          $%U%$
// GT$%Y%$$%M%$$%D%$$%h%$$%m%$$%s%$$%U%$

#include <bits/stdc++.h>

// Defines.

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define iint signed

using namespace std;

// Consts.

const int INF = 0x3f3f3f3f;
const int OVER_MAX = 2147483648LL;
const int OVER_MIN = -2147483649LL;
const int SHORT_MAX = 32767;
const int SHORT_MIN = -32768;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
const int MOD3 = 1145141919810LL;
const int MAXN = 200000;
const double PI = acos(-1.0);
const double E = 2.718281828;
const double PHI = (sqrt(5.0) - 1) / 2.0;

// Debugger.
// Grammar: debug << ...$$

bool is_debug = false;

#define debug if(is_debug){cout
#define $$ ;}

// Quick things

#pragma GCC optimize(3)

inline int read(){
	int ans = 0;
	char c = getchar();
	while(!isdigit(c)){
		c = getchar();
	}
	while(isdigit(c)){
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}

/**
 * @brief DisJoint Sets.
 * 
 * @details DisJoint Sets with ZHUANGTAIYASUO.
 * 			Time complexity O(a(n)), good.
 * 
 * @todo Add the DSU with weights.
 * 
 */
class DSU{
	public:
		int father[MAXN];
		void init(int n, int p){
			memset(father, 0, sizeof(father));
			for(int i = 0;i < n;i++){
				father[i] = i + p;
			}
		}
		int findfather(int n){
			if(father[n] == n){
				return n;
			}
			return findfather(father[n]);
		}
		void Union(int a, int b){
			a = findfather(a), b = findfather(b);
			if(a != b){
				father[a] = b;
			}
		}
	
};

// The lowbit calculation.

inline int lowbit(int n){
	return n & (-n);
}

inline int cnto(int n){
	int t = 1, ans = 0;
	while(t > 0){
		ans += (bool)(n & t);
		t <<= 1;
	}
	return ans;
}


class BIT{
	private:
		int s[100001], sz;
	public:
		void init(int z){
			memset(s, 0LL, sizeof(s));
			sz = z;
		}
		void add(int n, int k){
			while(n <= sz){
				s[n] += k;
				n += lowbit(n);
			}
		}
		int query(int n){
			int ans = 0LL;
			while(n >= 1){
				ans += s[n];
				n -= lowbit(n);
			}
			return ans;
		}
};

// Struct for segmenttrees.

struct Segment_tree{
	int l, r;
	long long val, lazy;
};

/**
 * @brief Segment trees.
 * 
 * @details This segment tree is a stimulation
 * 			of the segment tree.
 * 
 * @warning THE SEGMENTTREE STRUCT CANNOT BE MODIFIED!
 * 
 * @todo Add the functions.
 */
class SegmentTree{
	private:
		Segment_tree tree[2000001];
	public:
		void build(int l, int r, int k){
			tree[k].l = l;
			tree[k].r = r;
			if(l == r){
				tree[k].val = 0;
				return;
			}
			int mid = (l + r) >> 1;
			build(l, mid, k * 2);
			build(mid + 1, r, k * 2 + 1);
			tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
			return; 
		}
		void marks(int p){
			if(tree[p].lazy){
				tree[p * 2].val += tree[p].lazy * (tree[p * 2].r - tree[p * 2].l + 1);
				tree[p * 2 + 1].val += tree[p].lazy * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
				tree[p * 2].lazy += tree[p].lazy;
				tree[p * 2 + 1].lazy += tree[p].lazy;
				tree[p].lazy = 0LL; 
			}
			return;
		}
		void add(int l, int r, int k, int d){
			if(l <= tree[d].l && r >= tree[d].r){
				tree[d].val += (long long)(k) * (tree[d].r - tree[d].l + 1LL); 
				tree[d].lazy += k;
				return;
			}
			marks(d);
			int mid = (tree[d].l + tree[d].r) >> 1;
			if(l <= mid){
				add(l, r, k, d * 2);
			}
			if(r > mid){
				add(l, r, k, d * 2 + 1);
			}
			tree[d].val = tree[d * 2].val + tree[d * 2 + 1].val; 
		}
		long long query(int l, int r, int k){
			if(l <= tree[k].l && r >= tree[k].r){
				return tree[k].val;
			}
			marks(k);
			int mid = (tree[k].l + tree[k].r) >> 1;
			long long val = 0LL;
			if(l <= mid){
				val += query(l, r, k * 2);
			}
			if(r > mid){
				val += query(l, r, k * 2 + 1);
			}
			return val;
		}
};

// Math functions

bool isPrime(int n){
	if(n == 0 || n == 1){
		return false;
	}
	for(int i = 2;i * i <= n;i++){
		if(!(n % i)){
			return true;
		}
	}
	return false;
}

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}
int lcm(int a, int b){
	return a * b / gcd(a, b);
}

int power(int a, int b, int q){
	if(b == 0){
		return 1;
	}
	if(b % 2 == 1){
		return (power(a, b - 1, q) * a) % q;
	}
	int temp = power(a, b / 2, q) % q;
	return (temp * temp) % q;
}

// Quicker than STL.

int mmax(int a, int b){
	return a < b ? b : a;
}
int mmin(int a, int b){
	return a < b ? a : b;
}
void ckmax(int *a, int b){
	*a = mmax(*a, b);
}
void ckmin(int *a, int b){
	*a = mmin(*a, b);
}

// Quick OJ tools.

#define ncinn int n; cin >> n
#define tcin int n, m; cin >> n >> m
#define allcin int a[n]; for(int i = 0;i < n;i++){cin >> a[i];}
#define sorta sort(a, a + n)
#define mltst int t;cin >> t;while(t--){
#define ed }

// RE&TLE helpers

#define dd cout << "|" << endl
#define ddd cout << "@" << endl
#define dddd cout << "#" << endl

// Quick cout tools

void parr(int a[], int n, char sep){
	for(int i = 0;i < n;i++){
		cout << a[i] << sep;
	}
	cout << endl;
}
void pres(bool ok){
	cout << (ok ? "YES" : "NO") << endl;
}
void cmin(int a, int b){
	cout << ((a < b) ? "YES" : "NO") << endl;
}
void cmax(int a, int b){
	cout << ((a > b) ? "YES" : "NO") << endl;
}

// Some basic algorithms.

bool is32_overflow(int n){
	return n > INT_MAX || n < INT_MIN;
}
bool is16_overflow(int n){
	return n > SHORT_MAX || n < SHORT_MIN;
}

uint _hash(string s){
	uint a = 0;
	for(int i = 0;i < s.length();i++){
		a = a * 128 + (int)(s[i]);
	}
	return a;
}
void aset(auto *a, int n, int k){
	for(int i = 0;i < n;i++){
		*(a + i) = k;
	}
}

// Graphs and trees.

struct ged{
	int u, v, w;
	bool operator < (const ged x){
		return w < x.w;
	}
};
class Graph{
	private:
		bool vis[1000001];
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	public:
		int d[1000001];
		vector<pair<int, int> > gv[100001];
		vector<ged> ge;
		void add_edge(int u, int v, int w, bool dir){
			gv[u].push_back(make_pair(v, w));
			ge.push_back((ged){u, v, w});
			if(!dir){
				gv[v].push_back(make_pair(u, w));
				ge.push_back((ged){v, u, w});
			}
		}
		void dij(int k){
			aset(d, 1000000, 0x7fffffff);
			aset(vis, 1000000, 0);
			d[k] = 0;
			pq.push(make_pair(k, 0));
			while(pq.size()){
				int x = pq.top().second;
				pq.pop();
				if(vis[x]) continue;
				vis[x] = 1;
				for(int i = 0;i < gv[x].size();i++){
					int y = gv[x][i].first, z = gv[x][i].second;
					if(d[y] > d[x] + z){
						d[y] = d[x] + z;
						pq.push(make_pair(d[y], y));
					}
				}
			}
		}
		int MST(int n){
			DSU ds;
			ds.init(n, 1);
			sort(ge.begin(), ge.end());
			int tot = 0, ans = 0, i = 0;
			while(i < ge.size() && tot < n - 1){
				if(ds.findfather(ge[i].u) != ds.findfather(ge[i].v)){
					tot++, ans += ge[i].w;
					ds.Union(ge[i].u, ge[i].v);
				}
				i++;
			}
			if(tot != n - 1){
				return -1;
			}
			return ans;
		}
};


//-------------by @cui2010 -------------

signed main(){
	IO;
	// Type you code...
	return 0;
}
