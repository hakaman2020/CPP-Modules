#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact{
	public:
		
		Contact(void);
		Contact( 	std::string firstName,
					std::string lastName,
					std::string nickname,
					std::string phoneNumber,
					std::string darkestSecret);
		~Contact(void);

		std::string	getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		void copyContact(Contact& contact);
		
	private:

		 std::string _firstName;
		 std::string _lastName;
		 std::string _nickname;
		 std::string _phoneNumber;
		 std::string _darkestSecret;
};

#endif