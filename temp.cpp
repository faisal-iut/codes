#include <iostream>
using namespace std;

int main()
{
	char sentence[5][3] ;

	for ( int i = 0; i < 2; i++ )
	{

		cin>> sentence[i];
	}

	for ( int i = 0; i < 2; i++ )
	{
		cout << sentence[i] << "\n";
	}
}
