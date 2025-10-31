#pragma once
#include "Rectangulo.h"
#include "Elipse.h"
#include "Triangulo.h"
#include "Cuadrado.h"

namespace FormsSemana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		Graphics^ graficos;
	private: System::Windows::Forms::Timer^ timer;
		   Rectangulo* rectangulo = nullptr;
		   Triangulo* triangulo = nullptr;
		   Elipse* elipse = nullptr;
		   Cuadrado* cuadrado = nullptr;

	public:
		MyForm(void)
		{
			InitializeComponent();

			graficos = panel->CreateGraphics();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Location = System::Drawing::Point(12, 12);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(939, 693);
			this->panel->TabIndex = 0;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 10;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(963, 717);
			this->Controls->Add(this->panel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::R) {
			rectangulo = new Rectangulo(panel->Width, panel->Height);
		}
		if (e->KeyCode == System::Windows::Forms::Keys::T) {
			triangulo = new Triangulo(panel->Width, panel->Height);
		}
		if (e->KeyCode == System::Windows::Forms::Keys::C) {
			cuadrado = new Cuadrado(panel->Width, panel->Height);
		}
		if (e->KeyCode == System::Windows::Forms::Keys::E) {
			elipse = new Elipse(panel->Width, panel->Height);
		}
	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		graficos->Clear(Color::White);
		if (rectangulo != nullptr) {
			rectangulo->dibujar(graficos);
			rectangulo->mover(panel->Width, panel->Height);
		}
		if (triangulo != nullptr) {
			triangulo->dibujar(graficos);
			triangulo->mover(panel->Width, panel->Height);
		}
		if (cuadrado != nullptr) {
			cuadrado->dibujar(graficos);
			cuadrado->mover(panel->Width, panel->Height);
		}
		if (elipse != nullptr) {
			elipse->dibujar(graficos);
			elipse->mover(panel->Width, panel->Height);
		}
	}
	};
}
