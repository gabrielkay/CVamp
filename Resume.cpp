#include <iostream>
#include <Resume.h>
#include <string>



Resume::Resume(){
}

Resume::Resume(std::string &word){
}

void Resume::processFile(std::string &resumeFile){
}

void Resume::validEmail(const std::string &word){
}

void Resume::validPhone(const std::string &word){
}

void Resume::validAddress(){
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
            if (word[i] == '@'){
                validEmail(word);
            }
            char changer = word[i];
            word[i] = std::tolower(changer);
        }
    }
}

void Resume::analyzeWord(){
}

bool Resume::getValidEmail(std::string word){
    size_t location = word.find('@');
    if(location > 0){
        std::string str2 = str.substr(location);
        size_t location2 = str2.find('.');
    }

    return (location > 0) && (location2 > 0);
}


bool Resume::getHasAddress(){
}

bool Resume::getHasPhone(){
}
