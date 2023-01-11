#ifndef __PLATFORM_H__
#define __PLATFORM_H__

/******************************************************************************
 Platform - MSP432
******************************************************************************/
#if defined (MSP432)
#include "../msp432/msp432p401r.h"
#define PRINTF(...)
/******************************************************************************
 Platform - HOST
******************************************************************************/
#elif defined (HOST)
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
/* The dots are called, together with the __VA_ARGS__, variadic macros
* When the macro is invoked, all the tokens in its argument list [...],
* including any commas, become the variable argument.
* This sequence of tokens replaces the identifier VA_ARGS in the macro body wherever it appears.
*/
/******************************************************************************
 Platform - Unsupported
******************************************************************************/
#else
#error "Platform provided is not supported in this Build System"
#endif

#endif /* __PLATFORM_H__ */

