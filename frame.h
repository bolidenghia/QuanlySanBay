#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"

using namespace std;

// ==================== ADD FILE ====================== //




//Menu
const int itemmenuchinh = 5;
const int itemmenuMB=6;
//"                     "
								                                                                                                  
char MENU[itemmenuchinh][100] = {"   QUAN LY MAY BAY   ",
								 "  QUAN LY CHUYEN BAY ",
								 "    QUAN LY DAT VE   ",
								 "  QUAN LY HANH KHACH ", 
								 "       THOAT         "};
char MENUMAYBAY[itemmenuMB][50] = {
								   "      THEM MAY BAY      ",
								   "       XOA MAY BAY      ",
								   "  HIEU CHINH THONG TIN  ",
								   "  IN DANH SACH MAY BAY  ",								   
								   "       SAVE FILE        ",
								   "       OPEN FILE        "};
char MENUNHANVIEN[2][50] = {"  1.Nhap Nhan Vien  ","  2.In Danh Sach SV   "};


// ===== Giaodien =====

void header(){
	TextColor(117);		
	gotoxy (45,2);
	cout<<"                HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TP.HCM                 ";
	SetColor(4);	
	gotoxy (42,3);
	cout<<"---------------------------------------*--*--*------------------------------------------";
	SetColor(4);
	gotoxy(61,5); cout<<"============================================";
	gotoxy(61,6); cout<<"|";
	SetColor(4);
	gotoxy(74,6); cout<<"  QUAN LY MAY BAY    ";   
	SetColor(4);		
	gotoxy(104,6); cout<<"|";
	gotoxy(61,7);cout<<"============================================";
}
void footer1() {
	SetColor(8);
	gotoxy(15,46);
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------";
	
	// exit
	SetColor(15);
	SetBGColor(4);
	gotoxy(50,47); cout<< " ESC ";
	
	SetColor(6);
	SetBGColor(0);
	gotoxy(56,47); cout<< ": THOAT";
	
	// ok
	SetColor(15);
	SetBGColor(2);
	gotoxy(66,47); cout<< " ENTER ";
	
	SetColor(6);
	SetBGColor(0);
	gotoxy(73,47); cout<< ": CHON";
	
	// Di chuyen
	SetColor(15);
	SetBGColor(9);
	gotoxy(83,47); cout<< (char)94<<" "<<(char)118<<" " <<(char)60<<" " <<(char)62;
	
	SetColor(6);
	SetBGColor(0);
	gotoxy(90,47); cout<<  ": UP, DOWN, LEFT, RIGHT ";
}
void frameFull(){
	SetColor(9);
	SetBGColor(7);
	gotoxy(53,16);cout<<"      ============|  ====        ====   ====            ====                ";
	gotoxy(53,17);cout<<"      ============|  ====        ====   ====            ====                ";
	gotoxy(53,18);cout<<"      =====          ====        ====   ====            ====                ";
	gotoxy(53,19);cout<<"      =====          ====        ====   ====            ====                ";
	gotoxy(53,20);cout<<"      =====          ====        ====   ====            ====                ";
	gotoxy(53,21);cout<<"      ============|  ====        ====   ====            ====                ";
	gotoxy(53,22);cout<<"      ============|  ====        ====   ====            ====                ";
	gotoxy(53,23);cout<<"      ======         ====        ====   ====            ====                ";
	gotoxy(53,24);cout<<"      ======         ====        ====   ====            ====                ";
	gotoxy(53,25);cout<<"      ======         ================   =============   ==============      ";
	gotoxy(53,26);cout<<"      ======         ================   =============   ==============      ";
//	SetBGColor(7);
}
void frameContinue(){
		SetColor(4);
	SetBGColor(15);
	gotoxy(55, 42);
	cout << "                                                           ";
	gotoxy(55, 43);
	cout << "             NHAN PHIM BAT KY DE TIEP TUC                  ";
	gotoxy(55, 44);
	cout << "                                                           ";
	SetBGColor(7);
}
void frameAdd_MB(){
	
header();footer1();
	//anConTro();
	SetColor(4);
	SetBGColor(7);
	gotoxy(45,14);cout<<"+----------------+----------------------+------------+-------------+---------------+";
	gotoxy(45,15);cout<<"|    SO HIEU MB  |     LOAI MAY BAY     |   SO DAY   |   SO HANG   |  TONG SO GHE  |";
	gotoxy(45,16);cout<<"+----------------+----------------------+------------+-------------+---------------+";
	SetColor(13);
	gotoxy(72, 11);
	cout << "+-------------------------+";
	gotoxy(72, 12);
	cout << "|  NHAP DANH SACH MAY BAY |";
	gotoxy(72, 13);
	cout << "+-------------------------+";
	

}
int frameNext(){
		SetColor(12);
	SetBGColor(11);
	gotoxy(55, 36);
	cout << "                                                           ";
	gotoxy(55, 37);
	cout << "                   BAN CO MUON THEM TIEP?                  ";
	gotoxy(55, 38);
	cout << "                                                           ";
	SetBGColor(7);
	return GetKey();
	
}

