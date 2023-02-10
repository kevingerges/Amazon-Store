#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/

std::vector<std::string> split(string str, char del){
    std::stringstream ss(str);
    string tmp;
    vector<string> words;

    while(getline(ss, tmp, del)){
        words.push_back(tmp);
    }

    return words;
}

std::set<std::string> parseStringToWords(string rawWords)
{
    rawWords += " ";
    std::string word;
    std::set<std::string> set1;
    for(size_t i=0; i<rawWords.length(); i++){
        if(!isalnum(rawWords[i]) && word.length() >= 2){
            set1.insert(word);
            word = "";
        }
        else if(isalnum(rawWords[i])){
            word += rawWords[i];
        }
        else{
            word = "";
        }
    }
    // returing
    return set1;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
