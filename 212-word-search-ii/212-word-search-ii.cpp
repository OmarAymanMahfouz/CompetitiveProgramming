struct Node {
    map<char, Node*> child;
    bool isEndOfWord;
    bool added;
    Node() : isEndOfWord(false), added(false) {}
};

class Solution {
private:
    Node* root;
    vector<pair<short, short>> charPos[26];
    vector<vector<bool>> vis{12, vector<bool>(12)};
    vector<string> ans;
    short dx[4] = { 0, 1, 0, -1 };
    short dy[4] = { 1, 0, -1, 0 };
    short n, m;

    void dfs(short i, short j, vector<vector<char>>& vec, Node* curNode, string s) {
        if (curNode->isEndOfWord && !curNode->added)
            this->ans.push_back(s), curNode->added = true;

        this->vis[i][j] = true;

        for (short k = 0; k < 4; k++) {
            short nextI = i + dx[k];
            short nextJ = j + dy[k];
            if (nextI >= 0 && nextI < this->n && nextJ >= 0 && nextJ < this->m) {
                for (auto e : curNode->child)
                    if(e.second && e.first == vec[nextI][nextJ] && !vis[nextI][nextJ])
                        dfs(nextI, nextJ, vec, e.second, s + e.first);
            }
        }

        this->vis[i][j] = false;
        return;
    }

    void add(string& s) {
        Node* temp = this->root;
        for (int i = 0; i < s.size(); i++) {
            if (temp->child[s[i]])
                temp = temp->child[s[i]];
            else
                temp = temp->child[s[i]] = new Node();
        }
        temp->isEndOfWord = true;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->root = new Node();
        this->n = board.size();
        this->m = board[0].size();

        for (short i = 0; i < words.size(); i++)
            this->add(words[i]);


        for (short i = 0; i < n; i++) {
            for (short j = 0; j < m; j++){
                if(this->root->child[board[i][j]])
                    this->charPos[board[i][j] - 'a'].push_back({ i, j });
            }
        }

        for (auto e : this->root->child) {
            short x = e.first - 'a';
            string s = "";
            s.append(1, e.first);
            for (short i = 0; i < charPos[x].size(); i++) {
                pair<short, short>& p = charPos[x][i];
                dfs(p.first, p.second, board, e.second, s);
            }
        }

        return this->ans;
    }
}; 