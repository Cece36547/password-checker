#ifndef PWANALYZER_H
#define PWANALYZER_H

#include <iostream>
#include <string>
class Password{
    private:
      std::string pw;
      int spec_char_count;

    //Parameterized Constructor; No "direct" outside creation
    Password(const std::string& enterered_pw);

    //Helper to calculate spec_char_count
    public:
    /**
     * @brief Default Constructor: PW is intialized to an empty string; spec_char_count is intialized to 0
     */
    Password();

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
     * @param Constant Reference to a Password Object
     */
      int strengthScore(const Password& p) const;

   /**
    * @brief Getter for Special Character Count
    */
      int get_spec_char_count() const;
};

#endif // PWANALYZER_H