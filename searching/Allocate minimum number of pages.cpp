int findPages(int a[], int n, int m)
{
    // code here
    int low = INT_MIN;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, a[i]);
        high += a[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (!can_divide(mid, a, n, m))
            low = mid + 1;
        else
        {
            if (!can_divide(mid - 1, a, n, m))
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

bool can_divide(int given_sum, int a[], int n, int m)
{
    int cnt = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > given_sum)
            return false;
        else if ((sum + a[i]) > given_sum)
        {
            cnt++;
            if (cnt > m)
                return false;
            sum = a[i];
        }
        else
            sum += a[i];
    }

    return true;
}
