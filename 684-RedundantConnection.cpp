// 684 - Redundant Connection (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>

class Solution {
public:

    int find(int n)
    {
        int p = par[n];

        while (p != par[p])
        {
            p = par[p];
        }

        return p;
    }

    bool join(std::vector<int>& edge)
    {
        int p1 = find(edge[0]);
        int p2 = find(edge[1]);

        if (p1 == p2) return false;

        if (rank[p1] > rank[p2])
        {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else
        {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }

    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) 
    {
        par = std::vector<int>(edges.size() + 1);
        for (int i = 0; i < par.size(); ++i)
            par[i] = i;

        rank = std::vector(par.size(), 1);

        for (std::vector<int>& edge : edges)
        {
            if (!join(edge)) return edge;
        }

        return {};
    }

    std::vector<int> par;
    std::vector<int> rank;
};