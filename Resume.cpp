#include <iostream>
#include "Resume.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <set>
#include <map>
#include <cstdlib>
#include <locale>


Resume::Resume(std::string &word) : hasValidEmail(false), hasAddress(false), hasPhone(false), resumeFile(word), wordCount(0) {
}

void Resume::processFile() {

    std::string str1;
    std::ifstream dictFile("words_alpha.txt");
    if (dictFile.fail()) {
        std::cout
                << "Sorry, we encountered an error opening the dictionary, press enter to exit this program"
                << std::endl;
        getline(std::cin, str1);  // consume existing line
        std::cin.get();  // get the key press
        exit(1);
    }
    std::string dictWordIn;
    while (dictFile >> dictWordIn){
        dictionary.insert(dictWordIn);
    }

    std::string str2;
    std::ifstream file(resumeFile.c_str());
    if (!file) {
        std::cout
                << "Sorry, your resume could not be opened properly, press enter to exit this program"
                << std::endl;
        getline(std::cin, str2);  // consume existing line
        std::cin.get();  // get the key press
        exit(1);
    }
    std::string word;
    std::string line;
    while (std::getline(file, line)) {
        validAddress(line);
        //line methods (passive, address)
        std::istringstream lineStream(line);
        while (lineStream >> word) {
            wordCount++;
            analyzeWord(word);
            toLowerCase(word);
            if (word.length() == 0) {
                if (dictionary.count(word) > 0){
                    ++allWords[word];
                } else {
                    ++spellingErrors[word];
                }
            }
        }
    }
}

void Resume::validEmail(const std::string &word){
    size_t location = word.find('@');
    size_t location2;
    if(location > 0){
        std::string str2 = word.substr(location);
        location2 = str2.find('.');
    }

    if((location > 0) && (location2 > 0) && location2 != (word.length() -1)){
        hasValidEmail = true;
    }
    else{
        hasValidEmail = false;
    }
}

void Resume::validPhone(const std::string &word){
        bool check = true;
        if (word.size() != 10) {
            check = false;
        }
        else {
            for (int i = 0; i < 10; i++) {
                if (!isdigit(word[i])) {
                    check = false;
                }
            }
        }
        if (check) {
            hasPhone = true;
        }
}

void Resume::validAddress(const std::string &inputLine){
    WordSet state;
    std::string fname = "StateAbbreviations.txt";
    std::string str;
    std::ifstream file(fname.c_str());
    if (!file) {
        std::cout << "Unable to open file. Press enter to exit program";
        getline(std::cin, str); //consume existing line
        std::cin.get(); //get key press
        exit(1);
    }
    std::string fileWord, lineWord, lineNextWord;
    while (file >> fileWord){
        state.insert(fileWord);
    }

    std::istringstream lineStream(inputLine);
    bool check(true);
    while (lineStream >> lineWord) {
        //if state code
        if (state.count(lineWord) > 0){
            if (lineStream >> lineNextWord){
                if (lineNextWord.size() == 5){
                    for (size_t i = 0; i < 5; i++) {
                        if (!isdigit(lineNextWord[i])) {
                            check = false;
                        }
                    }
                    if (check){
                        hasAddress = true;
                    }
                }
            }
        }
    }
    file.close();
}


 /**
  ** toLowerCase
  ** Converts a string into lowercase and also removes any non-letters from the string
  ** pre: none
  ** post: returns a string with all letters from first string in original order and all lowercase
  *
  */

void Resume::toLowerCase(std::string &word) {
    for (size_t i = 0; i < word.length(); i++){
        if (word.length() > 0) {
            if (word[i] == '(' || word[i] == ')' || word[i] == '-' || word[i] == '.') {
                word = word.substr(0, i) + word.substr(i + 1);
            }
            if (word[i] == '@'){
                validEmail(word);
            }
            if (word[i] != '.' && word[i] != '@'){
                char changer = word[i];
                word[i] = std::tolower(changer);
            }
        }
    }
}

void Resume::analyzeWord(std::string &word){
    toLowerCase(word);
    validPhone(word); //calls validPhone, added by Nihar
}

bool Resume::getValidEmail(){
    return hasValidEmail;
}


bool Resume::getHasAddress(){
    return hasAddress;
}


bool Resume::getHasPhone(){
    return hasPhone;
}
