int min_index(int arr[], int n, int x)
{
    int su = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        su += arr[i];
        if (su >= x)
        {
            ans = i;
            break;
        }
    }

    return ans;
}