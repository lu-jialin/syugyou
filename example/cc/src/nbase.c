#include "lulix/includes.h"
#include "lulix/bitc.h"
#include "lulix/log.h"
#include "lulix/of.h"
#include "lulix/range.h"
#include "lulix/types.h"

#include "nbase.h"

base_t g_ibase = 0;
base_t g_obase = 0;

char_t
fig_by_base(num_t num)
{
	static const char_t * fig_p = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char_t dig = 0;

	if(num)
	{
		if(dig = fig_by_base(num / g_obase))putchar(dig);
		return fig_p[num % g_obase];
	}
	else
	{
		return 0;
	}
}

num_t
str2num_by_base(len_t strlen, char_t * str_p)
{
	unsigned long long int_t abs = 0;
	char_t c = 0;
	char_t ascii_v[0x100];
	memset(ascii_v , -1 , sizeof(ascii_v));

	_repeat_('0' , c ,'9') ascii_v[c] = c - '0' + 0x0;

	_repeat_('A' , c , 'Z') ascii_v[c] = c - 'A' + 0xA;

	_repeat_('a' , c , 'z') ascii_v[c] = c - 'a' + 0xa;

	int_t sign = 1;
	num_t ibase_power = 1;
	sign = ((*str_p != '-') || ((strlen--) && (*(str_p++) = 0))) * 2 - 1;

	while(strlen--)
	{
		if(ascii_v[str_p[strlen]] == -1)
		{
			exit(!printf("Input <number> with a invalid format: \"%s\"\n", str_p));
		}

		if(ascii_v[str_p[strlen]] >= g_ibase)
		{
			exit(!printf("input digit was out of base: \"%s\"\n", str_p));
		}

		abs += ascii_v[str_p[strlen]] * ibase_power;
		ibase_power *= g_ibase;
	}

	return sign * abs;
}
