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
	std::string		levels[4];

private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	other(void);

};

#endif