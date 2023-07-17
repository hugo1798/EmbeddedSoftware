/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  /* Other Variable Declarations Go Here */
  /*
   We need to make the conversion of the test to a pointer, which will give us 
   the address of the variable test
  */
  unsigned int size = 40;
  /* Statistics and Printing Functions Go Here */
  unsigned char med_val = find_median(test, size);
  unsigned char val_mean = find_mean(test, size);
  unsigned char val_max = find_maximum(test, size);
  unsigned char val_min = find_minimum(test, size);
  unsigned char arrayprint = print_array(test, size);
  unsigned char statisticsprint = print_statistics(val_min, val_max, val_mean, med_val);/*
  printf("%d\n", val_max);
  printf("%d\n", val_mean);
  printf("%d\n", med_val);
  printf("%d\n", val_min);*/
  return;
}

/* Add other Implementation File Code Here */
