#include "words.hpp"
#include <locale>
#include <map>
#include <set>

bool IsPunctuation(char c) {
    return c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == '-';
}
std::string ToUpper(const std::string &word) {
    std::string upper = "";

    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            upper += word[i] - 'a' + 'A';
        }
        else {
            upper += word[i];
        }
    }

    return upper;
}

std::map<std::string, int> count_words(std::string const &input) {
    std::map<std::string, int> upperStat; 
    std::set<std::string> uniqueWords; 
    size_t i = 0;

    while (i < input.size()) {
        while (i < input.size() && IsPunctuation(input[i]))
            i++; 

        std::string word = "";

        while (i < input.size() && !IsPunctuation(input[i]))
            word += input[i++]; 

        if (word.size() == 0)
            continue;

        uniqueWords.insert(word); 
        std::string upper = ToUpper(word); 

        auto it = upperStat.find(upper); 

        if (it != upperStat.end()) { 
            it->second++; 
        }
        else {
            upperStat[upper] = 1; 
        }
    }

    std::map<std::string, int> result; 

    for (auto it = upperStat.begin(); it != upperStat.end(); it++) { 
        for (auto wordIt = uniqueWords.begin(); wordIt != uniqueWords.end(); wordIt++) { 
            if (ToUpper(*wordIt) == it->first) { 
                result[*wordIt] = it->second; 
                uniqueWords.erase(*wordIt); 
                break;
            }
        }
    }

    return result; 
}
