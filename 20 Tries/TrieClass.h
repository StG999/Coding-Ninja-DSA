#include <iostream>

using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode **children;
        bool isTerminal;

        TrieNode(char d)
        {
            data = d;
            isTerminal = false;
            children = new TrieNode*[26];
            for(int i=0; i<26; i++)
                children[i] = nullptr;
        }
};

class Trie
{
    TrieNode *root;

    public:
        Trie()
        {
            root = new TrieNode(0);
        }

        void insert(string input, TrieNode *root)
        {
            if(input.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            TrieNode *child;
            int index = input[0] - 'a';
            if(root->children[index] != nullptr)
                child = root->children[index];
            
            else
            {
                child = new TrieNode(input[0]);
                root->children[index] = child;
            }

            insert(input.substr(1), child);
        }

        void insert(string input)
        {
            insert(input, root);
        }

        bool search(string input, TrieNode *root)
        {
            if(input.size() == 0)
            {
                if(root->isTerminal == true)
                    return true;
                
                return false;
            }

            int index = input[0] - 'a';

            if(root->children[index] == nullptr)
                return false;
            
            return search(input.substr(1), root->children[index]);
        }

        bool search(string input)
        {
            return search(input, root);
        }

        void remove(string input, TrieNode *root)
        {
            if(input.size() == 0)
            {
                root->isTerminal = false;
                return;
            }

            TrieNode *child;
            int index = input[0] - 'a';

            if(root->children[index] == NULL)
                return;
            
            child = root->children[index];

            remove(input.substr(1), child);

            if(child->isTerminal == false)
            {
                for(int i=0; i<26; i++)
                    if(child->children[i] != nullptr)
                        return;
            }

            delete child;
            root->children[index] = nullptr;
        }

        void remove(string input)
        {
            remove(input, root);
        }
};