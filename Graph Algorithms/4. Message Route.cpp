#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef set<ll> sl;
typedef multiset<ll> ml;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define F first 
#define S second
#define I iterator
#define mod 1000000007
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (0));
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<bool> v(n, false);
    vector<int> prevNod(n, -1);

    queue<int> s;
    s.push(0);
    v[0] = true;
    while(!s.empty()){
        int x = s.front(); s.pop();

        if (x == n-1){
            int p = x;
            vector<int> ans(0);
            while(p != -1){
                ans.push_back(p);
                p = prevNod[p];
            }
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            for (auto xx : ans){
                cout << xx+1 << ' ';
            }
            return 0;
        }

        for (auto k : g[x]){
            if (!v[k]){
                v[k] = true;
                prevNod[k] = x;
                s.push(k);
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

// - initial approach