void ToMauMenuChinh(int textColor, int bGColor, int vitri) {
	SetColor(textColor);			   
	SetBGColor(bGColor);			  
	gotoxy(0, 12 + vitri * 4); cout <<"                     ";
	gotoxy(0, 13 + vitri * 4); cout << MENU[vitri];
	gotoxy(0, 14 + vitri * 4); cout <<"                     ";
	
}
void ToMauMenuCon(int textColor, int bGColor, char MenuCon[][50], int vitri) {
	SetColor(textColor);
	SetBGColor(bGColor);					   
	gotoxy(25, 8 + (vitri + 1) * 4);	cout <<"                        ";
	gotoxy(25, 9 + (vitri + 1) * 4);	cout << MenuCon[vitri];
	gotoxy(25, 10 + (vitri + 1) * 4);	cout <<"                        ";
	
}
void TextViewChuDe(char s[],int x , int y , int dodai ,int background,int textcolor)
{
	gotoxy(x,y);              cout<<(char)218;
	for(int i= 0 ; i< dodai ; i++)  cout<<(char)196;   cout<<(char)191 ;
	gotoxy(x, y+1 );          cout<<(char)179;
	gotoxy(x + dodai + 1 , y+1 ); cout<<(char)179;
	gotoxy( x,y + 2 );          cout<<(char)192;
	for(int i=0; i< dodai;i++)  cout<<(char)196;       cout<<(char)217;
	SetColor( background);
	gotoxy(x + 1 , y + 1 ); cout<<s;
}
void ButtonThoat(int hang ,int cot, int background ,int textcolor)
{
	gotoxy(hang,cot);
	SetColor(7);
	gotoxy(hang,cot); cout<<"         ";
	gotoxy(hang,cot+1); cout<<"   ESC   ";
	gotoxy(hang,cot+2); cout<<"         ";
	
	gotoxy(hang+25,cot); cout<<"         ";
	gotoxy(hang+25,cot+1); cout<<"  ENTER  ";
	gotoxy(hang+25,cot+2); cout<<"         ";
	
	SetColor(background);
	gotoxy(hang+6,cot+1); cout<<": THOAT ";
	gotoxy(hang+35,cot+1); cout<<": OK    ";
	
}
void ButtonChucNang(int background,int textcolor)
{
	SetColor(14);
	gotoxy(5,28); cout<<"         ";
	gotoxy(5,29); cout<<"   ESC   ";
	gotoxy(5,30); cout<<"         ";
	gotoxy(25,28); cout<<"         ";
	gotoxy(25,29); cout<<"  INSERT ";
	gotoxy(25,30); cout<<"         ";
	gotoxy(45,28); cout<<"         ";
	gotoxy(45,29); cout<<"   END   ";
	gotoxy(45,30); cout<<"         ";
	gotoxy(65,28); cout<<"         ";
	gotoxy(65,29); cout<<"  DELETE ";
	gotoxy(65,30); cout<<"         ";

	SetColor(background);
	gotoxy(15,29); cout<<": THOAT ";
	gotoxy(36,29); cout<<": SUA  ";
	gotoxy(56,29); cout<<": THEM  ";
	gotoxy(76,29); cout<<": XOA   ";
}
//-----------------CHILDREN MENU-------------------------




