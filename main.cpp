#include <iostream>
#include <concepts>
#include <string>

using namespace std;

//-std=c++20

template<typename T> concept ComplexConcept = requires(const T v) 
{
	{v.hash()} -> convertible_to<long>; /// перевод int в long
	{v.toString()} -> convertible_to<string>; /// перевод int в string
};

template <typename T> concept chek_res_type = same_as<T, long> || same_as<T, string>; // Проверка типа возвращаемого значения


struct Number
{
	int _val{ 0 };
	string toString() const { return to_string(_val); };  /// int в string

	long hash() const { return static_cast<long>(_val); }; /// int в long
};

template<chek_res_type T> T show_value(T t) { return t; } /// выводит преобразованное значение в консоль с определением типа возвращаемого значения


int main()
{
	setlocale(LC_ALL, "rus");

	Number x{ 11 };
	cout << "Проверка существования virtual диструктора: " << has_virtual_destructor<Number>::value << endl;
	cout << "long: " << show_value(x.hash()) << endl;

	cout << "string: " << show_value(x.toString()) << endl;

	/*---Контроль выполнения проверка типа возвращаемого значения*/
	///cout << "int: " << show_value(5) << endl;
	return 0;
}