#include "password.h"
Password::Password(): pw("") {}

Password::Password(const std::string& enterered_pw){
    pw = enterered_pw;
}

std::string Password::getpw() const{
    return pw;
}