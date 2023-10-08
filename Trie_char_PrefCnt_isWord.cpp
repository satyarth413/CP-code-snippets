// https://atcoder.jp/contests/abc268/submissions/34830370
class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    int cnt;
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
        cnt=0;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
            p->cnt++;
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns count of words in the trie
    // that starts with the given prefix.
    int startsWith(string prefix)
    {
    	TrieNode* prefNode=find(prefix);
        return prefNode==NULL ? 0LL : prefNode->cnt;
    }

    // Returns count of words in the trie
    // which have key as prefix
	int get_sum(string key)
    {
        TrieNode *p = root;
        int sum=0;
        for(int i = 0; i < key.size(); ++ i)
        {
            p = p -> next[key[i] - 'a'];
        	sum += p->is_word;
        }
        return sum;
    }
    
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};