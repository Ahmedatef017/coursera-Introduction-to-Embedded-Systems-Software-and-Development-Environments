/******************************************************************************
* Definitions for 8/16/32-bit wide memory access                              *
******************************************************************************/
#define HWREG8(x)         (*((volatile uint8_t *)(x)))
#define HWREG16(x)        (*((volatile uint16_t *)(x)))
#define HWREG32(x)        (*((volatile uint32_t *)(x)))
#define HWREG(x)          (HWREG16(x))
#define HWREG8_L(x)       (*((volatile uint8_t *)((uint8_t *)&x)))
#define HWREG8_H(x)       (*((volatile uint8_t *)(((uint8_t *)&x)+1)))
#define HWREG16_L(x)      (*((volatile uint16_t *)((uint16_t *)&x)))
#define HWREG16_H(x)      (*((volatile uint16_t *)(((uint16_t *)&x)+1)))

/******************************************************************************
* Definitions for 8/16/32-bit wide bit band access                            *
******************************************************************************/
#define HWREGBIT8(x, b)   (HWREG8(((uint32_t)(x) & 0xF0000000) | 0x02000000 | (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2)))
#define HWREGBIT16(x, b)  (HWREG16(((uint32_t)(x) & 0xF0000000) | 0x02000000 | (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2)))
#define HWREGBIT32(x, b)  (HWREG32(((uint32_t)(x) & 0xF0000000) | 0x02000000 | (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2)))

#undef __wfi
#define __wfi()                         __asm("  wfi")
#define __sleep()                       __wfi()
#define __deep_sleep()                  { (*((volatile uint32_t *)(0xE000ED10))) |= 0x00000004; __wfi(); (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000004; }
#define __low_power_mode_off_on_exit()  { (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000002; }
#define __get_SP_register()             __get_MSP()
#define __set_SP_register(x)            __set_MSP(x)
#define __get_interrupt_state()         __get_PRIMASK()
#define __set_interrupt_state(x)        __set_PRIMASK(x)
#define __enable_interrupt()            __asm("  cpsie i")
#define __enable_interrupts()           __asm("  cpsie i")
#define __disable_interrupt()           __asm("  cpsid i")
#define __disable_interrupts()          __asm("  cpsid i")
#define __no_operation()                __asm("  nop")

// Intrinsics without ARM equivalents
#define __bcd_add_short(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long(x,y)             { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __even_in_range(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_char(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_short(x,y)       { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __never_executed()              { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __op_code()                     { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __code_distance()               { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bic_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }
#define __bic_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }
#define __delay_cycles(x)               { while(1); /* Using not-supported MSP430 intrinsic. Recommended to use a timer or a custom for loop. */ }

// Intrinsics without ARM equivalents
#define __low_power_mode_0()            { __sleep(); }
#define __low_power_mode_1()            { __sleep(); }
#define __low_power_mode_2()            { __sleep(); }
#define __low_power_mode_3()            { __deep_sleep(); }
#define __low_power_mode_4()            { __deep_sleep(); }
#define __data16_read_addr(x)           (*((volatile uint32_t *)(x)))
#define __data20_read_char(x)           (*((volatile uint8_t *)(x)))
#define __data20_read_short(x)          (*((volatile uint16_t *)(x)))
#define __data20_read_long(x)           (*((volatile uint32_t *)(x)))
#define __data16_write_addr(x,y)        { (*((volatile uint32_t *)(x))) }
#define __get_SR_register()             0
#define __get_SR_register_on_exit()     0
