#pragma once

#include "Caballo.h"
#include "VectorCaballos.h"
#include "GestorPuntajes.h"
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
		int tiempo = 0;
		int limiteTiempo = 15;
		GestorPuntajes *puntajes;
	private: System::Windows::Forms::Timer^ timerPuntaje;
	private: System::Windows::Forms::TextBox^ txtPuntajes;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Button^ btnAgregarPuntaje;

		   int score = 0;

	public:
		MyForm(void)
		{
			InitializeComponent();
			secundarios = new VectorCaballos();
			graficos = canvas->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graficos, canvas->ClientRectangle);
			bmpCaballos = gcnew Bitmap("images/caballos.png");
			principal = new Caballo(20, 20, bmpCaballos->Width / 6, bmpCaballos->Height / 8, 1);

			puntajes = new GestorPuntajes("puntajes.txt");
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
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtPuntajes = (gcnew System::Windows::Forms::TextBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerPuntaje = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnAgregarPuntaje = (gcnew System::Windows::Forms::Button());
			this->canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Controls->Add(this->btnAgregarPuntaje);
			this->canvas->Controls->Add(this->txtNombre);
			this->canvas->Controls->Add(this->txtPuntajes);
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(667, 606);
			this->canvas->TabIndex = 0;
			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::canvas_Paint);
			this->canvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::canvas_MouseClick);
			// 
			// txtNombre
			// 
			this->txtNombre->Enabled = false;
			this->txtNombre->Location = System::Drawing::Point(217, 87);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 20);
			this->txtNombre->TabIndex = 1;
			this->txtNombre->Visible = false;
			// 
			// txtPuntajes
			// 
			this->txtPuntajes->Enabled = false;
			this->txtPuntajes->Location = System::Drawing::Point(165, 142);
			this->txtPuntajes->Multiline = true;
			this->txtPuntajes->Name = L"txtPuntajes";
			this->txtPuntajes->Size = System::Drawing::Size(314, 382);
			this->txtPuntajes->TabIndex = 0;
			this->txtPuntajes->Visible = false;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// timerPuntaje
			// 
			this->timerPuntaje->Enabled = true;
			this->timerPuntaje->Interval = 1000;
			this->timerPuntaje->Tick += gcnew System::EventHandler(this, &MyForm::timerPuntaje_Tick);
			// 
			// btnAgregarPuntaje
			// 
			this->btnAgregarPuntaje->Enabled = false;
			this->btnAgregarPuntaje->Location = System::Drawing::Point(347, 87);
			this->btnAgregarPuntaje->Name = L"btnAgregarPuntaje";
			this->btnAgregarPuntaje->Size = System::Drawing::Size(75, 23);
			this->btnAgregarPuntaje->TabIndex = 2;
			this->btnAgregarPuntaje->Text = L"agregar puntaje";
			this->btnAgregarPuntaje->UseVisualStyleBackColor = true;
			this->btnAgregarPuntaje->Visible = false;
			this->btnAgregarPuntaje->Click += gcnew System::EventHandler(this, &MyForm::btnAgregarPuntaje_Click);
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
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		bool Colision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
		{
			return x1 < x2 + w2 &&
				x1 + w1 > x2 &&
				y1 < y2 + h2 &&
				y1 + h1 > y2;
		}


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

		for (int i = 0; i < secundarios->getCantidad(); i++) {
			if (Colision(principal->getX(), principal->getY(), principal->getAncho(), principal->getAlto(),
				secundarios->getElemento(i)->getX(), secundarios->getElemento(i)->getY(), secundarios->getElemento(i)->getAncho(), secundarios->getElemento(i)->getAlto())) {
				secundarios->deleteElemento(i);
				score++;
				i--;
			}
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		principal->mover(e->KeyCode, graficos);
		principal->cambiarColor(e->KeyCode);
		if (e->KeyCode == Keys::Escape) {
			this->Close();
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

	private: System::Void timerPuntaje_Tick(System::Object^ sender, System::EventArgs^ e) {
		tiempo++;
		if (tiempo >= limiteTiempo) {
			timer->Enabled = false;

			txtNombre->Visible = true;
			txtNombre->Enabled = true;
			btnAgregarPuntaje->Visible = true;
			btnAgregarPuntaje->Enabled = true;

			timerPuntaje->Enabled = false;
		}

	}
	String^ toSystemString(const std::string& s) {
		return gcnew String(s.c_str());
	}

	private: System::Void btnAgregarPuntaje_Click(System::Object^ sender, System::EventArgs^ e) {
		puntajes->agregarPuntaje("nombre", score);
		txtPuntajes->Text = toSystemString(puntajes->puntajesHistoricos());
		txtPuntajes->Visible = true;
	}
};
}
