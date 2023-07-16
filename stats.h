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
 * @file Header file for the statistics .c program
 * @brief In this file we can find the public function declarations that will be
 * used in the .c program
 *
 * All the functions proposed here have the following characeristics
 * Inputs: 1. unsigned char pointer to an n element data array, 2. unsigned integer
 * as the size of the array
 * Output: unsigned char
 * In this file we can find 8 functions that will be used in the stats.c program,
 * such as:
 * Finding the minimum
 * Finding the maximum
 * Finding the mean
 * Finding the median
 * Printing the array to the screen
 * Sorting the array from largest to smallest
 *
 * @author Salcedo
 * @date 12/07/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
/**
 * @brief Function used to find the median
 *
 * To find the median of a list of numbers, the array should be sorted. After sorting
 * the list, then we calculate the modulus of the size of the array to determine if 
 * the size number is even or odd. With this information, we can finally calculate the
 * median.
 * The function contains two input parameters:
 *
 * @param pointer_array corresponds to the pointer, so the function will 
 * retrieve the data from the array
 * where the data of the array is located
 * @param size_array This parameter will allow us to limit our for loop
 *
 * @return The value returned will be an unsigned char called med_val, which will
 * used later in the statistics printing
 */
unsigned char find_median(unsigned char pointer_array, unsigned int size_array){
    unsigned char *val, *med_val;
    unsigned char arrayaux[40] = {};
    unsigned char valprev;
    unsigned char i1 = 1;
    unsigned char i2 = 1;
    
    valprev = 0;
    
    for(int i = 0; i < 40; i++){
        val = &address_test[i];
        if(val>valprev){
            if(i == 0){
                arrayaux[i] = val;
            }
            else if(i > 1){
                i1 = 1;
                i2 = 1;
                while(val>arrayaux[i-i1]){
                    if((i - i1) < 0){
                        break;
                    }
                    else if(i1 == 1){
                        arrayaux[i] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                    }
                    else{
                        arrayaux[i - i2] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                        i2++;
                    }
                }
            }
            else{
                arrayaux[i] = valprev;
                arrayaux[i-1] = val;
            }
            valprev = val;
        }
        else{
            if(val<arrayaux[i-1]){
                arrayaux[i] = val;
            }
            else if(i > 1){
                i1 = 1;
                i2 = 1;
                while(val>arrayaux[i-i1]){
                    if((i - i1) < 0){
                        break;
                    }
                    else if(i1 == 1){
                        arrayaux[i] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                    }
                    else{
                        arrayaux[i - i2] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                        i2++;
                    }
                }
            }
            else{
                arrayaux[i] = arrayaux[i-1];
                arrayaux[i-1] = val;
            }
            valprev = val;
        }
    }
    if((size_array % 2) != 0){
         med_val = &address_test[size_array / 2];
    }
    else{
        med_val = (&address_test[size_array / 2] + &address_test[(size_array / 2) - 1]) / 2;
    }
    return med_val;
}
/**
 * @brief Function used to find the mean
 *
 * In this function we calculate the mean of the list. To do so, we create a variable
 * that will contain the sum of each one of the elements in the list. This is done with a 
 * for loop with an extension of the size of the array. We finally divide this sum over the 
 * size of the array.
 * The function contains two input parameters
 *
 * @param pointer_array corresponds to the pointer, so the function will 
 * retrieve the data from the array
 * where the data of the array is located
 * @param size_array This parameter will allow us to limit our for loop
 *
 * @return The value returned will be an unsigned char called mean_val, which will be used
 * later in the statistics printing
 */
unsigned char find_mean(unsigned char pointer_array, unsigned int size_array){
    unsigned char *value;
    // In this case we cannot use an unsigned char since the range for this variable
    // is not enough for us to do the right calculations
    unsigned int sum_val = 0;
    unsigned int mean_val = 0;
    for (int i = 0; i < size_array; i++){
        value = &address_test[i];
        sum_val += *value;
    }
    mean_val = sum_val / size_array;
    return mean_val;
}
/**
 * @brief Function used to find the maximum
 *
 * This function retrieves the data from the list provided. A variable stores the max value 
 * that is found within such list. This value is initialized as 0 to store the first value that we
 * find in the list. 
 * The function contains two input parameters
 *
 * @param pointer_array corresponds to the pointer, so the function will 
 * retrieve the data from the array
 * where the data of the array is located
 * @param size_array This parameter will allow us to limit our for loop
 *
 * @return The value returned will be an unsigned char called max_val, which will be used
 * later in the statistics printing
 */
