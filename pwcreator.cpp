#include "pwcreator.h"
/**
 * std::unique_ptr<Password> mypassword = nullptr;

while(true) {
    std::string entered_pw;
    std::getline(std::cin, entered_pw);
    
    if (myanalyzer.isValid(entered_pw)) {
        mypassword = std::make_unique<Password>(entered_pw);  // Replaces old one automatically
        std::cout << myanalyzer.get_spec_char_count(mypassword->getpw());
    }
}
 */
// Auto-cleanup when out of scope