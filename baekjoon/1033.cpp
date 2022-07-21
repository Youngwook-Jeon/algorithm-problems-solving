// https://www.acmicpc.net/problem/1033
// Find a solution of given pairs of equations
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;

struct Node {
    int b;
    int p;
    int q;
};

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(int current, vector<vector<Node> > &v, vector<bool> &visited, vector<ll> &ans) {
    visited[current] = true;
    for (auto node : v[current]) {
        int next = node.b;
        if (!visited[next]) {
            ans[next] = ans[current] * node.q / node.p;
            dfs(next, v, visited, ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<vector<Node> > v(n);
    vector<bool> visited(n, false);
    vector<ll> ans(n);
    
    ll lcm = 1LL;

    for (int i = 0; i < n - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        v[a].push_back({b, p, q});
        v[b].push_back({a, q, p});
        lcm *= (p * q) / gcd(p, q);
    }

    ans[0] = lcm;
    dfs(0, v, visited, ans);
    ll num = ans[0];
    for (int i = 1; i < n; i++) {
        num = gcd(num, ans[i]);
    }

    for (ll a : ans) {
        cout << a / num << " ";
    }
    return 0;
}