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
typedef pair<char, ll> pcl;
typedef pair<ll, ll> pll;

#define PB push_back
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    ll n=5,m=3;
    // cin >> n >> m;
    sl a;
    vl v{4,2,1,5,3};
    vl vr{-1,2,1,4,0,3};
    ll ans = 1;
    REP(i,0,n){
        ll tmp=v[i];
        // cin >> tmp;
        if (a.count(tmp+1)){
            ans++;
        }
        vr[tmp] = i;
        // v[i]=tmp;
        a.insert(tmp);
    }
    vector<pll> ms{make_pair(2,3), make_pair(1,5), make_pair(2,3)};
    REP(i,0,m){
        ll a=ms[i].F,b=ms[i].S;
        // cin >> a >> b;
        ll eaa = v[a-1];
        ll tans = ans;
        if (vr[eaa] < vr[eaa+1] && b-1 > vr[eaa+1]) tans++;
        if (vr[eaa] > vr[eaa+1] && b-1 < vr[eaa+1]) tans--;
        if (vr[eaa] < vr[eaa-1] && b-1 > vr[eaa-1]) tans--;
        if (vr[eaa] > vr[eaa-1] && b-1 < vr[eaa-1]) tans++;
        ll eab = v[b-1];
        if (vr[eab] < vr[eab+1] && b-1 > vr[eab+1]) tans++;
        if (vr[eab] > vr[eab+1] && b-1 < vr[eab+1]) tans--;
        if (vr[eab] < vr[eab-1] && b-1 > vr[eab-1]) tans--;
        if (vr[eab] > vr[eab-1] && b-1 < vr[eab-1]) tans++;

        if (abs(eaa-eab) == 1){ 
            if (tans > ans){
                ans = tans-1;
            } else if (tans < ans){
                ans = tans+1;
            } else {
                ans = tans;
            }
        } else {
            ans = tans;
        }
        v[a-1] = eab; v[b-1] = eaa;
        vr[eaa] = b-1; vr[eab] = a-1;
        cout << ans << ' ';
    }
}

//  TODO - incomplete

// - first approach 
// loop over the array, for x, if x+1 is before the ele, increase the rounds. then loop over the changes check if it switched the occurence of a,a-1;a,a+1;b,b-1;b,b+1 adjust accordingly
// couldnt implement 
