#include <windows.h>
#include <psapi.h>
#include <stdio.h>

#pragma comment(lib, "Psapi.lib")  

// Replace with your CPU's approximate average power (Watts)
#define CPU_POWER_WATTS 65.0
// Bangladesh grid emission factor (kg CO₂ / kWh)
#define BD_EMISSION_FACTOR 0.62

#include <bits/stdc++.h>
using namespace std;

const int N = 45;
const int INF = 1e9;

vector<pair<pair<int,int>,int>> edge_list;
vector<vector<pair<int,int>>> adj_list;
vector<int> dist;
vector<int> h;

void generate_sparse_graph(){

    edge_list.clear();

    int current,neighbour,weight;

    for(int i=0; i<200; i++){
        current = rand()%N;
        neighbour = rand()%N;
        weight = rand()%20+1;

        edge_list.push_back({{current,neighbour},weight});
    }
}

void generate_dense_graph(){

    edge_list.clear();

    int weight;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){

            weight = rand()%20+1;

            edge_list.push_back({{i,j},weight});
        }
    }
}

void floyd_warshall(int n){

    vector<int> vec(n,INF);
    vector<vector<int>> adj_matrix(n,vec);

    for(auto [x,y] : edge_list){
        adj_matrix[x.first][x.second] = y;
    }

    for(int i=0; i<n; i++){
        adj_matrix[i][i] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(j==i) continue;

            for(int k=0; k<n; k++){

                if(k==j) continue;

                if(adj_matrix[j][i]==INF || adj_matrix[i][k]==INF)
                    continue;

                if(adj_matrix[j][i]+adj_matrix[i][k] < adj_matrix[j][k]){
                    adj_matrix[j][k] =
                        adj_matrix[j][i]+adj_matrix[i][k];
                }
            }
        }
    }
}

void bellman_ford(int n, int src){

    h.clear();
    h.resize(n,INF);

    h[src] = 0;

    for(int i=0; i<n-1; i++){

        for(auto [x,y] : edge_list){

            if(h[x.first]==INF) continue;

            if(h[x.first]+y < h[x.second])
                h[x.second] = h[x.first]+y;
        }
    }
}

void dijkstra(int src){

    dist.clear();
    dist.resize(N,INF);

    dist[src] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({dist[src],src});

    pair<int,int> current;

    while(!pq.empty()){

        current = pq.top();
        pq.pop();

        if(current.first>dist[current.second])
            continue;

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

    adj_list.clear();
    adj_list.resize(n);

    for(auto [x,y] : edge_list){

        int current = x.first;
        int neighbour = x.second;
        int weight = y;

        if(current==new_src)
            continue;

        int new_weight = weight+h[current]-h[neighbour];

        adj_list[current].push_back({neighbour,new_weight});
    }

    for(int i=0; i<n; i++){

        dijkstra(i);

        for(int j=0; j<n; j++){

            if(dist[j]==INF)
                continue;

            dist[j] = dist[j]-h[i]+h[j];
        }
    }
}

int main() {

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    // -------- Your algorithm here --------

    generate_sparse_graph();
    floyd_warshall(N);

    edge_list.clear();

    generate_sparse_graph();
    johnson(N);

    edge_list.clear();

    generate_dense_graph();
    floyd_warshall(N);

    edge_list.clear();

    generate_dense_graph();
    johnson(N);

    // -------------------------------------

    QueryPerformanceCounter(&end);

    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;         // Joules
    double energy_kWh = energy / 3.6e6;                // kWh
    double co2 = energy_kWh * BD_EMISSION_FACTOR;      // kg CO₂

    // ----- Memory usage -----
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize; // Peak RAM usage

        printf("Execution time: %.6f seconds\n", elapsed);
        printf("Estimated energy consumption: %.2f Joules\n", energy);
        printf("Peak Memory Usage: %zu KB\n", peakMemUsed / 1024);
        printf("Estimated CO2 emissions (Bangladesh): %.8f kg\n", co2);
    } else {
        printf("Failed to get memory info.\n");
    }

    return 0;
}