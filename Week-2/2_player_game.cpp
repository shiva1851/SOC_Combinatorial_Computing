#include<bits/stdc++.h>
using namespace std;
// we try to traverse through all possible moves of player 1 at any grid and then assess possible moves that player 2 can make according to those of player 1.
// among them, we try to choose the one which has maximum weight.
// thus we keep on adding the max possible weights for player 2.
// after the last move, if the weights of player 2 is greater than that of player 1 in all the cases, then we say that player 2 has winning strategy.
// negation: if atleast one case exists where weights of player 1 is greater than palyer 2, then because player 1 makes first move, player 1 has winning strategy.
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
// store weights in the vector
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
