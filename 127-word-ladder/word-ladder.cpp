class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        unordered_map<string,int> f;

        for(int i=0;i<n;i++){
            f[wordList[i]] = 1;
        }

        if(f.find(beginWord)==f.end()){
            f[beginWord] = 1;
        }

        
        if(f.find(endWord)==f.end()){
            return 0;
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        f.erase(beginWord);

        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();

            string s = p.first;
            int val = p.second;

            if(s==endWord) return val;

            for(int i = 0; i < s.size(); i++) {

                char original = s[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    if(ch == original) continue;

                    s[i] = ch;

                    if(f.find(s) != f.end()) {

                        q.push({s, val + 1});

                        f.erase(s);
                    }
                }

                s[i] = original;
            }
        }

        return 0;
    }
};