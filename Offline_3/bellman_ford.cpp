#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> edge_list;
vector<int> dist;
vector<int> dist1;

void bellman_ford(int n){
    for(int i=0; i<n; i++){
        if(i==n-1) dist1 = dist;
        for(auto [x,y] : edge_list){
            if(dist[x.first]==INT_MAX) continue;
            if(dist[x.first]+y < dist[y])
                dist[y] = dist[x.first] + y;
        }
    }
}

int main() {

    int n,e,src;
    cin >> n >> e >> src;
    
    int current,neighbour,weight;
    edge_list.resize(e);
    pair<pair<int,int>,int> p;
    for(int i=0; i<e; i++){
        cin >> current >> neighbour >> weight;
        p.first.first = current;
        p.first.second = neighbour;
        p.second = weight;
        edge_list[i] = p;
    }
    
    dist.resize(n,INT_MAX);
    dist[src] = 0;
    dist1.resize(n);

    bellman_ford(n);

    if(dist1==dist){
        for(int i=0; i<n; i++){
            cout << i << " ->" << dist[i] << endl;
        }
    }
    else{
        cout << "No Solutions" << endl;
    }

    return 0;
}