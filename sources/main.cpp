
#ifdef WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <limits> // ввод через int
#include <fstream>
#include "tree.h"
using namespace std;
using namespace BSTree;

void menu();
void correct_input(int &choose);

int main(int argc, char* argv[])
{
#ifdef WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif
	Tree tree;
	if (argc > 1) {
		int i = 0;
		while (argc - 1 != i) {
			i++;
			tree.insert(atoi(argv[i]));
		}
	}
	bool exit = false;
	while (!exit)
	{
		menu();
		int choose;
		correct_input(choose);
		switch (choose)
		{
		case 1:
			tree.print();
			break;
		case 2:
		{
			if (tree.get_root() == nullptr) {
				cout << "Дерево пусто" << endl;
				break;
			}
			bool is_correct = false;
			while (!is_correct) {
				is_correct = true;
				cout << "a. Прямой обход" << endl;
				cout << "b. Поперечный обход" << endl;
				cout << "c. Обратный обход " << endl;
				char temp = 0;
				cin >> temp;
				is_correct = tree.print((traversal_order)temp);
			}
		}
		break;
		case 3:
		{
			int node_value;
			cout << "Введите значение для нового узла: ";
			correct_input(node_value);
			if (!tree.insert(node_value)) {
				cout << "Узел уже существует" << endl;
			}
			break;
		}
		break;
		case 4:
		{
			cout << "Введие значение для нового узла: ";
			int new_node;
			correct_input(new_node);
			if (tree.remove(new_node)) {
				cout << "Узел был успешно удален из дерева" << endl;
				break;
			}
			cout << "Узел не был найден в дереве" << endl;
		}
		break;
		case 5:
		{
			cout << "Введите путь к файлу: ";
			string way;
			cin >> way;
			ifstream temp(way);
			bool exist = temp.is_open();
			temp.close();
			if (exist) {
				cout << "Файл уже существует, перезаписать ? (Yes|No): ";
				string answer;
				cin >> answer;
				if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES") {
					ofstream filew(way);
					filew << tree;
					filew.close();
					break;
				}
				ofstream filew(way,ios_base::app);
				filew << endl;
				filew << tree;
				filew.close();
				break;
			}
			ofstream filew(way);
			filew << tree;
			filew.close();
		}
			break;
		case 6:
		{
			cout << "Введите путь к файлу: ";
			string way;
			cin >> way;
			ifstream file(way);
			bool exist = file.is_open();
			if (exist == 0) {
				cout << "Файл с заданным путем не существует" << endl;
				break;
			}
			tree.~Tree();
			int buff;
			while (!file.eof()) {
				file >> buff;
				tree.insert(buff);
			}
			cout << "Дерево было успешно загружено" << endl;
		}
			break;
		case 7:
			break;
		case 8:
		{
			bool is_correct = false;
			while (!is_correct)
			{
				cout << "Вы хотите выйти из программы ? (y,N)" << endl;
				string answer;
				cin >> answer;
				if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES")
				{
					cout << "До свидания!" << endl;
					is_correct = true;
					exit = true;
					break;
				}
				if (answer == "N" || answer == "n" || answer == "no" || answer == "No" || answer == "NO")
				{
					is_correct = true;
					break;
				}
				cout << "Попробуйте еще раз!" << endl;
			}
			break;
		}
		default:
			cout << "Неправильный ввод данных!" << endl;
			break;
		}
	}
	return 0;
}

void menu()
{
	cout << endl;
	cout << "Выберите одну из операций:" << endl;
	cout << "1. Вывести дерево на экран" << endl;
	cout << "2. Вывести список узлов дерева" << endl;
	cout << "3. Добавить узел в дерево" << endl;
	cout << "4. Удалить узел из дерева" << endl;
	cout << "5. Сохранить дерево в файл" << endl;
	cout << "6. Загрузить дерево из файла" << endl;
	cout << "7. Проверить наличие узла" << endl;
	cout << "8. Завершить работу программы" << endl;
}

void correct_input(int &choose) {
	bool good = true;
	do {
		cin >> choose;
		if (!(good = cin.good())) {
			cout << "Неправильный ввод данных. Попробуйте еще раз" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!good);
}