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
/*Declare*/
using namespace std;
typedef long long int ll;
typedef double db;

/*Initialize*/
int test, n, k;
int a[20];
bool done;
/*Function*/
void init(){
    cin >> n >> k;
    done = false;
    Fu(i, 0, k, 1)  a[i] = i+1;
}
void Display(){
    Fu(i, 0, k, 1)
        cout << a[i];
}
void Generate(){
    int i = k;
    while(a[i-1] == n+i-k)  --i;
    if(i){
        ++a[i-1];
        Fu(j, i, k, 1)  a[j] = a[j-1]+1;
    }
    else    done = true;
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        while(!done){
            Display();
            Generate();
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/