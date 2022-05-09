struct Node{
    Node* child[26];
    bool isEndOfWord;
    Node(): isEndOfWord(false){
       fill(child, child + 26, nullptr);
    }
};

class WordDictionary {
private:
    Node* root;
    bool solve(Node* cur, string& s, int idx){
        if(idx == s.size() && cur->isEndOfWord) 
            return true;
        else if (idx == s.size())
            return false;
        if(!cur)
            return false;
        
        if(s[idx] != '.'){
            if(cur->child[s[idx] - 'a'])
                return solve(cur->child[s[idx] - 'a'], s, idx + 1);
            else
                return false;
        }
        else{
            for(int i = 0; i < 26; i++){
                if(cur->child[i]){
                    bool flag = solve(cur->child[i], s, idx + 1);
                    if(flag)
                        return true;
                }
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++){
            if(temp->child[word[i] - 'a'])
                temp = temp->child[word[i] - 'a'];
            else
                temp = temp->child[word[i] - 'a'] = new Node();
        }
        temp->isEndOfWord = true;
    }
    
    bool search(string word) {
        return solve(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */