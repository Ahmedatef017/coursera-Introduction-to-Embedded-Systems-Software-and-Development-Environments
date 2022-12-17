/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * This file includes all the required functions implementations in the c1m1 assignment
 *
 * @author Ahmed Atef Abdul-Rahman.
 * @date 17/12/2022.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char minimum = 0;
  unsigned char maximum = 0;
  float mean = 0;
  unsigned char median = 0;

  /* Statistics and Printing Functions Go Here */
  printf("Array before sorting: \n");
  print_array(&test, SIZE);
  median = find_median(&test, SIZE);
  mean = find_mean(&test, SIZE);
  maximum = find_maximum(&test, SIZE);
  minimum = find_minimum(&test, SIZE);
  print_statistics(minimum, maximum, mean, median);
  sort_array(&test, SIZE);
  printf("Array after sorting: \n");
  print_array(&test, SIZE);
  return 0;
}

void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median)
{
    printf("The minimum is %d \n", minimum);
    printf("The maximum is %d \n", maximum);
    printf("The mean is %f \n", mean);
    printf("The median is %d \n", median);
}


void print_array (unsigned char *array, unsigned int counter)
{
    for (int i=0; i<counter; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
}


unsigned char find_median (unsigned char *array, unsigned int counter)
{
    unsigned char median = 0;
    median =array[(counter/2)]-1;
    return median;
}


float find_mean (unsigned char *array, unsigned int counter)
{
    unsigned int accumulator = 0; // variable to store the accumulator value throughout the mean finding process
    float mean = 0;
    for (int i=0; i<counter; i++)
    {
        accumulator = accumulator + array[i] ;
    }
    printf("acc = %d \n", accumulator);
    mean = accumulator / ((float) counter); //must type cast one of the two integers to float for accurate calculation.
    return mean;
}


unsigned char find_maximum (unsigned char *array, unsigned int counter)
{
    unsigned char maximum = array[0]; // initalize the maximum variable with the value of the first array element
    for (int i=1; i<counter; i++)  // start the loop from the second elemnt
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
        }
    }
    return maximum;
}


unsigned char find_minimum (unsigned char *array, unsigned int counter)
{
    unsigned char minimum = array[0]; // initalize the minimum variable with the value of the first array element
    for (int i=1; i<counter; i++)  // start the loop from the second elemnt
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }
    return minimum;
}

//bubble sort
void sort_array (unsigned char *array, unsigned int counter)
{
    unsigned char i,j,temp,sorting_flag=0;
    for(j=0; j<counter-1; j++)
    {
        sorting_flag=1;
        for(i=0; i<counter-1-j; i++)
        {
            if(array[i]>array[i+1])
            {
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                sorting_flag=0;

            }
        }
        if(sorting_flag==1)
        {
            break;
        }
    }
}



