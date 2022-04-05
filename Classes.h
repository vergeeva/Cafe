#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace System::IO;

public ref class dish //����� "�����"
{
private:
	String^ name; //������������ �����
	int calorific; //�������
	double price; //����

public:
	dish(); //����������� �� ���������
	dish(String^ name, int calorific, double price); //����������� c �����������
	~dish(); //����������
	bool operator ==(dish^ other);
	dish^ operator =(dish^ other);
	property String^ Name
	{//�������� ��� ������� � �����
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = gcnew String(Name);
		}
	}

	property int Cal
	{//�������� ��� ������� � ���������� �������
		int get() {
			return calorific;
		}
		void set(int Cal) {
			calorific = Cal;
		}
	}

	property double Price
	{//�������� ������� � ���� ������
		double get() {
			return price;
		}
		void set(double price) {
			this->price = price;
		}
	}
};

public ref class Dishes_List //������ ����
{
private:
	String^ name;
	List <dish^>^ food_list;
	double PriceAll; //����� ���������
	int CalorificAll; //����� ������������
	double sum_price();
	int sum_cal();
public:
	Dishes_List();//�����������
	~Dishes_List();

	Dishes_List^ operator =(Dishes_List^ other);
	bool operator ==(Dishes_List^ other);
	bool add_dish(dish^obj); //�������� �����
	bool delete_dish(dish^ obj); //������� �����


	property List <dish^>^ Food_list
	{ //������ ������ ��� ������ ������ ����
		List <dish^>^ get()
		{
			return food_list;
		}
		void set(List <dish^>^ obj)
		{
			food_list = obj;
		}
	}

	property String^ Name
	{//�������� ��� ������� � ������������
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = Name;
		}
	}
	property int AllCal
	{//�������� ��� ������� � �������� ������������
		int get() {
			return sum_cal();
		}
	}
	property double AlPrice
	{//�������� ��� ������� � �������� ����
		double get() {
			return sum_price()*0.8;
		//��������� ���� ����� �� �������
		//��� �������, � �������� �������
		}
	}
};

public ref class Lunches //������ ������
{
private:
	List <Dishes_List^>^ lunch_list;
public:
	Lunches();//�����������
	~Lunches();
	bool Add(Dishes_List^); //�������� ����
	bool Del(Dishes_List^); //������� ����

	property  List <Dishes_List^>^ Lunch_list
	{//�������� ������� � ������ ������
		List <Dishes_List^>^ get()
		{
			return lunch_list;
		}
	}
};