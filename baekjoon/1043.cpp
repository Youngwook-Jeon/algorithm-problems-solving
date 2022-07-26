// https://www.acmicpc.net/problem/1043
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int n, m, k, ans;
unordered_set<int> us;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    us.insert(a);
    q.push(a);
  }

  vector<vector<int> > party_people(m);

  for (int i = 0; i < m; i++) {
    int numbers;
    cin >> numbers;
    for (int j = 1; j <= numbers; j++) {
      int people;
      cin >> people;
      party_people[i].push_back(people);
    }
  }

  while (!q.empty()) {
    int truth = q.front();
    q.pop();

    for (int i = 0; i < m; i++) {
      bool flag = false;
      for (int people : party_people[i]) {
        if (people == truth) {
          flag = true;
        }
      }
      if (flag) {
        for (int people : party_people[i]) {
          if (us.find(people) == us.end()) {
            q.push(people);
            us.insert(people);
          }  
        }      
      }
    }
  }

  for (int i = 0; i < m; i++) {
    bool flag = false;
    for (int people : party_people[i]) {
      if (us.find(people) == us.end()) {
        flag = true;
      }
    }
    if (flag) ans++;
  }

  cout << ans << "\n";

  return 0;
}