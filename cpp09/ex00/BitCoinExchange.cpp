#include "BitCoinExchange.hpp"

//only allowed to use a container one time for the whole module this exercise I choose to only use std::list and not other container so I can use it in the other containers.

BitCoinEx::BitCoinEx(std::string const & databasefile){
	read_database(databasefile);
}

//set to private
BitCoinEx::BitCoinEx(BitCoinEx const & src){
	(void) src;
}

//set to private
BitCoinEx& BitCoinEx::operator=(BitCoinEx const & rhs){
	(void) rhs;
	return *this;
}

BitCoinEx::~BitCoinEx(void){}

void BitCoinEx::read_database(std::string const & database){
	std::fstream dbfile;

	dbfile.open(database.c_str(), std::ios::in);

	if(!dbfile.is_open()){
		throw std::runtime_error("Database file can't be opened");
	}
	std::string line;
	std::getline(dbfile, line); //skip the first line;
	while(std::getline(dbfile,line)){
		date_value_t date_node;
		date_node.year = std::strtol(line.c_str(),NULL,10);
		date_node.month = std::strtol(line.substr(5,2).c_str(), NULL, 10);
		date_node.day= std::strtol(line.substr(8,2).c_str(), NULL, 10);
		date_node.value = std::strtof(line.substr(11).c_str(), NULL);
		_database.push_back(date_node);
	}
	if(_database.empty())
		throw std::runtime_error("Database file is empty");
}


date_comp_e BitCoinEx::compare_dates(date_value_t input_date, date_value_t source_date){
	
	if(input_date.year > source_date.year){
		return GREATER;
	} else if (input_date.year < source_date.year) {
		return SMALLER;
	} else {
		if(input_date.month > source_date.month){
			return GREATER;
		} else if (input_date.month < source_date.month) {
			return SMALLER;
		} else{
			if(input_date.day > source_date.day){
				return GREATER;
			} else if (input_date.day < source_date.day) {
				return SMALLER;
			}
			else{
				return EQUAL;
			}
		}
	}
}

bool BitCoinEx::validate_date(date_value_t const & inputdate) const{
	//check year
	if (inputdate.year < 1900 || inputdate.year > 9999){
		std::cout << inputdate.year << " is not an accepted year." << std::endl;
		return false;
	}
	//check month
	if (inputdate.month < 1 || inputdate.month > 12){
		return false;
	}
	//check day
	if((inputdate.day >= 1 && inputdate.day <=31) && 
		(inputdate.month == 1 || inputdate.month == 3 
		|| inputdate.month == 5 || inputdate.month == 7
		|| inputdate.month == 8 || inputdate.month == 10
		|| inputdate.month == 12)){
			return true;
		}
	else if((inputdate.day >= 1 && inputdate.day <=30) && 
		(inputdate.month == 4 || inputdate.month == 6
		|| inputdate.month == 9 || inputdate.month == 11)){
			return true;
		}
	else if ((inputdate.day >= 1 && inputdate.day <= 28) && (inputdate.month == 2)){
		return true;
	}
	else if ((inputdate.day >= 1 && inputdate.day <= 29) &&
		(inputdate.year % 400 == 0 || (inputdate.year % 4 == 0 && inputdate.year % 100 !=0))){
		return true;
	}
	else{
		std::cout << "the day is not valid." << std::endl;
		return false;
	}
}

bool BitCoinEx::check_value_format(std::string const & value){
	//check the value format
	int dotcount = 0;
	for(size_t i = 0; i < value.size(); ++i){
		if(i == 0 && value[i] == '-' )
			continue;
		if(value[i] == '.'){
			dotcount++;
			if(dotcount > 1){
				return false;
			}
		} else if (value[i] < '0'|| value[i] > '9'){
			return false;
		}
	}
	return true;
}

bool BitCoinEx::check_date_format(std::string const & date){
	//check the date format xxxx-xx-xx if not then return false
	if(date[4] != '-' || date[7] != '-' || date.size() != 10)
		return false;
	for(size_t i = 0; i < 10; ++i){
		if(i == 4 || i == 7){
			continue;
		}
		if (date[i] < '0'|| date[i] > '9'){
			return false;
		}
	}
	return true;
}

//check if the inputline conforms to the format
bool BitCoinEx::format_check(std::string const & line)
{
	std::list<std::string> splitline = split(line, ' ');
	if (splitline.empty() || splitline.size() != 3){
		return false;
	}
	std::list<std::string>::const_iterator it;
	it = splitline.begin();
	//check date format
	if(!check_date_format(*it)){
		return false;
	}
	//check if the middle character is a '|'
	it++;
	if (*it != "|"){
		return false;
	}
	it++;
	//check the value format
	if(!check_value_format(*it)){
		return false;
	}
	return true;
}

//will split the string based on the the delim character
std::list<std::string> BitCoinEx::split(std::string const & line, char const delim){
	size_t pos = 0;
	std::list<std::string> splitlist;

	while(pos != std::string::npos){
		pos = line.find_first_not_of(delim, pos);
		if (pos == std::string::npos)
			break;
		size_t temp = line.find(delim, pos);
		splitlist.push_back(line.substr(pos, temp - pos));
		pos = line.find_first_not_of(delim, temp);
	}
	return (splitlist);
}

date_value_t BitCoinEx::create_date_value(std::string const & line){
	//check the format of the line
	if(!format_check(line)){
		std::string errormsg = "Error : bad input => " + line;
		throw std::invalid_argument(errormsg);
	}
	std::list<std::string> splitline = split(line, ' ');
	date_value_t date_node;
	date_node.year = std::strtod(splitline.front().substr(0,4).c_str(),NULL);
	date_node.month = std::strtod(splitline.front().substr(5,2).c_str(),NULL);
	date_node.day = std::strtod(splitline.front().substr(8,2).c_str(), NULL);
	date_node.value = std::strtof(splitline.back().c_str(), NULL);
	if (errno == ERANGE){
		throw std::invalid_argument("Error : too large a number.");
	}
	return date_node;
}

bool BitCoinEx::check_input_date(date_value_t const & input_date){
	//check if the date is valid
	if (!validate_date(input_date)){
		std::cout << "Error : date invalid" << std::endl;
		return false;
	}
	if(input_date.value < 0){
		std::cout << "Error : not a positive number." << std::endl;
		return false;
	} else if (input_date.value > 1000){
		std::cout << "Error : too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitCoinEx::print_line(date_value_t const & input_date, date_value_t const & database_date) const{
	std::cout << input_date.year << "-" << input_date.month << "-" << input_date.day << " => "
				<< input_date.value << " = " << input_date.value * database_date.value << std::endl;
}

void BitCoinEx::print_value(std::string const & line){
	//error if the database is empty
	if(_database.empty()){
		throw std::runtime_error("Database is empty");
	}

	//create convert the line into a date_value_t struct
	date_value_t input_date;
	try{
		input_date = create_date_value(line);
	} catch (std::exception & exception){
		std::cout << exception.what() << std::endl;
		return;
	}
	if(!check_input_date(input_date)){
		return;
	}
	std::list<date_value_t>::iterator it;
	for(it = _database.begin(); it != _database.end(); ++it){
		date_comp_e result = compare_dates(input_date, *it);
		if (result == EQUAL){
			print_line(input_date, *it);
			return;
		} else if(result == SMALLER && it != _database.begin()){
			--it;
			print_line(input_date, *it);
			return;
		}
	}
	it--;
	print_line(input_date, *it);
}