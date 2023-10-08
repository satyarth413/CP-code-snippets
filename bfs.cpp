auto bfs = [&](int s) {
  vector<int> D(n, -1);
  D[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for (int w : adj[v]) {
      if (D[w] == -1) {
        D[w] = D[v] + 1;
        Q.push(w);
      }
    }
  }
  return D;
};