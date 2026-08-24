#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dist;


void dijkstra(int src, int k){
    dist[src] = 0;
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    pq.push({{dist[src],src},0});
    pair<pair<int,int>,int> current;
    while(!pq.empty()){
        current = pq.top();
        pq.pop();
        //if(current.first.first>dist[current.first.second]) continue;
        if(current.second>k) continue;
        for(auto [neighbour,weight] : adj_list[current.first.second]){
            if(current.first.first + weight < dist[neighbour]){
                dist[neighbour] = current.first.first + weight;
                pq.push({{dist[neighbour],neighbour},current.second+1});
            }
        }        
    }
}


int main(){

    int n,e,src,dst,k;
    cin >> n >> e;
    int current,neighbour,weight;
    adj_list.resize(n);
    for(int i=0; i<e; i++){
        cin >> current >> neighbour >> weight;
        adj_list[current].push_back({neighbour,weight});
    }
    cin >> src >> dst >> k;
    dist.resize(n,INT_MAX);

    dijkstra(src,k);
    for(int i=0; i<n; i++){
        cout << i << " -> " << dist[i] << endl;
    }


    return 0;
}