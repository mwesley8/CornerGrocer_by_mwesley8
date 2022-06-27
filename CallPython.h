#ifndef CALLPYTHON.H
#include "Windows.h"
#include "Python.h"
#include <string>
#include <iostream>


using namespace std;
// Class declaration to initialize Python
class CallPython
{
public:	
	// Member function declarations
	void callPython(string PythonModuleName, string PythonFunctionName);
	int callIntFuncString(string proc, string param);
};

#endif