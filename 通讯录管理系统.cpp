#include <iostream>
#include <string>
#define MAX 4
using namespace std;
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string Addr;
};
struct Addressbooks
{
	person pArray[MAX];
	int size;

};
void showMenu()
{
	cout << "****************************" << endl;
	cout << "*****   1.�����ϵ��   *****" << endl;
	cout << "*****   2.��ʾ��ϵ��   *****" << endl;
	cout << "*****   3.ɾ����ϵ��   *****" << endl;
	cout << "*****   4.������ϵ��   *****" << endl;
	cout << "*****   5.�޸���ϵ��   *****" << endl;
	cout << "*****   6.�����ϵ��   *****" << endl;
	cout << "*****   0.�˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;
}
void addPerson(Addressbooks* p)
{
	if (p->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		p->pArray[p->size].name = name; 
		int  Sex;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		while (true)
		{
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				p->pArray[p->size].sex = Sex;
				break;
			}
			cout << "�����������������룡" << endl;
			break;
		}
		int age;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0)
			{
				p->pArray[p->size].age = age;
				break;
			}
			cout << "���������������������룡" << endl;
			
		}
		string phone;
		cout << "��������ϵ�绰��" << endl;
		
		while (true)
		{
			cin >> phone;
			
			if (phone.size() == 11) 
			{
				p->pArray[p->size].phone = phone;
				break;
			}
			cout << "��������������������룡" << endl;
			
		}
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		p->pArray[p->size].Addr = address;
		p->size++;
		cout << "��ӳɹ�" << endl;
		
		system("pause");
		system("cls");
		
	}
}
void showPeople(Addressbooks* p)
{
	if (p->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "������" << p->pArray[i].name << "\t";
			cout << "�Ա�" << (p->pArray[i].sex == 1?"��":"Ů") << "\t";
			cout << "���䣺" << p->pArray[i].age << "\t";
			cout << "�ֻ����룺" << p->pArray[i].phone << "\t";
			cout << "��ַ��" << p->pArray[i].Addr << endl;

		}
	}
	system("pause");
	system("cls");
}
void deletePerson(Addressbooks *p)
{
	string per;
	
	
			cout << "������������" << endl;
			cin >> per;
			for (int i = 0; i < p->size; i++)
			{
				if (p->pArray[i].name.find(per)!=-1)
				{
					for (int j = i; j < p->size; j++)
					{
						if (j!=MAX-1)
						{
							p->pArray[j] = p->pArray[j + 1];
						}
					}
					p->size--;	
					cout << "ɾ���ɹ�" << endl;
				}
				
			}
			system("pause");
			return;
			
	
	
}
void findPerson(Addressbooks *ADD)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < ADD->size; i++)
	{
		if (ADD->pArray[i].name.find(name) != -1)
		{
			cout << "������" << ADD->pArray[i].name << "\t";
			cout << "�Ա�" << (ADD->pArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ADD->pArray[i].age << "\t";
			cout << "�ֻ����룺" << ADD->pArray[i].phone << "\t";
			cout << "��ַ��" << ADD->pArray[i].Addr << endl;
		}
	}
}
int main()
{
	Addressbooks abs;
	abs.size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPeople(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������ȷ���" << endl;
			break;
		}
		
	}

	system("pause");
	return 0;

}