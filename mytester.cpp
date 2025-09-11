#include "pwanalyzer.cpp"

int main(){
    Password mypassword;
    std::string entered_pw;
    std::cout<< " Please note that to be valid, password must: \n 1. Be length of 10 or greater. \n 2. Have at least one algebraic charcter. \n 3. Have at least one numeric character. \n 4. No spaces. \n Please enter a password: ";
    std::cin >> entered_pw;
    mypassword.setPw(entered_pw);
    if(mypassword.isLengthValid() ? )
    return 0;
}