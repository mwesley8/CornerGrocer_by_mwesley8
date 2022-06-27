// CS 210 Programming Languages
// Created By Maurice Wesley
// June 15th, 2022

#include "main.h"
#include "Project3.h"

int main()
{
	system("color 1C");
	auto rp = make_shared<RunProgram>();  // smart pointer of object type Run Program
	rp->runProgram();                     // run the program
	return 0;
}
