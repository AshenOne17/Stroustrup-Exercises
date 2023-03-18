/*
 * 1. Write a program that consists of a while-loop that (each time around the loop) reads in two ints and then prints them.
 * Exit the prohram when a terminating '|' is entered.
 *
 * 2. Change the program to write out "the smaller value is:" followed by the smaller of the numbers and "the larger value is:" followed by the larger value.
 *
 * 3. Augment the program so that it writes the line "the numbers are equal " (only) if they are equal.
 *
 * 4. Change the program so that it uses doubles instead of ints.
 *
 * 5. Change the program so that it writes out "the numbers are almost equal" after writing out which is the larger and the smaller
 * if the two numbers differ by less than 1.0/100.
 */

#include <iostream>

int main()
{
    // #4.
    double first_value = 0.0, second_value = 0.0;

    // #1.
    while (std::cin >> first_value >> second_value)
    {
        std::cout << std::endl;

        // #2.
        if (first_value > second_value)
        {
	        std::cout << "The smaller value is: " << second_value << "\nThe bigger value is: " << first_value << "\n\n";

            // #5.
        	if (first_value - second_value < 1.0/100)
			{
				std::cout << "The values are almost equal.\n\n";
			}
        }
        // #3.
        else if (first_value == second_value)
        {
	        std::cout << "Value " << first_value << " is equal to the value " << second_value << "\n\n";
        }
        else if (first_value < second_value)
        {
	        std::cout << "The smaller value is: " << first_value << "\nThe bigger value is: " << second_value << "\n\n";

            // #5.
            if (second_value - first_value < 1.0/100)
			{
				std::cout << "The values are almost equal.\n\n";
			}
        }
        
    }

    return 0;
}