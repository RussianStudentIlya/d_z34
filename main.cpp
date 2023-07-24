#include <iostream>
#include <concepts>
#include <string>

using namespace std;

//-std=c++20

template<typename T> concept ComplexConcept = requires(const T v) 
{
	{v.hash()} -> convertible_to<long>; /// ������� int � long
	{v.toString()} -> convertible_to<string>; /// ������� int � string
};

template <typename T> concept chek_res_type = same_as<T, long> || same_as<T, string>; // �������� ���� ������������� ��������


struct Number
{
	int _val{ 0 };
	string toString() const { return to_string(_val); };  /// int � string

	long hash() const { return static_cast<long>(_val); }; /// int � long
};

template<chek_res_type T> T show_value(T t) { return t; } /// ������� ��������������� �������� � ������� � ������������ ���� ������������� ��������


int main()
{
	setlocale(LC_ALL, "rus");

	Number x{ 11 };
	cout << "�������� ������������� virtual �����������: " << has_virtual_destructor<Number>::value << endl;
	cout << "long: " << show_value(x.hash()) << endl;

	cout << "string: " << show_value(x.toString()) << endl;

	/*---�������� ���������� �������� ���� ������������� ��������*/
	///cout << "int: " << show_value(5) << endl;
	return 0;
}