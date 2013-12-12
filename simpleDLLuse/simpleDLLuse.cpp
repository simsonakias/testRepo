#include <iostream>
#include <windows.h>

using namespace std;

typedef int (*FuncDef)(int,const char*[]);

int main(int argc, char* argv[])
{

	FuncDef _Func;

	HINSTANCE hInstLibrary = LoadLibrary("gsm.dll");

	if (hInstLibrary)
	{
		cout << "DLL loaded! "<<endl;
		_Func = (FuncDef)GetProcAddress(hInstLibrary, "gsmUsage");

		const char *input[1];
		input[0]= "myProg";
		//input[1]= "-h";
		if (_Func)
		{
			cout << "calling gsm function" << _Func(1,input) << endl;
		}
		else
			cout << "No function "<<endl;

		FreeLibrary(hInstLibrary);
	}
	else
	{
		std::cout << "DLL Failed To Load!" << std::endl;
	}

	system("pause");
	return 0;
}
