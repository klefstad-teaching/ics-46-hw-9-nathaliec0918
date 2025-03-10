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
    // if (str1.length() != str2.length() ) {
    //     error(str1, str2, "length of two words are different.");
    //     return false;
    // }
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) num_char_diff++;
        if (num_char_diff > d) return false;
    }
    return true; // num_char_diff <= d
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