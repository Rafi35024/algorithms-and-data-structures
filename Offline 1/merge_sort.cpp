//024
#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

void merge(int l, int mid, int h){
    vector<int> ans;
    int i = l, j = mid+1;
    while(i<=mid && j<=h){
        if(vec[i]<=vec[j]){
            ans.push_back(vec[i]);
            i++;
        }
        else{
            ans.push_back(vec[j]);
            j++;
        }
    }
    while(i<=mid){
        ans.push_back(vec[i]);
        i++;
    }
    while(j<=h){
        ans.push_back(vec[j]);
        j++;
    }
    for(int i=l,j=0; i<=h; i++,j++){
        vec[i] = ans[j];
    }
}

void merge_sort(int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,h);
        merge(l,mid,h);
    }
}

int main() {

    int n,x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        vec.push_back(x);
    }

    merge_sort(0,n-1);
    for(auto x : vec) cout << x << " ";

    return 0;
}