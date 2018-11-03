#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <locale>
#include <iostream>
#include <fstream>

typedef std::set<std::string> WordSet;
typedef std::map<std::string, int> RepeatCounter;

WordSet readDictionary(){
    //TODO
    return dictionary;
}

int main() {
        WordSet dictionary = readDictionary();
        std::string resumeFile = "";
        std::cout << "Please enter the name/path of the file to be processed." << std::endl;
        std::cin >> resumeFile;
        Resume resume1(&resumeFile);
        //METHODS PERFORMED ON RESUME BELOW
        //resume.____;

        return 0;
}
