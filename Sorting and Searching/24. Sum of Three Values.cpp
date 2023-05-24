#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
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
    ll n,x;
    cin >> n >> x;
    vl v;
    REP(i,0,n){
        ll t;
        cin >> t;
        v.PB(t);
    }
    vl vc (v);
    sort(ALL(v));
    REP(i,0,n){
        ll i1 = 0;
        ll i2 = n-1;
        while(i1 < i2 && i1 < n && i2 >= 0){
            if (v[i1]+v[i2] == x-v[i]){
                if (i2 == i){ 
                    i2--; continue; 
                }
                if (i1 == i){ 
                    i1++; continue; 
                }
                auto it1 = find(ALL(vc),v[i]);
                cout << distance(vc.begin(),it1)+1 << " ";
                auto it2 = find(vc.begin(),it1,v[i1]); 
                if (it2 == it1){ it2 = find(++it1,vc.end(),v[i1]); }
                cout << distance(vc.begin(),it2)+1 << " ";
                auto it3 = find(vc.begin(),--it1,v[i2]); 
                if (it3 == it1){ it3 = find(++it1,it2,v[i2]); } 
                if (it3 == it2){ it3 = find(++it2,vc.end(),v[i2]); } 
                cout << distance(vc.begin(),it3)+1 << " ";
                return 0;
            } else if (v[i1]+v[i2] > x-v[i]){
                i2--;
            } else if (v[i1]+v[i2] < x-v[i]){
                i1++;
            }
        }

    }
    cout << "IMPOSSIBLE\n";
}

// - initial approach
// one nested loop to save the sum of every pair of element in a map then one loop to find the req pair
// tle
// - second approach
// sort , keep a copy, loop over all - use two pointer to find the other two values, find the position of those values in the copy
// ac