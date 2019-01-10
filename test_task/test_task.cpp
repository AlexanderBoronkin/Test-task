#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Transport
{
protected:
	string Name;
	int wheels;
	int max_speed;

public:
	//конструкторы
	Transport()
	{
		Name = "No name";
		wheels = 0;
		max_speed = 0;
	}
	Transport(string s_name, int s_wheels, int s_max_speed)
	{
		Name = s_name;
		wheels = s_wheels;
		max_speed = s_max_speed;
	}
	//set get
	void SetName(string s_name) { Name = s_name; }
	void SetWheels(int s_wheels) { wheels = s_wheels; }
	void SetMaxSpeed(int s_max_speed) { max_speed = s_max_speed; }

	string GetName() { return Name; }
	int GetWheels() { return wheels; }
	int GetMaxSpeed() { return max_speed; }

	//вывод значений полей
	void Print()
	{
		cout << "Наименование транспорта: " << Name << endl;
		cout << "Количество колес: " << wheels << endl;
		cout << "Максимальная скорость: " << max_speed << " км/ч" << endl << endl;
	}
};

class Factory : public Transport
{
private:
	int production;
	double cost;
public:
	//конструктор
	Factory(Transport a, int s_prod, int s_cost)
	{
		Name = a.GetName();
		wheels = a.GetWheels();
		max_speed = a.GetMaxSpeed();
		production = s_prod;
		cost = s_cost;
	}
	//вывод
	void Print()
	{
		cout << "Фабрика по производству следующего типа транспорта:" << endl;
		cout << "Наименование : " << Name << endl;
		cout << "Количество колес: " << wheels << endl;
		cout << "Максимальная скорость: " << max_speed << " км/ч" << endl << endl;
		cout << "Единиц техники в год: " << production << endl;
		cout << "Цена за единицу техники: " << cost << " тыс. рублей" << endl;
	}
};

int StrToInt(char *s)
{
	int temp = 0; // число
	int i = 0;
	int sign = 0; // знак числа 0 - положительное, 1 — отрицательное
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] >= 0x30 && s[i] <= 0x39)
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1)
		temp = -temp;
	return(temp);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	Transport moto("Мотоцикл", 2, 250);
	Transport samokat("Самокат", 3, 10);
	Transport car("Автомобиль", 4, 200);
	Transport bus("Автобус", 6, 100);

	//проверка с единицы, потому что в массиве параметров первый (по индексу нулевой) является именем программы.
	if (argc > 1)
	{
		for (int i = 1;i < argc; i++)
		{
			int temp = StrToInt(argv[i]);
			switch (temp)
			{
			case 0:
				moto.Print();
				break;
			case 1:
				samokat.Print();
				break;
			case 2:
				car.Print();
				break;
			case 3:
				bus.Print();
				break;
			default:
				cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА" << endl << endl;
				break;
			}
		}
		cout << "А ещё у нас есть вот такая фабрика: " << endl << endl;
		Factory my_factory(bus, 20, 750);
		my_factory.Print();
	}
	else cout << "Не введено ни одного параметра." << endl << "Конец программы.";
	
}
