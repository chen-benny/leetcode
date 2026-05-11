// bfs, T: O(nm2), n = wordList size, m = word length, S: O(mn)

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord,
                     std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) { return 0; }

        std::queue<std::string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            for (int i = 0; i < sz; ++i) {
                std::string word = q.front();
                q.pop();

                for (int j = 0; j < static_cast<int>(word.size()); ++j) {
                    char orig = word[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) { continue; }
                        word[j] = c;
                        if (word == endWord) { return steps + 1; }
                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }

                    word[j] = orig;
                }
            }
            ++steps;
        }
        return 0;
    }
};
