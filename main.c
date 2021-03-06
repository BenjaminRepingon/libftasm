/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:26:01 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/13 14:23:16 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <fcntl.h>

# include <libfts.h>

# define	MIN				( -4200 )
# define	MAX				( 5000 )
# define	STR_MAX_SIZE	( 5000 )
# define	random(min, max)( ( rand() % ( max - min ) ) + min )

static size_t	random_str( char *buff )
{
	size_t	len = random( 1, STR_MAX_SIZE );

	int i;
	for ( i = 0; i < len; ++i )
		buff[i] = random( 1, 256 );
	buff[i] = 0;
	return ( len );
}

int				main( void )
{
	int i = 0;
	srand( 42 );


	printf( "--------\nTest ft_bzero:\n" );
	char	str_bezro[STR_MAX_SIZE];
	char	str_ft_bezro[STR_MAX_SIZE];
	size_t	len_bzero;

	for ( i = MIN; i < MAX; i++ )
	{
		len_bzero = random_str( str_bezro );
		len_bzero -= random( 0, len_bzero );
		strcpy( str_ft_bezro, str_bezro );

		ft_bzero( str_ft_bezro, len_bzero );
		bzero( str_bezro, len_bzero );
		if ( memcmp( str_ft_bezro, str_bezro, len_bzero ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_ft_bezro, str_bezro );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_strcat:\n" );
	char	str_strcat[STR_MAX_SIZE * 2];
	char	str_ft_strcat[STR_MAX_SIZE * 2];
	char	str_strcat_s2[STR_MAX_SIZE];
	char	*ret_strcat;
	char	*ret_ft_strcat;
	size_t	len_strcat;
	size_t	len_strcat_s2;

	for ( i = MIN; i < MAX; i++ )
	{
		len_strcat_s2 = random_str( str_strcat_s2 );
		len_strcat = random_str( str_strcat );
		strcpy( str_ft_strcat, str_strcat );

		ret_ft_strcat = ft_strcat( str_ft_strcat, str_strcat_s2 );
		ret_strcat = strcat( str_strcat, str_strcat_s2 );
		if ( memcmp( str_strcat, str_ft_strcat, len_strcat + len_strcat_s2 ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_strcat, str_ft_strcat );
			exit( 0 );
		}
		if ( memcmp( ret_strcat, ret_ft_strcat, len_strcat + len_strcat_s2 ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", ret_strcat, ret_ft_strcat );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_isalpha:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_isalpha( i ) != isalpha( i ) )
		{
			printf("[%d] -> result: %d, expected result: %d\n", i, ft_isalpha( i ), isalpha( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_isdigit:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_isdigit( i ) != isdigit( i ) )
		{
			printf("[%d] -> result: %d, expected result: %d\n", i, ft_isdigit( i ), isdigit( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_isalnum:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_isalnum( i ) != isalnum( i ) )
		{
			printf("[%d] -> result: %d, expected result: %d\n", i, ft_isalnum( i ), isalnum( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_isascii:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_isascii( i ) != isascii( i ) )
		{
			printf("[%d] -> result: %d, expected result: %d\n", i, ft_isascii( i ), isascii( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_isprint:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_isprint( i ) != isprint( i ) )
		{
			printf("[%d] -> result: %d, expected result: %d\n", i, ft_isprint( i ), isprint( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_toupper:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_toupper( i ) != toupper( i ) )
		{
			printf("[%d] -> result: %c, expected result: %c\n", i, ft_toupper( i ), toupper( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_tolower:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_tolower( i ) != tolower( i ) )
		{
			printf("[%d] -> result: %c, expected result: %c\n", i, ft_tolower( i ), tolower( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	printf( "--------\nTest ft_strlen:\n" );
	char	str[STR_MAX_SIZE];
	size_t	len;
	size_t	ft_len;

	for ( i = MIN; i < MAX; i++ )
	{
		len = random_str( str );
		if ( ( ft_len = ft_strlen( str ) ) != len )
		{
			printf("[%s] -> result: %d, expected result: %d\n", str, ft_len, len );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	printf( "--------\nTest ft_memset:\n" );
	char	str_memset[STR_MAX_SIZE];
	char	str_ft_memset[STR_MAX_SIZE];
	size_t	len_memset;

	for ( i = MIN; i < MAX; i++ )
	{
		len_memset = random_str( str_memset );
		len_memset -= random( 0, len_memset );
		strcpy( str_ft_memset, str_memset );

		ft_memset( str_ft_memset, i, len_memset );
		memset( str_memset, i, len_memset );
		if ( memcmp( str_ft_memset, str_memset, len_bzero ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_ft_memset, str_memset );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	printf( "--------\nTest ft_memcpy:\n" );
	char	str_memcpy[STR_MAX_SIZE];
	char	str_ft_memcpy[STR_MAX_SIZE];
	char	str_memcpy_s2[STR_MAX_SIZE];
	size_t	len_memcpy;
	void	*ret_memcpy;
	void	*ret_ft_memcpy;

	for ( i = MIN; i < MAX; i++ )
	{
		len_memcpy = random_str( str_memcpy_s2 );

		ret_ft_memcpy = ft_memcpy( str_ft_memcpy, str_memcpy_s2, len_memcpy );
		ret_memcpy = memcpy( str_memcpy, str_memcpy_s2, len_memcpy );
		if ( memcmp( str_ft_memcpy, str_memcpy, len_memcpy ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_ft_memcpy, str_memcpy );
			exit( 0 );
		}
		if ( ret_ft_memcpy != str_ft_memcpy )
		{
			printf("result: \n%d\nexpected result: \n%d\n", (size_t)ret_ft_memcpy, (size_t)str_ft_memcpy );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_strdup:\n" );
	char	str_strdup[STR_MAX_SIZE];
	size_t	len_strdup;
	char	*ret_ft_strdup;
	char	*ret_strdup;


	for ( i = MIN; i < MAX; i++ )
	{
		len_strdup = random_str( str_strdup );

		ret_ft_strdup = ft_strdup( str_strdup );
		ret_strdup = strdup( str_strdup );
		if ( memcmp( ret_ft_strdup, ret_strdup, len_strdup ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", ret_ft_strdup, ret_strdup );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	printf("BONUS\n");
	printf( "--------\nTest ft_strncat:\n" );
	char	str_strncat[STR_MAX_SIZE * 2];
	char	str_ft_strncat[STR_MAX_SIZE * 2];
	char	str_strncat_s2[STR_MAX_SIZE];
	char	*ret_strncat;
	char	*ret_ft_strncat;
	size_t	len_strncat;
	size_t	len_strncat_s2;

	for ( i = MIN; i < MAX; i++ )
	{
		len_strncat_s2 = random_str( str_strncat_s2 );
		len_strncat = random_str( str_strncat );
		strcpy( str_ft_strncat, str_strncat );

		size_t n = random( 0, len_strncat_s2 );
		ret_ft_strncat = ft_strncat( str_ft_strncat, str_strncat_s2, n );
		ret_strncat = strncat( str_strncat, str_strncat_s2, n );
		if ( memcmp( str_strncat, str_ft_strncat, len_strncat + len_strncat_s2 ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_strncat, str_ft_strncat );
			exit( 0 );
		}
		if ( memcmp( ret_strncat, ret_ft_strncat, len_strncat + len_strncat_s2 ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", ret_strncat, ret_ft_strncat );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_isupper:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_isupper( i ) != isupper( i ) )
		{
			printf("[%d] -> result: %c, expected result: %c\n", i, ft_isupper( i ), isupper( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_islower:\n" );
	for ( i = MIN; i < MAX; i++ )
	{
		if ( ft_islower( i ) != islower( i ) )
		{
			printf("[%d] -> result: %c, expected result: %c\n", i, ft_islower( i ), islower( i ) );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_strcpy:\n" );
	char	str_ft_strcpy[STR_MAX_SIZE];
	char	str_strcpy[STR_MAX_SIZE];
	char	str_strcpy_s2[STR_MAX_SIZE];
	char	*ret_strcpy;
	char	*ret_ft_strcpy;
	int		len_strcpy;

	for ( i = MIN; i < MAX; i++ )
	{
		len_strcpy = random_str( str_strcpy_s2 );

		ret_strcpy = strcpy( str_strcpy, str_strcpy_s2 );
		ret_ft_strcpy = ft_strcpy( str_ft_strcpy, str_strcpy_s2 );

		if ( memcmp( str_ft_strcpy, str_strcpy, len_strcpy ) != 0 )
		{
			printf("result: \n%s\n, expected result: \n%s\n", str_ft_strcpy, str_strcpy );
			exit( 0 );
		}
		if ( memcmp( ret_strcpy, ret_ft_strcpy, len_strcpy ) != 0 )
		{
			printf("result: \n%s\n, expected result: \n%s\n", ret_strcpy, ret_ft_strcpy );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_strncpy:\n" );
	char	str_ft_strncpy[STR_MAX_SIZE];
	char	str_strncpy[STR_MAX_SIZE];
	char	str_strncpy_s2[STR_MAX_SIZE];
	char	*ret_strncpy;
	char	*ret_ft_strncpy;
	int		len_strncpy;

	for ( i = MIN; i < MAX; i++ )
	{
		len_strncpy = random_str( str_strncpy_s2 );
		len_strncpy -= random( 0, len_strncpy );

		ret_strncpy = strncpy( str_strncpy, str_strncpy_s2, len_strncpy );
		ret_ft_strncpy = ft_strncpy( str_ft_strncpy, str_strncpy_s2, len_strncpy );

		if ( strcmp( str_ft_strncpy, str_strncpy ) != 0 )
		{
			printf("result: \n%s\n, expected result: \n%s\n", str_ft_strncpy, str_strncpy );
			exit( 0 );
		}
		if ( strcmp( ret_strncpy, ret_ft_strncpy ) != 0 )
		{
			printf("result: \n%s\n, expected result: \n%s\n", ret_strncpy, ret_ft_strncpy );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");



	printf( "--------\nTest ft_cat:\n" );

	ft_cat( 4 );
	ft_cat( 8 );
	ft_cat( 15 );
	ft_cat( 16 );
	ft_cat( 23 );
	ft_cat( 42 );

	ft_cat( open( "Makefile", O_RDONLY ) );
	ft_cat( open( "./tests/random", O_RDONLY ) );
	ft_cat( open( "./tests/permission", O_RDONLY ) );

	printf("\n");

	ft_cat( 0 );

	printf("\033[32mOk\n\033[0m");
	return ( 0 );
}
