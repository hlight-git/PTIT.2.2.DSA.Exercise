/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS() ios::sync_with_stdio(false);
#define tie() cin.tie(NULL); cout.tie(NULL);
/*Compact*/
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define all(Object) Object.begin(), Object.end()
#define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
#define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
#define Re0(Object) memset(Object, 0, sizeof(Object))
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n, V, E;
int U[1005];

/*Function*/
void init(){
    cin >> V >> E;
}
bool BFS(vector <int> *a, int u){
    Re0(U);
    queue <int> q;
    U[u] = -1;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        Fu(i, 0, a[v].size(), 1)
            if(!U[a[v][i]]){
                U[a[v][i]] = v;
                q.push(a[v][i]);
            }
            else if(a[v][i] != U[v])   return true;
    }
    return false;
}

void solve(){
    int x, y;
    string res = "NO";
    vector <int> a[V+5];
    Fu(i, 0, E, 1){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    Fu(i, 1, V+1, 1)
        if(BFS(a, i)){
            res = "YES";
            break;
        }
    cout << res;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/