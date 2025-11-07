#include "analyzer.h"
/**
 * 
 * 
 */
int main(){
    Analyzer myanalyzer;
    Password mypassword;
    std::string entered_pw;
    std::cout<< " Please note that to be valid, password must: \n 1. Be length of 10 or greater. \n 2. Have at least one algebraic charcter. \n 3. Have at least one numeric character. \n 4. No spaces. \n Please enter a password: ";
    while(true) {
    std::string entered_pw;
    std::getline(std::cin, entered_pw);
    
    if (myanalyzer.isPasswordValid(mypassword)) {
        Password mypassword(entered_pw);  // Create new object each iteration
        std::cout << myanalyzer.get_spec_char_count();
    } else {
        std::cout << "Invalid password!\n";
    }
}
}