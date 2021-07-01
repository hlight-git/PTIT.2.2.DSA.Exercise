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
int test, n, V, E, visited;
bool U[100005];

/*Function*/
void init(){
    cin >> V >> E;
}
void BFS(vector <int> *a, int u){
    queue <int> q;
    U[u] = true;
    q.push(u);
    visited = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        Fu(i, 0, a[v].size(), 1)
            if(!U[a[v][i]]){
                U[a[v][i]] = true;
                q.push(a[v][i]);
                ++visited;
            }
    }
}
void DFS(vector <int> *a, int u){
    stack <int> s;
    U[u] = true;
    s.push(u);
    visited = 1;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        Fu(i, 0, a[v].size(), 1)
            if(!U[a[v][i]]){
                U[a[v][i]] = true;
                s.push(v);
                s.push(a[v][i]);
                ++visited;
                break;
            }
    }
}
void solve(){
    int x, y, FSed = 0;
    vector <int> a[V+5];
    Fu(i, 0, E, 1){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    Re0(U);
    BFS(a, 1);
    int res = visited;
    if(visited < V/2){
        FSed = visited;
        Fu(i, 2, V+1, 1){
            if(!U[i]){
                BFS(a, i);
                FSed = visited;
                res = max(res, visited);
                if(V - FSed <= res) break;
            }
        }
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