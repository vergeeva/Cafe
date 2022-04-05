#include "KeyMenu.h"


using namespace Кафе; 	
[STAThreadAttribute]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew KeyMenu());
	return 0;
}