unsigned char find_maximum(unsigned char address_test, unsigned int size_array){
    unsigned char *value;
    unsigned char max_val = 0;
    for (int i = 0; i < size_array; i++){
        value = &address_test[i];
        if(*value > max_val){
            max_val = *value;
        }
    }
    return max_val;
}
/**
 * @brief Function used to find the minimum
 *
 * This function retrieves the data from the list provided. A variable stores the min value 
 * that is found within such list. This value is initialized as 0 to store the first value that we
 * find in the list. 
 * The function contains two input parameters
 *
 * @param pointer_array corresponds to the pointer, so the function will 
 * retrieve the data from the array
 * where the data of the array is located
 * @param size_array This parameter will allow us to limit our for loop
 *
 * @return The value returned will be an unsigned char called min_val, which will be used
 * later in the statistics printing
 */
unsigned char find_minimum(unsigned char address_test, unsigned int size_array){
    unsigned char *value;
    unsigned char min_val = 5000;
    for (int i = 0; i < size_array; i++){
        value = &address_test[i];
        if(*value < min_val){
            min_val = *value;
        }
    }
    return min_val;
}
/**
 * @brief Function used to sort the array 
 *
 * This function sorts the array provided from larger to smallest number. The function is based
 * on comparing the value read on the array with a previous value read. The function not only 
 * compares this two values but also compares the value with the rest of the array. Finally, the 
 * sorted values are saved on an auxiliary array.
 * The function contains two input parameters
 *
 * @param pointer_array corresponds to the pointer, so the function will 
 * retrieve the data from the array
 * where the data of the array is located
 * @param size_array This parameter will allow us to limit our for loop
 *
 * @return This function returns an unsigned char called arrayaux which contains the sorted array
 */
unsigned char sort_array(unsigned char address_test, unsigned int size_array){
    unsigned char *val;
    unsigned char arrayaux[40] = {};
    unsigned char valprev;
    unsigned char i1 = 1;
    unsigned char i2 = 1;
    
    valprev = 0;
    
    for(int i = 0; i < 40; i++){
        val = &address_test[i];
        if(val>valprev){
            if(i == 0){
                arrayaux[i] = val;
            }
            else if(i > 1){
                i1 = 1;
                i2 = 1;
                while(val>arrayaux[i-i1]){
                    if((i - i1) < 0){
                        break;
                    }
                    else if(i1 == 1){
                        arrayaux[i] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                    }
                    else{
                        arrayaux[i - i2] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                        i2++;
                    }
                }
            }
            else{
                arrayaux[i] = valprev;
                arrayaux[i-1] = val;
            }
            valprev = val;
        }
        else{
            if(val<arrayaux[i-1]){
                arrayaux[i] = val;
            }
            else if(i > 1){
                i1 = 1;
                i2 = 1;
                while(val>arrayaux[i-i1]){
                    if((i - i1) < 0){
                        break;
                    }
                    else if(i1 == 1){
                        arrayaux[i] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                    }
                    else{
                        arrayaux[i - i2] = arrayaux[i-i1];
                        arrayaux[i-i1] = val;
                        i1++;
                        i2++;
                    }
                }
            }
            else{
                arrayaux[i] = arrayaux[i-1];
                arrayaux[i-1] = val;
            }
            valprev = val;
        }
    }
    return arrayaux;
}
/**
 * @brief Function used to print the maximum, minimum, mean, and median
 *
 * This function takes the variables that we created on previous functions in order to print
 * the maximimum, minimum, mean, and median of the array.
 * The function contains four input parameters
 *
 * @param minval This parameter can be retrieved from the function that determines the minimum value in the array
 * @param maxval This parameter can be retrieved from the function that determines the maximum value in the array
 * @param meanval This parameter can be retrieved from the function that determines the mean value in the array
 * @param medianval This parameter can be retrieved from the function that determines the median value in the array
 *
 * @return This function doesnt return any important value, since its a printing function
 */
unsigned char print_statistics(unsigned char minval, unsigned char maxval, unsigned char meanval, unsigned char medianval){
    printf("The statistics for this array are");
    printf("Minimum val %u\n", minval);
    printf("Maximum val %u\n", maxval);
    printf("Mean val %u\n", meanval);
    printf("Median val %u\n", medianval);
    return 0;
}
/**
 * @brief Function used to print the array
 *
 * This function uses a for loop to retrieve and print the values inside the array.
 * The function contains two input parameters
 *
 * @param pointer_array corresponds to the pointer, so the function will 
 * retrieve the data from the array
 * where the data of the array is located
 * @param size_array This parameter will allow us to limit our for loop
 *
 * @return This function doesnt return any important value, since its a printing function
 */
unsigned char print_array(unsigned char address_test, unsigned int size_array){
    unsigned char *value;
    printf("The values inside the array are");
    for (int i = 0; i < size_array; i++){
        value = &address_test[i];
        printf("%u\n", *value);
    }
    return 0;
}

#endif /* __STATS_H__ */