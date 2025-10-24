#pragma once

#include "Figura.h"
#include "Rectangulo.h"
#include "Elipse.h"
#include "Linea.h"
#include "VectorFigura.h"
#include <string>

namespace Semana9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Formulario
	/// </summary>
	public ref class Formulario : public System::Windows::Forms::Form
	{
	private:
		Graphics^ graphics;

		VectorFigura* vecRect;
		VectorFigura* vecElip;
		VectorFigura* vecLin;

	public:
		Formulario(void)
		{
			InitializeComponent();
			graphics = canvas->CreateGraphics();
			vecRect = new VectorFigura();
			vecElip = new VectorFigura();
			vecLin = new VectorFigura();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Formulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnDibujar;
	protected:
	private: System::Windows::Forms::ComboBox^ cbxFigura;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtPosX;
	private: System::Windows::Forms::TextBox^ txtPosY;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtLado2;
	private: System::Windows::Forms::TextBox^ txtLado1;
	private: System::Windows::Forms::Panel^ canvas;
	private: System::Windows::Forms::Label^ labelRadio;
	private: System::Windows::Forms::TextBox^ txtRadio1;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtArea;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtPosY2;

	private: System::Windows::Forms::TextBox^ txtPosX2;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnDibujar = (gcnew System::Windows::Forms::Button());
			this->cbxFigura = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPosX = (gcnew System::Windows::Forms::TextBox());
			this->txtPosY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtLado2 = (gcnew System::Windows::Forms::TextBox());
			this->txtLado1 = (gcnew System::Windows::Forms::TextBox());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->labelRadio = (gcnew System::Windows::Forms::Label());
			this->txtRadio1 = (gcnew System::Windows::Forms::TextBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtArea = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtPosY2 = (gcnew System::Windows::Forms::TextBox());
			this->txtPosX2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnDibujar
			// 
			this->btnDibujar->Location = System::Drawing::Point(499, 22);
			this->btnDibujar->Name = L"btnDibujar";
			this->btnDibujar->Size = System::Drawing::Size(128, 36);
			this->btnDibujar->TabIndex = 0;
			this->btnDibujar->Text = L"dibujar";
			this->btnDibujar->UseVisualStyleBackColor = true;
			this->btnDibujar->Click += gcnew System::EventHandler(this, &Formulario::btnDibujar_Click);
			// 
			// cbxFigura
			// 
			this->cbxFigura->FormattingEnabled = true;
			this->cbxFigura->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Círculo", L"Rectángulo", L"Elipse", L"Cuadrado", L"Línea" });
			this->cbxFigura->Location = System::Drawing::Point(115, 37);
			this->cbxFigura->Name = L"cbxFigura";
			this->cbxFigura->Size = System::Drawing::Size(121, 21);
			this->cbxFigura->TabIndex = 1;
			this->cbxFigura->SelectedIndexChanged += gcnew System::EventHandler(this, &Formulario::cbxFigura_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Elegir figura";
			// 
			// txtPosX
			// 
			this->txtPosX->Location = System::Drawing::Point(115, 97);
			this->txtPosX->Name = L"txtPosX";
			this->txtPosX->Size = System::Drawing::Size(100, 20);
			this->txtPosX->TabIndex = 3;
			// 
			// txtPosY
			// 
			this->txtPosY->Location = System::Drawing::Point(115, 141);
			this->txtPosY->Name = L"txtPosY";
			this->txtPosY->Size = System::Drawing::Size(100, 20);
			this->txtPosY->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Posicion X";
			this->label2->Click += gcnew System::EventHandler(this, &Formulario::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(40, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Posicion Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(481, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Lado 2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(481, 100);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Lado 1";
			// 
			// txtLado2
			// 
			this->txtLado2->Location = System::Drawing::Point(527, 141);
			this->txtLado2->Name = L"txtLado2";
			this->txtLado2->Size = System::Drawing::Size(100, 20);
			this->txtLado2->TabIndex = 8;
			// 
			// txtLado1
			// 
			this->txtLado1->Location = System::Drawing::Point(527, 97);
			this->txtLado1->Name = L"txtLado1";
			this->txtLado1->Size = System::Drawing::Size(100, 20);
			this->txtLado1->TabIndex = 7;
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(43, 269);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(584, 303);
			this->canvas->TabIndex = 11;
			// 
			// labelRadio
			// 
			this->labelRadio->AutoSize = true;
			this->labelRadio->Location = System::Drawing::Point(286, 96);
			this->labelRadio->Name = L"labelRadio";
			this->labelRadio->Size = System::Drawing::Size(35, 13);
			this->labelRadio->TabIndex = 13;
			this->labelRadio->Text = L"Radio";
			// 
			// txtRadio1
			// 
			this->txtRadio1->Location = System::Drawing::Point(332, 93);
			this->txtRadio1->Name = L"txtRadio1";
			this->txtRadio1->Size = System::Drawing::Size(100, 20);
			this->txtRadio1->TabIndex = 12;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->Location = System::Drawing::Point(356, 22);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(97, 36);
			this->btnLimpiar->TabIndex = 14;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = true;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &Formulario::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(304, 226);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Area: ";
			// 
			// txtArea
			// 
			this->txtArea->Enabled = false;
			this->txtArea->Location = System::Drawing::Point(345, 223);
			this->txtArea->Name = L"txtArea";
			this->txtArea->Size = System::Drawing::Size(100, 20);
			this->txtArea->TabIndex = 16;
			this->txtArea->Text = L"El area va aqui";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(40, 234);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Posicion Y2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(40, 190);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Posicion X2";
			this->label8->Click += gcnew System::EventHandler(this, &Formulario::label8_Click);
			// 
			// txtPosY2
			// 
			this->txtPosY2->Location = System::Drawing::Point(115, 231);
			this->txtPosY2->Name = L"txtPosY2";
			this->txtPosY2->Size = System::Drawing::Size(100, 20);
			this->txtPosY2->TabIndex = 18;
			// 
			// txtPosX2
			// 
			this->txtPosX2->Location = System::Drawing::Point(115, 187);
			this->txtPosX2->Name = L"txtPosX2";
			this->txtPosX2->Size = System::Drawing::Size(100, 20);
			this->txtPosX2->TabIndex = 17;
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(663, 584);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->txtPosY2);
			this->Controls->Add(this->txtPosX2);
			this->Controls->Add(this->txtArea);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->btnLimpiar);
			this->Controls->Add(this->labelRadio);
			this->Controls->Add(this->txtRadio1);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtLado2);
			this->Controls->Add(this->txtLado1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtPosY);
			this->Controls->Add(this->txtPosX);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbxFigura);
			this->Controls->Add(this->btnDibujar);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!validateInputs()) return;

		int posX = Convert::ToInt32(txtPosX->Text);
		int posY = Convert::ToInt32(txtPosY->Text);

		Figura* figura;
		if (cbxFigura->Text == "Rectángulo") {
			int lado1 = Convert::ToInt32(txtLado1->Text);
			int lado2 = Convert::ToInt32(txtLado2->Text);
			figura = new Rectangulo(posX, posY, lado1, lado2);
			vecRect->addElemento(figura);
		}
		else if (cbxFigura->Text == "Cuadrado") {
			int lado1 = Convert::ToInt32(txtLado1->Text);
			figura = new Rectangulo(posX, posY, lado1, lado1);
			vecRect->addElemento(figura);
		} else if (cbxFigura->Text == "Elipse") {
			int lado1 = Convert::ToInt32(txtLado1->Text);
			int lado2 = Convert::ToInt32(txtLado2->Text);
			figura = new Elipse(posX, posY, lado1, lado2);
			vecElip->addElemento(figura);

		} else if (cbxFigura->Text == "Círculo") {
			int radio = Convert::ToInt32(txtRadio1->Text);
			figura = new Elipse(posX, posY, radio*2, radio*2);
			vecElip->addElemento(figura);

		}
		else if (cbxFigura->Text == "Línea") {
			int posX2 = Convert::ToInt32(txtPosX2->Text);
			int posY2 = Convert::ToInt32(txtPosY2->Text);
			figura = new Linea(posX, posY, posX2, posY2);
			vecLin->addElemento(figura);
		}

		figura->dibujar(graphics);
		txtArea->Text = Convert::ToString(figura->getArea());
	}

	private: bool validateInputs() {
		if (String::IsNullOrEmpty(txtPosX->Text) || String::IsNullOrEmpty(txtPosY->Text)) {
			return false;
		}

		if (String::IsNullOrEmpty(cbxFigura->Text)) {
			return false;
		}

		if (cbxFigura->Text == "Rectángulo") {
			return (!String::IsNullOrEmpty(txtLado1->Text) && !String::IsNullOrEmpty(txtLado2->Text));
		} else if (cbxFigura->Text == "Cuadrado") {
			return (!String::IsNullOrEmpty(txtLado1->Text));
		} else if (cbxFigura->Text == "Elipse") {
			return (!String::IsNullOrEmpty(txtLado1->Text) && !String::IsNullOrEmpty(txtLado2->Text));
		} else if (cbxFigura->Text == "Círculo") {
			return (!String::IsNullOrEmpty(txtRadio1->Text));
		} else if (cbxFigura->Text == "Línea") {
			return (!String::IsNullOrEmpty(txtPosX2->Text) && !String::IsNullOrEmpty(txtPosY2->Text));
		}
	}
	private: System::Void cbxFigura_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// { L"Círculo", L"Rectángulo", L"Elipse", L"Cuadrado" }
		if (cbxFigura->Text == "Rectángulo") {
			txtRadio1->Enabled = false;
			txtLado1->Enabled = true;
			txtLado2->Enabled = true;
			txtPosX2->Enabled = false;
			txtPosY2->Enabled = false;
		}
		else if (cbxFigura->Text == "Cuadrado") {
			txtRadio1->Enabled = false;
			txtLado1->Enabled = true;
			txtLado2->Enabled = false;
			txtPosY2->Enabled = false;
			txtPosX2->Enabled = false;
		}
		else if (cbxFigura->Text == "Elipse") {
			txtRadio1->Enabled = false;
			txtLado1->Enabled = true;
			txtLado2->Enabled = true;
			txtPosX2->Enabled = false;
			txtPosY2->Enabled = false;
		}
		else if (cbxFigura->Text == "Círculo") {
			txtRadio1->Enabled = true;
			txtLado1->Enabled = false;
			txtLado2->Enabled = false;
			txtPosY2->Enabled = false;
			txtPosX2->Enabled = false;
		} else if (cbxFigura->Text == "Línea") {
			txtRadio1->Enabled = false;
			txtLado1->Enabled = false;
			txtLado2->Enabled = false;
			txtPosY2->Enabled = true;
			txtPosX2->Enabled = true;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		graphics->Clear(Color::White);
	}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
