#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class Karen
{
public:

	Karen(void);
	~Karen(void);

	void			complain(std::string level);
	typedef void	(Karen::*ptr)(void);
	ptr				complaints[4];
	std::string		levels[4];

private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

};

#endif