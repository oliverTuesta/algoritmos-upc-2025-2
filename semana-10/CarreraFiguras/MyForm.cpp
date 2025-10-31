#include "MyForm.h"

#include <cstdlib>
#include <ctime>

using namespace FormsSemana10;



int main() {

	srand(time(nullptr));

	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());

	return 0;
}
