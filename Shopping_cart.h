#pragma once
#include "Classes.h"


namespace Кафе {

	using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Shopping_cart
	/// </summary>
	public ref class Shopping_cart : public System::Windows::Forms::Form
	{
		Dishes_List^ basket;
	public:
		Shopping_cart(Dishes_List^ obj)
		{
			InitializeComponent();

			basket = obj;
		}

		List <dish^>^ ReadListOfDishesfromFile(List <dish^>^ obj, String^ FileName)
		{//Читаем список блюд из файла
			StreamReader^ SR = gcnew StreamReader(FileName);
			String^ str = gcnew String("");
			while (str = SR->ReadLine()) {
				dish^ d = gcnew dish();

				d->Name = str->Split('$')[0];
				d->Cal = Convert::ToInt32(str->Split('$')[1]);
				d->Price = Convert::ToDouble(str->Split('$')[2]);
				obj->Add(d);
			}
			SR->Close();
			return obj;
		}

		void WriteListOfDishesfromFile(List <dish^>^ obj, String^ FileName)
		{//записываем список блюд в файл
			StreamWriter^ My_SW = gcnew StreamWriter(FileName);
			for (int i = 0; i < obj->Count; i++)
			{
				String^ Line = gcnew String("");
				Line += obj[i]->Name + "$";
				Line += obj[i]->Cal + "$";
				Line += obj[i]->Price + "$" + "\n";
				My_SW->Write(Line);
			}
			My_SW->Close();
		}

		void ViewListInDGV(List <dish^>^ obj, DataGridView^ dgv)
		{//Отображение списка блюд в таблице на форме
			if (obj->Count == 0)
			{
				dgv->Rows[0]->Cells[0]->Value = "";
				dgv->Rows[0]->Cells[1]->Value = "";
				dgv->Rows[0]->Cells[2]->Value = "";
			}
			else
			{
				dgv->RowCount = obj->Count;
				for (int i = 0; i < obj->Count; i++)
				{
					dgv->Rows[i]->Cells[0]->Value = obj[i]->Name;
					dgv->Rows[i]->Cells[1]->Value = obj[i]->Cal;
					dgv->Rows[i]->Cells[2]->Value = obj[i]->Price;
				}
			}
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Shopping_cart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameOfDish;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Сaloric_content;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PriceOfDish;
	private: System::Windows::Forms::Panel^ panel_dish;
	private: System::Windows::Forms::Button^ buttonRemove;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxPrice;
	private: System::Windows::Forms::TextBox^ textBoxCal;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Button^ button1;









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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NameOfDish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Сaloric_content = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PriceOfDish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_dish = (gcnew System::Windows::Forms::Panel());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel_dish->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NameOfDish,
					this->Сaloric_content, this->PriceOfDish
			});
			this->dataGridView1->Location = System::Drawing::Point(16, 16);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(626, 361);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Shopping_cart::dataGridView1_CellClick);
			// 
			// NameOfDish
			// 
			this->NameOfDish->HeaderText = L"Наименование";
			this->NameOfDish->MinimumWidth = 6;
			this->NameOfDish->Name = L"NameOfDish";
			this->NameOfDish->ReadOnly = true;
			this->NameOfDish->Width = 300;
			// 
			// Сaloric_content
			// 
			this->Сaloric_content->HeaderText = L"Калорийность";
			this->Сaloric_content->MinimumWidth = 6;
			this->Сaloric_content->Name = L"Сaloric_content";
			this->Сaloric_content->ReadOnly = true;
			this->Сaloric_content->Width = 140;
			// 
			// PriceOfDish
			// 
			this->PriceOfDish->HeaderText = L"Цена";
			this->PriceOfDish->MinimumWidth = 6;
			this->PriceOfDish->Name = L"PriceOfDish";
			this->PriceOfDish->ReadOnly = true;
			this->PriceOfDish->Width = 125;
			// 
			// panel_dish
			// 
			this->panel_dish->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_dish->Controls->Add(this->buttonRemove);
			this->panel_dish->Controls->Add(this->label3);
			this->panel_dish->Controls->Add(this->label2);
			this->panel_dish->Controls->Add(this->label1);
			this->panel_dish->Controls->Add(this->textBoxPrice);
			this->panel_dish->Controls->Add(this->textBoxCal);
			this->panel_dish->Controls->Add(this->textBoxName);
			this->panel_dish->Location = System::Drawing::Point(649, 16);
			this->panel_dish->Name = L"panel_dish";
			this->panel_dish->Size = System::Drawing::Size(389, 295);
			this->panel_dish->TabIndex = 5;
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(15, 245);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(357, 35);
			this->buttonRemove->TabIndex = 5;
			this->buttonRemove->Text = L"Удалить из корзины";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &Shopping_cart::buttonRemove_Click);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(11, 168);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(220, 22);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Цена";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(11, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Калорийность";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(11, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(220, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Наименование";
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Enabled = false;
			this->textBoxPrice->Location = System::Drawing::Point(15, 193);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(294, 30);
			this->textBoxPrice->TabIndex = 2;
			// 
			// textBoxCal
			// 
			this->textBoxCal->Enabled = false;
			this->textBoxCal->Location = System::Drawing::Point(15, 119);
			this->textBoxCal->Name = L"textBoxCal";
			this->textBoxCal->Size = System::Drawing::Size(294, 30);
			this->textBoxCal->TabIndex = 1;
			// 
			// textBoxName
			// 
			this->textBoxName->Enabled = false;
			this->textBoxName->Location = System::Drawing::Point(15, 40);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(357, 30);
			this->textBoxName->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(665, 342);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(357, 35);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Получить чек";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Shopping_cart::button1_Click);
			// 
			// Shopping_cart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 402);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel_dish);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Shopping_cart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Корзина";
			this->Load += gcnew System::EventHandler(this, &Shopping_cart::Shopping_cart_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel_dish->ResumeLayout(false);
			this->panel_dish->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void buttonRemove_Click(System::Object^ sender, System::EventArgs^ e) {
	//удалить из корзины
	try
	{
		int  i = dataGridView1->SelectedRows[0]->Index;
		basket->Food_list->RemoveAt(i);
		ViewListInDGV(basket->Food_list, dataGridView1);
	}
	catch (Exception ^e)
	{
		MessageBox::Show("Необходимо выделить строку", "Сообщение");
	}

	//если строка выделена
	//удаляем элемент в панели из списка объекта
	//обновляем данные в файле
	//перерисовать грид
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//получить чек
	//если объектов корзины != 0
	String^ cheque = gcnew String("");
	if (basket->Food_list->Count == 0)
	{
		MessageBox::Show("Чтобы получить чек, добавьте в корзину что-нибудь", "Сообщение");
		this->Close();
	}
	else
	{
		//заполняем чек по красоте
		cheque += "ИП 'Здоровое питание'" + "\n";
		cheque += "Кассир: Иванова Лариса Витальевна" + "\n\n\n";
		cheque += "\t\t\tКАССОВЫЙ ЧЕК" + "\n";
		for (int i = 0; i < basket->Food_list->Count; i++)
		{
			cheque += basket->Food_list[i]->Name + "\n";
			cheque += "\t\t1.00 * " + basket->Food_list[i]->Price + " " +"\n";
			cheque += "-------------------------------------------------------------\n";
		}
		cheque += "ИТОГО:\t\t= " + (basket->AlPrice/0.8) + " руб.\n";
		cheque += "Способ оплаты: при получении" + "\n";
		//записываем наш чек в файл
		StreamWriter^ My_SW = gcnew StreamWriter("Чек.txt");

		My_SW->Write(cheque);
		My_SW->Close();
		MessageBox::Show("Чек сформирован и сохранен в файл Чек.txt");
	}

	//тогда формируем чек и сохраняем файл
	//информируем пользователя, что чек сохранен
}
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	// 	//Если элемент выделен и все ок, тогда
	int i = e->RowIndex;

	textBoxName->Text = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
	textBoxCal->Text = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
	textBoxPrice->Text = dataGridView1->Rows[i]->Cells[2]->Value->ToString();
	//Высвечиваем данные выделенного элемента в панель

}
private: System::Void Shopping_cart_Load(System::Object^ sender, System::EventArgs^ e) {
	if (basket->Food_list->Count == 0)
	{
		MessageBox::Show("Чтобы просмотреть корзину, добавьте в неё что-нибудь", "Сообщение");
		this->Close();
	}
	else
	{
		//ReadListOfDishesfromFile(basket->Food_list, "Корзина.txt");
		ViewListInDGV(basket->Food_list, dataGridView1);
	}
}
};
}
