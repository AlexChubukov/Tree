
#ifdef WIN32
#include <windows.h>
#endif
#include "tree.h"
#include <iostream>

using namespace std;
using namespace BSTree;

int main()
{
#ifdef WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif
	cout << "Пример работы двоичного дерева поиска" << endl;
	cout << "Создаем первое пустое дерево tree" << endl;
	Tree<int> tree;
	cout << "1. Вывести дерево на экран" << endl << "…" << endl;
	cout << "1 <-|" << endl;
	tree.print();
	cout << "2. Вывести список узлов дерева " << endl << "…" << endl;
	cout << "2 <-| a <-|" << endl;
	tree.print(traversal_order('a'));
	cout << "Дерево пусто" << endl;
	cout << "8. Завершить работу программы"<< endl;
	cout << "8 <-|" << endl;
	cout << "Вы действительно хотите выйти?(Yes|No): ";
	cout << "yes" << endl << endl;
	cout << "Создание второго дерева с узлами 15 8 22 26 12 3 10 19 45 28" << endl;
	Tree<int> tree1{15,8,22,26,12,3,10,19,45,28};
	cout << "1. Вывести дерево на экран" << endl << "…" << endl;
	cout << "1 <-|" << endl;
	tree1.print();
	cout << "2. Вывести список узлов дерева " << endl << "…" << endl;
	cout << "2 <-| a <-|" << endl;
	tree1.print(traversal_order('a'));
	cout <<endl<< "2. Вывести список узлов дерева " << endl << "…" << endl;
	cout << "2 <-| b <-|" << endl;
	tree1.print(traversal_order('b'));
	cout << endl<<"2. Вывести список узлов дерева " << endl << "…" << endl;
	cout << "2 <-| c <-|" << endl;
	tree1.print(traversal_order('c'));
	cout << "..." << endl << "3. Добавить узел в дерево" << "..." << endl;
	cout <<  "3 <-| 12 <-|" << endl;
	tree1.insert(12);
	cout << "Такой узел уже существует" << endl;
	cout << "..." << endl << "3. Добавить узел в дерево" << "..." << endl;
	cout <<  "3 <-| 16 <-|" << endl;
	tree1.insert(16);
	cout << "Узел был успешно добавлен" << endl;
	cout << "..." << endl << "4. Удалить узел из дерева" << "..." << endl;
	cout << "4 <-|" << endl;
	cout << "Введите значение для нового узла: 5 <-|" << endl;
	tree1.remove(5);
	cout << "Узел не был найден в дереве" << endl;
	cout << "..." << endl << "4. Удалить узел из дерева" << "..." << endl;
	cout << "4 <-|" << endl;
	cout << "Введите значение для нового узла: 15 <-|" << endl;
	tree1.remove(15);
	cout << "Узел был успешно удален из дерева" << endl;
	cout << "..." << endl << "5. Сохранить дерево в файл" << "..." << endl;
	cout << "5 <-|" << endl;
	cout << "Введите путь к файлу: test.txt <-|" << endl;
	tree1.save("text.txt");
	cout << "Дерево было успешно сохранено" << endl;
	cout <<endl<< "Добавим любой элемент в наше дерево. В данном случае добавим элемент 100" << endl;
	tree1.insert(100);
	cout << "Попробуем записать наше дерево в файл" << endl;
	cout << "..." << endl << "5. Сохранить дерево в файл" << "..." << endl;
	cout << "5 <-|" << endl;
	cout << "Введите путь к файлу: test.txt <-|" << endl;
	tree1.save("test.txt");
	cout << "Файл уже существует, перезаписать ? (Yes|No): Yes"<<endl;
	cout << "Файл был успешно перезаписан" << endl;
	cout << endl << "Теперь считаем только что записанное нами дерево из файла в пустое дерево tree" << endl;
	cout << "..." << endl << "6. Загрузить дерево из файла" << "..." << endl;
	cout << "6 <-|" << endl;
	cout << "Введите путь к файлу: test.txt <-|" << endl;
	tree.load("test.txt");
	cout << "Дерево было успешно загружено" << endl;
	cout << "Выведем только что загруженное дерево на экран" << endl;
	tree.print();
	cout << "..." << endl << "6. Загрузить дерево из файла" << "..." << endl;
	cout << "6 <-|" << endl;
	cout << "Введите путь к файлу: tsdfsa.txt <-|" << endl;
	tree.load("tsdfsa.txt");
	cout << "Файл с заданным путем не существует" << endl;
	cout << endl << "Проверим есть ли узлы в дереве" << endl;
	cout << "..." << endl << "7. Проверить наличие узла" << "..." << endl;
	cout << "7 <-|" << endl;
	cout << "Введите значение для поиска: 10 <-|" << endl;
	tree1.exists(10);
	cout << "Узел был успешно найден" << endl;
	cout << "..." << endl << "7. Проверить наличие узла" << "..." << endl;
	cout << "7 <-|" << endl;
	cout << "Введите значение для поиска: 1000 <-|" << endl;
	tree1.exists(1000);
	cout << "Узел не был найден" << endl;
	cout << "Реалиация выхода из программы" << endl;
	cout << "8. Завершить работу программы" << endl;
	cout << "8 <-|" << endl;
	cout << "Вы действительно хотите выйти?(Yes|No): ";
	cout << "yes" << endl << endl;

    return 0;
}