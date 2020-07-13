//#include <iostream>
////Завдання 1
//#include <ctime>
//
//using namespace std;
//
//int mass1[4], mass2[4], inp;
//
//void zadum()
//{
//    srand(time(0));
//    mass1[0] = rand() % 9 + 1;
//    for (int I = 1; I <= 3; I++)
//        mass1[I] = rand() % 10;
//}
//void razb()
//{
//    int del = 10;
//    for (int i = 3; i > -1; i--)
//    {
//        mass2[i] = inp % 10;
//        inp /= 10;
//    }
//
//}
//int b()
//{
//    int res = 0;
//    for (int I = 0; I < 4; I++)
//        if (mass1[I] == mass2[I])
//            res++;
//    return res;
//}
//int c()
//{
//    int res = 0;
//    for (int I = 0; I < 4; I++)
//        for (int J = 0; J < 4; J++)
//            if (mass1[I] == mass2[J] && I != J)
//                res++;
//    return res;
//}
//void game()
//{
//    zadum();
//    cout << "Число  Б К\n"
//        << "----------\n";
//    for (;;)
//    {
//        cin >> inp;
//        razb();
//        cout << "       " << b() << " " << c() << "\n";
//        if (b() == 4)
//        {
//            cout << "Вы выйграли!!!\n";
//            break;
//        }
//    }
//}
//void main()
//{
//    setlocale(0, "Russian");
//    char M;
//    cout << "Здравствуйте, это игра 'Быки и коровы'.\n"
//        << "Компьютер задумал 4-хзначное число. Ваша задача - отгадать его посредством ввода чисел.\n"
//        << "Если цифра совпадает, но стоит на другом месте - это корова, если стоит на том же месте - бык.\n\n";
//    for (;;)
//    {
//        game();
//        cout << "Ещё раз? (Д/Н)\n"; cin >> M;
//        if (M == 'н' || M == 'Н')
//            break;
//    }
//    system("pause");
//}
//Завдання 2

//#include<iostream>
//#include <stdio.h> 
//using namespace std;
//
//
//
//int countPositiveNumbers(int* arr, int n)
//{
//    int pos_count = 0;
//    int i;
//    for (i = 0; i < n; i++) {
//        if (arr[i] > 0)
//            pos_count++;
//    }
//    return pos_count;
//}
// 
//int countNegativeNumbers(int* arr, int n)
//{
//    int neg_count = 0;
//    int i;
//    for (i = 0; i < n; i++) {
//        if (arr[i] < 0)
//            neg_count++;
//    }
//    return neg_count;
//}
//
//void printArray(int* arr, int n)
//{
//    int i;
//
//    printf("Array: ");
//    for (i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//
//int main()
//{
//    int arr[] = { 2, -1, 5, 6, 0, -3 };
//    int n;
//    n = sizeof(arr) / sizeof(arr[0]);
//
//    printArray(arr, n);
//
//    printf("Count of Negative elements = %d\n",
//        countPositiveNumbers(arr, n));
//    printf("Count of Positive elements = %d\n",
//        countNegativeNumbers(arr, n));
//    cout << "Count of Zero elements = 0" << endl;
//    return 0;
//}
//Завдання 3
#include<iostream>
#include<string>
using namespace std;

const int sizeGroup = 20;
string group[sizeGroup];
int currentIndex = 0;





void showAllStudents() {
	bool isEmpty = true;
	for (int i = 0; i < sizeGroup; i++)
	{
		if (group[i] != "") {
			cout << i + 1 << "." << group[i] << endl;
			isEmpty = false;
		}
	}

	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
	cout << endl;

}
template <typename Type1>
Type1 addStudent(Type1 nameOfStudent) {
	if (currentIndex < sizeGroup) {
		group[currentIndex] = nameOfStudent;
		currentIndex++;
	}
	else {
		cout << "Group is full" << endl;
	}
	cout << endl;

}


template <typename Type>
Type removeStudent(Type indexOfStudent) { //1
	group[indexOfStudent] = "";

	string tempArray[sizeGroup];
	int tempIndex = 0;

	for (string item : group)
	{
		if (item != "") {
			tempArray[tempIndex] = item;
			tempIndex++;
		}
	}

	for (int i = 0; i < sizeGroup; i++)
	{
		group[i] = tempArray[i];
	}
	cout << endl;
}


void managerStudents() {
	int action = 0;

	do
	{
		cout << "1.Show all students" << endl;
		cout << "2.Remove student" << endl;
		cout << "3.Add student" << endl;
		cout << "4.Exit" << endl;
		cout << endl;
		cout << "Select action->_";
		cin >> action;

		switch (action)
		{
		case 1: {
			system("cls");
			showAllStudents();
		}break;

		case 2: {
			system("cls");
			int tempNumber = 0;
			cout << "Enter number student for delete: ";
			cin >> tempNumber;
			removeStudent(tempNumber - 1);
		}break;

		case 3: {
			system("cls");
			string temp;
			cout << "Enter name for new student: ";
			cin >> temp;

			addStudent(temp);
		}break;

		case 4: {
			cout << "Goodbye" << endl;
		}break;

		}
	} while (action != 4);

}

int main() {

	managerStudents();

	return 0;
}
