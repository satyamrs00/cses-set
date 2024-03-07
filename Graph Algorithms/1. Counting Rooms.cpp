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
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    ll n,m; cin >> n >> m;
    vs g (n);
    REP(i, 0, n){
        cin >> g[i];
    }
    vl rf {1, -1, 0, 0};
    vl cf {0, 0, 1, -1};

    int ans = 0;
    vector<vector<bool>> v (n, vector<bool> (m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!v[i][j] && g[i][j] == '.'){
                // cout << i << ' ' << j << '\n';
                ans++;
                v[i][j] = true;

                stack<pll> s;
                s.push({i, j});
                while(!s.empty()){
                    int a, b; tie(a, b) = s.top(); s.pop();

                    for (int k = 0; k < 4; k++){
                        if (a + rf[k] >= 0 && a + rf[k] < n && b + cf[k] >= 0 && b+cf[k] < m && g[a+rf[k]][b+cf[k]] == '.' && !v[a+rf[k]][b+cf[k]]){
                            v[a+rf[k]][b+cf[k]] = true;
                            s.push({a+rf[k], b+cf[k]});
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    
}

// - initial approach