#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<char, ll> mcl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<char, ll> pcl;
typedef pair<ll, ll> pll;


#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define POB pop_back
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    fastio();
    ll n;
    cin >> n;
    ll last_room = 0;
    vl free_rooms;
    unordered_map<ll,pair<ll,ll>> busy_rooms;
    vl ans ;
    REP(i,0,n){
        pll p;
        cin >> p.F >> p.S;
        for(auto x: busy_rooms){
            if (x.S < p.F){
                busy_rooms[x.F] = LLONG_MAX;
                free_rooms.PB(x.F);
            }
        }
        if (free_rooms.size() > 0){
            ans.PB(free_rooms.back());
            busy_rooms[free_rooms.back()] = p.S;
            free_rooms.POB();
        } else {
            ans.PB(++last_room);
            busy_rooms[last_room] = p.S;
        }
    }
    cout << last_room << "\n";
    REPIT(it,ans){
        cout << *it << " ";
    }
}
// TODO - incomplete