#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>
#define mn 1005
using namespace std;

int N, M;
queue<pii> q;
int paths[mn][mn];
int inf = INT_MAX;
pii A;
bool possible=false;
int i=0;

void check(pii origin, pii dest){ // check if the considered destination may be traveled to
    int pl = paths[origin.first][origin.second];
    if(pl+1<paths[dest.first][dest.second]){
        paths[dest.first][dest.second]  = pl+1;
        q.push(dest);
    }
}
bool person = false; // false if bfs for monsters, true if bfs for A
void bfs(){
    while(!q.empty()){
        pii loc = q.front(), next; q.pop();
        next = loc; next.first++; check(loc, next); // go through adjacent locations
        next = loc; next.first--; check(loc, next);
        next = loc; next.second++; check(loc, next);
        next = loc; next.second--; check(loc, next);
        if(person && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){
            cout << "YES" << endl;
            possible=true;
            return;
        }
    }
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= M; j++){
            paths[i][j] = inf;
            if(s[j-1] == '#') paths[i][j] = 0;
            if(s[j-1] == 'M') {q.push(pii(i,j)); paths[i][j]  = 0;}
            if(s[j-1] == 'A') {A.first = i; A.second = j;}
        }
    }
    bfs(); 
    person = true; 
    paths[A.first][A.second] = 0; q.push(A); 
    bfs(); 
    if(!possible) cout << "NO" << endl;
}