// 208 - Implement Trie (LeetCode Exercise)

#include <map>
#include <string>
#include <memory>

class TrieNode
{
public:
    TrieNode()
        : endOfWord(false)
    {

    }
    std::map<char, std::shared_ptr<TrieNode>> children;
    bool endOfWord;
};

class Trie {
public:
    Trie() 
    {
        root = std::make_shared<TrieNode>();
    }
    
    void insert(const std::string& word) 
    {
        TrieNode* curr = root.get();
        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = std::make_shared<TrieNode>();
            }
            curr = curr->children[c].get();
        }
        curr->endOfWord = true;
    }
    
    bool search(const std::string& word) 
    {
        TrieNode* curr = root.get();
        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c].get();
        }    
        return curr->endOfWord;
    }
    
    bool startsWith(const std::string& prefix) 
    {
        TrieNode* curr = root.get();
        for (char c : prefix)
        {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c].get();
        }    
        return true;
    }
private:
    std::shared_ptr<TrieNode> root;
};