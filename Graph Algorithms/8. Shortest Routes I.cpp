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
    ll n, m; cin >> n >> m;
    vector<vector<vector<ll>>> es (n, vector<vector<ll>> (0));
    for (ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        es[a-1].push_back({b-1, c});
    }
    vector<ll> ans (n, LLONG_MAX);
    ans[0] = 0;

    priority_queue<pair<ll, ll>> q;
    vector<bool> vis(n, false);

    q.push({0, 0});

    while(!q.empty()){
        ll d, n; tie(d, n) = q.top(); q.pop();
        if (!vis[n]) {
            vis[n] = true;
            for (auto x : es[n]){
                if (ans[n] + x[1] < ans[x[0]] && ans[n] + x[1] >= 0){
                    ans[x[0]] = ans[n] + x[1];
                    q.push({ans[x[0]] * -1, x[0]});
                }
            }
        }
    }

    for (auto x : ans){
        cout << x << ' ';
    }
    return 0;
}

// - initial approach