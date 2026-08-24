#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> node;

void bfs(int src){
    vector<bool> visited(node.size(),false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int root = q.front();
        q.pop();
        cout << root << " ";
        for(int neighbour : node[root]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
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

vector<int> d;
//maximum depth for every node
void depth(int root){
    for(int neighbour : node[root]){        
        if(d[neighbour] < d[root]+1){
            d[neighbour] = d[root] + 1;
            depth(neighbour);
        }
    }
}

int main(){

    int n,e,a,b;
    cin >> n >> e;
    node.resize(n);
    for(int i=0; i<e; i++){
        cin >> a >> b;
        node[a].push_back(b);
    }

    bfs(0);
    v.resize(n,false);
    dfs(0);
    cout << endl;
    
    v.resize(n,false);
    d.resize(n);
    d[0] = 0;
    depth(0);
    cout << *max_element(d.begin(),d.end()) << endl;

    return 0;
}