//write a function that takes a function as a parameter.
//The function it receives should take two arguments(min, max).
//Calculate a random number between those two numbers and return it.
//If the function fails return or assert on the call. 
//if the function that takes the min, max function fails give feedback to the user

#include <iostream>
#include <random>
#include <assert.h>
typedef bool(*Test)(const int&, const int&);
void StartTest(Test testcase)
{
	testcase(1, 5);//pass
	testcase(0, 5);//fail
	testcase(5, 1);//fail
	testcase(1, 2);//pass
}
int Assertion(const int &min, const int &max)//ask matthew why they have to be constants
{
	assert(min > 0);
	assert(min < max);
	return rand() % (max + 1 - min) + min;
}
int main()
{
	StartTest((Test)Assertion);
	system("pause");
	return 0;
}