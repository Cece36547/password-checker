#include "pwanalyzer.h"

int main(){
    Password mypassword;
    std::string entered_pw;
    mypassword.setPw(entered_pw);
    std::cout<< " Please note that to be valid, password must: \n 1. Be length of 10 or greater. \n 2. Have at least one algebraic charcter. \n 3. Have at least one numeric character. \n 4. No spaces. \n Please enter a password: ";
    

    while(true){
        std::getline(std::cin,entered_pw);

        //Case 1: Blank
        if(entered_pw.empty()){
            std::cout << "The password you have entered is blank. Please try again: ";
            continue;
        }
        //Case 2: Only spaces
        if(std::all_of(entered_pw.begin(),entered_pw.end(),isspace) || mypassword.hasWhitespace()){
            std::cout << "Your password cannot contain spaces. Try again: ";
            continue;
        }
        //Case 3: Only numbers
        if(std::all_of(entered_pw.begin(),entered_pw.end(),isdigit)){
            std::cout<< "The password you entered only contains numbers. Please try again: ";
            continue;
        }
        
        mypassword.setPw(entered_pw);
        break;
    }
    
    std::cout << mypassword.strengthScore(mypassword);
    //mypassword.isLengthValid() ? std::cout << " Length is valid. \n" : std::cout << " Length is invalid. \n";
    //mypassword.hasSpecialChar() ? std::cout << " Has Spec Char. \n" : std::cout << " Does not have Spec Char\n";
    return 0;
}