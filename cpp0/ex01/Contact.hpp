#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

    private:

        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;

    public:

        void SetFirstName (std::string fn);
        void SetLastName (std::string ln);
        void SetNickName (std::string nn);
        void SetPhoneNumber (std::string pn);
        void SetDarkestSecret (std::string ds);

        std::string GetFirstName ();
        std::string GetLastName ();
        std::string GetNicktName ();
        std::string GetPhoneNumber ();
        std::string GetDarkestSecret ();

};


#endif
