#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int color[1005];

bool dfs(int u){
    color[u] = 1;
    for (int v : adj[u]){
        if (color[v] == 0 && dfs(v)) return true; /* theo huong cua v co chu trinh */
        else if (color[v] == 1) return true; /* v dang dc tham va nam tren duong di hien tai
        => v dc di qua  roi moi den u => co chu trinh */
    }
    color[u] = 2;
    return false;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(color, 0, sizeof(color));
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        int found = 0;
        for (int i = 1; i <= n; i++){
            if (color[i] == 0){
                if (dfs(i)){
                    found = 1;
                    break;
                }
            }
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}