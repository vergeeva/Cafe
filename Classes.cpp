#include "Classes.h"

dish::dish()
{
	name = gcnew String("�������� �����");
	calorific = 1;
	price = 1;
}

dish::dish(String^ name, int calorific, double price)
{
	this->name = gcnew String(name);
	this->calorific = calorific;
	this->price = price;
}

dish::~dish()
{
	delete name;
}

bool dish::operator==(dish^ other)
{//�������� ��������� ������ ����� � ������
	return this->name == other->name && this->calorific == other->calorific && this->price == other->price;
}

dish^ dish::operator=(dish^ other)
{//�������� ������������
	this->Name = other->name;
	this->Cal = other->calorific;
	this->Price = other->price;
	return this;
}
//----------------------------------------------------------------------------------------------------------------------------------

Dishes_List::Dishes_List()
{
	food_list = gcnew List <dish^>(100);
	double PriceAll = sum_price();
	int CalorificAll = sum_cal();
}

Dishes_List::~Dishes_List()
{
	delete food_list;
}

double Dishes_List::sum_price() 
{//������� ����� ��������� ������ ����
	double sum_price = 0;
	for (int i = 0; i < food_list->Count; i++)
	{
		sum_price += food_list[i]->Price;
	}
	return sum_price;
}

int Dishes_List::sum_cal() 
{ //������� ����� ������� � ������ ����
	int sum_cal = 0;
	for (int i = 0; i < food_list->Count; i++)
	{
		sum_cal += food_list[i]->Cal;
	}
	return sum_cal;
}

Dishes_List^ Dishes_List::operator=(Dishes_List^ other)
{ //�������� ������������
	for (int i = 0; i < other->food_list->Count; i++)
	{
		try 
		{
			this->food_list[i]->Name = other->food_list[i]->Name;
			this->food_list[i]->Cal = other->food_list[i]->Cal;
			this->food_list[i]->Price = other->food_list[i]->Price;
		}
		catch (Exception ^e)
		{
			this->food_list->Add(other->food_list[i]);
		}
	}
	return this;
}

bool Dishes_List::operator==(Dishes_List^ other)
{//�������� ��������� ==
	for (int i = 0; i < food_list->Count; i++)
	{
		if (!(this->food_list[i] == other->food_list[i]))
			return 0;

	}
	return 1;
}

bool Dishes_List::add_dish(dish^ obj)
{//�������� �����
	try
	{
		food_list->Add(obj);
		return true;
	}
	catch (Exception ^e)
	{
		return false;
	}

}

bool Dishes_List::delete_dish(dish^ obj)
{//������� �����
	try
	{
		food_list->Remove(obj);
		return true;
	}
	catch (Exception^ e)
	{
		return false;
	}

}
//------------------------------------------------------------------------------------------------------------------
Lunches::Lunches()
{

	lunch_list = gcnew List<Dishes_List^>(100);

}

bool Lunches::Add(Dishes_List^ object)
{//�������� ����
	try
	{
		lunch_list->Add(object);
		return true;
	}
	catch (Exception ^e)
	{
		return false;
	}
}

bool Lunches::Del(Dishes_List^ object)
{//������� ����
	try
	{
		lunch_list->Remove(object);
		return true;
	}
	catch (Exception^ e)
	{
		return false;
	}
}

Lunches::~Lunches()
{
	delete lunch_list;
}

