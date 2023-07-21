// 15 - 3Sum (LeetCode Exercise)

// Time Complexity: O(n^2) - First iteration for the first value, second iteration uses TwoSum for second and third
// Space Compleixty: O(1) if sorted in place or O(n) if not

#include <vector>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> solutions;
        if (nums.size() < 3) return solutions;

        /* Sort the input array */
        std::sort(nums.begin(), nums.end());

        std::set<std::vector<int>> solutionsSeen;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int desiredTwoSum = 0 - nums[i];

            int l = i+1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int currentSum = nums[l] + nums[r];
                if (currentSum > desiredTwoSum)
                {
                    r--;
                }
                else if (currentSum < desiredTwoSum)
                {
                    l++;
                }
                else
                {
                    std::vector<int> solution{nums[i], nums[l], nums[r]};
                    if (solutionsSeen.find(solution) == solutionsSeen.end())
                    {
                        solutions.push_back(solution);
                        solutionsSeen.emplace(solution);
                    }
                    l++;
                    r--;
                }
            }

        }

        return solutions;
    }