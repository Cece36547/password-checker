
#ifndef PASSWORD_H
#define PASSWORD_H
#include <iostream>
#include <string>

class PasswordCreator;

class Password{
    private:
    std::string pw;
    friend class PasswordCreator;

    public:
    /**
     * @brief Default Construct for Password Object
     */
    Password();

    /**
     * @brief Parameterized Constructor
     */
    Password(const std::string& entered_pw);

    /**
     *  @brief A getter for password
     * @return A string variable
     */
    std::string getpw() const;
};

#endif