#include "CallPython.h"
#include <string>
#include <iostream>
#pragma warning(disable : 4996).


void CallPython::callPython(string PythonModuleName, string PythonFunctionName)
{
	char* funcname = new char[PythonFunctionName.length() + 1];
	strcpy_s(funcname, PythonFunctionName.length() + 1, PythonFunctionName.c_str());

	char* modname = new char[PythonModuleName.length() + 1];
	strcpy_s(modname, PythonModuleName.length() + 1, PythonModuleName.c_str());

	Py_Initialize();

	TCHAR cwd[2048];
	GetCurrentDirectory(sizeof(cwd), cwd);

	PyObject* my_module = PyImport_ImportModule(modname);

	PyErr_Print();

	// Get the address of the particular Python function in the imported module
	PyObject* my_function = PyObject_GetAttrString(my_module, funcname);

	PyErr_Print();

	// Call a callable Python object callable, with arguments given by the tuple args. 
	// If no arguments are needed, then args can be NULL.
	PyObject* my_result = PyObject_CallObject(my_function, NULL);

	PyErr_Print();

	// Undo all initializations made by Py_Initialize() and subsequent use of Python/C API functions, 
	// and destroy all sub-interpreters (see Py_NewInterpreter() below) that were created and not yet 
	// destroyed since the last call to Py_Initialize(). Ideally, this frees all memory allocated by the Python interpreter.
	Py_Finalize();

	delete[] funcname;
	delete[] modname;
}
int CallPython::callIntFuncString(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}