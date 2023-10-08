// https://www.hackerrank.com/contests/code-combat-23/challenges/is-this-ott/problem

// Initialize variable mod
const int g = 3;
int root, root_inv;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m) {
    return power(a, m - 2, m);
}

void init(int n) {
    root = power(g, (mod - 1) / n, mod);
    root_inv = modi(root, mod);
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_inv : root;
        for (int i = len; i < sz(a); i <<= 1)
            wlen = (int) (1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = (int) (1LL * a[i + j + len / 2] * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int) (1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_rev = modi(n, mod);
        for (int &x : a)
            x = (int) (1LL * x * n_rev % mod);
    }
}

// a[3] means coeff. of x^3 in polynimal a, return coeff. of product
vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1;
    while (n < sz(a) + sz(b))
        n <<= 1;
    a.resize(n);
    b.resize(n);
    init(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] * b[i]) % mod;
    }
    fft(a, true);
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int>v(100001, 0);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[val] += 1;
    }
    vector<int>x = multiply(v, v);
    vector<int>y = multiply(x, x);
    int q;
    cin >> q;
    while (q--) {
        int val;
        cin >> val;
        if (val < sz(y)) {
            cout << y[val] << endl;
        } else {
            cout << 0 << endl;
        }
    }
}