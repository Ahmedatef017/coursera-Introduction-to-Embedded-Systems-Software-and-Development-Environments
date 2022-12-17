/**
 * @file stats.h
 * @brief Definitions and macros required for the c1m1 assignment.
 *
 *
 * @author Ahmed Atef Abdul-Rahman.
 * @date 17/12/2022.
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#define SIZE 40
void print_array (unsigned char *array, unsigned int counter);
void print_statistics(unsigned char minimum, unsigned char maximum, float mean, unsigned char median);
unsigned char find_median (unsigned char *array, unsigned int counter);
float find_mean (unsigned char *array, unsigned int counter);
unsigned char find_maximum (unsigned char *array, unsigned int counter);
unsigned char find_minimum (unsigned char *array, unsigned int counter);
void sort_array (unsigned char *array, unsigned int counter);
#endif // __STATS_H__
