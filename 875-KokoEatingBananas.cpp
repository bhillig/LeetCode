// 875 - Koko Eating Bananas

// Time Complexity: O(log(max(piles)) * n) - Binary search from 1 to max_element(piles).
// At each step we iterate over piles

// Space Complexity: O(1) - We use constant amount of space no matter the input size

#include <vector>
#include <algorithm>

int minEatingSpeed(std::vector<int>& piles, int h) 
{
    int l = 1;    
    int r = *std::max_element(piles.begin(), piles.end());

    int currentMin = r;

    while (l <= r)
    {
        int k = l + (r-l)/2;

        int hours = 0;
        for(int i = 0; i < piles.size(); ++i)
        {
            hours += piles[i] / k;
            if (piles[i] % k > 0)
            {
                ++hours;
            }

            if (hours > h) break;
        }

        if (hours <= h)
        {
            currentMin = k;
            r = k - 1;
        }
        else
        {
            l = k + 1;
        }
    }

    return currentMin;

}