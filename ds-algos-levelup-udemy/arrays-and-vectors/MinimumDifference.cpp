// 두 배열에서 한 개씩 꺼내어 뺐을때, 절대값이 최소가 되게 하는 경우를 찾기
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

pair<int,int> minDifference1(vector<int> a,vector<int> b){
    //Complete this method
    int n = a.size();
    int m = b.size();

    int diff = 0;
    int min_diff = INT_MAX;
    pair<int, int> p;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            diff = abs(a[i] - b[j]);
            cout << "diff: " << diff << endl;
            min_diff = min(diff, min_diff);
            cout << "min_diff: " << min_diff << endl;
            if (diff == min_diff) {
                p.first = a[i];
                p.second = b[i];
            }
        }
    }

    return p;
}

pair<int,int> minDifference2(vector<int> a,vector<int> b){
    //Complete this method
    int n1 = a.size();
    int n2 = b.size();
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    pair<int,int> result;
    int ans = INT_MAX;
    
    int i = 0;
    int j = 0;
    
    while(i < n1 && j < n2)
    {
        int minDiff = abs(a[i] - b[j]);
        
        if(minDiff < ans)
        {
            ans = minDiff;
            result = make_pair(a[i],b[j]);
        }
        if(a[i] <= b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    
    return result;
}

int main() {
    vector<int> a {23, 5, 10, 17, 30};
    vector<int> b {26, 134, 135, 14, 19};
    pair<int, int> pp = minDifference1(a, b);
    cout << pp.first << " " << pp.second << endl;
    return 0;
}