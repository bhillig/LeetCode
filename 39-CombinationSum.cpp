// 39 - Combination Sum (LeetCode Exercise)

// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include <vector>

void combination(int i, std::vector<int>& comb, int total, int target, std::vector<std::vector<int>>& res, std::vector<int>& candidates)
{
    if(total > target) return;
    if(total == target)
    {
        res.push_back(comb); 
        return;
    }
    
    for (int index = i; index < candidates.size(); index++)
    { 
        comb.push_back(candidates[index]); 
        total += candidates[index];
        combination(index, comb, total, target, res, candidates); 
        comb.pop_back(); 
        total -= candidates[index];
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
{
    std::vector<std::vector<int>> result;
    std::vector<int> comb;
    combination(0, comb, 0, target, result, candidates);
    return result;
}