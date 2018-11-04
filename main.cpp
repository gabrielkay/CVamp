#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <locale>
#include <iostream>
#include <fstream>
#include "Resume.h"

typedef std::set<std::string> WordSet;
typedef std::map<std::string, int> RepeatCounter;

int main() {
    std::string resumeFile = "";
    std::cout << "Please enter the name/path of the file to be processed." << std::endl;
    std::cin >> resumeFile;
    Resume resume1(resumeFile);
    resume1.processFile();
    if(resume1.getValidEmail()){
        std::cout<<"Your resume has a properly formatted email address" << std::endl;
    } else {
        std::cout<<"Your resume does not have a properly formatted email address" << std::endl;
    }
    if(resume1.getHasAddress()){
        std::cout<<"Your resume has a properly formatted street address" << std::endl;
    } else {
        std::cout<<"Your resume does not have a properly formatted street address" << std::endl;
    }
    if(resume1.getHasPhone()){
        std::cout<<"Your resume has a properly formatted phone number" << std::endl;
    } else {
        std::cout<<"Your resume does not have a properly formatted phone number" << std::endl;
    }
    RepeatCounter::const_iterator it1 = resume1.allWords.begin();
    std::cout << "Your frequently used words are:" << std::endl;
    while (it1 != resume1.allWords.end()) {
        if ((double) it1->second / (double)resume1.wordCount > .005) {
            std::cout << it1->first << std::endl;
            std::cout << "which you used ";
            std::cout << it1->second;
            std::cout << " times" << std::endl;

        }
        it1++;
    }

    RepeatCounter::const_iterator it2 = resume1.spellingErrors.begin();
    std::cout << "Your misspelled words are:" << std::endl;
    while (it2 != resume1.spellingErrors.end()){
        if (it2->second > 0){
            std::cout << it2->first;
            std::cout << "which you used ";
            std::cout << it2->second;
            std::cout << " times" << std::endl;
        }
        it2++;
    }
    return 0;
}
