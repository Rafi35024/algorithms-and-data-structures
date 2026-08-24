#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> edge_list;
vector<vector<pair<int,int>>> adj_list;
vector<int> h;
vector<int> dist;

void bellman_ford(int n, int src){
    h.resize(n,INT_MAX);
    h[src] = 0;

    for(int i=0; i<n-1; i++){
        for(auto [x,y] : edge_list){
            if(h[x.first]==INT_MAX) continue;
            if(h[x.first]+y < h[x.second])
                h[x.second] = h[x.first] + y;
        }
    }
}

void dijkstra(int src){
    dist.resize(adj_list.size(),INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dist[src],src});

    pair<int,int> current;

    while(!pq.empty()){
        current = pq.top();
        pq.pop();

        if(current.first>dist[current.second]) continue;

        for(auto [neighbour,weight] : adj_list[current.second]){
            if(current.first+weight < dist[neighbour]){
                dist[neighbour] = current.first+weight;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
}

void johnson(int n){
    int new_src = n;

    for(int i=0; i<n; i++){
        edge_list.push_back({{new_src,i},0});
    }

    bellman_ford(n+1,new_src);

    adj_list.resize(n);

    for(int i=0; i<edge_list.size(); i++){
        int current = edge_list[i].first.first;
        int neighbour = edge_list[i].first.second;
        int weight = edge_list[i].second;

        if(current==new_src) continue;

        int new_weight = weight + h[current] - h[neighbour];

        adj_list[current].push_back({neighbour,new_weight});
    }

    for(int i=0; i<n; i++){
        dist.clear();
        dijkstra(i);

        for(int j=0; j<n; j++){
            if(dist[j]==INT_MAX) continue;

            dist[j] = dist[j] - h[i] + h[j];

            cout << i << " -> " << j << " = " << dist[j] << endl;
        }

        cout << endl;
    }
}

int main(){

    int n,e;
    cin >> n >> e;

    int current,neighbour,weight;

    for(int i=0; i<e; i++){
        cin >> current >> neighbour >> weight;
        edge_list.push_back({{current,neighbour},weight});
    }

    johnson(n);

    return 0;
}