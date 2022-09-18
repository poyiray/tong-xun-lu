#include<iostream>
#include<string>
using namespace std;

struct contact
{
	string name;
	string sex;
	string address;
	int age;
	string phone;
};

void Meun()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

void addPerson(contact * Person, int * index)
{
	cout << "请输入姓名: " << endl;
	cin >> Person[*index].name;

	cout << "请输入性别: " << endl;
	cin >> Person[*index].sex;
	if (Person[*index].sex != "男" && Person[*index].sex != "女")
	{
		cout << "请输入一个有效的性别" << endl;
		system("pause");
		return;
	}

	cout << "请输入年龄: " << endl;
	cin >> Person[*index].age;

	while (Person[*index].age > 100 || Person[*index].age < 0)
	{
		cout << "请输入一个有效的年龄" << endl;
		cin >> Person[*index].age;
	}

	cout << "请输入联系电话: " << endl;
	cin >> Person[*index].phone;

	cout << "请输入家庭地址: " << endl;
	cin >> Person[*index].address;

	*index += 1;
}

void showPerson(contact * Person, int num)
{
	if (num == 0)
	{
		cout << "这里空荡荡" << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "姓名: " << Person[i].name
				<< "  性别: " << Person[i].sex
				<< "  年龄: " << Person[i].age
				<< "  电话: " << Person[i].phone
				<< "  地址: " << Person[i].address << endl;
		}
	}
}

void deletePerson(contact * Person, int * index)
{
	string name;
	cout << "输入你要删除的联系人名称: " << endl;
	cin >> name;
	for (int i = 0; i < *index; i++)
	{
		if (name == Person[i].name)
		{
			for (int j = i; j < *index - 1; j++)
			{
				Person[j] = Person[j + 1];
			}
		}
	}
	
	*index -= 1;
}

void searchPerson(contact * Person, int index)
{
	cout << "输入联系人的相关信息来查找他" << endl;
	char search[40];

	cin >> search;
	
	for (int i = 0; i < index; i++)
	{
		if (search == Person[i].address || (int)search == Person[i].age || search == Person[i].sex || search == Person[i].phone || search == Person[i].name)
		{
			cout << "姓名: " << Person[i].name
				<< "  性别: " << Person[i].sex
				<< "  年龄: " << Person[i].age
				<< "  电话: " << Person[i].phone
				<< "  地址: " << Person[i].address << endl;
		}
	}
	system("pause");
}

void editPerson(contact * Person, int index)
{
	cout << "输入你要修改的联系人名字" << endl;
	string name;
	int select;
	cin >> name;

	for (int i = 0; i < index; i++)
	{
		if (name == Person[i].name)
		{
			while (true)
			{
				cout << "1 -- 修改此人的名字" << endl;
				cout << "2 -- 修改此人的性别" << endl;
				cout << "3 -- 修改此人的年龄" << endl;
				cout << "4 -- 修改此人的电话" << endl;
				cout << "5 -- 修改此人的地址" << endl;
				cout << "0 -- 退出编辑" << endl;
				cin >> select;

				switch (select)
				{
				case 1:
					cout << "请输入新的姓名: " << endl;
					cin >> Person[i].name;
					break;
				case 2:
					cout << "请输入新的性别: " << endl;
					cin >> Person[i].sex;
					break;
				case 3:
					cout << "请输入新的年龄: " << endl;
					cin >> Person[i].age;
					break;
				case 4:
					cout << "请输入新的联系电话: " << endl;
					cin >> Person[i].phone;
					break;
				case 5:
					cout << "请输入新的家庭地址: " << endl;
					cin >> Person[i].address;
					break;
				case 0:
					cout << "再见" << endl;
					system("pause");
					return;
				default:
					break;
				}
				cout << "修改成功" << endl;
				system("pause");
				system("cls");
				Meun();
			}
		}
	}
	cout << "没找到此人" << endl;
	system("pause");
}

void deleteAllPerson(contact * Person, int * index)
{
	cout << "你确定要删除所有联系人? " << endl;
	cout << "输入 1 继续" << endl;
	cout << "输入 0 取消" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		*index = 0;
	}
	else
	{
		cout << "退出成功" << endl;
		system("pause");
		return;
	}
}

int main() {
	contact Person[1000];
	int index = 0;
	while (1)
	{
		Meun();
		int choice = 20;
		cin >> choice;

		switch (choice)
		{
		case 1:
			addPerson(Person, &index);
			break;
		case 2:
			showPerson(Person, index);
			system("pause");
			break;
		case 3:
			showPerson(Person, index);
			deletePerson(Person, &index);
			break;
		case 4:
			searchPerson(Person, index);
			break;
		case 5:
			editPerson(Person, index);
			break;
		case 6:
			deleteAllPerson(Person, &index);
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "程序出错" << endl;
			system("pause");
			return 0;
			break;
		}

		system("cls");
	}

	system("pause");
	return 0;
}