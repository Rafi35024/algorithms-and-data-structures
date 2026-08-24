// branch and bound
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<bool> mark;
int cost;

void bb(int n){
    int c = 0;
    
}

int main() {
    
    int node,edge,src;
    cin >> node >> edge >> src;
    int current, neighbour, weight;
    adj_list.resize(node+1);
    mark.resize(node+1);
    for(int i=0; i<edge; i++){
        cin >> current >> neighbour >> weight;
        adj_list[current].push_back({neighbour,weight});
    }
    
    mark[src] = true;
    for(auto[x,y] : adj_list[src]){

    }


    


    return 0;
}