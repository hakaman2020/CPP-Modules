#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <list>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cerrno>

typedef struct date_value{
	int year;
	int month;
	int day;
	float value;
}	date_value_t;

typedef enum date_comp{
	SMALLER = -1,
	EQUAL = 0,
	GREATER = 1
} 			date_comp_e;

class BitCoinEx{
	private:

		std::list<date_value_t> _database;

		BitCoinEx(BitCoinEx const & src);
		BitCoinEx& operator=(BitCoinEx const & rhs);

		//read database
		void					read_database(std::string const & database);
		//validation
		bool 					format_check(std::string const & line);
		bool 					check_date_format(std::string const & date);
		bool 					check_value_format(std::string const & value);
		bool 					validate_date(date_value_t const & inputdate) const;
		bool					check_input_date(date_value_t const & input_date);
		//utilities
		date_comp_e				compare_dates(date_value_t inputdate, date_value_t source_date);
		std::list<std::string>	split(std::string const & line, char const delim);
		date_value_t 			create_date_value(std::string const & line);

		//print out the value
		void					print_line(date_value_t const & input_date, date_value_t const & database_date) const;

	public:

		BitCoinEx(std::string const & databasefile = "data.csv");
		~BitCoinEx(void);
		
		void					print_value(std::string const & line);
};

#endif