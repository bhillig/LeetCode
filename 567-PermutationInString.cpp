// 567 - Permutation In String (LeetCode Exercise)

// Time Complexity: O(n) where n is the length of s2
// Space Complexity: O(1) since we always have two arrays of size 26 no matter the input

#include <string>
#include <array>

bool checkInclusion(const std::string& s1, const std::string& s2) 
{
    if (s1.size() > s2.size()) return false;

    const int ALPHABET_SIZE = 26;
    typedef std::array<int, ALPHABET_SIZE> Alphabet;

    Alphabet s1Map = {};
    Alphabet s2Map = {};
    for (int i = 0; i < s1.size(); ++i)
    {
        s1Map[s1[i] - 'a'] += 1;
        s2Map[s2[i] - 'a'] += 1;
    }

    int matches = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (s1Map[i] == s2Map[i]) ++matches;
    }

    if (matches == ALPHABET_SIZE) return true;

    int l = 1;
    int r = s1.size();

    while (r < s2.size())
    {
        int charLostIndex = s2[l-1] - 'a';
        s2Map[charLostIndex] -= 1;

        if (s1Map[charLostIndex] == s2Map[charLostIndex]) ++matches;
        else if (s2Map[charLostIndex] + 1 == s1Map[charLostIndex]) --matches;

        int charGainedIndex = s2[r] - 'a';
        s2Map[charGainedIndex] += 1;

        if (s1Map[charGainedIndex] == s2Map[charGainedIndex]) ++matches;
        else if (s2Map[charGainedIndex] - 1 == s1Map[charGainedIndex]) --matches;

        if (matches == ALPHABET_SIZE) return true;

        l += 1;
        r += 1;
    }

    return false;
}