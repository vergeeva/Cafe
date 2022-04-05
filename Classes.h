#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace System::IO;

public ref class dish //Класс "Блюдо"
{
private:
	String^ name; //Наименование блюда
	int calorific; //калории
	double price; //цена

public:
	dish(); //конструктор по умолчанию
	dish(String^ name, int calorific, double price); //конструктор c параметрами
	~dish(); //деструктор
	bool operator ==(dish^ other);
	dish^ operator =(dish^ other);
	property String^ Name
	{//Свойство для доступа к имени
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = gcnew String(Name);
		}
	}

	property int Cal
	{//Свойство для доступа к количеству калорий
		int get() {
			return calorific;
		}
		void set(int Cal) {
			calorific = Cal;
		}
	}

	property double Price
	{//Свойство доступа к цене товара
		double get() {
			return price;
		}
		void set(double price) {
			this->price = price;
		}
	}
};

public ref class Dishes_List //Список блюд
{
private:
	String^ name;
	List <dish^>^ food_list;
	double PriceAll; //Общая стоимость
	int CalorificAll; //Общая калорийность
	double sum_price();
	int sum_cal();
public:
	Dishes_List();//Конструктор
	~Dishes_List();

	Dishes_List^ operator =(Dishes_List^ other);
	bool operator ==(Dishes_List^ other);
	bool add_dish(dish^obj); //Добавить блюдо
	bool delete_dish(dish^ obj); //удалить блюдо


	property List <dish^>^ Food_list
	{ //Доступ только для чтения списка блюд
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
	{//Свойство для доступа к наименованию
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = Name;
		}
	}
	property int AllCal
	{//Свойство для доступа к сумарной калорийности
		int get() {
			return sum_cal();
		}
	}
	property double AlPrice
	{//Свойство для доступа к сумарной цене
		double get() {
			return sum_price()*0.8;
		//суммарная цена ланча со скидкой
		//как правило, в коплекте дешевле
		}
	}
};

public ref class Lunches //Список ланчей
{
private:
	List <Dishes_List^>^ lunch_list;
public:
	Lunches();//Конструктор
	~Lunches();
	bool Add(Dishes_List^); //Добавить ланч
	bool Del(Dishes_List^); //Удалить ланч

	property  List <Dishes_List^>^ Lunch_list
	{//Свойство доступа к списку ланчей
		List <Dishes_List^>^ get()
		{
			return lunch_list;
		}
	}
};