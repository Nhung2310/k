#include"dausach.h"
#include"docgia.h"
#include<Windows.h>


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}


void handleDraw(int row, int col, LIST_DS l_ds, int loop = 15, int loop2 = 1)
{
	//
	string arrMmenu[] = { "STT", "ISBN", "TEN SACH", "TAC GIA", "THE LOAI", "SO TRANG", "NAM XUAT BAN" };
	gotoxy(1, 3);
	cout << (char)218;
	int index = 1;
	int idx = 0;
	for (int i = 0; i < col - 1; ++i)
	{
		for (int k = 0; k < loop; ++k)
		{
			cout << (char)196;
		}
		cout << (char)194;
	}
	for (int k = 0; k < loop; ++k)
	{
		cout << (char)196;
	}
	cout << (char)191;
	cout << '\n';
	for (int i = 0; i < 2 * row - 1; ++i)
	{
		index = 0;
		if (i % 2 != 0)
		{
			cout << (char)195;
			for (int j = 0; j < col - 1; ++j)
			{
				for (int k = 0; k < loop; ++k)
				{
					cout << (char)196;
				}
				cout << (char)197;
			}
			for (int k = 0; k < loop; ++k)
			{
				cout << (char)196;
			}
			cout << (char)180;
		}
		else
		{
			for (int k = 0; k < loop2; ++k)
			{
				cout << (char)179;
				for (int j = 0; j < col; ++j)
				{
					if (i == 0)
					{
						cout << arrMmenu[j];
						for (int k = arrMmenu[j].length(); k < loop; ++k)
						{
							cout << ' ';
						}
					}
					else
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 1)
						{
							cout << l_ds.ds_dausach[idx]->ISBN;
							for (int k = l_ds.ds_dausach[idx]->ISBN.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 2)
						{
							cout << l_ds.ds_dausach[idx]->tensach;
							for (int k = l_ds.ds_dausach[idx]->tensach.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 3)
						{
							cout << l_ds.ds_dausach[idx]->tacgia;
							for (int k = l_ds.ds_dausach[idx]->tacgia.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 4)
						{
							cout << l_ds.ds_dausach[idx]->theloai;
							for (int k = l_ds.ds_dausach[idx]->theloai.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 5)
						{
							cout << l_ds.ds_dausach[idx]->sotrang;
							for (int k = to_string(l_ds.ds_dausach[idx]->sotrang).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 6)
						{
							cout << l_ds.ds_dausach[idx]->namxuatban;
							for (int k = to_string(l_ds.ds_dausach[idx]->namxuatban).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						/*cout << l_ds.ds_dausach[j]->ISBN;
						for (int k = arrMmenu[j].length(); k < loop; ++k)
						{
							cout << ' ';
						}*/
					}
					cout << (char)179;
				}
			}
		}
		cout << '\n';
		if (i != 0 && i % 2 == 0)
			idx++;
	}
	cout << (char)192;
	for (int i = 0; i < col - 1; ++i)
	{
		for (int k = 0; k < loop; ++k)
		{
			cout << (char)196;
		}
		cout << (char)193;
	}
	for (int k = 0; k < loop; ++k)
	{
		cout << (char)196;
	}
	cout << (char)217;
}

void inDanhSachDauSach(LIST_DS l_ds)
{
	system("cls");
	gotoxy(40, 1);
	cout << "DANH SACH DAU SACH";
	handleDraw(l_ds.sl + 1, 7, l_ds);

	gotoxy(10, 2 * l_ds.sl + 6);
	cout << "NHAN [ESC] DE THOAT";

	while (true)
	{
		char c = _getch();
		if ((int)c == 27)
		{
			return;
		}
	}
}

void ThemDauSach(LIST_DS& l_ds)
{
	system("cls");
	gotoxy(40, 1);
	cout << "THEM DAU SACH";

	string arr[] = { "ISBN", "TEN SACH", "SO TRANG", "TAC GIA", "NAM XUAT BAN", "THE LOAI" };

	int n = sizeof(arr) / sizeof(arr[0]);

	int Y = 5;

	for (int i = 0; i < n; ++i)
	{
		gotoxy(30, Y);
		cout << arr[i];

		//
		gotoxy(45, Y - 1);
		cout << (char)218;
		for (int j = 0; j < 28; ++j)
		{
			cout << (char)196;
		}
		cout << (char)191;
		gotoxy(45, Y);
		cout << (char)179;

		gotoxy(45 + 29, Y);
		cout << (char)179;

		gotoxy(45, Y + 1);
		cout << (char)192;

		for (int j = 0; j < 28; ++j)
		{
			cout << (char)196;
		}
		cout << (char)217;

		Y += 3;
	}

	int idx = 0;

	DAUSACH* ds = new DAUSACH();//KHAI CAO Ô NHƠ CẦN THÊM

	Y = 5;

	bool check = false;
	do
	{
		gotoxy(45 + 1, Y);

		cout << "                          ";

		gotoxy(45 + 1, Y);
		getline(cin, ds->ISBN);

		ds->ISBN = chuan_hoa_chuoi(ds->ISBN);
		ds->ISBN = viet_in_hoa(ds->ISBN);

		gotoxy(45 + 1, Y);
		cout << ds->ISBN;

		if (ds->ISBN == "")//MÃ RỖNG
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "MA KHONG DUOC RONG";
		}
		else if (kt_trung_ISBN(ds->ISBN, l_ds) != -1)//KIỂM TRA MÃ TRÙNG
		{
			check = false;//
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "MA KHONG TRUNG";
		}
		else if (ds->ISBN.length() > 7)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "ISBN DAI TOI DA 7 KY TU";
		}
		else
		{
			gotoxy(80, Y);
			cout << "                                   ";
			check = true;
		}

	} while (check == false);


	Y += 3;
	gotoxy(45 + 1, Y);

	check = false;
	do
	{
		gotoxy(45 + 1, Y);

		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, ds->tensach);

		ds->tensach = chuan_hoa_chuoi(ds->tensach);//"     " ---> ""
		ds->tensach = viet_in_hoa(ds->tensach);//MS1--> NGUOI DUNG NHAP: ms1->MS1

		gotoxy(45 + 1, Y);
		cout << ds->tensach;

		if (ds->tensach == "")//RỖNG
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "TEN SACH KHONG DUOC RONG";
		}
		else if (ds->tensach.length() > 24)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "TEN SACH DAI TOI DA 24 KY TU";
		}
		else
		{
			gotoxy(80, Y);
			cout << "                                   ";
			check = true;
		}

	} while (check == false);


	Y += 3;
	string sotrang = "";
	check = false;
	do
	{
		gotoxy(45 + 1, Y);
		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, sotrang);

		check = checkDegit(sotrang);

		gotoxy(45 + 1, Y);
		cout << "                          ";

		gotoxy(45 + 1, Y);
		cout << sotrang;
		if (sotrang == "")
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "SO TRANG KHONG DUOC RONG";
		}
		else if (check == false)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "SO TRANG KHONG HOP LE";
		}
		else if (atoi((char*)sotrang.c_str()) == 0)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "SO TRANG LON HON KHONG";
		}
		else if (atoi((char*)sotrang.c_str()) > 999999)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "SO TRANG QUA GIO HAN";
		}
		else
		{
			ds->sotrang = atoi((char*)sotrang.c_str());
			gotoxy(80, Y);
			cout << "                                   ";
			check = true;
		}
	} while (check == false);


	Y += 3;
	gotoxy(45 + 1, Y);
	check = false;
	do
	{
		gotoxy(45 + 1, Y);

		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, ds->tacgia);


		ds->tacgia = chuan_hoa_chuoi(ds->tacgia);
		ds->tacgia = viet_in_hoa(ds->tacgia);

		gotoxy(45 + 1, Y);
		cout << ds->tacgia;

		if (ds->tacgia == "")
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "TEN TAC GIA KHONG DUOC RONG";
		}
		else if (ds->tacgia.length() > 17)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "TEN TAC GIA TOI DA 17 KY TU";
		}
		else
		{
			gotoxy(80, Y);
			cout << "                                   ";
			check = true;
		}

	} while (check == false);

	Y += 3;
	gotoxy(45 + 1, Y);
	string namxb = "";
	check = false;
	do
	{
		gotoxy(45 + 1, Y);
		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, namxb);

		check = checkDegit(namxb);

		gotoxy(45 + 1, Y);
		cout << "                          ";

		gotoxy(45 + 1, Y);
		cout << namxb;
		if (namxb == "")
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "NAM XUAT BAN KHONG DUOC RONG";
		}
		else if (check == false)
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "NAM XUAT BAN KHONG HOP LE";
		}
		else if (atoi((char*)namxb.c_str()) == 0)
		{
			//		cout << '|' << atoi((char*)namxb.c_str());
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "NAM XUAT BAN LON HON KHONG";
		}
		else
		{
			time_t current_time;
			struct tm  local_time;

			time(&current_time);
			localtime_s(&local_time, &current_time);

			int Year = local_time.tm_year + 1900;

			if (atoi((char*)namxb.c_str()) > Year)
			{
				check = false;
				gotoxy(80, Y);
				cout << "                                   ";
				gotoxy(80, Y);
				cout << "NAM XUAT BAN <= NAM HIEN TAI";
			}
			else
			{
				ds->namxuatban = atoi((char*)namxb.c_str());
				gotoxy(80, Y);
				cout << "                                   ";
				check = true;

			}
		}
	} while (check == false);

	rewind(stdin);
	Y += 3;
	gotoxy(45 + 1, Y);
	check = false;
	do
	{
		gotoxy(45 + 1, Y);

		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, ds->theloai);



		ds->theloai = chuan_hoa_chuoi(ds->theloai);
		ds->theloai = viet_in_hoa(ds->theloai);

		gotoxy(45 + 1, Y);
		cout << ds->theloai;

		if (ds->theloai == "")
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "THE LOAI KHONG DUOC RONG";
		}
		else
		{
			gotoxy(80, Y);
			cout << "                                   ";
			check = true;
		}

	} while (check == false);

	int luachon = -1;
	while (true)
	{

		gotoxy(45, Y + 4);
		cout << "                                                                                 ";

		gotoxy(45, Y + 4);
		cout << "BAN CO MUON LUU KHONG [1: CO], [0: KHONG]: ";
		cin >> luachon;
		if (luachon != 0 && luachon != 1)
		{
			gotoxy(45, Y + 5);
			cout << "LUA CHON KHONG HOP LE";
		}
		else if (luachon == 1)
		{
			themDauSach(l_ds, ds);
			//ghi file (not done)
			ghi_file_ds_dau_sach(l_ds);
			return;
		}
		else
		{
			return;
		}
	}
}

