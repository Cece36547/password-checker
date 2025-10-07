#include "pwanalyzer.h"

Password::Password(){
    initializer("");
}

void Password::initializer(const std::string &p){
    pw = p;
    spec_char_count = 0;
    for(char c : pw){
        if(!isalnum(c) &&!isspace(c)) {
            spec_char_count++;
        }
    }
}

Password::Password(const std::string &enterered_pw){
    initializer(enterered_pw);
}

void Password::setPw(const std::string &p){
    initializer(p);
}

std::string Password::getPW() const{
    return pw;
}


bool Password::isLengthValid() const {
    return pw.length() > 10;
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
    return spec_char_count;
}

void Password::set_spec_char_count() const{
    int spec_char_count = 0;
    for(int i = 0; i < pw.length(); i++){
        if(ispunct(pw[i])){
            spec_char_count++;
        }
    }
}

/**
* @brief This method will return a score calculating the strength of the password
* @param Constant Reference to a Password Object
*/
int strengthScore(const Password& p) {
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
    //Case 4: If password contains special characters, strength
    //score goes increases 5 pts per symbol
    if(p.hasSpecialChar()){
        score += 5 * p.get_spec_char_count();
    }
    return score;
}

bool Password::isPasswordValid(const Password &p) const {
    //Case 1: Length check
    if(!p.isLengthValid()){
        return false;
    }
    //Case 2: No spaces allowed
    if(p.hasWhitespace()){
        return false;
    }
    //Case 3: Only numbers
    if(std::all_of(p.getPW().begin(),p.getPW().end(),isdigit)){
        return false;
    }

    if(strengthScore(p) < 15){
        //if strength score is less than 15, that means the user's
        //input did not include (1) both uppercase and lowercase
        //(2) uppercase/lowercase with mulitple special chars
        return false;
    }
    return true;
}

extern "C"{
    #include <cstring>
    bool check_pw_valid(const char* pw){
        Password p;
        p.setPw(pw);
        return p.isPasswordValid(p);
    }
    int pw_strength_score(const char* pw){
        Password p;
        p.setPw(pw);
        return strengthScore(p);
    }
}