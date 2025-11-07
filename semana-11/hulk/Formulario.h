#pragma once

#include "Character.h"

namespace Semana11Hulk {

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
		Graphics^ graficos;
		Character* hulk;
		Character* hulk2;
		BufferedGraphics^ buffer;

	private: System::Windows::Forms::Timer^ timer1;
		   Bitmap^ bmpHulk;

	public:
		Formulario(void)
		{
			InitializeComponent();
			
			graficos = canvas->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graficos, canvas->ClientRectangle);
			bmpHulk = gcnew Bitmap("img/hulk.png");
			hulk = new Character(1,1,bmpHulk->Width / 4, bmpHulk->Height / 4, 1);
			hulk2 = new Character(100,100,bmpHulk->Width / 4, bmpHulk->Height / 4, 1);
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
	private: System::Windows::Forms::Panel^ canvas;
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
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(913, 787);
			this->canvas->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario::timer1_Tick);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(937, 811);
			this->Controls->Add(this->canvas);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::Formulario_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		hulk->dibujar(buffer->Graphics, bmpHulk);
		hulk2->dibujar(buffer->Graphics, bmpHulk);


		buffer->Render(graficos);
	}
	private: System::Void Formulario_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		hulk->mover(e->KeyCode, graficos);
	}
	};
}
