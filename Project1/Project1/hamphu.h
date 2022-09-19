#pragma once
#include"ctdl.h"
using namespace std;

int LaySoLuongDSMS(LIST_DMS l)
{
	int dem = 0;

	for (NODE_DMS* p = l.pHead; p != NULL; p = p->pNext)
		dem++;

	return dem;
}

string chuan_hoa_chuoi(string s)
{
	// xoa ky tu trong dau
	while (s.length() > 0 && s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}

	while (s.length() > 0 && s[s.length() - 1] == ' ')
	{
		s.erase(s.begin() + s.length() - 1);
	}



	// xoa 2 ky tu trong o giua
	while (s.find("  ") != string::npos)
	{
		s.erase(s.find("  "), 1);
	}
	return s;
	// chuan hoa chuoi
}

string viet_in_hoa(string s)
{
	string s1 = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s1 += ' ';
		}
		else
		{
			s1 += toupper(s[i]);
		}
	}
	return s1;
}

void them_1_tdg(tree& t, theDocGia* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->maThe > t->maThe)//data o ngoai lon hon de qui sang phai 
		{
			them_1_tdg(t->pRight, p);
		}

		else if (p->maThe < t->maThe)
		{
			them_1_tdg(t->pLeft, p);
		}
	}
}
