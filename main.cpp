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

//оптимизированный алгоритм
// огда все символы подстроки различны, мы можем сдвинуть индекс более чем на 1. 
// огда несоответствие возникает после совпадений j, мы знаем, что первый символ шаблона
//не будет соответствовать j совпадающим символам, потому что все символы подстроки различны. 
//“аким образом, мы всегда можем сдвинуть шаблон на j, не пропуска€ никаких действительных сдвигов. 

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