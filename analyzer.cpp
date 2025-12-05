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

bool Analyzer::hasSpecialChar(const Password& pw) const {
    for(int i = 0; i < pw.getpw().length(); i++){
        if(ispunct(pw.getpw()[i])){
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

unsigned int Analyzer::calc_strength_score(const Password& p) {
    // Use a local variable for the score to ensure each call is independent.
    unsigned int score = 0;

    if(hasLowercase(p)){
        score += 5; //if the password contains a lowercase char, increase score by 5
    }
    if(hasUppercase(p)){
        score += 5; //if password contains a uppercase char, increase score by 5
    }
    if(hasDigit(p)){
        score += 5; // if password contains a number, increase score by 5
    }

    // Count special characters locally instead of relying on a persistent member variable.
    for(char c : p.getpw()){
        if(ispunct(c)){
            score += 3; // For each special character, add 3 to the score.
        }
    }

    strength_score = score; // Update member variable for external access if needed.
    return strength_score;
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

    /*Case 5: 
    * Base: Score should be 18 (18 is good but it could be better if there are more special chars)
    * This check is problematic because it relies on a previously calculated score.
    * It's better to calculate it here or remove the check if other rules suffice.
    */
    // A temporary, non-const analyzer is needed to call the non-const calc_strength_score
    Analyzer temp_analyzer;
    if(temp_analyzer.calc_strength_score(pw) < 18) {
         return false;
    }
    return true;

}

extern "C"{
    #include <cstring>
    bool check_pw_valid(const char* pw){
        Password p(pw);
        Analyzer analyze;
        return analyze.isPasswordValid(p);
    }
    bool check_common(const char* pw){
        Password p(pw);
        Analyzer analyze;
        return analyze.isCommon(p);
    }
    int pw_strength_score(const char* pw){
        Password p(pw);
        Analyzer analyze;
        analyze.calc_strength_score(p);
    }
}