void hienThiMenuQuanLyDauSach(string arrMenu[], int n)
{
	system("cls");

	//ĐỔI MÀU NỀN GIAO DIỆN
	textcolor(188);
	for (int i = 0; i < 90; ++i)
	{
		for (int j = 0; j < 50; ++j)
			cout << ' ';
	}

	gotoxy(50, 2);
	textcolor(177);
	cout << "QUAN LY DAU SACH\n";
	textcolor(7);
	
	cout << "\t\t\t\t NHAN [ESC] DE THOAT";
	textcolor(199);
	gotoxy(45, 6);
	cout << (char)218;
	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}
	cout << (char)191;

	gotoxy(45, 7);
	cout << (char)179;


	gotoxy(46, 7);
	textcolor(192);
	cout << ' ';
	cout << arrMenu[0];
	gotoxy(46 + arrMenu[0].length() + 1, 7);
	for (int p = arrMenu[0].length() + 1; p < 24; ++p)
		cout << ' ';
	textcolor(199);

	gotoxy(45 + 25, 7);
	cout << (char)179;

	int temp = 1;//XUỐNG DÒNG
	for (int i = 1; i < n; ++i)
	{
		gotoxy(45, 7 + temp);
		cout << (char)195;
		for (int j = 0; j < 24; ++j)
		{
			cout << (char)196;
		}
		cout << (char)180;
		cout << '\n';

		gotoxy(45, 7 + temp + 1);
		cout << (char)179;

		textcolor(192);
		gotoxy(46, 7 + temp + 1);
		cout << ' ';
		cout << arrMenu[i];
		gotoxy(46 + arrMenu[i].length() + 1, 7 + temp + 1);
		for (int p = arrMenu[i].length(); p < 24; ++p)
			cout << ' ';
		textcolor(199);

		gotoxy(45 + 25, 7 + temp + 1);
		cout << (char)179;

		temp += 2;

		cout << '\n';
	}
	gotoxy(45, 7 + temp);
	cout << (char)192;

	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}

	cout << (char)217;
}

void hienThiMenuQuanLyDocGia(string arrMenu[], int n)
{
	system("cls");

	//ĐỔI MÀU NỀN GIAO DIỆN
	textcolor(188);
	for (int i = 0; i < 90; ++i)
	{
		for (int j = 0; j < 50; ++j)
			cout << ' ';
	}

	gotoxy(50, 2);
	textcolor(177);
	cout << "QUAN LY DOC GIA \n";
	textcolor(7);

	cout << "\t\t\t\t\NHAN [ESC] DE THOAT";
	textcolor(199);
	gotoxy(45, 6);
	cout << (char)218;
	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}
	cout << (char)191;

	gotoxy(45, 7);
	cout << (char)179;


	gotoxy(46, 7);
	textcolor(192);
	cout << ' ';
	cout << arrMenu[0];
	gotoxy(46 + arrMenu[0].length() + 1, 7);
	for (int p = arrMenu[0].length() + 1; p < 24; ++p)
		cout << ' ';
	textcolor(199);

	gotoxy(45 + 25, 7);
	cout << (char)179;

	int temp = 1;//XUỐNG DÒNG
	for (int i = 1; i < n; ++i)
	{
		gotoxy(45, 7 + temp);
		cout << (char)195;
		for (int j = 0; j < 24; ++j)
		{
			cout << (char)196;
		}
		cout << (char)180;
		cout << '\n';

		gotoxy(45, 7 + temp + 1);
		cout << (char)179;

		textcolor(192);
		gotoxy(46, 7 + temp + 1);
		cout << ' ';
		cout << arrMenu[i];
		gotoxy(46 + arrMenu[i].length() + 1, 7 + temp + 1);
		for (int p = arrMenu[i].length(); p < 24; ++p)
			cout << ' ';
		textcolor(199);

		gotoxy(45 + 25, 7 + temp + 1);
		cout << (char)179;

		temp += 2;

		cout << '\n';
	}
	gotoxy(45, 7 + temp);
	cout << (char)192;

	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}

	cout << (char)217;
}

