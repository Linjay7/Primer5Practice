#include "practices.h"
#include <iostream>
using namespace std;

namespace practices
{
	void function1_3()
	{
		cout << "Hello, World" << endl;
	}

	void function1_4()
	{
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		cout << "The sum is" << v1 * v2 << endl;
	}

	void function1_9()
	{
		int sum = 0, i = 50;
		while (i <= 100)
		{
			sum += i++;
		} 
	}

	void function1_10()
	{
		int i = 10;
		while (i > 1)
		{
			cout << --i << " ";
		}
		cout << endl;
	}

	void function1_11()
	{
		cout << "Please Enter 2 numbers :" << endl;
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;

		int min = fmin(v1, v2);
		int max = fmax(v1, v2);

		cout << "Numbers between " << min << " and " << max << " is:" << endl;

		while (min <= max)
		{
			cout << min++ << " ";
		}
		cout << endl;
	}

}