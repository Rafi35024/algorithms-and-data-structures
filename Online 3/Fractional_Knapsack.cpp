//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    cout << fixed << setprecision(6);
    vector<tuple<double,double,double>> vec(val.size());
    for(int i=0; i<val.size(); i++){
        vec[i] = {(double)val[i]/wt[i], val[i], wt[i]};
    }
    sort(vec.begin(), vec.end(), greater<tuple<double,double,double>>());
    double ans = 0, cap = capacity;
    for(auto [x,y,z] : vec){
        double p = min(cap,z);
        ans += (p*y/z);
        cap -= p;
        if(cap==0) break;
    }
    return ans;
}

int main(){



    return 0;
}