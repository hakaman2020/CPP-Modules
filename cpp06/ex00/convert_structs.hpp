#ifndef CONVERT_STRUCTS_HPP
# define CONVERT_STRUCTS_HPP

typedef enum e_errors
{
	NO_ERRORS,
	ERR_OUT_OF_RANGE
}			t_errors;

typedef enum types
{
	INVALID,
	INTEGER,
	FLOAT,
	DOUBLE,
	E_NAN,
	E_NANF,
	E_INF,
	E_INFF,
	E_NINF,
	E_NINFF,
	NOT_SPECIAL
} 			t_types;

typedef union u_converted
{
	char	cvalue;
	int		intvalue;
	float	floatvalue;
	double	doublevalue;
}				t_converted;

#endif