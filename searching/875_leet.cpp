/*
Question:- Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
*/

/* 
INTUTION:-
*take any number , say 3 and check if we can finish the banans in 'h' hours, 
piles = [3,6,7,11], h = 8
t=1 [0,6,7,11]
t=2 [0,3,7,11]   t=3 [0,0,7,11]
t=4 [0,0,4,11]   t=5 [0,0,1,11]  t=6[0,0,0,11]  
t=7 [0,0,0,8]    t=8 [0,0,0,5]   t=9[0,0,0,2] t=10[0,0,0,0]
total time =10hrs > h

* so now lets taka larger number, say 6
t=1 [0,6,7,11]
t=2 [0,0,7,11]
t=3 [0,0,1,11]  t=4[0,0,0,11]
t=5 [0,0,0,5]  t=6[0,0,0,0]
total time =6hrs <h

* so now that we know that in 'k' banans per hour the task can be acomplished, but we need minimum k,
now we have k=3 that is not enough and k=6 take is enough time so check for k=4 and 5 and we find that 4 will be the min k. (Simple binary search application)

*wo we find mid  as we do in BS and for 'k'(mid) we check if it is a candidate for k or not

*/

int minEatingSpeed(vector<int> &piles, int h)
{
  int time = 0;
  int n = piles.size();

  int low = 1;
  int high = 1000000000;

  while (low <= high)
  {
    time = 0;
    int mid = low + (high - low) / 2;
    for (int i = 0; i < n; i++)
    {
      time += ceil(1.0 * piles[i] / mid);
    }
    if (time > h)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
