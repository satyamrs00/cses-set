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

vector<vector<int>> gr;
vector<int> ans;
vector<int> vis;

bool dfs (int n) {
    vis[n] = 1;

    for (auto x : gr[n]){
        if (vis[x] == 1){
            cout << "IMPOSSIBLE";
            return false;
        } else if (vis[x] == 0) {
            bool pp2 = dfs(x);
            if (!pp2) return false;
        }
    }

    ans.push_back(n);
    vis[n] = 2;
    return true;
}

int main() {
    fastio();
    int n, m;
    cin >> n >> m;
    gr.resize(n, vector<int> (0));

    REP(i, 0, m){
        int a, b;
        cin >> a >> b;
        gr[a-1].push_back(b-1);
    }

    vis.resize(n, 0);

    for (int i = 0; i < n; i++){
        if (vis[i] == 0){
            bool pp = dfs(i);
            if (!pp){
                return 0;
            }
        }
    }

    reverse(ALL(ans));
    for (auto x : ans){
        cout << x+1 << ' ';
    }
}

// - initial approach