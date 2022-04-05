#pragma once
#include "Classes.h"
using namespace System::IO;

namespace ���� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� StandartMenu
	/// </summary>
	public ref class StandartMenu : public System::Windows::Forms::Form
	{
		Dishes_List^ list_of_dishes;

		Dishes_List^ basket;
	public:
		StandartMenu(Dishes_List ^ obj)
		{
			InitializeComponent();


			list_of_dishes = gcnew Dishes_List();
			basket = obj;
		}

		List <dish^>^ ReadListOfDishesfromFile(List <dish^>^ obj, String^ FileName)
		{//������ ������ ���� �� �����
			StreamReader^ SR = gcnew StreamReader(FileName); //������� ������ ��� ������ ����������� �����
			String^ str = gcnew String(""); //��� �������� ������ ������ �����
			while (str = SR->ReadLine()) { //���� �������� ������ � �����
				dish^ d = gcnew dish(); //��������� ������ "�����"
				//������� �� ������ �������� � �����������
				d->Name = str->Split('$')[0]; 
				d->Cal = Convert::ToInt32(str->Split('$')[1]); 
				d->Price = Convert::ToDouble(str->Split('$')[2]);
				obj->Add(d); //��������� � ����� ������ ���� ����� �����
				//������� ������ ��� ��������� �� ������
			}
			SR->Close(); //��������� �����������
			return obj; //���������� ����������� ������ ����
		}

		void WriteListOfDishesfromFile(List <dish^>^ obj, String^ FileName)
		{//���������� ������ ���� � ����
			StreamWriter^ My_SW = gcnew StreamWriter(FileName);
			for (int i = 0; i < obj->Count; i++)
			{
				String^ Line = gcnew String("");
				Line += obj[i]->Name + "$";
				Line += obj[i]->Cal + "$";
				Line += obj[i]->Price + "$"+"\n";
				My_SW->Write(Line);
			}
			My_SW->Close();
		}

		void ViewListInDGV(List <dish^>^obj, DataGridView ^dgv)
		{//����������� ������ ���� � ������� �� �����
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
		/// ���������� ��� ������������ �������.
		/// </summary>
		~StandartMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameOfDish;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ �aloric_content;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PriceOfDish;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxCal;
	private: System::Windows::Forms::TextBox^ textBoxPrice;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonAdd;

	private: System::Windows::Forms::Panel^ panel_dish;
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






















	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NameOfDish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�aloric_content = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PriceOfDish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->panel_dish = (gcnew System::Windows::Forms::Panel());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel_dish->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NameOfDish,
					this->�aloric_content, this->PriceOfDish
			});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(620, 591);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StandartMenu::dataGridView1_CellClick);
			// 
			// NameOfDish
			// 
			this->NameOfDish->HeaderText = L"������������ �����";
			this->NameOfDish->MinimumWidth = 6;
			this->NameOfDish->Name = L"NameOfDish";
			this->NameOfDish->ReadOnly = true;
			this->NameOfDish->Width = 300;
			// 
			// �aloric_content
			// 
			this->�aloric_content->HeaderText = L"������������";
			this->�aloric_content->MinimumWidth = 6;
			this->�aloric_content->Name = L"�aloric_content";
			this->�aloric_content->ReadOnly = true;
			this->�aloric_content->Width = 140;
			// 
			// PriceOfDish
			// 
			this->PriceOfDish->HeaderText = L"���� �����";
			this->PriceOfDish->MinimumWidth = 6;
			this->PriceOfDish->Name = L"PriceOfDish";
			this->PriceOfDish->ReadOnly = true;
			this->PriceOfDish->Width = 125;
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
			this->label1->Text = L"������������ �����";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(11, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"������������";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(11, 168);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(220, 22);
			this->label3->TabIndex = 4;
			this->label3->Text = L"����";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(15, 257);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(357, 35);
			this->buttonAdd->TabIndex = 5;
			this->buttonAdd->Text = L"�������� � �������";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &StandartMenu::buttonAdd_Click);
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
			this->panel_dish->TabIndex = 1;
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
			this->groupBox1->Size = System::Drawing::Size(389, 280);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"���������� �������";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(222, 179);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(119, 30);
			this->textBox4->TabIndex = 21;
			this->textBox4->Text = L"10000";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &StandartMenu::textBoxes_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(58, 179);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(119, 30);
			this->textBox3->TabIndex = 24;
			this->textBox3->Text = L"0";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &StandartMenu::textBoxes_KeyPress);
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(183, 182);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 22);
			this->label8->TabIndex = 23;
			this->label8->Text = L"��";
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(16, 182);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(36, 22);
			this->label9->TabIndex = 22;
			this->label9->Text = L"��";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(222, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(119, 30);
			this->textBox2->TabIndex = 20;
			this->textBox2->Text = L"10000";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &StandartMenu::textBoxes_KeyPress);
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(183, 115);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 22);
			this->label7->TabIndex = 19;
			this->label7->Text = L"��";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(16, 115);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 22);
			this->label6->TabIndex = 18;
			this->label6->Text = L"��";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(16, 154);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(274, 22);
			this->label5->TabIndex = 17;
			this->label5->Text = L"����";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(16, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(274, 22);
			this->label4->TabIndex = 15;
			this->label4->Text = L"������������ ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(58, 112);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(119, 30);
			this->textBox1->TabIndex = 16;
			this->textBox1->Text = L"0";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &StandartMenu::textBoxes_KeyPress);
			// 
			// buttonOk
			// 
			this->buttonOk->Location = System::Drawing::Point(16, 229);
			this->buttonOk->Name = L"buttonOk";
			this->buttonOk->Size = System::Drawing::Size(357, 35);
			this->buttonOk->TabIndex = 6;
			this->buttonOk->Text = L"���������";
			this->buttonOk->UseVisualStyleBackColor = true;
			this->buttonOk->Click += gcnew System::EventHandler(this, &StandartMenu::buttonOk_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"�� ����������� ������������", L"�� ����������� ����",
					L"��� ����������"
			});
			this->comboBox1->Location = System::Drawing::Point(16, 43);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(357, 30);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->Text = L"�������� ����������";
			// 
			// StandartMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1037, 620);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel_dish);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StandartMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������� ����";
			this->Load += gcnew System::EventHandler(this, &StandartMenu::StandartMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel_dish->ResumeLayout(false);
			this->panel_dish->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void StandartMenu_Load(System::Object^ sender, System::EventArgs^ e)
{
	//��������� ���� �� �����
	list_of_dishes->Food_list = ReadListOfDishesfromFile(list_of_dishes->Food_list, "����.txt");
	ViewListInDGV(list_of_dishes->Food_list, dataGridView1);
	comboBox1->SelectedItem = "��� ����������";
	//������� � ����
}

private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//���� ������� ������
	//����� ��������� ������� � �������
	try
	{
		int i = dataGridView1->SelectedRows[0]->Index;
		basket->add_dish(list_of_dishes->Food_list[i]);
		WriteListOfDishesfromFile(basket->Food_list, "�������.txt");
		MessageBox::Show("����� ��������� � �������", "�����������");
	}
	catch (Exception ^e)
	{
		MessageBox::Show("���������� �������� ������ � �������", "������");
	}
}
private: System::Void buttonOk_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//� ����������� �� ����, ��� ������� ��������� ���������� � ������� ������ ����
	if (comboBox1->SelectedItem->ToString() == "�� ����������� ������������")
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
		if (comboBox1->SelectedItem->ToString() == "�� ����������� ����")
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
			if (comboBox1->SelectedItem->ToString() == "��� ����������")
			{	//���� ��� ����������, �� ���������� �� ����� � ��� �� � ���� ������
				list_of_dishes->Food_list->Clear();
				ReadListOfDishesfromFile(list_of_dishes->Food_list, "����.txt");
			}
		}
	}

	//�������  �� ��������� ��������
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
				i = i-1;
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
	catch (Exception ^e)
	{
		MessageBox::Show("�������� ������ ������� � ����������", "����������");
	}
	//���� ��������� ��������� ���� ��� ��������� ������������ � ����,
	//����� ��������� ������ 
	ViewListInDGV(list_of_dishes->Food_list, dataGridView1);
}

private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	//���� ������� ������� � ��� ��, �����
	int i = e->RowIndex;

	textBoxName->Text = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
	textBoxCal->Text = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
	textBoxPrice->Text = dataGridView1->Rows[i]->Cells[2]->Value->ToString();
	//����������� ������ ����������� ����� � ������
}

private: System::Void textBoxes_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	//����������� �� ���� � ��������� ����, ���������:
	//����� + ������� + ���������� BackSpace
	if ((Char::IsNumber(e->KeyChar) || (e->KeyChar == Convert::ToChar(",")) || e->KeyChar == '\b')) return;
	else
		e->Handled = true;
}
};
}
