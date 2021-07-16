#include <cmath>
#include <string>
#include <time.h>
#include <iostream>
using namespace std;


class Car { //Основной класс
private:
	string brand; //св-тво с брендом машины
	int coast; //св-тво с ценой машины

	//Car() { // Конструктор с параметрами по умолчанию
	//	brand = "none"; 
	//	coast = 0;
	//};

	//~Car() { // Диструктор с параметрами по умолчанию
	//	cout<<"Bye!";
	//};

protected:
	bool TryTo() // метод для попытки завести мотор
	{
		int t = rand() %5+1; //генерирует случайное число от 1 до 6
		if (t % 2 == 0) //проверка числа на четность
		{
			return true;// если четное - машина завелась
		}
		else
		{
			return false; //нечетное - не завелась
		}
	}
	
public:
	void StartEngine() //  метод завести мотор
	{
		if (TryTo()) //Вызываем метод попытки завестись  
		{
			cout << "Sounds of motor"<<endl; //Если метод TryTo() вернул значение True - заводимся
		}
		else
			cout << "Something wrong, try again"<<endl;  // или нет
	}

	// далее идут методы Get и Set для ввода получения данных, которые находятся в поле private

	void SetBrand(string brand) // ввести бренд
	{
		this->brand = brand; //присваеваем название бренда для объекта класса
	}

	void GetBrand() // получить бренд
	{
		cout <<"Brand: " << brand << endl;
	}
	void SetCoast(int coast) // ввести стоимость 
	{
		this->coast = coast;
	}

	void GetCoast()  // получить стоимость
	{
		cout <<"Coast: " << coast << endl;
	}

};

class SportCar : public Car { // класс-наследник (Дочерний) класса Car
private:
	string model;
	string type;

public:
	void SetModel(string model) // ввести модель
	{
		this->model = model;
	}

	void GetModel() // получить модель
	{
		cout <<"Model: "<< model << endl;
	}

	void SetType(string type) // ввести тип
	{
		this->type = type;
	}

	void GetType(){ // получить тип
		cout <<"Type: " << type << endl;
	}

};

int main()
{
	srand(time(NULL)); // Функция для создания раномных чисел

	string brand = "Mersedess-Benz"; // переменные для передачи в класс
	int coast = 12000;

	SportCar car1; //создаем объект класса SportCar
	car1.SetBrand(brand); // передаем аргументы через метод(который наследуем из класса Car)
	car1.SetCoast(coast);

	car1.GetBrand(); // вызываем метод для просмотра информации по бренду
	car1.GetCoast();

	string model = "CLS 550"; //еще одни переменные для передачи в класс
	string type = "Coupe";

	car1.SetModel(model); // передаем аргументы через метод 
	car1.SetType(type);

	car1.GetModel(); // вызываем метод для просмотра информации по Модели
	car1.GetType();

	link_try: // ссылка для оператора goto 

	cout << "Want to try start the engine? \n 1.Yes \n 2.No" << endl;
	int choice; // переменная для принятия данных о выборе пользователя
	cin >> choice; // Ввод данных

	switch (choice) // свич для обработки введенных данных
	{
	case 1:
		car1.StartEngine(); //пользователь согласился завести машину, вызываем метод "завести мотор"
		break;
	case 2:
		cout << "Bye!" << endl; //пользователь решил закончить, прощаемся
		break;
	default:
		cout << "What?" << endl; // пользователь ввел что-то не то
		goto link_try; // через оператора goto возвращаем его к моменту выбора действия
		break;
	}



}

