#include "analyzer.h"

bool Analyzer::isLengthValid(const Password& pw) const {
    return pw.getpw().length() > 10;
}

bool Analyzer::hasUppercase(const Password& pw) const {
    for(int i = 0; i < pw.getpw().length(); i++){
        if(isupper(pw.getpw()[i])){
            return true;
        }
    }
    return false;
}

bool Analyzer::hasLowercase(const Password& pw) const {
    for(int i = 0; i < pw.getpw().length(); i++){
        if(islower(pw.getpw()[i])){
            return true;
        }
    }
    return false;
}

bool Analyzer::hasDigit(const Password& pw) const {
    for(int i = 0; i < pw.getpw().length(); i++){
        if(isdigit(pw.getpw()[i])){
            return true;
        }
    }
    return false;
}

bool Analyzer::hasSpecialChar(const Password& pw) {
    for(int i = 0; i < pw.getpw().length(); i++){
        if(ispunct(pw.getpw()[i])){
            spec_char_count++;
            return true;
        }
    }
    return false;
}

bool Analyzer::hasWhitespace(const Password& pw) const {
        for(int i = 0; i < pw.getpw().length(); i++){
        if(isspace(pw.getpw()[i])){
            return true;
        }
    }
    return false;
}

int Analyzer::get_spec_char_count() const{
    return spec_char_count;
}


bool Analyzer::isCommonPassword(const Password &p, const std::string& comparable) const{
    return false; //dummy
}

int Analyzer::calc_strength_score(const Password& p) const{
    return false;
}

bool Analyzer::isPasswordValid(const Password& pw) const{
     //Case 1: Length has to be > 10
    if(isLengthValid(pw)){
        return false;
    }
    //Case 2: No Spaces Allowed
    if(hasWhitespace(pw)){
        return false;
    }
    //Case 3: Password cannot be a pin
    if(std::all_of(pw.getpw().begin(),pw.getpw().end(),isdigit)){
        return false;
    }
    /*Case 4: if strength score is less than 15, that means the user's
    * input did not include:
    * (1) both uppercase and lowercase
    * (2) uppercase/lowercase with mulitple special chars
    */
    if(strength_score < 15){
        return false;
    }
    return true;
}

/**
 * extern "C"{
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
 */