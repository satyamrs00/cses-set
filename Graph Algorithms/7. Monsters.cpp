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
    vector<string> g (n);
    REP(i, 0, n){
        cin >> g[i];
    }
    vl rf {1, -1, 0, 0};
    vl cf {0, 0, 1, -1};
    vector<string> dr {"D", "U", "R", "L"};
 
    vector<vector<bool>> vis(n, vector<bool> (m, false));
 
    queue<tuple<int, int, int>> q;
    pll ap;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'M'){
                q.push({i, j, 0});
                vis[i][j] = true;
            }
            if (g[i][j] == 'A'){
                ap = {i, j};
            }
        }
    }
 
    vector<vector<int>> ms (n, vector<int> (m, INT_MAX));
 
    while (!q.empty()){
        int a, b, d; tie(a, b, d) = q.front(); q.pop();
        ms[a][b] = min(ms[a][b], d);
        // if (d == 0){
        //     vis = vector<vector<bool>> (n, vector<bool> (m, false));
        //     vis[a][b] = true;
        // }
 
        for (int p = 0; p < 4; p++){
            if (a + rf[p] < 0 || a + rf[p] >= n || b + cf[p] < 0 || b + cf[p] >= m) continue;
            if (g[a+rf[p]][b+cf[p]] == '.' && ms[a+rf[p]][b+cf[p]] > d+1 && !vis[a+rf[p]][b+cf[p]]){
                vis[a+rf[p]][b+cf[p]] = true;
                q.push({a+rf[p], b+cf[p], d+1});
            }
        }
    }
 
    q.push({ap.first, ap.second, 0});
 
    vector<vector<string>> prevStep(n, vector<string> (m, "O"));
 
    vis = vector<vector<bool>> (n, vector<bool> (m, false));
    vis[ap.first][ap.second] = true;

    while(!q.empty()){
        int a, b, d; tie(a, b, d) = q.front(); q.pop();
        if (a == 0 || a == n-1 || b == 0 || b == m-1){
            string ans;
            int aa = a, bb = b; string dd = prevStep[aa][bb]; 
            while(dd != "O"){
                if (dd == "U"){
                    aa++;
                } else if (dd == "D"){
                    aa--;
                } else if (dd == "R"){
                    bb--;
                } else if (dd == "L"){
                    bb++;
                }
                ans += dd;
                dd = prevStep[aa][bb];
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n" << ans.size() << '\n' << ans;
            return 0;
        }
 
        for (int p = 0; p < 4; p++){
            if (a + rf[p] < 0 || a + rf[p] >= n || b + cf[p] < 0 || b + cf[p] >= m) continue;
            if (g[a+rf[p]][b+cf[p]] == '.' && ms[a+rf[p]][b+cf[p]] > d+1 && !vis[a+rf[p]][b+cf[p]]){
                vis[a+rf[p]][b+cf[p]] = true;
                prevStep[a+rf[p]][b+cf[p]] = dr[p];
                q.push({a+rf[p], b+cf[p], d+1});
            }
        }
    }
    
    cout << "NO";
 
    return 0;
}

// initial approach