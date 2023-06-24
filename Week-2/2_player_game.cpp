#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int m, vector<vector<int>>& w) {
  vector<vector<int>> T(n, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (j == m) {
        T[i][j] = w[i][0] + w[0][i];
      } else {
        for (int k = 0; k < n; k++) {
          T[i][j] = max(T[i][j], w[i][0] + T[k][j - 1]);
        }
      }
    }
  }
  int result = 1;
if (T[0][m] > T[1][m]) {
  result = 1;
} else {
  result = 2;
}
return result;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> w(n * (n - 1) / 2);
  for (int i = 0; i < int(w.size()); i++) {
  w[i].resize(m + 1);
  for (int j = 0; j < m + 1; j++) {
    cin >> w[i][j];
  }
}
  cout << solve(n, m, w) << endl;
  return 0;
}