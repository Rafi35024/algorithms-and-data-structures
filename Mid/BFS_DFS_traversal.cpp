#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> node;

void bfs(int src){
    vector<bool> visited(node.size(), false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    cout << "BFS : " ;
    while(!q.empty()){
        int root = q.front();
        cout << root << " ";
        for(int neighbour : node[root]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            } 
        }
        q.pop();
    }
    cout << endl;
}

vector<bool> v;
void dfs(int root){
    cout << root << " ";
    v[root] = true;
    for(int neighbour : node[root]){
        if(!v[neighbour]){
            dfs(neighbour);
        }
    }
}

int main() {

    int n,e,a,b;
    cin >> n >> e;
    node.resize(n);
    for(int i=0; i<e; i++){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    bfs(0);

    v.resize(node.size(),false);
    cout << "DFS : " ;
    dfs(0);

    return 0;
}