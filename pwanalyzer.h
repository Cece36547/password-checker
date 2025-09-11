#pragma once
#include <iostream>
#include <string>
class Password{
    private:
        std::string pw;
    public:
    /**
     * @brief A setter for the password
     * @param p A Constant Reference to a string
     */
        void setPw(const std::string &p);

    /**
     *  @brief A getter for password
     * @return A string variable
     */

        std::string getPW() const;
    /**
     * @brief This method checks if the given password's length is valid. 
     * @return True if length >10. If else, return false.
     */
        bool isLengthValid() const;

    /**
     * @brief This method checks is the given password contains at least one uppercase alphabetic character.
     */
        bool hasUppercase() const;
    /**
     * @brief This method checks is the given password contains at least one uppercase alphabetic charater.
     */
        bool hasLowercase() const;
    
    /**
     * @brief This method checks if the given password contains at least one digit.
     */
        bool hasDigit() const;

     /**
     * @brief This method checks if the given password contains at least one special character.
     */
        bool hasSpecialChar() const;
    
     /**
     * @brief This method checks if the given password contains white space.
     */
        bool hasWhitespace() const;

    /**
     * @brief This method will return a score calculating the strength of the password
     */
        int strengthScore() const;
};

