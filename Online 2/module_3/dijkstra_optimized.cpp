#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dist;


void dijkstra(int src){
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dist[src],src});
    pair<int,int> current;
    while(!pq.empty()){
        current = pq.top();
        pq.pop();
        if(current.first>dist[current.second]) continue;
        for(auto [neighbour,weight] : adj_list[current.second]){
            if(current.first + weight < dist[neighbour]){
                dist[neighbour] = current.first + weight;
                pq.push({dist[neighbour],neighbour});
            }
        }        
    }
}


int main(){

    int n,e,src;
    cin >> n >> e >> src;
    int current,neighbour,weight;
    adj_list.resize(n);
    for(int i=0; i<e; i++){
        cin >> current >> neighbour >> weight;
        adj_list[current].push_back({neighbour,weight});
    }
    dist.resize(n,INT_MAX);

    dijkstra(src);
    for(int i=0; i<n; i++){
        cout << i << " -> " << dist[i] << endl;
    }


    return 0;
}