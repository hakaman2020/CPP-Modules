#include "printing.hpp"

static void print_char(t_converted value, t_types type)
{
	std::cout << "char: ";
	if (type == INTEGER)
	{
		if (value.intvalue < 0 || value.intvalue > 255)
			std::cout << "Impossible" << std::endl;
		else if((value.intvalue >= 0 && value.intvalue < 32) || (value.intvalue > 127 && value.intvalue < 256))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(value.intvalue) << "'" << std::endl;
	}
	else if (type == FLOAT)
	{
		if (value.floatvalue < 0 || value.floatvalue > 255)
			std::cout << "Impossible" << std::endl;
		else if((value.floatvalue >= 0 && value.floatvalue < 32) || (value.floatvalue > 127 && value.floatvalue < 256))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(value.floatvalue) << "'" << std::endl;
	}
	else if (type == DOUBLE)
	{
		if (value.doublevalue < 0 || value.doublevalue > 255)
			std::cout << "Impossible" << std::endl;
		else if((value.doublevalue >= 0 && value.doublevalue < 32) || (value.doublevalue > 127 && value.doublevalue < 256))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(value.doublevalue) << "'" << std::endl;
	}
	else if(type == E_NAN || type == E_INF || type == E_NINF || type == E_NANF || type == E_INFF || type == E_NINFF)
		std::cout << "Impossible" << std::endl;
}

static void print_int(t_converted value, t_types type)
{
	std::cout << "int: ";
	if (type == INTEGER)
	{
		if (value.intvalue < INT_MIN || value.intvalue > INT_MAX)
			std::cout << "Impossible" << std::endl;
		else
			std::cout << value.intvalue << std::endl;
	}
	else if (type == FLOAT)
	{
		if (value.floatvalue < INT_MIN || value.floatvalue > INT_MAX)
			std::cout << "Impossible" << std::endl;
		else
			std::cout << static_cast<int>(value.floatvalue) << std::endl;
	}
	else if (type == DOUBLE)
	{
		if (value.doublevalue < INT_MIN || value.doublevalue > INT_MAX)
			std::cout << "Impossible" << std::endl;
		else
			std::cout << static_cast<int>(value.doublevalue) << std::endl;
	}
	else if(type == E_NAN || type == E_INF || type == E_NINF || type == E_NANF || type == E_INFF || type == E_NINFF)
		std::cout << "Impossible" << std::endl;
}

static void print_float(t_converted value, t_types type)
{
	std::cout << "float: ";
	if(type == INTEGER)
		std::cout << static_cast<float>(value.intvalue) << ".0f" << std::endl;
	else if(type == FLOAT)
	{
		std::cout << value.floatvalue;
		if (value.floatvalue == (static_cast<float>(static_cast<int>(value.floatvalue))))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else if (type == DOUBLE)
	{
		if (value.doublevalue < -FLT_MAX || value.doublevalue > FLT_MAX|| (value.doublevalue > 0 && value.doublevalue < FLT_MIN) || (value.doublevalue < 0 && value.doublevalue > -FLT_MIN))
			std::cout << "Impossible" << std::endl;
		else
		{
			std::cout << static_cast<float>(value.doublevalue);
			if (value.doublevalue == (static_cast<double>(static_cast<int>(value.doublevalue))))
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
	}
	else if(type == E_NAN || type == E_INF || type == E_NINF)
		std::cout << static_cast<float>(value.doublevalue) << "f" << std::endl;
	else if(type == E_NANF || type == E_INFF || type == E_NINFF)
		std::cout << value.floatvalue << "f" << std::endl;
}

static void print_double(t_converted value, t_types type)
{
	std::cout << "double: ";
	if(type == INTEGER)
		std::cout << static_cast<double>(value.intvalue) << ".0" << std::endl;
	else if(type == FLOAT)
	{
		std::cout << static_cast<double>(value.floatvalue);
		if (value.floatvalue == (static_cast<float>(static_cast<int>(value.floatvalue))))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (type == DOUBLE)
	{
		std::cout << static_cast<double>(value.doublevalue);
		if (value.doublevalue == (static_cast<double>(static_cast<int>(value.doublevalue))))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if(type == E_NAN || type == E_INF || type == E_NINF)
		std::cout << value.doublevalue << std::endl;
	else if(type == E_NANF || type == E_INFF || type == E_NINFF)
		std::cout << static_cast<double>(value.floatvalue) << std::endl;
}

//will print for each datatype the value if possible
void	print_types(t_converted converted_value, t_types type)
{
	print_char(converted_value, type);
	print_int(converted_value, type);
	print_float(converted_value, type);
	print_double(converted_value, type);
}