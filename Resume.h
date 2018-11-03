

class Resume {
private:
    bool hasValidEmail;
    bool hasAddress;
    bool hasPhone;
    std::string resumeFile; //read inFile
public:
    //Default Constructor
    Resume();

    //Alt Constructor
    Resume(std::string &word);

    //Calls everything.
    //While in a while loop of processing, calls to Lowercase, maps all words to a big map, maps
    //verbs to a verb map,
    //maps to words and verbs and checks passive voice
    void processFile(std::string &resumeFile);

    //updates hasValidEmail bool
    void validEmail(const std::string &word);

    //updates hasAddress bool
    void validAddress();

    //updates hasPhone
    void validPhone();

    //Change everything to lowercase except @ and .
    void toLowerCase(std::string &word);

    //Checks passive, checks address, checks email, checks phone number, calls toLowercase
    void analyzeWord();

    //accessor methods for private variables
    bool getValidEmail();
    bool getHasAddress();
    bool getHasPhone();

};