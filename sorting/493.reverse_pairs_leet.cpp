//application of inversion cnt;

int cnt = 0;
int reversePairs(vector<int> &nums)
{

    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return cnt;
}

void mergeSort(vector<int> &nums, int l, int h)
{
    if (l == h)
        return;
    int mid = (l + h) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, h);
    merge(nums, l, mid, h);
}

void merge(vector<int> &nums, int l, int mid, int h)
{
    int j = mid + 1;
    vector<int> tmp;
    for (int i = l; i <= mid; i++)
    {
        while (j <= h && (long)nums[i] > (long)2 * nums[j])
        {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    int i = l;
    j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (nums[i] < nums[j])
        {
            tmp.push_back(nums[i++]);
        }
        else
            tmp.push_back(nums[j++]);
    }
    while (i <= mid)
        tmp.push_back(nums[i++]);
    while (j <= h)
        tmp.push_back(nums[j++]);

    for (i = l; i <= h; i++)
    {
        nums[i] = tmp[i - l];
    }
}