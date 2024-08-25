#include <bits/stdc++.h>
using namespace std;

struct Event
{
    int time;
    int depart;
    int train;
};

bool comp(Event a, Event b)
{
    if (a.time == b.time)
    {
        if (a.depart == b.depart)
        {
            return a.train < b.train;
        }
        return a.depart < b.depart;
    }
    return a.time < b.time;
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    vector<int> b(m);
    vector<int> s(m);
    vector<int> t(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> s[i] >> t[i];
    }

    vector<Event> events;
    for (int i = 0; i < m; i++)
    {
        Event de{s[i], 1, i};
        Event ar{t[i], 0, i};
        events.push_back(de);
        events.push_back(ar);
    }

    sort(events.begin(), events.end(), comp);

    vector<int> ans(m);
    ans[0] = x;
    vector<int> stations(n + 1);

    for (Event e : events)
    {
        if (e.depart)
        {
            if (e.train)
            {
                ans[e.train] = max(ans[e.train], stations[a[e.train]] - e.time);
            }
        }
        else
        {
            stations[b[e.train]] = max(stations[b[e.train]], ans[e.train] + e.time);
        }
    }

    for (int i = 1; i < m; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}