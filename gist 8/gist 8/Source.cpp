//gist: write a function that calculates the length of a character array using only pointers.
//pass that function as an argument to another function to evaluate it's correctness.
//ex : char c[] = { "hello" };

#include <iostream>
using namespace std;
typedef char(*Callback)(char&);
char  c[] = "hello";

void StartTest(Callback a)
{
	
	//a("");
}
int CountLetters(char d[]);
{
	char d[] = "a";
	cout << sizeof d;
	return sizeof d;
}
int main() {
	

	//CountLetters();



	system("pause");
	return 0;
}