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
	/// Сводка для LunchMenu
	/// </summary>
	public ref class LunchMenu : public System::Windows::Forms::Form
	{
		Dishes_List^ basket;
		Dishes_List^ list_of_dishes;
		Lunches^ lunches;
	public:
		LunchMenu(Dishes_List^ obj)
		{
			InitializeComponent();

			basket = obj; //для общей корзины
			lunches = gcnew Lunches(); //ланчи
			list_of_dishes = gcnew Dishes_List(); //Для сортировки
		}

		List <Dishes_List^>^ ReadLunchesfromFile(List <Dishes_List^>^ obj, String^ FileName)
		{//Читаем ланчи из файла
			Dishes_List^ dl = gcnew Dishes_List();
			dish^ d = gcnew dish();

			StreamReader^ SR = gcnew StreamReader(FileName);
			String^ str = gcnew String("");
			dl->Name = SR->ReadLine();
			while (str = SR->ReadLine()) 
			{
				if (str == "")
				{
					obj->Add(dl);
					dl = gcnew Dishes_List();
					dl->Name = SR->ReadLine();
				}
				else
				{
					dish^ d = gcnew dish();
					d->Name = str->Split('$')[0];
					d->Cal = Convert::ToInt32(str->Split('$')[1]);
					d->Price = Convert::ToDouble(str->Split('$')[2]);
					dl->add_dish(d);
				}
			}
			obj->Add(dl);
			SR->Close();
			return obj;
		}

		void WriteLunchesInFile(Lunches^ obj, String^ FileName)
		{//записываем список ланчей в файл
			StreamWriter^ My_SW = gcnew StreamWriter(FileName);
			int Count = obj->Lunch_list->Count;
			for (int i = 0; i < Count; i++)
			{
				String^ Line = gcnew String("");
				int Len = obj->Lunch_list[i]->Food_list->Count;
				Line = obj->Lunch_list[i]->Name + "\n";
				My_SW->Write(Line);
				for (size_t i = 0; i < Len; i++)
				{
					String^ Line_dish = gcnew String("");
					Line_dish += obj->Lunch_list[i]->Food_list[i]->Name + "$" + "\n";
					Line_dish += obj->Lunch_list[i]->Food_list[i]->Cal + "$" + "\n";
					Line_dish += obj->Lunch_list[i]->Food_list[i]->Price + "$" + "\n";

					My_SW->Write(Line_dish);
				}

				if (Count > 1 && i != Count - 1) My_SW->Write("\n");

			}
			My_SW->Close();
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

		void ViewListInDGV(List <Dishes_List^>^ obj, DataGridView^ dgv)
		{//Отображение ланчей в таблице на форме
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
					dgv->Rows[i]->Cells[1]->Value = obj[i]->AllCal;
					dgv->Rows[i]->Cells[2]->Value = obj[i]->AlPrice;
				}
			}
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LunchMenu()
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







	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonOk;

	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::DataGridView^ dataGridView2;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxCal;
	private: System::Windows::Forms::TextBox^ textBoxPrice;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonAdd;

	private: System::Windows::Forms::Panel^ panel_dish;





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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonOk = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->panel_dish = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(620, 305);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &LunchMenu::dataGridView1_CellClick);
			// 
			// NameOfDish
			// 
			this->NameOfDish->HeaderText = L"Наименование ланча";
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
			this->PriceOfDish->HeaderText = L"Цена ланча";
			this->PriceOfDish->MinimumWidth = 6;
			this->PriceOfDish->Name = L"PriceOfDish";
			this->PriceOfDish->ReadOnly = true;
			this->PriceOfDish->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->buttonOk);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Location = System::Drawing::Point(638, 323);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(389, 285);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Установить фильтры по ланчам";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(221, 179);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(119, 30);
			this->textBox4->TabIndex = 11;
			this->textBox4->Text = L"10000";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LunchMenu::textBoxes_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(57, 179);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(119, 30);
			this->textBox3->TabIndex = 14;
			this->textBox3->Text = L"0";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LunchMenu::textBoxes_KeyPress);
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(182, 182);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 22);
			this->label8->TabIndex = 13;
			this->label8->Text = L"До";
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(15, 182);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(36, 22);
			this->label9->TabIndex = 12;
			this->label9->Text = L"От";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(221, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(119, 30);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"10000";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LunchMenu::textBoxes_KeyPress);
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(182, 115);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 22);
			this->label7->TabIndex = 9;
			this->label7->Text = L"До";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(15, 115);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 22);
			this->label6->TabIndex = 8;
			this->label6->Text = L"От";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(15, 154);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(274, 22);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Цена";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(15, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(274, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Калорийность ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 112);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(119, 30);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"0";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LunchMenu::textBoxes_KeyPress);
			// 
			// buttonOk
			// 
			this->buttonOk->Location = System::Drawing::Point(16, 232);
			this->buttonOk->Name = L"buttonOk";
			this->buttonOk->Size = System::Drawing::Size(357, 35);
			this->buttonOk->TabIndex = 6;
			this->buttonOk->Text = L"Применить";
			this->buttonOk->UseVisualStyleBackColor = true;
			this->buttonOk->Click += gcnew System::EventHandler(this, &LunchMenu::buttonOk_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"По возрастанию калорийности", L"По возрастанию цены",
					L"Без сортировки"
			});
			this->comboBox1->Location = System::Drawing::Point(16, 43);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(357, 30);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->Text = L"Выберите сортировку";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
			});
			this->dataGridView2->Location = System::Drawing::Point(12, 323);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(620, 285);
			this->dataGridView2->TabIndex = 7;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Наименование блюда";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 300;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Калорийность";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 140;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Цена блюда";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->ReadOnly = true;
			this->dataGridViewTextBoxColumn6->Width = 125;
			// 
			// textBoxName
			// 
			this->textBoxName->Enabled = false;
			this->textBoxName->Location = System::Drawing::Point(15, 40);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(357, 30);
			this->textBoxName->TabIndex = 0;
			// 
			// textBoxCal
			// 
			this->textBoxCal->Enabled = false;
			this->textBoxCal->Location = System::Drawing::Point(15, 119);
			this->textBoxCal->Name = L"textBoxCal";
			this->textBoxCal->Size = System::Drawing::Size(294, 30);
			this->textBoxCal->TabIndex = 1;
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Enabled = false;
			this->textBoxPrice->Location = System::Drawing::Point(15, 193);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(294, 30);
			this->textBoxPrice->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(11, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(220, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Наименование ланча";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(11, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Калорийность";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(11, 168);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(220, 22);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Цена ланча";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(15, 257);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(357, 35);
			this->buttonAdd->TabIndex = 5;
			this->buttonAdd->Text = L"Добавить в корзину";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &LunchMenu::buttonAdd_Click);
			// 
			// panel_dish
			// 
			this->panel_dish->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_dish->Controls->Add(this->buttonAdd);
			this->panel_dish->Controls->Add(this->label3);
			this->panel_dish->Controls->Add(this->label2);
			this->panel_dish->Controls->Add(this->label1);
			this->panel_dish->Controls->Add(this->textBoxPrice);
			this->panel_dish->Controls->Add(this->textBoxCal);
			this->panel_dish->Controls->Add(this->textBoxName);
			this->panel_dish->Location = System::Drawing::Point(638, 12);
			this->panel_dish->Name = L"panel_dish";
			this->panel_dish->Size = System::Drawing::Size(389, 305);
			this->panel_dish->TabIndex = 4;
			// 
			// LunchMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1045, 627);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel_dish);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LunchMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Меню бизнес-ланчей";
			this->Load += gcnew System::EventHandler(this, &LunchMenu::LunchMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel_dish->ResumeLayout(false);
			this->panel_dish->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void buttonOk_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (comboBox1->SelectedItem->ToString() == "По возрастанию калорийности")
	{
		for (int i = 0; i < list_of_dishes->Food_list->Count; i++)
		{
			list_of_dishes->Food_list[i]->Cal;
			dish^ temp = gcnew dish();
			int len = list_of_dishes->Food_list->Count;

			for (int i = 0; i < len - 1; i++) {
				for (int j = 0; j < len - i - 1; j++) {
					if (list_of_dishes->Food_list[j + 1]->Cal < list_of_dishes->Food_list[j]->Cal) {

						temp->operator=(list_of_dishes->Food_list[j]);
						list_of_dishes->Food_list[j]->operator=(list_of_dishes->Food_list[j + 1]);
						list_of_dishes->Food_list[j + 1]->operator=(temp);
					}
				}
			}
		}
	}
	else
	{
		if (comboBox1->SelectedItem->ToString() == "По возрастанию цены")
		{
			for (int i = 0; i < list_of_dishes->Food_list->Count; i++)
			{
				list_of_dishes->Food_list[i]->Price;
				dish^ temp = gcnew dish();
				int len = list_of_dishes->Food_list->Count;

				for (int i = 0; i < len - 1; i++) {
					for (int j = 0; j < len - i - 1; j++) {
						if (list_of_dishes->Food_list[j + 1]->Price < list_of_dishes->Food_list[j]->Price) {

							temp->operator=(list_of_dishes->Food_list[j]);
							list_of_dishes->Food_list[j]->operator=(list_of_dishes->Food_list[j + 1]);
							list_of_dishes->Food_list[j + 1]->operator=(temp);
						}
					}
				}
			}
		}
		else
		{
			if (comboBox1->SelectedItem->ToString() == "Без сортировки")
			{	//если без сортировки, то подгружаем из файла и так же в грид грузим
				list_of_dishes->Food_list->Clear();
				for (int i = 0; i < lunches->Lunch_list->Count; i++)
				{
					dish^ temp = gcnew dish(lunches->Lunch_list[i]->Name, lunches->Lunch_list[i]->AllCal, lunches->Lunch_list[i]->AlPrice);
					list_of_dishes->add_dish(temp);
				}
			}
		}
	}

	//Фильтры  на диапазоны значений
	try
	{
		int From_Cal = Convert::ToInt32(textBox1->Text);
		int Until_Cal = Convert::ToInt32(textBox2->Text);
		int len = list_of_dishes->Food_list->Count;
		for (int i = 0; i < len; i++)
		{
			if (list_of_dishes->Food_list[i]->Cal <= From_Cal || list_of_dishes->Food_list[i]->Cal >= Until_Cal)
			{
				list_of_dishes->Food_list->RemoveAt(i);
				i = i - 1;
				len--;
			}
		}

		int From_Price = Convert::ToInt32(textBox3->Text);
		int Until_Price = Convert::ToInt32(textBox4->Text);
		for (int i = 0; i < len; i++)
		{
			if (list_of_dishes->Food_list[i]->Price <= From_Price || list_of_dishes->Food_list[i]->Price >= Until_Price)
			{
				list_of_dishes->Food_list->RemoveAt(i);
				i = i - 1;
				len--;
			}
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Неверные данные фильтра и сортировки", "Информация");
	}
	//если заполнены текстовые поля для диапазона калорийности и цены,
	//тогда выполняем фильтр 
	ViewListInDGV(list_of_dishes->Food_list, dataGridView1);
}
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	//если нашли выбранный индекс
	//тогда переносим данные в панель ланча
	//или высвечиваем первый
	int ind = e->RowIndex;
	int j = 0;
	try
	{//ищем выделенный элемент в списке ланчей
		for (int i = 0; i < lunches->Lunch_list->Count; i++)
		{
			if (lunches->Lunch_list[i]->Name == list_of_dishes->Food_list[ind]->Name)
			{
				j = i;
			}
			
		}
	}
	catch (Exception ^e)
	{
		MessageBox::Show("Ошибочка вышла", "Уведомление");
		//если что-то пошло не так
	}
	//если нашли, высвечиваем, иначе просто нулевой останется
	ViewListInDGV(lunches->Lunch_list[j]->Food_list, dataGridView2);
	//список блюд в ланче высвечиваем во второй грид
	try
	{
		textBoxName->Text = dataGridView1->Rows[ind]->Cells[0]->Value->ToString();
		textBoxCal->Text = dataGridView1->Rows[ind]->Cells[1]->Value->ToString();
		textBoxPrice->Text = dataGridView1->Rows[ind]->Cells[2]->Value->ToString();
	}
	catch (Exception^ e)
	{
		//Если пользователь что-то по-китайски тыкает
	}

}
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	//смотрим, что за данные о ланче
	//добавляем в конец файла данные о ланче
	try
	{
		int i = dataGridView1->SelectedRows[0]->Index;
		dish^ temp = gcnew dish(lunches->Lunch_list[i]->Name,lunches->Lunch_list[i]->AllCal, lunches->Lunch_list[i]->AlPrice);

		basket->add_dish(temp);
		WriteListOfDishesfromFile(basket->Food_list, "Корзина.txt");
		MessageBox::Show("Блюдо добавлено в корзину", "Уведомление");
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Необходимо выделить строку в таблице", "Помощь");
	}
	//что внутри ланча можно посмотреть и на этой форме
	//поэтому в корзину достаточно добавить только данные о ланче
}
private: System::Void LunchMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	//Загружаем из файла ланчи
	ReadLunchesfromFile(lunches->Lunch_list, "Ланчи.txt");
	//высвечиваем в грид
	ViewListInDGV(lunches->Lunch_list, dataGridView1);
	comboBox1->SelectedItem = "Выберите фильтр"; //по умолчанию фильтр ставим
	for (int i = 0; i < lunches->Lunch_list->Count; i++)
	{
		dish^ temp = gcnew dish(lunches->Lunch_list[i]->Name, lunches->Lunch_list[i]->AllCal, lunches->Lunch_list[i]->AlPrice);
		list_of_dishes->add_dish(temp);
	}
} 
private: System::Void textBoxes_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	//Ограничения на ввод в текстовое поле, разрешены:
	//Цифры + запятая + работающий BackSpace
	if ((Char::IsNumber(e->KeyChar) || (e->KeyChar == Convert::ToChar(",")) || e->KeyChar == '\b')) return;
	else
		e->Handled = true;
}
};
}
