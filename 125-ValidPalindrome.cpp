// 125 - Valid Palindrome (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>

std::string removeSpecialCharacter(std::string s)
{
    // Initialize an empty string
    std::string ans = "";
    for (auto ch : s) {
        // if the current character
        // is an alphabet
        if (isalnum(ch))
            ans += ch;
    }
    return ans;
}

bool isPalindrome(std::string b) {

    std::string s = removeSpecialCharacter(b);

    for(size_t i = 0; i < s.size(); ++i)
    {
        if (i > (s.size() -1 - i)) break;

        char t = tolower(s[i]);
        char u = tolower(s[s.size() - 1 - i]);

        if(t != u) return false;
    }

    return true;
}