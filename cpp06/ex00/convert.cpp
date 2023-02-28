#include "convert.hpp"
#include "convert_structs.hpp"
#include "printing.hpp"

//make sure that the exponent is valid
static t_types	check_exponent(std::string input, int i)
{
	t_types	result = INVALID;
	
	if (input[i] == 'f')
		return(INVALID);
	if (input[i] == '-' || input[i] == '+')
		i++;
	while(input[i] != '\0')
	{	
		if(input[i] == 'f' && input[i + 1] == '\0')
			return(FLOAT);
		if(std::isdigit(input[i]) == false)
			return (INVALID);
		result = DOUBLE;
		i++;
	}
	return (result);
}

//check for special input
static t_types check_special_input(std::string input)
{
	if (input.compare("nan") == 0)
		return (E_NAN);
	else if (input.compare("nanf") == 0)
		return (E_NANF);
	else if (input.compare("inf") == 0)
		return (E_INF);
	else if (input.compare("-inf") == 0)
		return (E_NINF);
	else if (input.compare("inff") == 0)
		return (E_INFF);
	else if (input.compare("-inff") == 0)
		return (E_INFF);
	else
		return (NOT_SPECIAL);
}

//determine the type of the string input
static t_types determine_input_type(std::string input)
{
	bool decimal_point		= false;
	t_types current_type	= INTEGER;
	int i 					= 0;

	if (input[0] == '\0' || input[0] == 'f')
		return(INVALID);
	current_type = check_special_input(input);
	if (current_type != NOT_SPECIAL)
		return (current_type);
	else
		current_type = INTEGER;

	if ((input[0] == '-' || input[0] == '+'))
	{
		if (input[1] == '\0' || input[1] == 'f')
			return (INVALID);
		i++;
	}
	
	while (input[i] != '\0')
	{
		if (input[i] == '.')
		{
			if (decimal_point == true)
				return (INVALID);
			decimal_point = true;
			i++;
		}
		else if (input[i] == 'f' && input[i + 1] == '\0')
			return (FLOAT);
		else if (input[i] == 'e' || input[i] == 'E')
			return check_exponent(input, i + 1);
		else
		{
			if(std::isdigit(input[i]) == false)
				return (INVALID);
			i++;
		}
	}
	if (decimal_point == true)
		current_type = DOUBLE;
	return (current_type);
}

//convert the input to right type
static t_errors convert_input(std::string input, t_types type, t_converted &value)
{
	t_errors error = NO_ERRORS;
	
	if (type == E_NAN || type == E_INF || type == E_NINF)
		value.doublevalue = std::strtod(input.c_str(), NULL);
	else if (type == E_NANF || type == E_INFF || type == E_NINFF)
		value.floatvalue = static_cast<float>(std::strtod(input.c_str(), NULL));
	else if (type == INTEGER)
	{
		long tempvalue = std::strtol(input.c_str(), NULL, 10);
		if (errno == ERANGE || tempvalue > INT_MAX || tempvalue < INT_MIN)
			error = ERR_OUT_OF_RANGE;
		else
			value.intvalue = static_cast<int>(tempvalue);
	}
	else if (type == FLOAT)
	{
		double tempvalue = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE || tempvalue > FLT_MAX || tempvalue < -FLT_MAX  || (tempvalue > 0 && tempvalue < FLT_MIN) || (tempvalue < 0 && tempvalue > -FLT_MIN))
			error = ERR_OUT_OF_RANGE;
		else
			value.floatvalue = static_cast<float>(tempvalue);
	}
	else if (type == DOUBLE)
	{
		value.doublevalue = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE)
			error = ERR_OUT_OF_RANGE;
	}
	return (error);
}

int main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cout << "only one argument is accepted." << std::endl;
		return (0);
	}

	t_types type = INVALID;
	std::string input = argv[1];
	t_converted converted_value;

	type = determine_input_type(input);
	if (type == INVALID)
	{
		std::cout << "Can't convert input: invalid input." << std::endl;
		return (1);
	}

	t_errors error = convert_input(input, type, converted_value);
	if (error == ERR_OUT_OF_RANGE)
	{
		std::cout << "Can't convert the input: input value is out of range for the type." << std::endl;
		return (1);
	}
	print_types(converted_value, type);
	
	return (0);
}
