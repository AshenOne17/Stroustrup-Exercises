/*
 * 6. Now change the body of the loop so that it reads just one 'double' each time around.
 * Define two variables to keep track of which is the smallest and which is the largest value you have seen so far.
 * Each time through the loop write out the value entered. If it's the smallest so far, write the smallest so far after the number.
 * If it's the largest so far, write 'the largest so far' after the number.
 *
 * 7. Add a unit to each 'double' entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m.
 * Accept the four units: cm, m, in, ft. Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12 in.
 * Read the unit indicator into a string. You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a space).
 *
 * 8. Reject values without units or with "illegal" representations of units, such as y, yard, meter, km, and gallons.
 *
 * 9. Keep track of the sum of values entered (as well as the smallest and the largest) and the number of values entered.
 * When the loop ends, print the smallest, the largest, the number of values, and the sum of values.
 * Note that to keep the sum, you gave to decide on a unit to use for that sum; use meters.
 *
 * 10. Keep all the values entered (converted into meters) in a vector. At the end, write out those values.
 *
 * 11. Before writing out the values from the vector, sort them (that will make them come out in increasing order).
 */

#include <vector>
#include <iostream>
#include <algorithm> // For std::sort()

int main()
{
    // #6.
    long double sum = 0, smallest = 0.0, biggest = 0.0, input = 0.0;

	long long number_of_values = 0; 

    bool first_input = true;

    // #10.
    std::vector<long double> numbers;

    // #7.
    std::string unit, smallest_unit, biggest_unit;

    std::cout << "The program to keep track of smallest and biggest value, number of values, and its sum. "
				 "To stop counting and produce the result, terminate the program with CTRL+Z/symbol '|'.\n\n";
     
    std::cout << "Enter first value to initialize: ";

    while(std::cin >> input)
    {
        if (first_input)
        {
	        smallest = biggest = input;
            first_input = false;
            std::cout << "\nThe value " << input << " m is the largest so far.\n\n";
        }
        else
        {
            std::cout << "Enter the unit of measure (cm, m, ft, in): ";

            // #8.
            while (!(std::cin >> unit) || (unit != "cm" && unit != "m" && unit != "ft" && unit != "in"))
            {
	            std::cout << "Illegal unit or wrong value! Try again.\n\n";
                std::cout << "Enter the unit of measure (cm, m, ft, in): ";
                // Clear the fail flag
                std::cin.clear();
                // Discard the invalid input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            }

            std::cout << "\nInput value: " << input << ' ' << unit << "\n\n";

            if (unit != "m")
            {
                if (unit == "cm")
                {
	                input *= 0.01;
                }
                else if (unit == "ft")
                {
	                input *= 0.3048;
                }
                else if (unit == "in")
                {
	                input *= 0.0254;
                }
                else
                {
	                std::cout << "\nError. Program terminated.\n";
                	exit(1);
                }
            }

            // #9.
            number_of_values++;

            sum += input;

            numbers.push_back(input);

	        if (input > biggest)
	        {
				biggest = input;
                biggest_unit = unit;
				std::cout << "The value " << input << " m is the largest so far.\n\n";
	        }
        	else if (input < smallest)
            {
	            smallest = input;
                smallest_unit = unit;
        		std::cout << "The value " << input << " m is the smallest so far.\n\n";
            }
            else
            {
	            std::cout << "The value " << input << " m is neither smallest nor largest.\n\n";
            }
        }
       
        std::cout << "Enter the value: ";

        std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // #11.
    std::sort(numbers.begin(), numbers.end());

    std::cout << "\nThe smallest value is: " << smallest << ' ' << smallest_unit << "\n\n";

    std::cout << "The biggest value is: " << biggest << ' ' << biggest_unit << "\n\n";

    std::cout << "The number of values is: " << number_of_values << "\n\n";

    std::cout << "The sum of values (in m) is: " << sum << "\n\n";

    std::cout << "Output of numbers of a vector: \n";

    for (const auto& num: numbers)
    {
	    std::cout << num << " m\n";
    }

	return 0;
}