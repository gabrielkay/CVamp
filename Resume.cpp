#include <iostream>
#include <Resume.h>
#include <string>


//add typedefs

Resume::Resume(){
}

Resume::Resume(std::string &word){
}

void Resume::processFile(std::string &resumeFile){
    std::string str;
    std::ifstream file(resumeFile.c_str());
    if (!file){
        std::cout<<"Sorry, your resume could not be opened properly, press enter to exit this program"<<std::endl;
        getline(std::cin, str);  // consume existing line
        std::cin.get();  // get the key press
        exit(1);
    }
    std::string word;
    while (file >> word){
        wordCount++;
        analyzeWord(word);
        word = toLowerCase(word);
        if (commonList.count(nextWord > 0) || word.length() == 0){
            continue;
        }
        else {
            //add word to overall wordcount map
        }

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
            if (word[i] != '.' && word[i] != '@'){
                char changer = word[i];
                word[i] = std::tolower(changer);
            }
        }
    }
}

//in analyze word, make sure the word is in the dictionary. Also check if it is a phone number. Can move that chunk of code that checks the passive voice into here.
void Resume::analyzeWord(&word){
    //TODO let this method have access to the Dictionary
    //TODO make private/public class variables of RepeatCounters for Passive voice and spelling errors
    if (passive.count(word) > 0){
        //TODO define passiveUsed as a RepeatCounter
        ++passiveUsed[word];
    }
    if (dictionary.count(word) < 1){
        ++spelledWrong[word];
    }
    word = toLowerCase(word);
    if (word.length() == 10){
        //check to see if its all numbers
    }

}

bool Resume::getValidEmail(){
}

bool Resume::getHasAddress(){
}

bool Resume::getHasPhone(){
}
