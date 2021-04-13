#include <iostream>
#include <vector>
#include <algorithm>

int cache[1000005];
int beacons[1000005][2];

using namespace std;

int main() {
    int n;
    vector<int> b;

    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        b.emplace_back(tmp1);
        beacons[tmp1][0] = 1, beacons[tmp1][1] = tmp2;
    }

    sort(b.begin(), b.end());

    cache[0] = 0;
    int maximum = 0;

    for(int i = 0; i < n; i++){
        int temp = b[i] - beacons[b[i]][1];
        if(temp <= 0) {
            cache[b[i]] = 1;
            continue;
        }
        int j = temp - 1;

        while(j > -1){
            if(beacons[j][0] == 1)
                break;
            j--;
        }

        if(j > -1)
            cache[b[i]] = cache[j] + 1;
        else
            cache[b[i]] = 1;
    }

    for(int i = 0; i <= b[n - 1]; i++){
        if(maximum < cache[i])
            maximum = cache[i];
    }

    int result = n - maximum;

    cout << result << endl;

    return 0;
}
