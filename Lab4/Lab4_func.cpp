#include <iostream>
using namespace std;

/** sumOfThree
* @brief returns the sum of x, y, and z
*
* @param x : (int)
* @param y : (int)
* @param z : (int)
* @return int
*/

int sumOfThree(int x, int y, int z)
{
    
}

/** myPrint
 * @brief Calls select() to print out the output with the correct prompt
 * 
 * @tparam T : (int, double, or string) output of sum, diviion, or isGreaterThan
 * @param func_type : (string)
 * @param output
*/

template <typename T>
void myPrint (string func_type, T output){
    cout << select(func_type) << output << endl;
}

int main()
{
    // initialize 3 int paramters
    int x1 = 2;
    int x2 = 3;
    int x3 = 5;

    // call sumOfThree
    int sum_out = sumOfThree(x1, x2, x3);
    // call myPrint
    myPrint("sum", sum_out)

    // initialize 2 double parameters
    double dividend = 12345.1;
    double divisor = 2345.6;

    // call division
    double dov_out = division( dividend, divisor);
    myPrint("division", div_out);

    // compare div_out and sum_out
    bool is_greater_out = isGreaterThan (div_out, sum_out);
    myPrint("comparison", is_greater_than);
    return 0;
}