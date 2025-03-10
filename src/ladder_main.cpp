#include "ladder.h"

int main(int argc, char *argv[]) {
    string file_name = "src/words.txt";
    set<string> word_list;
    load_words(word_list, file_name);
}