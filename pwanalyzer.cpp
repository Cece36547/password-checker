#include "pwanalyzer.h"

void Password::setPw(const std::string &p){
    pw = p;
}

std::string Password::getPW() const{
    return pw;
}

bool Password::isLengthValid() const {
    if(pw.length() > 10){
        return true;
    }else{
        return false;
        //invalid password
    }
}

bool Password::hasUppercase() const {
    return false; //dummy
}

bool Password::hasLowercase() const {
    return false; //dummy
}

bool Password::hasDigit() const {
    return false; //dummy
}

bool Password::hasSpecialChar() const {
    return false; //dummy
}

bool Password::hasWhitespace() const {
    return false; //dummy
}

int Password::strengthScore() const{
    return 0;
}