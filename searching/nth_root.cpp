// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int NthRoot(int n, int m)
	{
		// Code here.
		if (m == 1)
			return 1;
		int low = 1;
		int high = m / 2;
		while (low <= high)
		{
			int mid = low + high / 2;
			long long power = pow(mid, n);
			if (power == m)
				return mid;
			else if (power < m)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return -1;
	}
};

// { Driver Code Starts.
int main()
{
	int n, m;
	cin >> n >> m;
	Solution ob;
	int ans = ob.NthRoot(n, m);
	cout << ans << "\n";
	return 0;
} // } Driver Code Ends
