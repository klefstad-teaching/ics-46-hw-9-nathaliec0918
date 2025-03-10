// #include <iostream>
// #include <fstream>
// #include <queue>
// #include <set>
// #include <map>
// #include <vector>
// #include <string>
// #include <cmath>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg) {
    cout << "error for (" << word1 << ", " << word2 << "): " << msg << endl;
}

// ensure str1 and str2 only have one char different
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int num_char_diff = 0;
    if (abs( static_cast<int>(str1.length()) - static_cast<int>(str2.length()) ) > 1) {
        error(str1, str2, "length of two words difference is greater than 1.");
        return false;
    }

    int smaller = str1.length() < str2.length() ? str1.length() : str2.length();
    if (str1.length() != str2.length()) num_char_diff++;

    for (size_t i = 0; i < smaller; ++i) {
        if (str1[i] != str2[i]) num_char_diff++;
        if (num_char_diff > d) return false;
    }
    return num_char_diff <= d; // num_char_diff <= d, or just return true
}

// call edit_distance_within and make sure it's true
bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {

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
    for (string word : ladder) {
        cout << word << " ";
    }
}

void verify_word_ladder() {

}