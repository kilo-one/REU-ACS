#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /* Число-перевертыш
    int am = 8765;
    int a = am % 10;
    int b = am / 10 % 10;
    int c = am / 100 % 10;
    int d = am / 1000;
    cout << a << b << c << d;
    */
    /* ЗАДАЧА ПРО ПРОЦЕНТЫ БАНКА
    float sum;
    float n;
    cin >> sum >> n;
    float q1 = ((sum * 0.05) / 365) * 30;
    float q2 = q1 * n;
    float q3 = sum + q2;
    cout << q1 << " " << q2 << " " << q3;
    */
    /* квадраты чисел от 1 до 10
    int n = 1;
    while (n <= 10) {
        cout << n << "\t" << n * n << "\n";
        ++n;
    }
    */
    /* если хотим получить коды букавок
    string line;
    getline(cin, line);
    for (char c : line) {
        cout << c << "\t" << static_cast<int>(c) << "\n";
    */
    /* Проверка, иожет ли ферзь попасть в заданную клетку из исходной
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if ((a1 == a2) || (b1 == b2)) {
        cout << "YES\n";
    } else if (abs(a1 - a2) == abs(b1 - b2)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    } */
    /* Вывести сумму цифр числа
    int k;
    cin >> k;
    int tr = 0;
    if (k >= 0 && k <= pow(10, 9)) {
        while (k > 0) {
            tr += k % 10;
            k = k / 10;
        }
    }
    cout << tr;
    */
    /*
    int k;
    cin >> k;
    unsigned long long int tr = 0;
    for (int i = 1; i <= k; i++) {
        unsigned long long int kol = i * i;
        tr += kol;
    }
    cout << tr << endl;
    */
    /*  ______________________________ | _________________________________
          Задача о кузнечике
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;

      int main() {
          int n;
          cin >> n;
          int* a = new int[n];
          for (int i = 0; i < n; i++) a[i] = 0;
          a[0] = 1;
          a[1] = 1;
          int m;
          cin >> m;
          for (int i = 0; i < m; i++) {
              int t;
              cin >> t;
              a[t] = -1;
          }
          for (int i = 2; i < n; i++) {
              if (a[i] == -1) a[i] = 0;
              else a[i] = a[i - 1] + a[i - 2];
          }
          cout << a[n - 1];
          return 0;
      }
      _______________________________________________________________
          Задача о черепашке
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;

      int main() {
          int n, m;
          cin >> n >> m;
          int a[n][m];
          for (int i = 0; i < n; i++)
              for (int j = 0; j < m; j++)
                  cin >> a[i][j];
          for (int i = 1; i < n; i++) a[i][0] += a[i - 1][0];
          for (int j = 1; j < m; j++) a[0][j] += a[0][j - 1];
          for (int i = 1; i < n; i++)
              for (int j = 1; j < m; j++)
                  a[i][j] += max(a[i][j - 1], a[i - 1][j]);
          cout << a[n - 1][m - 1];

          return 0;
      }
      _______________________________________________________________
          Задачи о размене суммы монетами с восстановлением ответа
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;

      int main() {
          const int INF = 1e9;
          int n, m;
          cin >> n >> m;
          vector <int> coins(m, 0);
          for (int i = 0; i < m; i++) cin >> coins[i];
          vector <int> f(n + 1, 0);
          vector <int> path(n + 1, 0);
          for (int i = 1; i <= n; i++) {
              f[i] = INF;
              for (auto c : coins) {
                  if (i - c >= 0 && f[i] >= f[i - c] + 1) {
                      f[i] = f[i - c] + 1;
                      path[i] = c;
                  }
              }
          }
          cout << f[n] << endl;
          int N = n;
          while (N > 0) {
              cout << path[n] << " ";
              N -= path[n];
          }
          return 0;
      }
      _______________________________________________________________
          Задача о колве способов размена суммы монет
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;

      int main() {
          const int INF = 1e9;
          int n, m;
          cin >> n >> m;
          vector <int> coins(m, 0);
          for (int i = 0; i < m; i++) cin >> coins[i];
          vector <int> f(n + 1, 0);
          f[0] = 1;
          for (int i = 1; i <= n; i++)
              for (auto c : coins)
                  if (i - c >= 0) f[i] += f[i - c];
          cout << f[n];
          return 0;
      }
      _______________________________________________________________
          НВП за квадрат
          _______________________________________________________________
  #include <iostream>
          using namespace std;

      int main()
      {
          int n;
          cin >> n;
          int* a = new int[n];
          for (int i = 0; i < n; i++)
          {
              cin >> a[i];
          }

          int* p = new int[n];
          int* l = new int[n];

          for (int i = 0; i < n; i++)
          {
              p[i] = -1;
          }

          for (int k = 0; k < n; k++)
          {
              l[k] = 1;
              for (int i = 0; i < k; i++)
              {
                  if (a[i] < a[k])
                  {
                      l[k] = max(l[k], l[i] + 1);
                      p[k] = i;
                  }
              }
          }

          int max = 0;
          int pos = 0;

          for (int i = 0; i < n; i++)
          {
              if (max < l[i])
              {
                  max = l[i];
                  pos = i;
              }
          }

          cout << max << " ";

      }
      _______________________________________________________________
          НВП за н логарифм н
          _______________________________________________________________
  #include<bits/stdc++.h>
          using namespace std;

      const int INF = 1e5;

      int main() {
          int n;
          cin >> n;

          int a[n];
          for (int i = 0; i < n; cin >> a[i++]);

          vector<int> d(n + 1, INF);
          d[0] = -INF;
          vector<int> index(n + 1, INF);
          vector<int> prev(n, -1);


          for (int i = 0; i < n; ++i) {//O(n)

              int left = 0, right = n;
              do {
                  int middle = (left + right) / 2;
                  if (d[middle] > a[i]) right = middle;
                  else left = middle;
              } while (right - left > 1);//O(logn)

              int j = right;

              if (d[j - 1] < a[i] && a[i] < d[j]) d[j] = a[i], index[j] = i;

              if (index[j] > index[j - 1]) prev[index[j]] = index[j - 1];

          }

          vector<int> path;

          int pos = n;
          while (index[pos] == INF)pos--;
          pos = index[pos];
          path.push_back(a[pos]);

          while (prev[pos] != -1) {
              pos = prev[pos];
              path.push_back(a[pos]);
          }

          for (int i = path.size() - 1; i >= 0; cout << path[i--] << " ");

          return 0;
      }
      _______________________________________________________________
          Задача о последовательностях без единиц
          _______________________________________________________________
  #include <iostream>
          using namespace std;

      int main()
      {
          int n, k;
          cin >> n >> k;

          int* f = new int[n + 1];

          for (int i = 0; i < k; i++)
          {
              f[i] = 1 << i;
          }

          for (int i = k; i <= n; i++)
          {
              f[i] = 0;
              for (int j = 1; j <= k; j++)
              {
                  f[i] += f[i - j];
              }
          }

          cout << f[n];
      }
      _______________________________________________________________
          Задача о нзначных послед сумма простое число
          _______________________________________________________________
  #include "bits/stdc++.h"
          using namespace std;
      int main() {
          int n;
          std::cin >> n;
          std::vector<std::vector<int>> f(n + 1, std::vector<int>(10, 0));
          for (int i = 1; i < 10; ++i) {
              f[1][i] = 1;
          }
          f[1][0] = 0;
          for (int i = 2; i < n + 1; ++i) {
              for (int j = 0; j < 10; ++j) {
                  switch (j) {
                  case 0:
                      f[i][j] = f[i - 1][2] + f[i - 1][3] + f[i - 1][5] + f[i - 1][7]; break;
                  case 1:
                      f[i][j] = f[i - 1][1] + f[i - 1][2] + f[i - 1][4] + f[i - 1][6]; break;
                  case 2:
                      f[i][j] = f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][5] + f[i - 1][9]; break;
                  case 3:
                      f[i][j] = f[i - 1][0] + f[i - 1][2] + f[i - 1][4] + f[i - 1][8]; break;
                  case 4:
                      f[i][j] = f[i - 1][1] + f[i - 1][3] + f[i - 1][7] + f[i - 1][9]; break;
                  case 5:
                      f[i][j] = f[i - 1][0] + f[i - 1][2] + f[i - 1][6] + f[i - 1][8]; break;
                  case 6:
                      f[i][j] = f[i - 1][1] + f[i - 1][5] + f[i - 1][7]; break;
                  case 7:
                      f[i][j] = f[i - 1][0] + f[i - 1][4] + f[i - 1][6]; break;
                  case 8:
                      f[i][j] = f[i - 1][3] + f[i - 1][5] + f[i - 1][9]; break;
                  case 9:
                      f[i][j] = f[i - 1][2] + f[i - 1][4] + f[i - 1][8]; break;
                  }
              }
          }
          int solve = 0;
          for (int i = 0; i < 10; ++i) {
              solve += f[n][i];
          }
          std::cout << solve;
          return 0;
      }

      _______________________________________________________
          без 2 3 к единиц подрят
          _________________________________________
  #include <iostream>
          using namespace std;
      int main() {
          int n, k;
          cin >> n >> k;
          int f[n + 1];
          for (int i = 0; i < k; i++) {
              f[i] = 1 « i;
          }
          for (int i = k; i <= n; i++) {
              f[i] = 0;
              for (int j = 1; j <= k; j++) {
                  f[i] += f[i - j];
              }
          }
          cout << f[n];
      }
      ______________________________________________________________
          Нечестная пизда
          _______________________________________________________________
  #include<bits/stdc++.h>
          using namespace std;

      int main() {
          int n, k;
          cin >> n >> k;
          bool a[n + 1][n + 1];

          for (int j = 1; j <= n; ++j) {
              a[0][j] = true;
          }

          for (int i = 1; i <= n; ++i) {
              for (int j = 1; j <= n; ++j) {
                  a[i][j] = true;
                  int m = j + 1;
                  if (m > i) m = i;

                  for (int t = 1; t <= m; ++t) {
                      a[i][j] = a[i][j] and a[i - t][t];
                  }
                  a[i][j] = !a[i][j];
              }
          }

          int m = k;
          if (m > n) m = n;
          for (int t = 1; t <= m; ++t) {
              if (!a[n - t][t]) cout << t << " ";
          }

          return 0;
      }
      _______________________________________________________________
          Обход в глубину
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;
      vector <vector <long long>> graph;
      vector <bool> used;
      void dfs(long long v) {
          used[v] = 1;
          for (auto u : graph[v]) {
              if (!used[u]) {
                  dfs(u);
              }
          }
      }
      int main()
      {
          long long n;
          cin >> n;
          graph.resize(n + 1);
          used.resize(n + 1, false);
          for (int i = 0; i < m; i++) {
              long long a, b;
              cin >> a >> b;
              graph[a].push_back(b);
              graph[b].push_back(a);
          }
          dfs(1);
      }
      _______________________________________________________________
          Обход в ширину
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;

      int main() {
          const int INF = 1e9;
          int n, m;
          cin >> n >> m;
          vector <vector <int>> graph(n + 1);
          vector <int> dist(n + 1, INF);
          for (int i = 0; i < m; i++) {
              int a, b;
              cin >> a >> b;
              graph[a].push_back(b);
              graph[b].push_back(a);
          }
          queue <int> q;
          q.push(1);
          dist[1] = 0;
          while (!q.empty()) {
              int v = q.front();
              q.pop();
              for (auto u : graph[v]) {
                  if (dist[u] == INF) {
                      dist[u] = dist[v] + 1;
                      q.push(u);
                  }
              }
          }
          return 0;
      }
      _______________________________________________________________
          Поиск компонент связности
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;

      int main() {
          const int INF = 1e9;
          int n, m;
          cin >> n >> m;
          vector <vector <int>> graph(n + 1);
          vector <bool> used(n + 1, false);
          for (int i = 0; i < m; i++) {
              int a, b;
              cin >> a >> b;
              graph[a].push_back(b);
              graph[b].push_back(a);
          }
          int count = 0;
          for (int i = 1; i <= n; i++) {
              if (!used[i]) {
                  count++;
                  used[i] = true;
                  queue <int> q;
                  q.push(i);
                  while (!q.empty()) {
                      int v = q.front();
                      q.pop();
                      for (auto u : graph[v]) {
                          if (!used[u]) {
                              used[u] = true;
                              q.push(u);
                          }
                      }
                  }
              }
          }
          cout << count;
          return 0;
      }
      _______________________________________________________________
          Проверка графа на цикличность
          _______________________________________________________________
  #include <iostream>
  #include <vector>
  #include <map>
  #include <queue>
          using namespace std;
      vector<int> distant;
      vector<bool> visited;
      vector<int> pred;
      map<int, vector<int>> adj;
      bool Cycle = 0;

      void bfs(int s)
      {
          visited[s] = 1;
          distant[s] = 0;
          pred[s] = -1;

          queue<int> q;
          q.push(s);

          while (!q.empty())
          {
              int x = q.front();
              q.pop();
              for (auto u : adj[x])
              {

                  if (visited[u] and u != pred[x]) Cycle = 1;

                  if (!visited[u]) {
                      pred[u] = x;
                      visited[u] = 1;
                      distant[u] = distant[x] + 1;
                      q.push(u);
                  }
              }
          }
      }

      int main()
      {
          int n, m;

          cin >> n >> m;

          for (int i = 0; i < m; i++)
          {
              pair<int, int> edge;
              cin >> edge.first >> edge.second;
              adj[edge.first].push_back(edge.second);
              adj[edge.second].push_back(edge.first);
          }

          visited.resize(n);
          fill(visited.begin(), visited.end(), 0);
          distant.resize(n);
          fill(distant.begin(), distant.end(), 1000000);
          pred.resize(n);

          bfs(0);

          cout << Cycle;
      }
      _______________________________________________________________
          Алгоритм Беллмана
          _______________________________________________________________
  #include <iostream>
  #include <map>
  #include <vector>

          using namespace std;

      const int INF = 1e9;

      struct Edge {
          int a;
          int b;
          int weight;
      };

      int main() {
          int n, m;
          cin >> n >> m;

          map<int, vector<pair<int, int>>> adj;

          for (int i = 0; i < m; i++) {
              Edge edge;
              cin >> edge.a >> edge.b >> edge.weight;
              adj[edge.a].push_back({ edge.b, edge.weight });
              adj[edge.b].push_back({ edge.a, edge.weight });
          }

          vector<int> distant(n, INF);
          distant[0] = 0;

          bool flag = 0;

          for (int i = 0; i < n; i++) {
              for (auto edge : adj) {
                  int a = edge.first;
                  for (auto bw : edge.second) {
                      int b = bw.first, w = bw.second;

                      distant[b - 1] = min(distant[b - 1], distant[a - 1] + w);
                  }
              }
          }
          for (int i = 0; i < distant.size(); i++) {
              cout << distant[i] << " ";
          }
      }
      _______________________________________________________________
          Алгоритм Дейкстры
          _______________________________________________________________
  #include <iostream>
  #include <vector>
  #include <map>
  #include <queue>
          using namespace std;

      const int INF = 1e9;

      struct Edge
      {
          int a;
          int b;
          int weight;
      };

      int main()
      {
          int n, m;
          cin >> n >> m;
          map<int, vector<pair<int, int>>> adj;

          for (int i = 0; i < m; i++)
          {
              Edge edge;
              cin >> edge.a >> edge.b >> edge.weight;
              adj[edge.a].push_back({ edge.b, edge.weight });
              adj[edge.b].push_back({ edge.a, edge.weight });
          }

          vector<int> d(n, INF);
          vector<bool> visited(n, 0);

          d[0] = 0;

          priority_queue<pair<int, int>> q;

          q.push({ 0 , 0 });

          while (!q.empty())
          {
              int a = q.top().second;
              q.pop();

              if (visited[a]) continue;
              visited[a] = 1;

              for (auto x : adj[a])
              {
                  int b = x.first, w = x.second;

                  if (d[a] + w < d[b])
                  {
                      d[b] = d[a] + w;
                      q.push({ d[b],b });
                  }
              }
          }
      }
      _______________________________________________________________
          Алгоритм Джорджа Флойда
          _______________________________________________________________
      #include <bits/stdc++.h>
          using namespace std;
      int main()
      {
          long long n;
          const long long INF = 99999999;
          cin >> n;
          vector <vector <long long>> g(n + 1, vector <long long>(n + 1, 0));
          vector <vector <long long>> d(n + 1, vector <long long>(n + 1, INF));
          vector <vector <long long>> prev(n + 1, vector <long long>(n + 1, 0));
          for (int i = 1; i <= n; i++) {
              for (int j = 1; j <= n; j++) {
                  cin >> g[i][j];
                  if (g[i][j] != 0) {
                      d[i][j] = g[i][j];
                      prev[i][j] = j;
                  }
              }
          }
          for (int i = 1; i <= n; i++) {
              d[i][i] = 0;
          }
          for (int k = 1; k <= n; k++) {
              for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= n; j++) {
                      if (d[i][k] < INF && d[k][j] < INF) {
                          if (d[i][j] > d[i][k] + d[k][j]) {
                              d[i][j] = d[i][k] + d[k][j];
                              prev[i][j] = prev[i][k];
                          }
                      }
                  }
              }
          }
          if (d[start][finish] == INF) {
              cout << "No path!";
              return 0;
          }
          cout << d[start][finish] << endl;
          long long start, finish;
          cin >> start >> finish;
          long long dop = start;
          while (dop != finish) {
              cout << dop << " ";
              dop = prev[dop][finish];
          }
          cout << finish;
      }
      _______________________________________________________________
          Топологическая сортировка
          _______________________________________________________________
      #include <bits/stdc++.h>
          using namespace std;
      int main() {
          int n, m, x, y;
          cin >> n >> m;
          vector <int> count_in(n, 0);
          vector <vector <int> > graph(n);
          for (int i = 0; i < m; i++) {
              cin >> x >> y;
              x--; y--;
              graph[x].push_back(y);
              count_in[y]++;
          }
          queue <int> q;
          vector <int> ans;
          for (int i = 0; i < n; i++) {
              if (count_in[i] == 0) {
                  q.push(i);
              }
          }
          while (!q.empty()) {
              x = q.front();
              q.pop();
              ans.push_back(x);
              for (auto to : graph[x]) {
                  count_in[to]--;
                  if (count_in[to] == 0) {
                      q.push(to);
                  }
              }
          }
          if (ans.size() == n) {
              cout << "Yes\n";
              for (auto e : ans) {
                  cout << e + 1 << " ";
              }
          }
          else {
              cout << "No\n";
          }
          return 0;
      }
      _______________________________________________________________
          Алгоритм Прима
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;
      int INF = 1000000000;
      int main() {
          int n, m;
          cin >> n >> m;
          vector <vector <pair <int, int> > > v(n);
          int x, y, w;
          for (int i = 0; i < m; i++) {
              cin >> x >> y >> w;
              x--; y--;
              v[x].push_back({ y, w });
              v[y].push_back({ x, w });
          }
          int dist[n], color[n];
          for (int i = 0; i < n; i++) {
              dist[i] = INF;
              color[i] = 0;
          }
          dist[0] = 0;
          set <pair <int, int> > s;
          int ans = 0;
          for (int i = 0; i < n; i++) {
              s.insert({ dist[i], i });
          }
          while (!s.empty()) {
              x = (*s.begin()).second;
              ans += dist[x];
              color[x] = 1;
              s.erase(s.begin());
              for (auto p : v[x]) {
                  y = p.first;
                  w = p.second;
                  if (w < dist[y] && color[y] == 0) {
                      s.erase({ dist[y], y });
                      dist[y] = w;
                      s.insert({ dist[y], y });
                  }
              }
          }
          cout << ans << "\n";
          return 0;
      }
      _______________________________________________________________
          Алгоритм Краскала
          _______________________________________________________________
  #include <bits/stdc++.h>
          using namespace std;
      vector <int> par, size;
      int get(int x) {
          if (x == par[x]) {
              return x;
          }
          int y = get(par[x]);
          par[x] = y;
          return y;
      }
      bool merge(int x, int y) {
          x = get(x);
          y = get(y);
          if (x == y) {
              return false;
          }
          if (size[x] < size[y]) {
              swap(x, y);
          }
          par[y] = x;
          size[x] += size[y];
          return true;
      }
      int main() {
          int n, m;
          cin >> n >> m;
          vector <pair <int, pair <int, int> > > v(m);
          int x, y, w;
          for (int i = 0; i < m; i++) {
              cin >> x >> y >> w;
              x--; y--;
              v.push_back({ w, {x, y} });
          }
          sort(v.begin(), v.end());
          par.resize(n);
          size.resize(n);
          for (int i = 0; i < n; i++) {
              par[i] = i;
              size[i] = 1;
          }
          int ans = 0;
          for (auto p : v) {
              if (merge(p.second.first, p.second.second)) {
                  ans += p.first;
              }
          }
          cout << ans << "\n";
          return 0;
      }
      _______________________________________________________________
          СМН реализован в Краскале
          _______________________________________________________________
          */

          /*
          ifstream fin("D://Users//Anaheim//Desktop//test.txt");
          vector <int> a;
          while (!fin.eof()) {
              int tmp = 0;
              fin >> tmp;
              a.push_back(tmp);
          }
          for (size_t i = 0; i < a.size()-1; i+=1) {
              if (i % 2 == 0) {
                  cout << a[i] << " ";
              }
          }
          */


          /*vector<int> v;
          int ae;
          while (cin >> ae) {
              v.push_back(ae);
          }
          for (size_t i = 0; i != v.size(); ++i) {
              if (i % 2 == 0) {
                  cout << v[i] << ' ';
              }
          }*/


          /* SOUNDEX!!!!!!!!!!!!!!! ____________________________________________________________________________________________
          string str;
          getline(cin, str);
          for (size_t i = 1; i < str.size(); ++i) {
              if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'h') || (str[i] == 'i') ||
                  (str[i] == 'o') || (str[i] == 'u') || (str[i] == 'w') || (str[i] == 'y')) {
                  str.erase(i, 1);
                  i--;
              }
              if (i >= 1) {
                  if ((str[i] == 'b') || (str[i] == 'f') || (str[i] == 'p') || (str[i] == 'v')) {
                      str[i] = '1';
                  }
                  else if ((str[i] == 'c') || (str[i] == 'g') || (str[i] == 'j') || (str[i] == 'k') ||
                      (str[i] == 'q') || (str[i] == 's') || (str[i] == 'x') || (str[i] == 'z')) {
                      str[i] = '2';
                  }
                  else if ((str[i] == 'd') || (str[i] == 't')) {
                      str[i] = '3';
                  }
                  else if (str[i] == 'l') {
                      str[i] = '4';
                  }
                  else if ((str[i] == 'm') || (str[i] == 'n')) {
                      str[i] = '5';
                  }
                  else if (str[i] == 'r') {
                      str[i] = '6';
                  }
              }
          }
          for (size_t i = 1; i < str.size(); ++i) {
              if ((str[i - 1] == str[i]) && (i > 1)) {
                  str.erase(i, 1);
                  --i;
              }
          }
          while (str.size() < 4) {
              str.push_back('0');
          }
          if (str.size() > 4) {
              string s = str.substr(0, 4);
              cout << s;
          }
          else {
              cout << str;
          }*/

    string str;
    int lines = 0, words = 0, letters = 0;
    while (getline(cin, str)) {
        ++lines;
        for (size_t i = 1; i < str.size(); ++i) {
            if (static_cast<char>(str[i - 1]) < 65 && static_cast<char>(str[i]) < 65) {
                break;
            }
            else if (static_cast<char>(str[i - 1]) < 65) {
                ++words;
            }
            else if (static_cast<char>(str[i]) < 65) {
                ++words;
            }
            else if ((65 <= static_cast<char>(str[i - 1]) && static_cast<char>(str[i - 1]) <= 90) || (97 <= static_cast<char>(str[i - 1]) && static_cast<char>(str[i - 1]) <= 122)) {
                ++letters;
            }
        }
    }
    cout << lines << '\n' << words + lines << '\n' << letters;



    return 0;
}
