#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("-ex00_test_case-\n\n");
	char dest1[10];
	char src1[6] = "Hello";
	printf("strcpy : %s ft_strcpy : %s", strcpy(dest1, src1), ft_strcpy(dest1, src1));
	printf("\n\n------------------------------\n\n");

	printf("-ex01_test_case-\n\n");
	char dest2[10] = "Howareyou";
	char src2[6] = "Hello";
	printf("input dest : Howareyou | src : Hello |  n : 5\n\n");
	printf("--answer--\nstrncpy : %s ft_strncpy : %s\n\n", strncpy(dest2, src2, 5), ft_strncpy(dest2, src2, 5));
	printf("input  dest : Howareyou | src : Hello | n : 10\n\n");
	printf("--answer--\nstrncpy : %s ft_strncpy : %s", strncpy(dest2, src2, 10), ft_strncpy(dest2, src2, 10));
	printf("\n\n------------------------------\n\n");

	printf("-ex02_test_case-\n\n");
	char test1[] = "Hello";
	printf("input : Hello result : %d\n\n", ft_str_is_alpha(test1));
	char test2[] = "42Hello";
	printf("input : 42Hello result : %d\n\n", ft_str_is_alpha(test2));
	char test3[] = "";
	printf("input : empty string result : %d", ft_str_is_alpha(test3));
	printf("\n\n------------------------------\n\n");

	printf("-ex03_test_case-\n\n");
	char test4[] = "42132";
	printf("input : 42132 result : %d\n\n", ft_str_is_numeric(test4));
	printf("input : 42Hello result : %d\n\n", ft_str_is_numeric(test2));
	printf("input : empty string result : %d", ft_str_is_numeric(test3));
	printf("\n\n------------------------------\n\n");

	printf("-ex04_test_case-\n\n");
	char test5[] = "asdwa";
	printf("input : asdwa result : %d\n\n", ft_str_is_lowercase(test5));
	printf("input : 42Hello result : %d\n\n", ft_str_is_lowercase(test2));
	printf("input : empty string result : %d", ft_str_is_lowercase(test3));
	printf("\n\n------------------------------\n\n");

	printf("-ex05_test_case-\n\n");
	char test6[] = "AJDSDZ";
	printf("input : AJDSDZ result : %d\n\n", ft_str_is_uppercase(test6));
	printf("input : 42Hello result : %d\n\n", ft_str_is_uppercase(test2));
	printf("input : empty string result : %d", ft_str_is_uppercase(test3));
	printf("\n\n------------------------------\n\n");

	printf("-ex06_test_case-\n\n");
	char test7[] = "AJDSDZ";
	char test8[] = "42Hea\\0";
	printf("input : AJDSDZ result : %d\n\n", ft_str_is_uppercase(test7));
	printf("input : 42Hea\\0 result : %d\n\n", ft_str_is_uppercase(test8));
	printf("input : empty string result : %d", ft_str_is_uppercase(test3));
	printf("\n\n------------------------------\n\n");

	printf("-ex07_test_case-\n\n");
	char test9[] = "Hello42";
	printf("before : %s\n\n", test9);
	ft_strupcase(test9);
	printf("after : %s", test9);
	printf("\n\n------------------------------\n\n");

	printf("-ex08_test_case-\n\n");
	printf("before : %s\n\n", test9);
	ft_strlowcase(test9);
	printf("after : %s", test9);
	printf("\n\n------------------------------\n\n");

	printf("-ex09_test_case-\n\n");
	char test10[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char test13[] = "ASLD masldw+ ?lsa 3wmdalASDzqp asm sdk2sk";
	printf("before : %s\n\n", test10);
	ft_strcapitalize(test10);
	printf("after : %s\n\n", test10);
	printf("-------------------------------\n\n");
	printf("before : %s\n\n", test13);
	ft_strcapitalize(test13);
	printf("after : %s\n\n", test13);
	printf("\n\n------------------------------\n\n");

	printf("-ex10_test_case-\n\n");
	char dest3[10] = "Howareyou";
	char src3[5] = "Hiow";
	printf("input dest : Howareyou | src : Hiow | n : 4\n\n");
	printf("--answer--\nstrlcpy : %lu dest : %s\nft_strlcpy : %u dest : %s\n\n", strlcpy(dest3, src3, 4), dest3,  ft_strlcpy(dest3, src3, 4), dest3);
	printf("input  dest : Howareyou | src : Hiow | n : 10\n\n");
	printf("--answer--\nstrlcpy : %lu dest : %s\nft_strlcpy : %u dest : %s", strlcpy(dest3, src3, 10), dest3,  ft_strlcpy(dest3, src3, 10), dest3);
	printf("\n\n------------------------------\n\n");

	printf("-ex11_test_case-\n\n");
	char test11[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(test11);
	printf("\n\n------------------------------\n\n");

	// Exercise 12
	char arr[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	if (ft_print_memory(arr, 92) != arr)
		return -1;
	char brr[] = "Chuncheon is better than Seoul!\200:)\377;)";
	ft_print_memory(brr, 38);
	ft_print_memory(brr, 10);
	ft_print_memory(brr, 0);
	for (int i = 13; i < 24; ++i)
		brr[i] = '\0';
	ft_print_memory(brr, 37);
	ft_print_memory(brr, 37);
	return 0;
}
