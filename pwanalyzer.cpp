#include "pwanalyzer.h"


Password::Password(): pw(""), spec_char_count(0) {}

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
    for(int i = 0; i < pw.length(); i++){
        if(isupper(pw[i])){
            return true;
        }
    }
    return false;
}

bool Password::hasLowercase() const {
    for(int i = 0; i < pw.length(); i++){
        if(islower(pw[i])){
            return true;
        }
    }
    return false;
}

bool Password::hasDigit() const {
    for(int i = 0; i < pw.length(); i++){
        if(isdigit(pw[i])){
            return true;
        }
    }
    return false;
}

bool Password::hasSpecialChar() const {

    for(int i = 0; i < pw.length(); i++){
        if(ispunct(pw[i])){
            return true;
        }
    }
    return false;
}

bool Password::hasWhitespace() const {
        for(int i = 0; i < pw.length(); i++){
        if(isspace(pw[i])){
            return true;
        }
    }
    return false;
}

int Password::get_spec_char_count() const{
    return 0;
}



//Calculating Strength Score
int Password::strengthScore(const Password& p) const{
    int score = 0;
    
    //Case 1: If password contains uppercase
    if (p.hasUppercase()){
        score += 5;
    }

    //Case 2: If password contains lowercase
    if (p.hasLowercase()){
        score += 5;
    }
    //Case 3: If password contains digits
    if (p.hasDigit()){
        score += 10;
    }
    return score;
}