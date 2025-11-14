#include "MyForm.h"

#include <cstdlib>
#include <ctime> 

using namespace Caballos;

int main() {
	srand(time(nullptr));
	Application::Run(gcnew MyForm());
	return 0;
}