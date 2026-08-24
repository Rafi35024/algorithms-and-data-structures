#include <bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
using namespace std;

#pragma comment(lib, "Psapi.lib")

using namespace std;

// Replace with your CPU's approximate average power (Watts)
constexpr double CPU_POWER_WATTS = 65.0;

// Bangladesh grid emission factor (kg CO₂ / kWh)
constexpr double BD_EMISSION_FACTOR = 0.62;

int main() {
    LARGE_INTEGER freq, start, end;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    // -------- Your algorithm here --------
    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; i++) 
        cin >> vec[i];
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        bool flag = false;
        for(int i=0; i<n; i++){
            if(vec[i]==s){
                cout << s << " - found" << endl;
                flag = true;
                break; 
            }
        }
        if(!flag){
            cout << s << " - not found" << endl;
        }
    }
    // -------------------------------------

    QueryPerformanceCounter(&end);

    double elapsed = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;      // Joules
    double energy_kWh = energy / 3.6e6;             // kWh
    double co2 = energy_kWh * BD_EMISSION_FACTOR;   // kg CO₂

    // ----- Memory usage -----
    PROCESS_MEMORY_COUNTERS_EX pmc;

    if (GetProcessMemoryInfo(
            GetCurrentProcess(),
            reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&pmc),
            sizeof(pmc))) {

        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize;

        cout << "Execution time: " << elapsed << " seconds\n";
        cout << "Estimated energy consumption: " << energy << " Joules\n";
        cout << "Peak Memory Usage: " << peakMemUsed / 1024 << " KB\n";
        cout << "Estimated CO2 emissions (Bangladesh): "
             << co2 << " kg\n";
    }
    else {
        cout << "Failed to get memory info.\n";
    }

    return 0;
}