#include "pwanalyzer.h"

int main(){
    Password mypassword;
    std::string entered_pw;
    std::cout<< " Please note that to be valid, password must: \n 1. Be length of 10 or greater. \n 2. Have at least one algebraic charcter. \n 3. Have at least one numeric character. \n 4. No spaces. \n Please enter a password: ";
    while(true){
        std::getline(std::cin,entered_pw);
        mypassword.setPw(entered_pw);
        if(!mypassword.isPasswordValid(mypassword)){
            std::cout << "The password you have entered does not fit our criteria. Please try again: ";
            continue;
        }
        break;
    }
    //mypassword.isLengthValid() ? std::cout << " Length is valid. \n" : std::cout << " Length is invalid. \n";
    //mypassword.hasSpecialChar() ? std::cout << " Has Spec Char. \n" : std::cout << " Does not have Spec Char\n";
    return 0;
}