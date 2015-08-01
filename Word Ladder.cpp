class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.erase(beginWord);
        wordDict.insert(endWord);
        queue<string> next;
        addNextWord(beginWord,next,wordDict);
        next.push(beginWord);
        int len=2;
        while(!next.empty()){
            int num = next.size();
            for (int i = 0; i < num; i++) {
                if(next.front() == endWord)
                    return len;
                addNextWord(next.front(),next,wordDict);
                next.pop();
            }
            len++;
        }
        return 0;
    }
    
    void addNextWord(string word, queue<string> &next, unordered_set<string>& wordDict){
        for(int i=0; i<word.length(); i++){
            char tmp=word[i];
            for(int j=0; j<26;j++){
                word[i]='a'+j;
                if(wordDict.find(word)!=wordDict.end()){
                    next.push(word);
                    wordDict.erase(word);
                }
            }
            word[i]=tmp;
        }
    }
};
