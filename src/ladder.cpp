// #include <iostream>
// #include <fstream>
// #include <queue>
// #include <set>
// #include <map>
// #include <vector>
// #include <string>
// #include <cmath>
#include <stack>
#include "ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

using namespace std;

void error(string word1, string word2, string msg) {
    cout << "error for (" << word1 << ", " << word2 << "): " << msg << endl;
}

// ensure str1 and str2 only have one char different
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    // int num_char_diff = 0;
    int diff = abs( static_cast<int>(str1.length()) - static_cast<int>(str2.length()) );
    if (diff > d) {
        // error(str1, str2, "length of two words difference is greater than 1.");
        return false;
    }

    int m = str1.length();
    int n = str2.length();
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for (int j = 0; j <= n; ++j) 
        prev[j] = j;
    for (int i = 1; i <= m; ++i) {
        curr[0] = i;
        for (int j = 1; j <= n; ++j) {
            if (str1[i-1] == str2[j-1])
                curr[j] = prev[j-1];
            else
                curr[j] = 1 + min( {curr[j-1], prev[j], prev[j-1]} );
        }
        prev = curr;
    }
    return prev[n] <= d;
}

// call edit_distance_within and make sure it's true
bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        error(begin_word, end_word, "starting and ending word cannot be the same.");
        return {};
    }
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop(); // -- the ladder queue
        string last_word = ladder.back();
        
        for (string word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                visited.insert(word);
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);
                if (word == end_word) {
                    return new_ladder;
                }
                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    string word;
    while (in >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() == 0) 
        cout << "No word ladder found." << endl;
    else {
        cout << "Word ladder found: ";
        for (string word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    // my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    // my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    // my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    vector<string> one = generate_word_ladder("work", "play", word_list);
    // vector<string> two = generate_word_ladder("sleep", "awake", word_list);
    // vector<string> three = generate_word_ladder("car", "cheat", word_list);

    print_word_ladder(one);
    my_assert(one.size() == 6);
    // my_assert(two.size() == 8);
    // my_assert(three.size() == 4);
    // my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    // my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    // my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}