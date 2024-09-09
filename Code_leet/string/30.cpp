/*
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) {
        return result;
    }

    int word_length = words[0].size();
    int words_count = words.size();
    int substring_length = word_length * words_count;

    unordered_map<string, int> word_count;
    for (const string& word : words) {
        ++word_count[word];
    }

    for (int i = 0; i <= (int)s.size() - substring_length; ++i) {
        unordered_map<string, int> seen_words;
        int j = 0;

        while (j < words_count) {
            int word_start_index = i + j * word_length;
            string word = s.substr(word_start_index, word_length);

            if (word_count.find(word) == word_count.end()) {
                break;
            }

            ++seen_words[word];
            if (seen_words[word] > word_count[word]) {
                break;
            }

            ++j;
        }

        if (j == words_count) {
            result.push_back(i);
        }
    }

    return result;
}

};
//sliding window