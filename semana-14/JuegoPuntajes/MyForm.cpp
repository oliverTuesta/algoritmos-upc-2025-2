#include "MyForm.h"

#include <cstdlib> // For rand() and srand()
#include <ctime> 

using namespace JuegoPuntajes;

int main() {
	srand(time(nullptr));

	Application::Run(gcnew MyForm);
}