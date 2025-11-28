#pragma once

#include "Juego.h"

namespace JuegoPuntajes {

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
		Bitmap^ bmpJugador;
		Bitmap^ bmpEnemigo;

		Juego* juego;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::TextBox^ txtHistorico;

	private: System::Windows::Forms::TextBox^ txtScore;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Button^ btnAgregarScore;

		   Graphics^ graficos;

	public:
		MyForm(void)
		{
			InitializeComponent();

			bmpJugador = gcnew Bitmap("images/jugador.png");
			bmpEnemigo = gcnew Bitmap("images/enemigo.png");

			graficos = canvas->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graficos, canvas->ClientRectangle);

			juego = new Juego(graficos, bmpJugador, bmpEnemigo);
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
	private: System::Windows::Forms::Timer^ timer1;
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
			this->btnAgregarScore = (gcnew System::Windows::Forms::Button());
			this->txtHistorico = (gcnew System::Windows::Forms::TextBox());
			this->txtScore = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Controls->Add(this->btnAgregarScore);
			this->canvas->Controls->Add(this->txtHistorico);
			this->canvas->Controls->Add(this->txtScore);
			this->canvas->Controls->Add(this->txtNombre);
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(662, 557);
			this->canvas->TabIndex = 0;
			// 
			// btnAgregarScore
			// 
			this->btnAgregarScore->Enabled = false;
			this->btnAgregarScore->Location = System::Drawing::Point(187, 85);
			this->btnAgregarScore->Name = L"btnAgregarScore";
			this->btnAgregarScore->Size = System::Drawing::Size(224, 23);
			this->btnAgregarScore->TabIndex = 3;
			this->btnAgregarScore->Text = L"Agregar";
			this->btnAgregarScore->UseVisualStyleBackColor = true;
			this->btnAgregarScore->Visible = false;
			this->btnAgregarScore->Click += gcnew System::EventHandler(this, &MyForm::btnAgregarScore_Click);
			// 
			// txtHistorico
			// 
			this->txtHistorico->Enabled = false;
			this->txtHistorico->Location = System::Drawing::Point(187, 133);
			this->txtHistorico->Multiline = true;
			this->txtHistorico->Name = L"txtHistorico";
			this->txtHistorico->Size = System::Drawing::Size(224, 295);
			this->txtHistorico->TabIndex = 2;
			this->txtHistorico->Visible = false;
			// 
			// txtScore
			// 
			this->txtScore->Enabled = false;
			this->txtScore->Location = System::Drawing::Point(311, 59);
			this->txtScore->Name = L"txtScore";
			this->txtScore->Size = System::Drawing::Size(100, 20);
			this->txtScore->TabIndex = 1;
			this->txtScore->Visible = false;
			// 
			// txtNombre
			// 
			this->txtNombre->Enabled = false;
			this->txtNombre->Location = System::Drawing::Point(187, 59);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 20);
			this->txtNombre->TabIndex = 0;
			this->txtNombre->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 581);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		juego->mostrarTodo(buffer->Graphics, bmpJugador, bmpEnemigo);
		buffer->Render(graficos);

		juego->moverEnemigos(graficos);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Escape) {
			timer1->Enabled = false;
			juego->terminarJuego();

			txtNombre->Enabled = true;
			txtScore->Enabled = true;
			btnAgregarScore->Enabled = true;

			txtNombre->Visible = true;
			btnAgregarScore->Visible = true;
			txtScore->Visible = true;
		}
		else {
			juego->moverJugador(graficos, e->KeyCode);
		}
	}
	private: System::Void btnAgregarScore_Click(System::Object^ sender, System::EventArgs^ e) {

		juego->guardarScore(txtNombre->Text, txtScore->Text);
		txtHistorico->Visible = true;
		btnAgregarScore->Enabled = false;
		txtHistorico->Text = juego->traerScores();

	}
};
}
