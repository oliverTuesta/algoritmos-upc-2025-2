#pragma once
#include "Rectangulo.h"
#include "Elipse.h"
#include "Triangulo.h"

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

		   int scoreRectangulo = 0;
		   int scoreTriangulo = 0;
		   int scoreElipse = 0;

		   int vueltas = 0;

		   int meta;

		   int puntos = 3;
		   bool llegoRectangulo = false;
		   bool llegoTriangulo = false;
		   bool llegoElipse = false;
	private: System::Windows::Forms::Label^ txtResultados;


	public:
		MyForm(void)
		{
			InitializeComponent();

			graficos = panel->CreateGraphics();
			meta = panel->Width - 10;
			rectangulo = new Rectangulo(panel->Height / 3 - 100);
			triangulo = new Triangulo(panel->Height / 3 * 2 - 100);
			elipse = new Elipse(panel->Height - 100);
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
			this->txtResultados = (gcnew System::Windows::Forms::Label());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Controls->Add(this->txtResultados);
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
			// txtResultados
			// 
			this->txtResultados->AutoSize = true;
			this->txtResultados->Location = System::Drawing::Point(247, 62);
			this->txtResultados->Name = L"txtResultados";
			this->txtResultados->Size = System::Drawing::Size(35, 13);
			this->txtResultados->TabIndex = 0;
			this->txtResultados->Text = L"label1";
			this->txtResultados->Visible = false;
			this->txtResultados->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
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
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (vueltas < 5) {
			graficos->Clear(Color::White);

			rectangulo->dibujar(graficos);
			rectangulo->mover(panel->Width, panel->Height);

			triangulo->dibujar(graficos);
			triangulo->mover(panel->Width, panel->Height);

			elipse->dibujar(graficos);
			elipse->mover(panel->Width, panel->Height);

			int cuantosLlegaron = rectangulo->estaEnMeta(meta) + triangulo->estaEnMeta(meta) + elipse->estaEnMeta(meta);
			puntos = 4 - cuantosLlegaron;

			if (llegoRectangulo == false && rectangulo->estaEnMeta(meta)) {
				scoreRectangulo += puntos;
				llegoRectangulo = true;
			}

			if (llegoTriangulo == false && triangulo->estaEnMeta(meta)) {
				scoreTriangulo += puntos;
				llegoTriangulo = true;
			}

			if (llegoElipse == false && elipse->estaEnMeta(meta)) {
				scoreElipse += puntos;
				llegoElipse = true;
			}

			if (rectangulo->estaEnMeta(meta) && triangulo->estaEnMeta(meta) && elipse->estaEnMeta(meta)) {
				vueltas++;
				rectangulo->iniciarDeNuevo();
				triangulo->iniciarDeNuevo();
				elipse->iniciarDeNuevo();
			}
		}
		else {
			graficos->Clear(Color::White);
			timer->Enabled = false;
			mostrarResultados();
		}

	}

	private: void mostrarResultados() {
		txtResultados->Text = "rectangulo: " + scoreRectangulo + "\n" + 
			"triangulo: " + scoreTriangulo + "\n" +
			"elipse: " + scoreElipse + "\n";
		txtResultados->Visible = true;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
