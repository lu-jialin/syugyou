#include <stdio.h>

#include "lulix/includes.h"
#include "lulix/bitc.h"
#include "lulix/log.h"
#include "lulix/of.h"
#include "lulix/range.h"
#include "lulix/types.h"

#include "nbase.h"

main_t
main(int_t argc, char_t* arg_v[])
{
	num_t num = 0;
	g_ibase = g_obase = 10;

	/* getopt */
	signed int_t opt = 0;
	while((opt = getopt(argc, arg_v, "i:o:")) != -1)
	{
		switch(opt)
		{
			case 'i':
				g_ibase = abs(atoi(optarg));
				arg_v[optind - 1] = arg_v[optind - 1 - (optarg == arg_v[optind - 1])] = NULL;
				break;

			case 'o':
				g_obase = abs(atoi(optarg));
				arg_v[optind - 1] = arg_v[optind - 1 - (optarg == arg_v[optind - 1])] = NULL;
				break;

			default:
				/* exit(!puts("parameters error")); */
				break;
		}
	}
	/* getopt */

	while(--argc)
	{
		if(!arg_v[argc]) continue;

		num = str2num_by_base(strlen(arg_v[argc]), arg_v[argc]);
		//printf("(g_ibase, g_obase, num) <- (%d, %d, %d)", g_ibase, g_obase, num);
		#if 0
		char_t* Sign = "-";
		putchar(Sign[(num >> (sizeof(num) * 010 - 1)) + 1]);
		/* f(num) = (num >> (sizeof(num) * 010 - 1)) => f(-|num|) -> 0, f(+|num|) -> 1 */
		/* Sign[0] === '-', Sign[1] === '\0' */
		#endif
		if(num < 0) putchar('-');
		putchar(fig_by_base(labs(num)));
		putchar('\n');
	}

	return (main_t)0;
}
