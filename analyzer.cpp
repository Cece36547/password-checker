#include "analyzer.h"

bool Analyzer::isLengthValid(const Password& pw) const {
    return pw.getpw().length() >= 10;
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


unsigned int Analyzer::common_substr(const Password &pw) const{
    std::ifstream file("common_passwords.txt");
    if(!file.is_open()){ // if file doesn't exist, dont penalize
        throw std::runtime_error("Failed to open file.");
    }
    unsigned int count = 0;
    std::string pw_lower = pw.getpw();
    std::transform(pw_lower.begin(),pw_lower.end(),pw_lower.begin(),::tolower);
    
    std::string common;
    while(std::getline(file,common)){
        std::transform(common.begin(),common.end(),common.begin(),::tolower);
        if(pw_lower == common){
            count = 4; //if users input is same as common password, automatically declate as common
        }
        if(pw_lower.find(common) != std::string::npos){
            count++;
        }
    }
    file.close();
    return count;
}

bool Analyzer::isCommon(const Password &pw) const{
    if(common_substr(pw) <= 3 ){
        return false;
    }
    return true;
}

int Analyzer::calc_strength_score(const Password& p) const{
    return false;
}

bool Analyzer::isPasswordValid(const Password& pw) const{
     //Case 1: Length has to be > 10
    if(!isLengthValid(pw)){
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
    //Case 4: If there are no lowercase AND uppercase letters within the users input
    if(!hasLowercase(pw) && !hasUppercase(pw)){
        return false;
    }

    /*Case 5: if strength score is less than 15, that means the user's
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