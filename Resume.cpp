 /**
  *   * toLowerCase
  *     * Converts a string into lowercase and also removes any non-letters from the string
  *       * pre: none
  *         * post: returns a string with all letters from first string in original order and all lowercase
  *           */
#include <iostream>

#include <Resume.h>

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

