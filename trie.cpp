struct Node {
    array<Node*, 26> links = {};
    int prefixCnt = 0;
    int endWith = 0;
    Node() { links.fill(nullptr); }

    void put(char c, Node* node) { links[c - 'a'] = node; }
    bool containsKey(char c) { return links[c - 'a'] != nullptr; }
    Node* get(char c) { return links[c - 'a']; }
    void increasePrefixCnt() { prefixCnt++; }
    void increaseEndWith() { endWith++; }
    int getPrefixCnt() { return prefixCnt; }
    int getEndWith() { return endWith; }
};
class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }
    Trie(Node* r) { root = r; }

    void insert(string word) {
        Node* node = root;
        for (auto c : word) {
            if (!containsKey(c)) {
                node->put(c, new Node());
            }
            node->increasePrefixCnt();
            node = node->get(c);
        }
        node->increaseEndWith();
    }
};

class Solution {
   public:
    string completeString(vector<string>& nums) {
        // your code goes here

        Trie* trie = new Trie();
        for (string s : nums) {
            trie->insert(s);
        }
    }
};