void HienThiThemMotDauSach(LIST_DS& l, int idx)
{
	system("cls");
	gotoxy(40, 1);
	cout << "NHAP THONG TIN DANH MUC SACH";

	danhmucsach ms;
	ms.masach = l.ds_dausach[idx]->ISBN + to_string(LaySoLuongDSMS(l.ds_dausach[idx]->dms));
	string arr[] = { "MA MUC SACH", "TRANG THAI", "VI TRI" };

	int n = sizeof(arr) / sizeof(arr[0]);

	int Y = 5;

	for (int i = 0; i < n; ++i)
	{
		gotoxy(30, Y);
		cout << arr[i];

		//
		gotoxy(45, Y - 1);
		cout << (char)218;
		for (int j = 0; j < 28; ++j)
		{
			cout << (char)196;
		}
		cout << (char)191;
		gotoxy(45, Y);
		cout << (char)179;

		gotoxy(45 + 29, Y);
		cout << (char)179;

		gotoxy(45, Y + 1);
		cout << (char)192;

		for (int j = 0; j < 28; ++j)
		{
			cout << (char)196;
		}
		cout << (char)217;

		Y += 3;
	}

	int i = 0;

	Y = 5;

	gotoxy(45 + 1, Y);
	cout << ms.masach;

	Y += 3;
	gotoxy(45 + 1, Y);

	gotoxy(75, Y);
	cout << "0:MUON DUOC | 1:CO DOC GIA | 2:THANH LY";
	gotoxy(80, Y);

	string trangthai = "";
	bool check = false;
	do
	{
		gotoxy(45 + 1, Y);
		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, trangthai);

		check = checkDegit(trangthai);

		gotoxy(45 + 1, Y);
		cout << "                          ";

		gotoxy(45 + 1, Y);
		cout << trangthai;
		if (trangthai == "")
		{
			check = false;
			gotoxy(75, Y);
			cout << "                                        ";
			gotoxy(75, Y);
			cout << "TRANG THAI KHONG DUOC RONG";
		}
		else if (check == false)
		{
			check = false;
			gotoxy(75, Y);
			cout << "                                       ";
			gotoxy(75, Y);
			cout << "SO TRANG KHONG HOP LE";
		}
		else if (atoi((char*)trangthai.c_str()) > 2)
		{
			check = false;
			gotoxy(75, Y);
			cout << "                                       ";
			gotoxy(75, Y);
			cout << "TRANG THAI THUOC [0-2]";
		}
		else if (atoi((char*)trangthai.c_str()) > 2)
		{
			check = false;
			gotoxy(75, Y);
			cout << "                                        ";
			gotoxy(75, Y);
			cout << "TRANG THAI KHONG HOP LE";
		}
		else
		{
			ms.trangthai = atoi((char*)trangthai.c_str());
			gotoxy(75, Y);
			cout << "                                     ";
			check = true;
		}

		Sleep(1000);

		gotoxy(75, Y);
		cout << "0:MUON DUOC | 1:CO DOC GIA | 2:THANH LY";

	} while (check == false);


	Y += 3;
	gotoxy(45 + 1, Y);
	check = false;
	do
	{
		gotoxy(45 + 1, Y);

		cout << "                          ";
		gotoxy(45 + 1, Y);
		getline(cin, ms.vitri);


		ms.vitri = chuan_hoa_chuoi(ms.vitri);
		ms.vitri = viet_in_hoa(ms.vitri);

		gotoxy(45 + 1, Y);
		cout << ms.vitri;

		if (ms.vitri == "")
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "VI TRI KHONG DUOC RONG";
		}
		else if (ms.vitri.length() > 17)
		{
			check = false;
			gotoxy(75, Y);
			cout << "                                   ";
			gotoxy(75, Y);
			cout << "VI TRI GIA TOI DA 17 KY TU";
		}
		else
		{
			gotoxy(75, Y);
			cout << "                                   ";
			check = true;
		}

	} while (check == false);

	rewind(stdin);
	int luachon = -1;
	while (true)
	{
		gotoxy(45, Y + 4);
		cout << "                                                                                 ";

		gotoxy(45, Y + 4);
		cout << "BAN CO MUON LUU KHONG [1: CO], [0: KHONG]: ";
		cin >> luachon;
		if (luachon != 0 && luachon != 1)
		{
			gotoxy(45, Y + 5);
			cout << "LUA CHON KHONG HOP LE";
		}
		else if (luachon == 1)
		{
			them_dms(l.ds_dausach[idx]->dms, ms);
			//ghi file (not done)
			ghi_file_ds_dau_sach(l);
			return;
		}
		else
		{
			return;
		}
	}

}
void xuLyThemDanhMucSach(LIST_DS& l)
{
	system("cls");

	gotoxy(40, 1);
	cout << "CHON DAU SACH CAN THEM DANH MUC SACH";

	handleDraw(l.sl + 1, 7, l);

	int idx = -1;//, indxOld = -1;

	int x = 6;

	char c;

	while (true)
	{
		c = _getch();
		if ((int)c == -32)
		{
			c = _getch();
			if ((int)c == 72)//lenh
			{
				if (idx > 0)
				{
					if (idx != -1)
					{
						gotoxy(2, x + idx * 2);
						for (int j = 0; j < 7; ++j)
						{
							if (j == 0)//STT
							{
								cout << idx + 1;
								for (int k = to_string(idx + 1).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 1)
							{
								cout << l.ds_dausach[idx]->ISBN;
								for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 2)
							{
								cout << l.ds_dausach[idx]->tensach;
								for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 3)
							{
								cout << l.ds_dausach[idx]->tacgia;
								for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 4)
							{
								cout << l.ds_dausach[idx]->theloai;
								for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 5)
							{
								cout << l.ds_dausach[idx]->sotrang;
								for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 6)
							{
								cout << l.ds_dausach[idx]->namxuatban;
								for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
								{
									cout << ' ';
								}
							}
						}
					}
					idx--;

					gotoxy(2, x + idx * 2);
					textcolor(116);
					for (int j = 0; j < 7; ++j)
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 1)
						{
							cout << l.ds_dausach[idx]->ISBN;
							for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 2)
						{
							cout << l.ds_dausach[idx]->tensach;
							for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 3)
						{
							cout << l.ds_dausach[idx]->tacgia;
							for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 4)
						{
							cout << l.ds_dausach[idx]->theloai;
							for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 5)
						{
							cout << l.ds_dausach[idx]->sotrang;
							for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 6)
						{
							cout << l.ds_dausach[idx]->namxuatban;
							for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
							{
								cout << ' ';
							}
						}
					}
					textcolor(199);
				}
			}
			else if ((int)c == 80)//xuong
			{
				if (idx < l.sl - 1)
				{
					if (idx != -1)
					{
						gotoxy(2, x + idx * 2);
						for (int j = 0; j < 7; ++j)
						{
							if (j == 0)//STT
							{
								cout << idx + 1;
								for (int k = to_string(idx + 1).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 1)
							{
								cout << l.ds_dausach[idx]->ISBN;
								for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 2)
							{
								cout << l.ds_dausach[idx]->tensach;
								for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 3)
							{
								cout << l.ds_dausach[idx]->tacgia;
								for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 4)
							{
								cout << l.ds_dausach[idx]->theloai;
								for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 5)
							{
								cout << l.ds_dausach[idx]->sotrang;
								for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 6)
							{
								cout << l.ds_dausach[idx]->namxuatban;
								for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
								{
									cout << ' ';
								}
							}
						}
					}
					idx++;

					gotoxy(2, x + idx * 2);
					textcolor(116);
					for (int j = 0; j < 7; ++j)
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 1)
						{
							cout << l.ds_dausach[idx]->ISBN;
							for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 2)
						{
							cout << l.ds_dausach[idx]->tensach;
							for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 3)
						{
							cout << l.ds_dausach[idx]->tacgia;
							for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 4)
						{
							cout << l.ds_dausach[idx]->theloai;
							for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 5)
						{
							cout << l.ds_dausach[idx]->sotrang;
							for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 6)
						{
							cout << l.ds_dausach[idx]->namxuatban;
							for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
							{
								cout << ' ';
							}
						}
					}
					textcolor(199);
				}
			}
		}
		else if ((int)c == 13 && idx != -1)
		{
			HienThiThemMotDauSach(l, idx);
			return;
		}
		else if ((int)c == 27)
		{
			return;
		}
	}
}

