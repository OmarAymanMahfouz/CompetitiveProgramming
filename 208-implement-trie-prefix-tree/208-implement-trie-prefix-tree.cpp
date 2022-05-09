struct node {
	vector<node*> next{ 26, nullptr };
	bool isEndOfWord;
	node(): isEndOfWord(false) {}
};

class Trie {
private:
	node* head;
public:
    Trie() {
		head = new node();
    }

    void insert(string word) {
		node* cur = head;
		for (int i = 0; i < word.size(); i++) {
			int ch = int(word[i] - 'a');
			if (!cur->next[ch])
				cur->next[ch] = new node();
			
			cur = cur->next[ch];
		}
		cur->isEndOfWord = true;
    }

    bool search(string word) {
		node* cur = head;
		for (int i = 0; i < word.size(); i++) {
			int ch = int(word[i] - 'a');
			if (!cur->next[ch])
				return false;

			cur = cur->next[ch];
		}
		if (cur->isEndOfWord)
			return true;
		return false;
    }

    bool startsWith(string prefix) {
		node* cur = head;
		for (int i = 0; i < prefix.size(); i++) {
			int ch = int(prefix[i] - 'a');
			if (!cur->next[ch])
				return false;
			cur = cur->next[ch];
		}
		return true;
    }
};