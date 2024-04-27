#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
int maxGroups(int x, int y, int z) {
    vector<int> stones {x, y, z};
    sort(stones.begin(), stones.end());

    vector<int> rem(3, 0);
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        res += stones[i] /3;
        rem[i] = stones[i] % 3;
    }

    sort(rem.begin(), rem.end());

    // elements in rem is 0 or 1 or 2
    return res + rem[0];
}

int main() {
    // 1 3 3 -> 2
    // 2, 3, 5 -> 2 
    // 2, 3, 6 -> 3 
    int group;
    cin >> group;
    int cnt = 0;
    while (cnt < group) {
        int x, y, z;
        cin >> x >> y >> z;
        int result = maxGroups(x, y, z);
        // cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
        cout << "res = " << result << endl;
        ++cnt;
    }
}