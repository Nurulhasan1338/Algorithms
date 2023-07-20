#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int n;
vector<int> a;
vector<int> prefix_max;
vector<int> suffix_max;

int32_t main() {
    cin >> n;
    a.resize(n);
    prefix_max.resize(n);
    suffix_max.resize(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int cur_max = a[0];
    for(int i=0; i<n; i++) {
        cur_max = max(cur_max, a[i]);
        prefix_max[i] = cur_max;
    }

    cur_max = a[n-1];
    for(int i=n-1; i>=0; i--) {
        cur_max = max(cur_max, a[i]);
        suffix_max[i] = cur_max;
    }

    int ans = 0;
    for(int i=1; i<n-1; i++) {
        int left_max = prefix_max[i-1];
        int right_max = suffix_max[i+1];
        ans = max(ans, left_max + a[i] + right_max);
    }

    cout << ans % mod << endl;

    return 0;
}
