// https://www.acmicpc.net/problem/1655
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
// 중간값을 포함하여 그 이하의 수들을 유지할 Max queue
priority_queue<int> max_q;
// 중간값 이상의 수들을 유지할 Min queue
// 따라서 두 큐의 사이즈 차이는 최대 1만큼.
priority_queue<int, vector<int>, greater<int>> min_q;

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    if (max_q.size() == min_q.size())
    {
      max_q.push(num);
    }
    else
    {
      min_q.push(num);
    }

    if (!max_q.empty() && !min_q.empty())
    {
      int cur_max = max_q.top();
      int cur_min = min_q.top();
      if (cur_max > cur_min)
      {
        max_q.pop();
        min_q.pop();
        max_q.push(cur_min);
        min_q.push(cur_max);
      }
    }

    cout << max_q.top() << '\n';
  }
  return 0;
}