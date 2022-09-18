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
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

void addPerson(contact * Person, int * index)
{
	cout << "����������: " << endl;
	cin >> Person[*index].name;

	cout << "�������Ա�: " << endl;
	cin >> Person[*index].sex;
	if (Person[*index].sex != "��" && Person[*index].sex != "Ů")
	{
		cout << "������һ����Ч���Ա�" << endl;
		system("pause");
		return;
	}

	cout << "����������: " << endl;
	cin >> Person[*index].age;

	while (Person[*index].age > 100 || Person[*index].age < 0)
	{
		cout << "������һ����Ч������" << endl;
		cin >> Person[*index].age;
	}

	cout << "��������ϵ�绰: " << endl;
	cin >> Person[*index].phone;

	cout << "�������ͥ��ַ: " << endl;
	cin >> Person[*index].address;

	*index += 1;
}

void showPerson(contact * Person, int num)
{
	if (num == 0)
	{
		cout << "����յ���" << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "����: " << Person[i].name
				<< "  �Ա�: " << Person[i].sex
				<< "  ����: " << Person[i].age
				<< "  �绰: " << Person[i].phone
				<< "  ��ַ: " << Person[i].address << endl;
		}
	}
}

void deletePerson(contact * Person, int * index)
{
	string name;
	cout << "������Ҫɾ������ϵ������: " << endl;
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
	cout << "������ϵ�˵������Ϣ��������" << endl;
	char search[40];

	cin >> search;
	
	for (int i = 0; i < index; i++)
	{
		if (search == Person[i].address || (int)search == Person[i].age || search == Person[i].sex || search == Person[i].phone || search == Person[i].name)
		{
			cout << "����: " << Person[i].name
				<< "  �Ա�: " << Person[i].sex
				<< "  ����: " << Person[i].age
				<< "  �绰: " << Person[i].phone
				<< "  ��ַ: " << Person[i].address << endl;
		}
	}
	system("pause");
}

void editPerson(contact * Person, int index)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	int select;
	cin >> name;

	for (int i = 0; i < index; i++)
	{
		if (name == Person[i].name)
		{
			while (true)
			{
				cout << "1 -- �޸Ĵ��˵�����" << endl;
				cout << "2 -- �޸Ĵ��˵��Ա�" << endl;
				cout << "3 -- �޸Ĵ��˵�����" << endl;
				cout << "4 -- �޸Ĵ��˵ĵ绰" << endl;
				cout << "5 -- �޸Ĵ��˵ĵ�ַ" << endl;
				cout << "0 -- �˳��༭" << endl;
				cin >> select;

				switch (select)
				{
				case 1:
					cout << "�������µ�����: " << endl;
					cin >> Person[i].name;
					break;
				case 2:
					cout << "�������µ��Ա�: " << endl;
					cin >> Person[i].sex;
					break;
				case 3:
					cout << "�������µ�����: " << endl;
					cin >> Person[i].age;
					break;
				case 4:
					cout << "�������µ���ϵ�绰: " << endl;
					cin >> Person[i].phone;
					break;
				case 5:
					cout << "�������µļ�ͥ��ַ: " << endl;
					cin >> Person[i].address;
					break;
				case 0:
					cout << "�ټ�" << endl;
					system("pause");
					return;
				default:
					break;
				}
				cout << "�޸ĳɹ�" << endl;
				system("pause");
				system("cls");
				Meun();
			}
		}
	}
	cout << "û�ҵ�����" << endl;
	system("pause");
}

void deleteAllPerson(contact * Person, int * index)
{
	cout << "��ȷ��Ҫɾ��������ϵ��? " << endl;
	cout << "���� 1 ����" << endl;
	cout << "���� 0 ȡ��" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		*index = 0;
	}
	else
	{
		cout << "�˳��ɹ�" << endl;
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
			cout << "�˳��ɹ�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������" << endl;
			system("pause");
			return 0;
			break;
		}

		system("cls");
	}

	system("pause");
	return 0;
}