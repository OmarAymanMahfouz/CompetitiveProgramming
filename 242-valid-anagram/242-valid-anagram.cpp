class Solution {
public:
	bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            if(!mp[t[i]])
                return false;
            else
                mp[t[i]]--;
        return t.size() == s.size();
	}
};