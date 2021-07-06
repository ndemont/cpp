#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <vector>
# include <iostream>
# include <cstdlib>
# include <list>

class	Contact
{
	public:

	Contact();
	~Contact();

	void	create_contact(int index);
	void	display_preview(void);
	void	display_all(void);
	int		get_index(void);
	void	lower_index(void);

	private:

	int			m_index;
	std::string	m_firstname;
	std::string	m_lastname;
	std::string	m_nickname;
	std::string	m_phonenumber;
	std::string	m_darkestsecret;
};

#endif