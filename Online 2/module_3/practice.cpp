#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dist;
vector<int> lvl;

void set_lvl(int src){
    lvl[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto [neighbour,weight] : adj_list[current]){
            if(lvl[neighbour]==-1){
                lvl[neighbour] = lvl[current]+1;
                q.push(neighbour);
            }
        }
    }
}


void dijkstra(int src, int k){
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dist[src],src});
    pair<int,int> current;
    while(!pq.empty()){
        current = pq.top();
        pq.pop();
        //if(lvl[current.second]>k || current.first>dist[current.second]) continue;
        for(auto [neighbour,weight] : adj_list[current.second]){
            if(lvl[current.second]<=k && current.first + weight < dist[neighbour]){
                dist[neighbour] = current.first + weight;
                pq.push({dist[neighbour],neighbour});
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
    lvl.resize(n,-1);
    set_lvl(src);

    dijkstra(src, k);
    if(dist[dst]==INT_MAX) cout << "Impossible\n";
    else cout << dist[dst] << endl;


    return 0;
}