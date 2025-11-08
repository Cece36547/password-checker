#ifndef PWCREATOR_H
#define PWCREATOR_H
#include <memory>
#include "password.h"
#include "analyzer.h"

/**
 * @brief Dynamically creates password if the users input
 * is validated by the analyzer
 */
class creator{
    private:
        Analyzer analyzer;

    public:
        Password* createPassword(const std::string& pw);
        std::unique_ptr<Password> createPasswordSafe(const std::string& pw);

};



#endif
