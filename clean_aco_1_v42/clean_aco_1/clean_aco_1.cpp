// clean_aco_1.cpp : main project file.

#include "stdafx.h"
#include "test.h"
#include "Form1.h"

using namespace std;
using namespace clean_aco_1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	cout << ">>> Start program!\n";
	
	tt.aloc_map();
	tt.gen_random_map();
	tt.afis_map_1();
	
	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
