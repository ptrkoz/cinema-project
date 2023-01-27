#include "StartScreen.h"
#include "PickDateForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kino::StartScreen form1;
	Application::Run(% form1);

}
