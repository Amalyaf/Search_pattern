#include <iostream>
#include <string>

using namespace std;

void search(const string& part, const string& txt)
{
	int m = part.size();
	int n = txt.size();
	int j = 0;
	for (int i = 0; i <= n - m; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (txt[i + j] != part[j])
				break;
		}
		if (j == m)
		{
			cout << "Pattern found at index " << i << endl;
		}
	}
}

//���������������� ��������
//����� ��� ������� ��������� ��������, �� ����� �������� ������ ����� ��� �� 1. 
//����� �������������� ��������� ����� ���������� j, �� �����, ��� ������ ������ �������
//�� ����� ��������������� j ����������� ��������, ������ ��� ��� ������� ��������� ��������. 
//����� �������, �� ������ ����� �������� ������ �� j, �� ��������� ������� �������������� �������. 

void search_optim(const string& part, const string& txt)
{
	int m = part.size();
	int n = txt.size();
	int j = 0;
	int i = 0;
	while (i <= n - m)
	{
		for (j = 0; j < m; j++)
		{
			if (txt[i + j] != part[j])
				break;
		}
		if (j == m)
		{
			cout << "Pattern found at index " << i << endl;
			i = i + m;
		}

		else if (j == 0)
		{
			i = i + 1;
		}

		else
		{
			i = i + j;
		}
	}
}


int main()
{
	string part = "abc";
	string txt = "abcdabdcabcabcabcabc";

	search(part, txt);
	cout << endl;
	search_optim(part, txt);
}