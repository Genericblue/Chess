/*
	Names: Mark Eads and Wilson Yip
	Program Name: Chess (Programming Assignment 8)
	Due Date: April 29th 2015
*/

#include "stdafx.h"
#include "Form1.h"
#include "Board.h"

using namespace ChessApplication;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	//Application::Run(gcnew Rules());
	Application::Run(gcnew Form1());
	
	return 0;
}
