#include <iostream>
#include "../header/Stack.h"
#include "../header/StackTemp.h"
#include <string>


using namespace std;

int main()
{
	int n;
	cout << "1-Stack, 2 - StackTemp: ";
	cin >> n;
	if (n == 1)
	{
		int arr, pos, element;
		cout << "Stack length: ";
		cin >> arr;
		Stack s(arr);
		do
		{
			cout << "Add element? (0-no, 1-yes) ";
			cin >> pos;
			if (pos == 1)
			{
				cout << "Element " << s.GetSize() << " from " << arr << ": ";
				cin >> element;
				s.Push(element);
			}
			else if (pos == 0)
			{
				cout << "Element " << s.GetSize() << " from " << arr << ": " << 0 << endl;
				s.Push(0);
			}
			
		} while ((s.GetSize() - 1) < arr);
		cout << endl << "Stack: " << s << endl;
	}
	else if (n == 2)
	{
		int arr, pos, element;
		cout << "StackTemp length: ";
		cin >> arr;
		StackTemp<int> a(arr);
		do
		{
			cout << "Add element? (0-no, 1-yes) ";
			cin >> pos;
			if (pos == 1)
			{
				cout << "Element " << a.GetSize() << " from " << arr << ": ";
				cin >> element;
				a.Push(element);
			}
			else if (pos == 0)
			{
				cout << "Element " << a.GetSize() << " from " << arr << ": " << 0 << endl;
				a.Push(0);
			}
			
		} while ((a.GetSize() - 1) < arr);
		cout << endl << "StackTemp: " << a << endl;
	}

	system("pause");
}