#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTLIST_SIZE 8
# include "contact.hpp"

class Phonebook{
	public:

		Phonebook(void);
		~Phonebook(void);
		
		bool	addContact(void);
		Contact	getContact(int index);
		void	displayContactList(void);
		void	displayFullContact(const Contact& contact);
		int		getMaxContactListSize(void);
		
	private:

		Contact _book[MAX_CONTACTLIST_SIZE];

		void		displayOneContact(const Contact& contact, int index);
		void		displayHeader(void);
		std::string	formatContactInfo(std::string info);
		bool		createContact(Contact& contact);
		std::string	getInfo(std::string fieldName);
		bool		isStringEmpty(std::string& inputstring);

};

#endif