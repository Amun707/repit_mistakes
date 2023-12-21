#include <iostream>
#include<cmath>
#include <string>

struct Date {
	int day = 14;
	int month = 2;
	int year = 1988;
	std::string note = "date of born";
};

//вывод объекта в консоль
void print_date(const Date &D) {
	std::cout << D.day << '.' << D.month << '.' << D.year << " - " << D.note << std::endl;
}
//генерирует объект структуры через ввод пользователя и возвращает его
Date input_date() {
	Date tmp;

	std::cout << "Введите день -> ";
	std::cin >> tmp.day;
	std::cout << "Введите месяц -> ";
	std::cin >> tmp.month;
	std::cout << "Введите год -> ";
	std::cin >> tmp.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, tmp.note);


	return tmp;
}
//заполняет объект структуры данными вводимыми пользователем
void fill_date(Date &D) {
	std::cout << "Введите день -> ";
	std::cin >> D.day;
	std::cout << "Введите месяц -> ";
	std::cin >> D.month;
	std::cout << "Введите год -> ";
	std::cin >> D.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, D.note);

}


//Задача1 хранитель монет
struct MyPerson {
	std::string name = "noname";
	int age = 18;
	int coins_number = 0;
	int* coins = nullptr;
};

void show_person(const MyPerson &MP) { //выводит информацию о переданном объекте
	std::cout << "Имя: " << MP.name << std::endl;
	std::cout << "Возраст: " << MP.age << std::endl;
	std::cout << "Монеты: ";
	for (int i = 0; i < MP.coins_number; i++)
		std::cout << MP.coins[i] << ", ";
	std::cout << "\b\b \n";
}

int year_of_birth(const MyPerson &MP, int year){//принимает год рождения и текущий год, возвращает год рождения объекта
	return year - MP.age;
}

int cash(const MyPerson &MP) {//принимает объект структуры и считает общие сбережения
	int sum = 0;
	for (int i = 0; i < MP.coins_number; i++)
		sum += MP.coins[i];
	return sum*(-1);
}




/*
//перегрузка
int max(int num1, int num2) {
	std::cout << "TWO INT\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLE\n";
	return num1 > num2 ? num1 : num2;
}
char max(char num1, char num2) {
	std::cout << "TWO CHAR\n";
	return num1 > num2 ? num1 : num2;
}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INT\n";
	int max = num1 > num2 ? num1 : num2;
	return num3 > max ? num3 : max;
}

//шаблонная
template <typename T>
double mean(T num1, T num2) {
	return(num1 + num2) / 2.0;
}


//вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
}

void decide(double a, double b) {
	std::cout<<"x = "<<(-b) / a<<std::endl;
}
void decide(double a, double b, double c) {
	double D = b * b - 4 * a * c;
	if (D > 0) {
		std::cout << "x1 = " << (-b - sqrt(D)) / (2.0 * a) << std::endl;
		std::cout << "x2 = " << (-b + sqrt(D)) / (2.0 * a) << std::endl;
		return;
	}
	if (D == 0) {
		std::cout << "x = " << (-b) / (2.0 * a) << std::endl;
		return;
	}
	std::cout << "Корней нет\n";
}

int main() {
	system("chcp 1251>null");
	int n, m;

	//перегрузка
	std::cout << max(15, 12) << std::endl;//15
	std::cout << max(7.2, 7.3) << std::endl;//7.3
	std::cout << max('a', 'A') << std::endl;//a
	std::cout << max(15, 17, 14) << std::endl;//17

	//шаблонная функция
	std::cout << mean(5, 6) << std::endl;//5.5
	std::cout << mean(4.3, 4.4) << std::endl;//4.35

	int int_arr[3]{ 3,4,6 };
	double dbl_arr[4]{ 2.3,4.8,2.1,6.6 };
	print_arr(int_arr, 3);
	print_arr(dbl_arr, 4);

	//задача 4
	//решения уравнений
	std::cout << "Задача 4\n\nЛинейные уравнения\n";
	int a, b, c;
	std::cout << "Введите два коэф ->\n";
	std::cin >> a >> b;
	std::cout << "x + " << b << " = 0\n";
	decide(a, b);

	std::cout << "\nКвадратное уравнение:\n";
	std::cout << "Введите 3 коэф ->";
	std::cin >> a >> b >> c;
	std::cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
	decide(a, b, c);*/
int main(){
	system("chcp 1251>null");
	int n, m;


	//структуры создание
/*	struct Location {
		std::string country;
		std::string city;
		std::string smt;
		std::string street;
		int house_number;
	};

	struct Person {
		std::string name;
		int age;
		std::string job;
		int salary;
		Location address;
	} p3, p4, p5;

	Person p1;
	p1.name = "Karolina Lavrushina";
	p1.age = 35;
	p1.job = "programmer";
	p1.salary = 200000;
	p1.address.country = "Russia";
	p1.address.city = "Yekaterinburg";
	p1.address.smt = "Kalininets - 6";
	p1.address.street = "Fruktovaya";
	

	std::cout << "Name: " << p1.name << std::endl;
	std::cout << "Age: " << p1.age << std::endl;
	std::cout << "Job: " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl<<std::endl;
	std::cout << "Country: " << p1.address.country << std::endl;
	std::cout << "City: " << p1.address.city << std::endl;
	std::cout << "Smt: " << p1.address.smt << std::endl;
	std::cout << "Street: " << p1.address.street << std::endl;
	std::cout << "----------------------------------------\n";


	Person p2{ 
		"Kirill Alferiev",
		32,
		"industrial climber",
		150000
	};
	p2.address.country = "Russia";
	p2.address.city = "Yekaterinburg";
	p2.address.smt = "Kalininets - 6";
	p2.address.street = "Fruktovaya";

	std::cout << "Name: " << p2.name << std::endl;
	std::cout << "Age: " << p2.age << std::endl;
	std::cout << "Job: " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl<<std::endl;
	std::cout << "Country: " << p2.address.country << std::endl;
	std::cout << "City: " << p2.address.city << std::endl;
	std::cout << "Smt: " << p2.address.smt << std::endl;
	std::cout << "Street: " << p2.address.street << std::endl;
	std::cout << "------------------------------\n\n";

	p3 = p1;
	p3.age = 36;
	std::cout << "Name: " << p3.name << std::endl;
	std::cout << "Age: " << p3.age << std::endl;
	std::cout << "Job: " << p3.job << std::endl;
	std::cout << "Salary: " << p3.salary << std::endl << std::endl;
	std::cout << "------------------------------\n\n";*/

	
	//указатели и функции при работе с объектами структур
	/*Date d1;

	print_date(d1);

	Date* pd1 = &d1;//указатель на объект структуры Date

	std::cout << "Note: " << pd1->note << std::endl;//обращение к полю оюъекта через указатель на этот объект

	std::cout << "\nВвод данных в объект:\n";
	//Date d2 = input_date();
	//print_date(d2);

	Date d3;
	fill_date(d3);
	print_date(d3);*/

	//задача 1 хранитель монет
	std::cout << "Задача 1.\n";
	MyPerson ck{
		"Karolina",
		35,
		5,
		new int[5] {444000, 1000000000, 100000000, 1000000000, 1000000000}
	};
	show_person(ck);
	std::cout << "Год рождения: " << year_of_birth(ck, 2023) << std::endl;

	std::cout << "Общие сбережения: " << cash(ck) << std::endl;

	delete[] ck.coins;//освобождения памяти выделенной под динамическиймассив

	return 0;
}