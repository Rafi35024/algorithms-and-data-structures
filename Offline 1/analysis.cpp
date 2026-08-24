#include <windows.h>
#include <psapi.h>
#include <stdio.h>

#pragma comment(lib, "Psapi.lib")  // Needed for MSVC linking

// Replace with your CPU's approximate average power (Watts)
#define CPU_POWER_WATTS 65.0
// Bangladesh grid emission factor (kg CO₂ / kWh)
#define BD_EMISSION_FACTOR 0.62

int main() {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    // -------- Your algorithm here --------
    

int vec[100000];

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

    
    for(int i=0; i<n; i++){
        cin >> x;
        vec.push_back(x);
    }

    merge_sort(0,n-1);
    for(auto x : vec) cout << x << " ";

    return 0;
}

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