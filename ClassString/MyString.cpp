#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
//2.	�������� ���� �String�.���� ������� ������ :
// 
//�	����������� �� ������������, �� �������� �������� ������ �������� 80 �������;
//�	�����������, �� �������� ���������� ������ ��������� ������;
//�	�����������, ���� ������� ������ � ��������� �� �������, ��������� �� �����������, �� ��������.
// 
//���� ����� ������� ������ ������ :
//�	������ - ��������;
//�	�������� ������ � ���������;
//�	��������� ������ �� �����;
//�	���������� ������ ������;
//�	������� ������ ������� ��� �������� � �������;
//�	��������� �������� ������� ��� ��������;
//�	����������� �������� � ������;
//�	����� � ����� ������� ��� �������� � ������.
// 
//� ������� main() ��������:
//�	���� �ᒺ�� ����� � ������������� ������������ �� ������������, 
//��������� ���� �� ��������� ������ ��� �������� ������ � ������� �� �����;
//�	���� �ᒺ�� ����� � ������������� ������������, 
//�� �������� ���������� ������ ��������� ������, ��������� ���� �� ��������� ������ ��� �������� ������ 
//� ������� �� �����;
//�	���� �ᒺ�� �����, ���� ���� ������� ������ � ��������� �� �������, 
//��������� �� �����������, �� �������� � ������� �� �����.

class String
{
private:
	int size = 80;
	char* str = new char[size];
public:
	String()//�	����������� �� ������������, �� �������� �������� ������ �������� 80 �������;
	{
		char* str = new char[size];
	}
	String(int size)//�	�����������, �� �������� ���������� ������ ��������� ������;
	{
		char* str = new char[size];
	}
	String(char* str)//������������, ���� ������� ������ � ��������� �� �������, ��������� �� �����������, �� ��������.
	{
		this->str = str;
	}
	void KeyboardImput()//�	�������� ������ � ���������;
	{
		cout << "������� ������ � ����������:\t";
		cin >> str;
	}
	void PrintString()//���������� ������ �� �����;
	{
		cout << "������� ������:\t";
		cout << str << endl;
	}
	void SizeString()//����������� ������ ������;
	{
		cout << "������ ������:\t";
		int length = strlen(str);
		cout << length << endl;
	}
	void EditString()//�������� ������ ������� ��� �������� � �������;
	{

	}
	void DeleteString()//���������� �������� ������� ��� ��������;
	{
		char Symbol;
		int length = strlen(str);
		char* Str = new char[256];
		int obj = 0;
		cout << "��� �� ������ �������?" << endl;
		cout << "1.������\t" << "2.���������" << endl;
		cin >> obj;
		if (obj == 1)
		{
			cout << "����� ������ �������?" << endl;
			cin >> Symbol;
			for (int i = 0; i < length; ++i)
			{
				if (str[i] == Symbol)
				{
					for (int j = i; j < length; ++j)
					{
						str[j] = str[j + 1];
					}
					break;
				}
			}
			cout << "���������:\t" << str << endl;
		}
		if (obj == 2)
		{
			cout << "����� ��������� �������?" << endl;
			cin >> Str;
			/*strcpy_s(str, strlen(Str)+1, str);*/
			string NewStr = string(str);
			string DelStr = string(Str);

			string::size_type pos = NewStr.find(DelStr);
			while (pos != string::npos)
			{
				NewStr.erase(pos, DelStr.size());
				pos = NewStr.find(DelStr, pos + 1);
			}
			cout << "���������:" << NewStr << endl;
		}
		if (obj != 1 && obj != 2)
		{
			cout << "������� �������� ��������." << endl;
		}

		delete[] Str;
	}
	void SearchString()//������������ �������� � ������;
	{

	}
	void SearchAndEddit()//������ � ����� ������� ��� �������� � ������.
	{
		//�� ���� ��� �� ����� DeleteString.
	}
	~String()
	{
		delete str;
	}
};
int main()
{
	setlocale(LC_ALL, "ru");
	int SIZE = 0;

	String Default; //�	���� �ᒺ�� ����� � ������������� ������������ �� ������������, 
	Default.KeyboardImput();//��������� ���� �� ��������� ������ ��� �������� ������
	Default.PrintString(); //� ������� �� �����.

	cout << "������� ������ ������:\t";
	cin >> SIZE;

	String AnySize(SIZE);//�� �������� ���������� ������ ��������� ������, 
	AnySize.KeyboardImput();//��������� ���� �� ��������� ������ ��� �������� ������ 
	AnySize.PrintString();//� ������� �� �����;

	char* Text = new char[256];
	cout << "������� ������:\t";
	cin >> Text;

	String MyStr(Text); //���� �ᒺ�� �����,���� ������� ������ � ��������� �� �������,
	MyStr.PrintString();//��������� �� �����������, �� �������� � ������� �� �����.

	system("pause");
	return 0;
}
