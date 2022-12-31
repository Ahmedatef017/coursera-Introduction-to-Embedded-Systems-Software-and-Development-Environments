
#ifndef SYSTEM_MSP432P401R_H
#define SYSTEM_MSP432P401R_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *
 * Performs the following initialization steps:
 *     1. Enables the FPU
 *     2. Halts the WDT
 *     3. Enables all SRAM banks
 *     4. Sets up power __REGULATOR and VCORE
 *     5. Enable Flash wait states if needed
 *     6. Change MCLK to desired frequency
 *     7. Enable Flash read buffering
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_MSP432P401R_H */
