#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_matrix;

void floyd_warshall(int n){
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            if(j==i) continue;
            for(int k=0; k<n; k++){
                if(k==j) continue;
                if(adj_matrix[j][i]==INT_MAX || adj_matrix[i][k]==INT_MAX) continue;
                if(adj_matrix[j][i]+adj_matrix[i][k] < adj_matrix[j][k]){
                    adj_matrix[j][k] = adj_matrix[j][i] + adj_matrix[i][k];
                }
            }
        }
    }
}

int main() {
    int n,e;
    cin >> n >> e;

    vector<int> vec(n,INT_MAX);
    adj_matrix.resize(n,vec);
    int current, neighbour, weight;
    for(int i=0; i<e; i++){
        cin >> current >> neighbour >> weight;
        adj_matrix[current][neighbour] = weight;
    }
    for(int i=0; i<n; i++){
        adj_matrix[i][i] = 0;
    }

    floyd_warshall(n);


    return 0;
}