void handleDrawDMS(int row, int col, LIST_DS l, int idxDauSach, int loop = 15, int loop2 = 1)
{
	//
	string arrMmenu[] = { "STT", "MA MUC SACH", "TRANG THAI", "VI TRI" };
	gotoxy(1, 3);
	cout << (char)218;

	int index = 1;
	int idx = 0;

	NODE_DMS* p = l.ds_dausach[idxDauSach]->dms.pHead;

	for (int i = 0; i < col - 1; ++i)
	{
		for (int k = 0; k < loop; ++k)
		{
			cout << (char)196;
		}
		cout << (char)194;
	}
	for (int k = 0; k < loop; ++k)
	{
		cout << (char)196;
	}
	cout << (char)191;
	cout << '\n';
	for (int i = 0; i < 2 * row - 1; ++i)
	{
		index = 0;
		if (i % 2 != 0)
		{
			cout << (char)195;
			for (int j = 0; j < col - 1; ++j)
			{
				for (int k = 0; k < loop; ++k)
				{
					cout << (char)196;
				}
				cout << (char)197;
			}
			for (int k = 0; k < loop; ++k)
			{
				cout << (char)196;
			}
			cout << (char)180;
		}
		else
		{
			for (int k = 0; k < loop2; ++k)
			{
				cout << (char)179;
				for (int j = 0; j < col; ++j)
				{
					if (i == 0)
					{
						cout << arrMmenu[j];
						for (int k = arrMmenu[j].length(); k < loop; ++k)
						{
							cout << ' ';
						}
					}
					else
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 1)
						{
							cout << p->data.masach;
							for (int k = p->data.masach.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 2)
						{
							string temp = "";
							if (p->data.trangthai == 0)
								temp = "MUON DUOC";
							else if (p->data.trangthai == 1)
								temp = "CO DOC GIA";
							else
								temp = "THANH LY";
							cout << temp;
							for (int k = temp.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 3)
						{
							cout << p->data.vitri;
							for (int k = p->data.vitri.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
					}
					cout << (char)179;
				}
			}
		}
		cout << '\n';
		if (i != 0 && i % 2 == 0)
		{
			p = p->pNext;
			idx++;
		}
	}
	cout << (char)192;
	for (int i = 0; i < col - 1; ++i)
	{
		for (int k = 0; k < loop; ++k)
		{
			cout << (char)196;
		}
		cout << (char)193;
	}
	for (int k = 0; k < loop; ++k)
	{
		cout << (char)196;
	}
	cout << (char)217;
}
void HienThiXemMotDauSach(LIST_DS& l, int idx)
{
	system("cls");
	gotoxy(40, 1);
	cout << "DANH SACH DAU SACH";
	handleDrawDMS(LaySoLuongDSMS(l.ds_dausach[idx]->dms) + 1, 4, l, idx);

	gotoxy(10, 2 * LaySoLuongDSMS(l.ds_dausach[idx]->dms) + 6);
	cout << "NHAN [ESC] DE THOAT";

	while (true)
	{
		char c = _getch();
		if ((int)c == 27)
		{
			return;
		}
	}
}

void HienThiThongTinDauSachTK(LIST_DS& l, string tenSach, int dem)
{
	string ten_sach;
	int* arrTemp = new int[dem];
	int couter = 0;
	for (int i = 0; i < l.sl; ++i)
	{

		if (l.ds_dausach[i]->tensach == tenSach)
			arrTemp[couter++] = i;
	}
	couter = 0;
	int col = 7;
	int loop = 15;

	int row = dem + 1;
	int loop2 = 1;

	string arrMmenu[] = { "STT", "ISBN", "TEN SACH", "TAC GIA", "THE LOAI", "SO TRANG", "NAM XUAT BAN" };
	gotoxy(1, 3);
	cout << (char)218;
	int index = 1;
	int idx = 0;
	for (int i = 0; i < col - 1; ++i)
	{
		for (int k = 0; k < loop; ++k)
		{
			cout << (char)196;
		}
		cout << (char)194;
	}
	for (int k = 0; k < loop; ++k)
	{
		cout << (char)196;
	}
	cout << (char)191;
	cout << '\n';
	for (int i = 0; i < 2 * row - 1; ++i)
	{
		index = 0;
		if (i % 2 != 0)
		{
			cout << (char)195;
			for (int j = 0; j < col - 1; ++j)
			{
				for (int k = 0; k < loop; ++k)
				{
					cout << (char)196;
				}
				cout << (char)197;
			}
			for (int k = 0; k < loop; ++k)
			{
				cout << (char)196;
			}
			cout << (char)180;
		}
		else
		{
			for (int k = 0; k < loop2; ++k)
			{
				cout << (char)179;
				for (int j = 0; j < col; ++j)
				{
					if (i == 0)
					{
						cout << arrMmenu[j];
						for (int k = arrMmenu[j].length(); k < loop; ++k)
						{
							cout << ' ';
						}
					}
					else
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 1)
						{
							cout << l.ds_dausach[arrTemp[couter]]->ISBN;
							for (int k = l.ds_dausach[arrTemp[couter]]->ISBN.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 2)
						{
							cout << l.ds_dausach[arrTemp[couter]]->tensach;
							for (int k = l.ds_dausach[arrTemp[couter]]->tensach.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 3)
						{
							cout << l.ds_dausach[arrTemp[couter]]->tacgia;
							for (int k = l.ds_dausach[arrTemp[couter]]->tacgia.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 4)
						{
							cout << l.ds_dausach[arrTemp[couter]]->theloai;
							for (int k = l.ds_dausach[arrTemp[couter]]->theloai.length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 5)
						{
							cout << l.ds_dausach[arrTemp[couter]]->sotrang;
							for (int k = to_string(l.ds_dausach[arrTemp[couter]]->sotrang).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						else if (j == 6)
						{
							cout << l.ds_dausach[arrTemp[couter]]->namxuatban;
							for (int k = to_string(l.ds_dausach[arrTemp[couter]]->namxuatban).length(); k < loop; ++k)
							{
								cout << ' ';
							}
						}
						/*cout << l_ds.ds_dausach[j]->ISBN;
						for (int k = arrMmenu[j].length(); k < loop; ++k)
						{
							cout << ' ';
						}*/
					}
					cout << (char)179;
				}
			}
		}
		cout << '\n';
		if (i != 0 && i % 2 == 0)
		{
			idx++;
			couter++;
		}
	}
	cout << (char)192;
	for (int i = 0; i < col - 1; ++i)
	{
		for (int k = 0; k < loop; ++k)
		{
			cout << (char)196;
		}
		cout << (char)193;
	}
	for (int k = 0; k < loop; ++k)
	{
		cout << (char)196;
	}
	cout << (char)217;

	char c;
	while (true)
	{
		c = _getch();

		if ((int)c == 27)
		{
			return;
		}
	}
}

void TimKiemThongTinDS(LIST_DS& l)
{
	system("cls");
	gotoxy(40, 1);
	cout << "NHAP MA SACH CAM TIM KIEM (NHAN ESC DE THOAT)";

	int Y = 5;

	gotoxy(30, Y);
	cout << "TEN SACH";

	//
	gotoxy(45, Y - 1);
	cout << (char)218;
	for (int j = 0; j < 28; ++j)
	{
		cout << (char)196;
	}
	cout << (char)191;
	gotoxy(45, Y);
	cout << (char)179;

	gotoxy(45 + 29, Y);
	cout << (char)179;

	gotoxy(45, Y + 1);
	cout << (char)192;

	for (int j = 0; j < 28; ++j)
	{
		cout << (char)196;
	}
	cout << (char)217;


	bool check = false;

	char c;

	string tenSach = "";
	do
	{
		gotoxy(45 + 1, Y);

		cout << "                          ";

		gotoxy(45 + 1, Y);
		getline(cin, tenSach);

		tenSach = chuan_hoa_chuoi(tenSach);
		tenSach = viet_in_hoa(tenSach);

		gotoxy(45 + 1, Y);
		cout << tenSach;

		if (tenSach == "")//MÃ RỖNG
		{
			check = false;
			gotoxy(80, Y);
			cout << "                                   ";
			gotoxy(80, Y);
			cout << "TEN KHONG DUOC RONG";
		}
		else
		{
			int dem = 0;
			for (int i = 0; i < l.sl; ++i)
			{
				if (l.ds_dausach[i]->tensach == tenSach)
					dem++;
			}
			if (dem == 0)
			{
				gotoxy(80, Y);
				cout << "                                   ";
				gotoxy(80, Y);
				cout << "KHONG TON TAI TEN SACH";
			}
			else
			{
				HienThiThongTinDauSachTK(l, tenSach, dem);
				return;
			}
			check = true;
		}

		c = _getch();
		if ((int)c == 27)
		{
			return;
		}
	} while (check == true);
}

void XuLyHienThiMucSach(LIST_DS& l)
{
	system("cls");

	gotoxy(40, 1);
	cout << "CHON DAU SACH CAN HIEN THI DANH SACH MUC SACH";

	handleDraw(l.sl + 1, 7, l);

	int idx = -1;//, indxOld = -1;

	int x = 6;

	char c;

	while (true)
	{
		c = _getch();
		if ((int)c == -32)
		{
			c = _getch();
			if ((int)c == 72)//lenh
			{
				if (idx > 0)
				{
					if (idx != -1)
					{
						gotoxy(2, x + idx * 2);
						for (int j = 0; j < 7; ++j)
						{
							if (j == 0)//STT
							{
								cout << idx + 1;
								for (int k = to_string(idx + 1).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 1)
							{
								cout << l.ds_dausach[idx]->ISBN;
								for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 2)
							{
								cout << l.ds_dausach[idx]->tensach;
								for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 3)
							{
								cout << l.ds_dausach[idx]->tacgia;
								for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 4)
							{
								cout << l.ds_dausach[idx]->theloai;
								for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 5)
							{
								cout << l.ds_dausach[idx]->sotrang;
								for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 6)
							{
								cout << l.ds_dausach[idx]->namxuatban;
								for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
								{
									cout << ' ';
								}
							}
						}
					}
					idx--;

					gotoxy(2, x + idx * 2);
					textcolor(116);
					for (int j = 0; j < 7; ++j)
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 1)
						{
							cout << l.ds_dausach[idx]->ISBN;
							for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 2)
						{
							cout << l.ds_dausach[idx]->tensach;
							for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 3)
						{
							cout << l.ds_dausach[idx]->tacgia;
							for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 4)
						{
							cout << l.ds_dausach[idx]->theloai;
							for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 5)
						{
							cout << l.ds_dausach[idx]->sotrang;
							for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 6)
						{
							cout << l.ds_dausach[idx]->namxuatban;
							for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
							{
								cout << ' ';
							}
						}
					}
					textcolor(199);
				}
			}
			else if ((int)c == 80)//xuong
			{
				if (idx < l.sl - 1)
				{
					if (idx != -1)
					{
						gotoxy(2, x + idx * 2);
						for (int j = 0; j < 7; ++j)
						{
							if (j == 0)//STT
							{
								cout << idx + 1;
								for (int k = to_string(idx + 1).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 1)
							{
								cout << l.ds_dausach[idx]->ISBN;
								for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 2)
							{
								cout << l.ds_dausach[idx]->tensach;
								for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 3)
							{
								cout << l.ds_dausach[idx]->tacgia;
								for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 4)
							{
								cout << l.ds_dausach[idx]->theloai;
								for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 5)
							{
								cout << l.ds_dausach[idx]->sotrang;
								for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
								{
									cout << ' ';
								}
								cout << (char)179;
							}
							else if (j == 6)
							{
								cout << l.ds_dausach[idx]->namxuatban;
								for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
								{
									cout << ' ';
								}
							}
						}
					}
					idx++;

					gotoxy(2, x + idx * 2);
					textcolor(116);
					for (int j = 0; j < 7; ++j)
					{
						if (j == 0)//STT
						{
							cout << idx + 1;
							for (int k = to_string(idx + 1).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 1)
						{
							cout << l.ds_dausach[idx]->ISBN;
							for (int k = l.ds_dausach[idx]->ISBN.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 2)
						{
							cout << l.ds_dausach[idx]->tensach;
							for (int k = l.ds_dausach[idx]->tensach.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 3)
						{
							cout << l.ds_dausach[idx]->tacgia;
							for (int k = l.ds_dausach[idx]->tacgia.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 4)
						{
							cout << l.ds_dausach[idx]->theloai;
							for (int k = l.ds_dausach[idx]->theloai.length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 5)
						{
							cout << l.ds_dausach[idx]->sotrang;
							for (int k = to_string(l.ds_dausach[idx]->sotrang).length(); k < 15; ++k)
							{
								cout << ' ';
							}
							cout << (char)179;
						}
						else if (j == 6)
						{
							cout << l.ds_dausach[idx]->namxuatban;
							for (int k = to_string(l.ds_dausach[idx]->namxuatban).length(); k < 15; ++k)
							{
								cout << ' ';
							}
						}
					}
					textcolor(199);
				}
			}
		}
		else if ((int)c == 13 && idx != -1)
		{
			HienThiXemMotDauSach(l, idx);
			return;
		}
		else if ((int)c == 27)
		{
			return;
		}
	}
}

void quanLyDauSach(LIST_DS& l_ds)
{
	string arrMenu[] = { "Them dau sach",
						"Hien thi cac dau sach",
						"Them danh muc sach",
						"Hien thi danh muc sach",
						"Tim thong tin sach",
						"Sap xep sach tang dan",
	};
	int n = sizeof(arrMenu) / sizeof(arrMenu[0]);

	hienThiMenuQuanLyDauSach(arrMenu, n);

	//CHỈ SỐ CHỌN MENU
	int idx = -1;//VỊ TRÍ ĐANG CHỌN
	int idxOld = -1;//
	char c;
	while (true)
	{
		c = _getch();
		//cout << (int)c << '\n';
		if ((int)c == -32)
		{
			c = _getch();
			if ((int)c == 72)//lenh
			{
				if (idx > 0)
				{
					idxOld = idx;
					idx--;

					if (idxOld != -1)
					{
						textcolor(192);
						gotoxy(46, 7 + 2 * idxOld);
						cout << ' ';
						cout << arrMenu[idxOld];
						gotoxy(46 + arrMenu[idxOld].length() + 1, 7 + 2 * idxOld);
						for (int p = arrMenu[idxOld].length() + 1; p < 24; ++p)
							cout << ' ';
						textcolor(199);
					}

					//DOI MÀU VỊ TRÍ HIỆN TẠI
					textcolor(116);
					gotoxy(46, 7 + 2 * idx);
					cout << ' ';
					cout << arrMenu[idx];
					gotoxy(46 + arrMenu[idx].length() + 1, 7 + 2 * idx);
					for (int p = arrMenu[idx].length() + 1; p < 24; ++p)
						cout << ' ';
					textcolor(199);
				}
			}
			else if ((int)c == 80)//xuong
			{
				if (idx < n - 1)
				{
					idxOld = idx;
					idx++;

					if (idxOld != -1)
					{
						textcolor(192);
						gotoxy(46, 7 + 2 * idxOld);
						cout << ' ';
						cout << arrMenu[idxOld];
						gotoxy(46 + arrMenu[idxOld].length() + 1, 7 + 2 * idxOld);
						for (int p = arrMenu[idxOld].length() + 1; p < 24; ++p)
							cout << ' ';
						textcolor(199);
					}

					textcolor(116);
					gotoxy(46, 7 + 2 * idx);
					cout << ' ';
					cout << arrMenu[idx];
					gotoxy(46 + arrMenu[idx].length() + 1, 7 + 2 * idx);
					for (int p = arrMenu[idx].length() + 1; p < 24; ++p)
						cout << ' ';
					textcolor(199);
				}
			}
		}
		else if ((int)c == 13 && idx != -1)//enter
		{
			if (idx == 0)
			{
				ThemDauSach(l_ds);
				hienThiMenuQuanLyDauSach(arrMenu, n);

			}
			else if (idx == 1)
			{
				inDanhSachDauSach(l_ds);
				hienThiMenuQuanLyDauSach(arrMenu, n);
			}
			else if (idx == 2)
			{
				xuLyThemDanhMucSach(l_ds);
				hienThiMenuQuanLyDauSach(arrMenu, n);
			}
			else if (idx == 3)
			{
				XuLyHienThiMucSach(l_ds);
				hienThiMenuQuanLyDauSach(arrMenu, n);
			}
			else if (idx == 4)
			{
				TimKiemThongTinDS(l_ds);
				hienThiMenuQuanLyDauSach(arrMenu, n);
			}
			else if (idx == 5)//sắp xếp
			{
				sap_xep_ds_theo_ten(l_ds);
				inDanhSachDauSach(l_ds);
				hienThiMenuQuanLyDauSach(arrMenu, n);
			}
		}
		//else if ((int)c == )
		if ((int)c == 27)
			return;
	}
}

void ThemDocGia(DS_THE_DOC_GIA dsDocGia)
{
	system("cls");

	gotoxy(50, 2);

	cout << "NHAP THONG TIN DOC GIA";

	theDocGia* p = khoi_tao_node_doc_gia();

	gotoxy(50, 5);

	p->maThe = tao_ma_dg(dsDocGia.TREE);
	cout << "Ma the doc gia: " << p->maThe << endl;
	//cin.ignore();

	rewind(stdin);

	do
	{
		gotoxy(50, 6);
		cout << "Nhap ho:"; getline(cin, p->ho);
		p->ho = viet_in_hoa(chuan_hoa_chuoi(p->ho));
	} while (p->ho == "");


	do
	{
		gotoxy(50, 7);
		cout << "Nhap ten:"; getline(cin, p->ten);
		p->ten = viet_in_hoa(chuan_hoa_chuoi(p->ten));
	} while (p->ten == "");

	do
	{
		gotoxy(50, 8);
		cout << "                                                                               ";
		gotoxy(50, 8);
		cout << "Nhap gioi tinh (NAM - NU): "; getline(cin, p->phai);

		p->phai = viet_in_hoa(chuan_hoa_chuoi(p->phai));
	} while (p->phai != "NU" && p->phai != "NAM");

	gotoxy(30, 9);
	cout << " Trang thai the = 0 khi the bi khoa, trang thai the = 1 khi the hoat dong  " << endl;

	do
	{
		gotoxy(50, 10);
		cout << "                                                                                                 ";

		gotoxy(50, 10);
		cout << "Nhap trang thai:";

		getline(cin, p->trangThai);

	} while (p->trangThai != "0" && p->trangThai != "1");

	int luachon = -1;
	int Y = 10;
	while (true)
	{

		gotoxy(45, Y + 4);
		cout << "                                                                                 ";

		gotoxy(45, Y + 4);
		cout << "BAN CO MUON LUU KHONG [1: CO], [0: KHONG]: ";
		cin >> luachon;
		if (luachon != 0 && luachon != 1)
		{
			gotoxy(45, Y + 5);
			cout << "LUA CHON KHONG HOP LE";
		}
		else if (luachon == 1)
		{
			//themDauSach(l_ds, ds);
			//ghi file (not done)
			//ghi_file_ds_dau_sach(l_ds);

			them_1_tdg(dsDocGia.TREE, p);
			ghi_file_tdg(dsDocGia);
			return;
		}
		else
		{
			return;
		}
	}
}

void QuanLyDocGia(DS_THE_DOC_GIA dsDocGia)
{
	string arrMenu[] = { "Them the doc gia",
						"In theo ten ho",
						"In theo  ma tang",
						"Xoa the doc gia",
						"Hieu chinh doc gia",
	};
	int n = sizeof(arrMenu) / sizeof(arrMenu[0]);


	hienThiMenuQuanLyDocGia(arrMenu, n);

	gotoxy(50, 2);
	textcolor(177);
	cout << "QUAN LY  DOC GIA  ";
	textcolor(7);
	
	
	//CHỈ SỐ CHỌN MENU
	int idx = -1;//VỊ TRÍ ĐANG CHỌN
	int idxOld = -1;//
	char c;
	while (true)
	{
		c = _getch();
		//cout << (int)c << '\n';
		if ((int)c == -32)
		{
			c = _getch();
			if ((int)c == 72)//lenh
			{
				if (idx > 0)
				{
					idxOld = idx;
					idx--;

					if (idxOld != -1)
					{
						textcolor(192);
						gotoxy(46, 7 + 2 * idxOld);
						cout << ' ';
						cout << arrMenu[idxOld];
						gotoxy(46 + arrMenu[idxOld].length() + 1, 7 + 2 * idxOld);
						for (int p = arrMenu[idxOld].length() + 1; p < 24; ++p)
							cout << ' ';
						textcolor(199);
					}

					//DOI MÀU VỊ TRÍ HIỆN TẠI
					textcolor(116);
					gotoxy(46, 7 + 2 * idx);
					cout << ' ';
					cout << arrMenu[idx];
					gotoxy(46 + arrMenu[idx].length() + 1, 7 + 2 * idx);
					for (int p = arrMenu[idx].length() + 1; p < 24; ++p)
						cout << ' ';
					textcolor(199);
				}
			}
			else if ((int)c == 80)//xuong
			{
				if (idx < n - 1)
				{
					idxOld = idx;
					idx++;

					if (idxOld != -1)
					{
						textcolor(192);
						gotoxy(46, 7 + 2 * idxOld);
						cout << ' ';
						cout << arrMenu[idxOld];
						gotoxy(46 + arrMenu[idxOld].length() + 1, 7 + 2 * idxOld);
						for (int p = arrMenu[idxOld].length() + 1; p < 24; ++p)
							cout << ' ';
						textcolor(199);
					}

					textcolor(116);
					gotoxy(46, 7 + 2 * idx);
					cout << ' ';
					cout << arrMenu[idx];
					gotoxy(46 + arrMenu[idx].length() + 1, 7 + 2 * idx);
					for (int p = arrMenu[idx].length() + 1; p < 24; ++p)
						cout << ' ';
					textcolor(199);
				}
			}
		}
		else if ((int)c == 13 && idx != -1)//enter
		{
			if (idx == 0)
			{
				cout << "                                       " << endl;
				cout << "\t\t\t\ THEM DOC GIA  (ESC :THOAT) " << endl;
				cout << "                                       " << endl;
				ThemDocGia(dsDocGia);
				hienThiMenuQuanLyDocGia(arrMenu, n);

			}
			else if (idx == 1)
			{
				system("cls");

				cout << "                                       " << endl;
				cout << "\t\t\t\ IN DOC GIA THEO TEN HO  TANG DAN (ESC :THOAT) " << endl;
				cout << "                                       " << endl;
				
				theDocGia* ds[1000];
				int nds = 0;
				chuyen_cay_sang_mang(dsDocGia.TREE, ds, nds);
				sap_xep_ds_tdg(ds, nds);
				in_ds_doc_gia(ds, nds);
				giai_phong_ds_the_doc_gia(ds, nds);
				system("pause");

				hienThiMenuQuanLyDocGia(arrMenu, n);
			}
			else if (idx == 2)
			{
				system("cls");
				cout << "                                       " << endl;
				cout << "\t\t\t\ IN DOC GIA THEO MA TANG DAN (ESC :THOAT) " << endl;
				cout << "                                       " << endl;
				Duyet_LNR(dsDocGia.TREE);

				system("pause");

				hienThiMenuQuanLyDocGia(arrMenu, n);
			}
			else if (idx == 3)
			{
				system("cls");

				cout << "                                       " << endl;
				cout << "\t\t\t\ XOA DOC GIA  (ESC :THOAT) " << endl;
				cout << "                                       " << endl;
				int a;
				cout << "\t\t\t\Nhap ma doc gia: "; cin >> a;
				bool kt = kt_ma_dg_trung(dsDocGia.TREE, a);
				int Y = 10;
				if (kt == true)
				{
					//xoa
					int luachon = -1;

					while (true)
					{

						gotoxy(45, Y + 4);
						cout << "                                                                                 ";

						gotoxy(45, Y + 4);
						cout << "BAN CO MUON LUU KHONG [1: CO], [0: KHONG]: ";
						cin >> luachon;

						if (luachon != 0 && luachon != 1)
						{
							gotoxy(45, Y + 5);
							cout << "LUA CHON KHONG HOP LE";
						}
						else if (luachon == 1)
						{
							xoa_1_the_doc_gia(dsDocGia.TREE, a);
							dsDocGia.sl--;
							ghi_file_tdg(dsDocGia);

						}
					}
					hienThiMenuQuanLyDocGia(arrMenu, n);
				}
				else
				{
					gotoxy(45, Y + 4);
					cout << "Ma nhan vien khong ton tai!" << endl;

					Sleep(1000);
					hienThiMenuQuanLyDocGia(arrMenu, n);
				}
			}
			else if (idx == 4)
			{
				system("cls");

				cout << "                                       " << endl;
				cout << "\t\t\t\ HIEU CHINH THONG TIN DOC GIA  (ESC :THOAT) " << endl;
				cout << "                                       " << endl;
				int a;
				int Y = 10;
				rewind(stdin);
				cout << "Nhap ma the doc gia can hieu chinh: ";
				cin >> a;
				bool kt = kt_ma_dg_trung(dsDocGia.TREE, a);
				if (kt == true)
				{
					//hieu_chinh_1_tdg(ds_tdg.TREE, a);

					int luachon = -1;

					while (true)
					{

						gotoxy(45, Y + 4);
						cout << "                                                                                 ";

						gotoxy(45, Y + 4);
						cout << "BAN CO MUON LUU KHONG [1: CO], [0: KHONG]: ";
						cin >> luachon;

						if (luachon != 0 && luachon != 1)
						{
							gotoxy(45, Y + 5);
							cout << "LUA CHON KHONG HOP LE";
						}
						else if (luachon == 1)
						{
							ghi_file_tdg(dsDocGia);

							hieu_chinh_1_tdg(dsDocGia.TREE, a);
						}
					}
					hienThiMenuQuanLyDocGia(arrMenu, n);

				}
				else
				{
					gotoxy(45, Y + 4);
					cout << "Ma khong ton tai!" << endl;

					Sleep(1000);
					hienThiMenuQuanLyDocGia(arrMenu, n);
				}
				system("pause");

				hienThiMenuQuanLyDocGia(arrMenu, n);
			}
		}
		//else if ((int)c == )
		if ((int)c == 27)
			return;
	}


}

void HienThiMenu()
{
	string arrMenu[] = { "QUAN LY DOC GIA", "QUAN LY DAU SACH", "MUON TRA SACH" };
	int n = sizeof(arrMenu) / sizeof(arrMenu[0]);

	//ĐỔI MÀU NỀN GIAO DIỆN
	textcolor(185);
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 50; ++j)
			cout << ' ';
	}

	gotoxy(50, 2);
	textcolor(177);
	cout << "QUAN LY THU VIEN";
	textcolor(7);

	textcolor(199);
	gotoxy(45, 6);
	cout << (char)218;
	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}
	cout << (char)191;

	gotoxy(45, 7);
	cout << (char)179;


	gotoxy(46, 7);
	textcolor(192);
	cout << ' ';
	cout << arrMenu[0];
	gotoxy(46 + arrMenu[0].length() + 1, 7);
	for (int p = arrMenu[0].length() + 1; p < 24; ++p)
		cout << ' ';
	textcolor(199);

	gotoxy(45 + 25, 7);
	cout << (char)179;

	int temp = 1;//XUỐNG DÒNG
	for (int i = 1; i < n; ++i)
	{
		gotoxy(45, 7 + temp);
		cout << (char)195;
		for (int j = 0; j < 24; ++j)
		{
			cout << (char)196;
		}
		cout << (char)180;
		cout << '\n';

		gotoxy(45, 7 + temp + 1);
		cout << (char)179;

		textcolor(192);
		gotoxy(46, 7 + temp + 1);
		cout << ' ';
		cout << arrMenu[i];
		gotoxy(46 + arrMenu[i].length() + 1, 7 + temp + 1);
		for (int p = arrMenu[i].length(); p < 24; ++p)
			cout << ' ';
		textcolor(199);


		gotoxy(45 + 25, 7 + temp + 1);
		cout << (char)179;

		temp += 2;

		cout << '\n';
	}
	gotoxy(45, 7 + temp);
	cout << (char)192;

	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}
	cout << (char)217;
}

void menu()
{
	LIST_DS l_ds;
	doc_file_ds_dau_sach(l_ds);

	DS_THE_DOC_GIA dsDocGia;

	doc_file_tdg(dsDocGia);

	string arrMenu[] = { "QUAN LY DOC GIA", "QUAN LY DAU SACH", "MUON TRA SACH" };
	int n = sizeof(arrMenu) / sizeof(arrMenu[0]);

	//ĐỔI MÀU NỀN GIAO DIỆN
	textcolor(185);
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 50; ++j)
			cout << ' ';
	}

	gotoxy(50, 2);
	textcolor(177);
	cout << "QUAN LY THU VIEN";
	textcolor(7);

	textcolor(199);
	gotoxy(45, 6);
	cout << (char)218;
	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}
	cout << (char)191;

	gotoxy(45, 7);
	cout << (char)179;


	gotoxy(46, 7);
	textcolor(192);
	cout << ' ';
	cout << arrMenu[0];
	gotoxy(46 + arrMenu[0].length() + 1, 7);
	for (int p = arrMenu[0].length() + 1; p < 24; ++p)
		cout << ' ';
	textcolor(199);

	gotoxy(45 + 25, 7);
	cout << (char)179;

	int temp = 1;//XUỐNG DÒNG
	for (int i = 1; i < n; ++i)
	{
		gotoxy(45, 7 + temp);
		cout << (char)195;
		for (int j = 0; j < 24; ++j)
		{
			cout << (char)196;
		}
		cout << (char)180;
		cout << '\n';

		gotoxy(45, 7 + temp + 1);
		cout << (char)179;

		textcolor(192);
		gotoxy(46, 7 + temp + 1);
		cout << ' ';
		cout << arrMenu[i];
		gotoxy(46 + arrMenu[i].length() + 1, 7 + temp + 1);
		for (int p = arrMenu[i].length(); p < 24; ++p)
			cout << ' ';
		textcolor(199);


		gotoxy(45 + 25, 7 + temp + 1);
		cout << (char)179;

		temp += 2;

		cout << '\n';
	}
	gotoxy(45, 7 + temp);
	cout << (char)192;

	for (int i = 0; i < 24; ++i)
	{
		cout << (char)196;
	}
	cout << (char)217;

	char c;

	//CHỈ SỐ CHỌN MENU
	int idx = -1;//VỊ TRÍ ĐANG CHỌN
	int idxOld = -1;//

	while (true)
	{
		c = _getch();
		//cout << (int)c << '\n';
		if ((int)c == -32)
		{
			c = _getch();
			if ((int)c == 72)//lenh
			{
				if (idx > 0)
				{
					idxOld = idx;
					idx--;

					if (idxOld != -1)
					{
						textcolor(192);
						gotoxy(46, 7 + 2 * idxOld);
						cout << ' ';
						cout << arrMenu[idxOld];
						gotoxy(46 + arrMenu[idxOld].length() + 1, 7 + 2 * idxOld);
						for (int p = arrMenu[idxOld].length() + 1; p < 24; ++p)
							cout << ' ';
						textcolor(199);
					}

					//DOI MÀU VỊ TRÍ HIỆN TẠI
					textcolor(116);
					gotoxy(46, 7 + 2 * idx);
					cout << ' ';
					cout << arrMenu[idx];
					gotoxy(46 + arrMenu[idx].length() + 1, 7 + 2 * idx);
					for (int p = arrMenu[idx].length() + 1; p < 24; ++p)
						cout << ' ';
					textcolor(199);
				}
			}
			else if ((int)c == 80)//xuong
			{
				if (idx < n - 1)
				{
					idxOld = idx;
					idx++;

					if (idxOld != -1)
					{
						textcolor(192);
						gotoxy(46, 7 + 2 * idxOld);
						cout << ' ';
						cout << arrMenu[idxOld];
						gotoxy(46 + arrMenu[idxOld].length() + 1, 7 + 2 * idxOld);
						for (int p = arrMenu[idxOld].length() + 1; p < 24; ++p)
							cout << ' ';
						textcolor(199);
					}

					textcolor(116);
					gotoxy(46, 7 + 2 * idx);
					cout << ' ';
					cout << arrMenu[idx];
					gotoxy(46 + arrMenu[idx].length() + 1, 7 + 2 * idx);
					for (int p = arrMenu[idx].length() + 1; p < 24; ++p)
						cout << ' ';
					textcolor(199);
				}
			}
		}
		else if ((int)c == 13 && idx != -1)//enter
		{
			if (idx == 0)
			{
				system("cls");

				QuanLyDocGia(dsDocGia);

				system("cls");
				HienThiMenu();
			}

			if (idx == 1)
			{
				//xóa màn hình
				system("cls");
				quanLyDauSach(l_ds);
				system("cls");
				HienThiMenu();
			}
		}
	}
}

int main() {

	//srand(time(NULL));//reset gia tri cho rand()
	/*while (true)
	{
		char c = _getch();
		cout << (int)c << '\n';
	}*/

	//hien_main_menu();
	resizeConsole(1500, 700);
	menu();

	/*for (int i = 0; i < 255; ++i)
	{
		textcolor(i);
		cout << i << '\n';
	}*/



	//_getch();
	return 0;

}

