#pragma once
#include "StandartMenu.h"
#include "LunchMenu.h"
#include "Shopping_cart.h"

namespace Кафе {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для KeyMenu
	/// </summary>
	public ref class KeyMenu : public System::Windows::Forms::Form
	{
	public:
		Dishes_List^ basket;
		KeyMenu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			basket = gcnew Dishes_List();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~KeyMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(51, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(397, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Общее стандартное меню";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &KeyMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(51, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(397, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ассортимент бизнес-ланчей";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &KeyMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(51, 149);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(397, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Просмотр корзины";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &KeyMenu::button3_Click);
			// 
			// KeyMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 233);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"KeyMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Меню";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ frm = gcnew StandartMenu(basket);
		frm->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ frm = gcnew LunchMenu(basket);
		frm->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ frm = gcnew Shopping_cart(basket);
		frm->ShowDialog();
	}
};
}
