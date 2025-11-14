#pragma once

#include "Caballo.h"
#include "VectorCaballos.h"
#include "vector"

namespace Caballos {

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
		Caballo *principal;
		Bitmap^ bmpCaballos;
		Graphics^ graficos;
		BufferedGraphics^ buffer;
		VectorCaballos* secundarios;
		int maximoSecundarios = 100;

	public:
		MyForm(void)
		{
			InitializeComponent();
			secundarios = new VectorCaballos();
			graficos = canvas->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graficos, canvas->ClientRectangle);
			bmpCaballos = gcnew Bitmap("images/caballos.png");
			principal = new Caballo(20, 20, bmpCaballos->Width / 6, bmpCaballos->Height / 8, 1);
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
	private: System::Windows::Forms::Panel^ canvas;
	protected:
	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;

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
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(667, 606);
			this->canvas->TabIndex = 0;
			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::canvas_Paint);
			this->canvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::canvas_MouseClick);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 630);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		principal->dibujar(buffer->Graphics, bmpCaballos);
		for (int i = 0; i < secundarios->getCantidad(); i++) {
			secundarios->getElemento(i)->dibujar(buffer->Graphics, bmpCaballos);
		}
		buffer->Render(graficos);

		for (int i = 0; i < secundarios->getCantidad(); i++) {
			secundarios->getElemento(i)->mover(graficos);
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		principal->mover(e->KeyCode, graficos);
		principal->cambiarColor(e->KeyCode);
		if (e->KeyCode == Keys::Escape) {
			this->Close();
		}
		if (e->KeyData == Keys::E) {
			int cnt = secundarios->getCantidad();
			secundarios->deleteElemento(cnt - 1);
		}

	}
	private: System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void canvas_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (secundarios->getCantidad() < maximoSecundarios) {
			Caballo* nuevoCaballo = new Caballo(e->X, e->Y, bmpCaballos->Width / 6, bmpCaballos->Height / 8, 0.5);
			nuevoCaballo->cambiarColor();
			secundarios->addElemento(nuevoCaballo);
		}
	}
	};
}
