//https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<int> &start, vector<int> &end) {
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int ans = 0, rooms = 0, i = 0, j = 0;
    int n = start.size();
    while(i<n && j<n){
        if(start[i]<end[j]){
            rooms++;
            i++;
        }
        else{
            j++;
            rooms--;
        }
        ans = max(ans,rooms);
    }
    return ans;
}

int main() {

    


    return 0;
}