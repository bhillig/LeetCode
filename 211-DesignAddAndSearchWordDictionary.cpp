// 211 - Design Add And Search Words Dictionary (LeetCode Exercise)

#include <map>
#include <string>

class TrieNode
{
public:
    TrieNode()
    {
        children = {};
        endOfWord = false;
    }

    std::map<char, TrieNode*> children;
    bool endOfWord;
};

class WordDictionary 
{
public:
    WordDictionary() 
    {
        root = new TrieNode();
    }
    
    void addWord(string word) 
    {
        TrieNode* curr = root;

        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }

            curr = curr->children[c];
        }

        curr->endOfWord = true;
    }
    
    bool dfs(int index, TrieNode* root, const std::string& word)
    {
        TrieNode* curr = root;

        for (int i = index; i < word.size(); ++i)
        {
            char c = word[i];

            if (c == '.')
            {
                for (auto& [character,path] : curr->children)
                {
                    if (dfs(i + 1, path, word)) return true;
                }
                return false;
            }
            else
            {
                if (curr->children.find(c) == curr->children.end()) return false;

                curr = curr->children[c];
            }
        }

        return curr->endOfWord;
    }

    bool search(std::string word) 
    {
        return dfs(0, root, word);
    }

    TrieNode* root;
};