#ifndef __NBASE_INCLUDE_UNIQ__
#define __NBASE_INCLUDE_UNIQ__

#include "nbase.h"
typedef signed long long int num_t;
typedef signed long long int cnt_t;
typedef unsigned int base_t;
typedef signed int len_t;
typedef signed int pos_t;
typedef signed int ind_t;

extern base_t g_ibase;
extern base_t g_obase;

extern char_t fig_by_base();
extern num_t str2num_by_base();
#endif
