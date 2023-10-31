#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, m;
vector<int> A;
vector<int> sA;
vector<int> B;
vector<int> sB;
int main() {
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            sA.push_back(sum);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += B[j];
            sB.push_back(sum);
        }
    }

    sort(sB.begin(), sB.end());

    long long ans = 0;
    for (int i = 0; i < sA.size(); i++) {
        int f = t - sA[i];
        auto up = upper_bound(sB.begin(), sB.end(), f);
        auto lp = lower_bound(sB.begin(), sB.end(), f);
        ans += up - lp;
    }
    cout << ans << "\n";
}