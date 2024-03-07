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
    vector<vector<ll>> es (0);
    REP(i, 0, m){
        ll a, b, c;
        cin >> a >> b >> c;
        es.push_back({a-1, b-1, c});
    }

    vector<ll> d(n, 0);
    vector<ll> pre (n, -1);

    int c = -1;
    REP(i, 0, 2*n){
        for (auto &e : es){
            if (d[e[0]] != LLONG_MAX){
                if (d[e[0]] + e[2] < d[e[1]]){
                    d[e[1]] = d[e[0]] + e[2];

                    if (i >= n - 1) {
                        pre[e[1]] = e[0];
                        if (c == -1) c = e[0];
                    }
                }
            }
        }
    }
    if (c != -1){
        set<int> there;
        vector<int> ans;
        while(c != -1){
            if (there.find(c) != there.end()){
                ans.PB(c);
                break;
            }
            there.insert(c);
            ans.PB(c);
            c = pre[c];
        }
        cout << "YES\n";
        REPR(i, ans.size()-1, -1){
            if (i != ans.size()-1 && ans[i] == ans[ans.size()-1]){
                cout << ans[i]+1; break;
            }
            cout << ans[i]+1 << ' ';
        }
        return 0;
    }
    cout << "NO\n";
}

// - initial approach