#include<bits/stdc++.h>
using namespace std;
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
vi a,b;
int n,m;
void Input(){
    cin >> n >> m;
    a.resize(n) ; b.resize(m);
    for(int i = 0; i < n; i++ ) cin >> a[i];
    for(int i = 0; i < m; i++ ) cin >> b[i];
}   
void Solve(){
    int cnt[1000] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int  j = 0 ; j < m ; j++){
            cnt[i+j] += a[i]*b[j];
        }
    }
    for(int i = 0; i <= n + m - 2; i++){
        cout << cnt[i] << ' ';
    }
    cout << '\n';
}
int main(){
    setIO();
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}