#include <iostream>
 #include <string.h>
#include "khaibao.h"
#include "frame.h"
#include <sstream> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//tim va tra ve vi tri cua Mb có so hieu chuyen bay X
int search(List_MB listMB, char shmb[]) {
  for (int i =0; i < listMB.soluong ; i++)
     if (strcmp(listMB.nodeMB[i]->sohieu_MB,shmb)==0) return i;
  return -1;
}
int isEmpty(List_MB l){
	return l.soluong==0;
}
int isFull(List_MB l){
	return l.soluong==MAXMAYBAY;
}
//hien thi dach sach may bay
void showList_MB(List_MB listMB, boolean flag){
	//system("cls") ;
	SetBGColor(7);
	header();
	if(listMB.soluong==0 && flag==TRUE ){
		Alert("CHUA CO MAY BAY",77,40,3);
	}else if(listMB.soluong==0 && flag==FALSE ){
		Alert("SAN SANG NHAP",79,40,1.2);
	}else{
		footer1();
	//anConTro();
	SetColor(4);
	SetBGColor(7);	//	"|________________|______________________|____________|_____________|_______________|"	
	gotoxy(45,14);cout<<"+----------------+----------------------+------------+-------------+---------------+";
	gotoxy(45,15);cout<<"|    SO HIEU MB  |     LOAI MAY BAY     |   SO DAY   |   SO HANG   |  TONG SO GHE  |";
	gotoxy(45,16);cout<<"+----------------+----------------------+------------+-------------+---------------+";
	for(int i=0;i<listMB.soluong;i++){
		SetColor(4);
		//SetBGColor(7);
	//	gotoxy(45,dongStart+i);cout<<"|";gotoxy(62,dongStart+i);cout<<"|";gotoxy(85,dongStart+i);cout<<"|";
	//	gotoxy(98,dongStart+i);cout<<"|";gotoxy(112,dongStart+i);cout<<"|";gotoxy(128,dongStart+i);cout<<"|";
		gotoxy(45,dongStart+i);cout<<"|________________|______________________|____________|_____________|_______________|";
		gotoxy(51,dongStart+i);cout<<listMB.nodeMB[i]->sohieu_MB; 
		gotoxy(69,dongStart+i);cout<<listMB.nodeMB[i]->loai_MB;
		gotoxy(91,dongStart+i);cout<<listMB.nodeMB[i]->soday_MB;
		gotoxy(105,dongStart+i);cout<<listMB.nodeMB[i]->sohang_MB;
		gotoxy(119,dongStart+i);cout<<(listMB.nodeMB[i]->soday_MB*listMB.nodeMB[i]->sohang_MB);
		
	}
	
	}

}
//them thong tin cho may bay
int  addInfo_MB ( List_MB &listMB, MAYBAY &mb){
clrscr();
	frameAdd_MB();Sleep(0);
	showList_MB(listMB,FALSE);int key; int vitri;
	Sleep(0);
	SetColor(4);

		gotoxy(45,dongStart+listMB.soluong);cout<<"|";gotoxy(62,dongStart+listMB.soluong);cout<<"|";gotoxy(85,dongStart+listMB.soluong);cout<<"|";
		gotoxy(98,dongStart+listMB.soluong);cout<<"|";gotoxy(112,dongStart+listMB.soluong);cout<<"|";gotoxy(128,dongStart+listMB.soluong);cout<<"|";
		gotoxy(45,dongStart+listMB.soluong);cout<<"|________________|______________________|____________|_____________|_______________|";
SOHIEUCB:///////////////// NHAP SO HIEU MAY BAY //////////////
	// ghi chu
	SetColor(4);
	SetBGColor(15);
	gotoxy(55, 42);
	cout << "                                                           ";
	gotoxy(55, 43);
	cout << "         SO HIEU MB: GOM CAC KI TU (A-Z) & (0-9)           ";
	gotoxy(55, 44);
	cout << "                                                           ";
	vitri=0;
	//
	while(1){
		gotoxy(51+vitri,dongStart+listMB.soluong);
		SetColor(9);
		SetBGColor(7);
		key= GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key <= '9' && key >= '0')) && (vitri < maxSOHIEUMB)) {
			mb.sohieu_MB[vitri]= toupper((char)key);
			cout << mb.sohieu_MB[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(51 + vitri,dongStart+listMB.soluong );
			SetColor(4);
			cout << "_";
		}
		if(key==ESC){
			gotoxy(50,40);
			
			SetBGColor(7);
			cout<<"                                                            ";
			SetColor(4);
			SetBGColor(7);
			gotoxy(76,40);
			cout<<"BAN CO CHAC CHAN HUY?";
			int cofirm=GetKey();
			if(cofirm==ENTER){
				return 0;
			}
			gotoxy(76,40);
			SetBGColor(7);
			cout<<"                                                            ";
		}
		if ( key == ENTER) {
			mb.sohieu_MB[vitri] = '\0';
			if (mb.sohieu_MB[0] == '\0') {
				Alert("CHUA NHAP SO HIEU MAY BAY",73,40,2);
				goto SOHIEUCB ;
			}else if(search(listMB,mb.sohieu_MB)>-1){
					Alert("SO HIEU MB BI TRUNG!",73,40,2);
					gotoxy(51,dongStart+listMB.soluong );
					SetColor(4);cout<<"________";
					goto SOHIEUCB ;
			}else{
				goto LOAIMAYBAY;
			}
		}
}

LOAIMAYBAY: /////////// NHAP LOAI MAY BAY //////////////
		// ghi chu
	SetColor(4);
	SetBGColor(15);
	gotoxy(55, 42);
	cout << "                                                           ";
	gotoxy(55, 43);
	cout << "        LOAI MAY BAY: GOM CAC KI TU (A-Z) & (0-9)          ";
	gotoxy(55, 44);
	cout << "                                                           ";
	vitri=0;
	//
	while(1){
		gotoxy(69+vitri,dongStart+listMB.soluong);
		SetColor(9);
		SetBGColor(7);
		key= GetKey();	
		if(((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key <= '9' && key >= '0')) && (vitri < maxLOAIMB)){
			mb.loai_MB[vitri]= toupper((char)key);
			cout << mb.loai_MB[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(69 + vitri,dongStart+listMB.soluong );SetColor(4);
			cout << "_";
		}
				if(key==ESC){
			gotoxy(50,40);
			
			SetBGColor(7);
			cout<<"                                                            ";
			SetColor(4);
			SetBGColor(7);
			gotoxy(76,40);
			cout<<"BAN CO CHAC CHAN HUY?";
			int cofirm=GetKey();
			if(cofirm==ENTER){
				return 0;
			}
			gotoxy(76,40);
			SetBGColor(7);
			cout<<"                                                            ";
		}
		if ( key == ENTER) {
			mb.loai_MB[vitri] = '\0';
			if (mb.loai_MB[0] == '\0') {
				Alert("CHUA NHAP LOAI MAY BAY",73,40,2);
				goto LOAIMAYBAY ;			
			}else{
				goto SODAY;
			}
		}			
	}
SODAY:////////////// NHAP SO DAY MAY BAY/////////////////
	char sodaychar[3];
			// ghi chu
	SetColor(4);
	SetBGColor(15);
	gotoxy(55, 42);
	cout << "                                                           ";
	gotoxy(55, 43);
	cout << "                 0 < SO LUONG DAY < 10                     ";
	gotoxy(55, 44);
	cout << "                                                           ";
	vitri=0;
	///
	while(1){
		gotoxy(91+vitri,dongStart+listMB.soluong);
		SetColor(9);
		SetBGColor(7);
		fflush(stdin);
		key= GetKey();
		if(key >= '0' && key <= '9' && vitri < 2){
			sodaychar[vitri] = (char)key;
			cout << sodaychar[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(91 + vitri, dongStart+listMB.soluong);SetColor(4);
			cout << "_";
			
		}if(key==ENTER){
			sodaychar[vitri]='\0';
			if(sodaychar[0]=='\0'){
				Alert("CHUA NHAP SO DAY",77,40,2);
				goto SODAY;
			}else{
			mb.soday_MB=atoi(sodaychar);
				if(mb.soday_MB >10|| mb.soday_MB<=0){
					Alert("SO DAY KHONG THOA MAN ",72,40,2);
					SetColor(4);								
			gotoxy(91, dongStart+listMB.soluong);
			cout << "__";
					goto SODAY;
				}else{
					goto SOHANG;
				}
			}
		}
				if(key==ESC){
			gotoxy(50,40);
			
			SetBGColor(7);
			cout<<"                                                            ";
			SetColor(4);
			SetBGColor(7);
			gotoxy(76,40);
			cout<<"BAN CO CHAC CHAN HUY?";
			int cofirm=GetKey();
			if(cofirm==ENTER){
				return 0;
			}
			gotoxy(76,40);
			SetBGColor(7);
			cout<<"                                                            ";
		}
	}
SOHANG://///////////// NHAP SO HANG CUA MAY BAY ////////////////////
	char sohangchar[3];
			// ghi chu
	SetColor(4);
	SetBGColor(15);
	gotoxy(55, 42);
	cout << "                                                           ";
	gotoxy(55, 43);
	cout << "                 0 < SO LUONG HANG < 30                    ";
	gotoxy(55, 44);
	cout << "                                                           ";
	vitri=0;
	///
	while(1){
		gotoxy(105+vitri,dongStart+listMB.soluong);
		SetColor(9);
		SetBGColor(7);
		fflush(stdin);
		key= GetKey();
		if(key >= '0' && key <= '9' && vitri < 2){
			sohangchar[vitri] = (char)key;
			cout << sohangchar[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(105 + vitri, dongStart+listMB.soluong);SetColor(4);
			cout << "_";
		}if(key==ENTER){
			sohangchar[vitri]='\0';
			if(sohangchar[0]=='\0'){
				Alert("CHUA NHAP SO HANG",77,40,2);
				goto SOHANG;
			}else{
			mb.sohang_MB=atoi(sohangchar);
				if(mb.sohang_MB >30|| mb.sohang_MB<=0){
					Alert("SO HANG KHONG THOA MAN ",72,40,2);
					SetColor(4);								
			gotoxy(105, dongStart+listMB.soluong);
			cout << "__";
					goto SOHANG;
				}else{
					goto ENDp;
				}
			}
		}
		if(key==ESC){
			gotoxy(50,40);
			
			SetBGColor(7);
			cout<<"                                                            ";
			SetColor(4);
			SetBGColor(7);
			gotoxy(76,40);
			cout<<"BAN CO CHAC CHAN HUY?";
			int cofirm=GetKey();
			if(cofirm==ENTER){
				return 0;
			}
			gotoxy(76,40);
			SetBGColor(7);
			cout<<"                                                            ";
		}
	}
ENDp:
	gotoxy(119,dongStart+listMB.soluong);
	cout<<(mb.soday_MB*mb.sohang_MB);
		return 1;
		
	}


void addList_MB(List_MB &listMB){
	int key1;
	do{
		if (isFull(listMB)){//kiem tra day chua?
		header();
		Alert("DANH SACH MAY BAY DA DAY!",70,40,3);
		clrscr();
		header();
		frameFull();
		frameContinue();	
		return ;
	}else{//neu chua day...
	if(isEmpty(listMB)){//... thi kiem tra xem co phan tu chua?
		MAYBAY mb;
		if(addInfo_MB(listMB,mb)==0){
			gotoxy(50,40);
			
			SetBGColor(7);
			cout<<"                                                            ";
			Alert("DA HUY",82,40,2);	

		}else{
		listMB.nodeMB[0]= new MAYBAY;
	*listMB.nodeMB[0]=mb; listMB.soluong++;
			Alert("THEM MAY BAY THANH CONG!",70,40,2)	;

			}
		}else{
		MAYBAY mb;
		if(addInfo_MB(listMB,mb)==0){
			gotoxy(50,40);			
			SetBGColor(7);
			cout<<"                                                            ";
			Alert("DA HUY",82,40,2);

		}else{
				int j, k;
	for (j=0; j < listMB.soluong && strcmp(listMB.nodeMB[j]->sohieu_MB,mb.sohieu_MB)<1 ; j++ );
	for ( k = listMB.soluong-1; k >=j  ; k--) 
	listMB.nodeMB[k+1]= listMB.nodeMB[k];
	listMB.nodeMB[j]= new MAYBAY;
	*listMB.nodeMB[j]=mb; listMB.soluong++;
		Alert("THEM MAY BAY THANH CONG!",70,40,2)	;
	
			}		
		}	
	}	
	key1=frameNext();if(key1==ESC){
		SetColor(12);
	SetBGColor(11);
	gotoxy(55, 36);
	cout << "                                                           ";
	gotoxy(55, 37);
	cout << "                       XAC NHAN HUY?                       ";
	gotoxy(55, 38);
	cout << "                                                           ";
	SetBGColor(7);
	}	
	}while(key1==ENTER);
	
	
}

//xoa may bay co SHMB X khoi danh sach
int deleteMB(List_MB &listMB,char shmb[]){

	int i=search(listMB,shmb);
	if (i==-1) BaoLoi("So hieu may bay khong co trong danh sach");
   else  
   { delete  listMB.nodeMB[i];
     for (int j=i+1; j <listMB.soluong; j++)
       listMB.nodeMB[j-1]=listMB.nodeMB[j];       
       listMB.soluong--;  
	}
}
int frameDeleteMB(List_MB &listMB){
	SetBGColor(7);
	header();
	anConTro();
	if(isEmpty(listMB)){
		Alert("CHUA CO MAY BAY TRONG DANH SACH ",70,40,3);
	}else {
		footer1();
	//anConTro();
	SetColor(4);
	SetBGColor(7);		
	gotoxy(45,14);cout<<"+----------------+----------------------+------------+-------------+---------------+";
	gotoxy(45,15);cout<<"|    SO HIEU MB  |     LOAI MAY BAY     |   SO DAY   |   SO HANG   |  TONG SO GHE  |";
	gotoxy(45,16);cout<<"+----------------+----------------------+------------+-------------+---------------+";
	for(int i=0;i<listMB.soluong;i++){
		if (i == 0) {
		HighLight();
		} else {
			Normal();
		}
		gotoxy(45,dongStart+i);cout<<"|________________|______________________|____________|_____________|_______________|";
		gotoxy(51,dongStart+i);cout<<listMB.nodeMB[i]->sohieu_MB; 
		gotoxy(69,dongStart+i);cout<<listMB.nodeMB[i]->loai_MB;
		gotoxy(91,dongStart+i);cout<<listMB.nodeMB[i]->soday_MB;
		gotoxy(105,dongStart+i);cout<<listMB.nodeMB[i]->sohang_MB;
		gotoxy(119,dongStart+i);cout<<(listMB.nodeMB[i]->soday_MB*listMB.nodeMB[i]->sohang_MB);
	}
	int vitri=0;
	SetBGColor(7);
	while(true){
		int key=GetKey();
		switch (key){
			case DOWN:
				if(vitri<=listMB.soluong-1){
					Normal();
		gotoxy(45,dongStart+vitri);cout<<"|________________|______________________|____________|_____________|_______________|";
		gotoxy(51,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohieu_MB; 
		gotoxy(69,dongStart+vitri);cout<<listMB.nodeMB[vitri]->loai_MB;
		gotoxy(91,dongStart+vitri);cout<<listMB.nodeMB[vitri]->soday_MB;
		gotoxy(105,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohang_MB;
		gotoxy(119,dongStart+vitri);cout<<(listMB.nodeMB[vitri]->soday_MB*listMB.nodeMB[vitri]->sohang_MB);
					vitri ++;
              		HighLight();
        gotoxy(45,dongStart+vitri);cout<<"|________________|______________________|____________|_____________|_______________|";
		gotoxy(51,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohieu_MB; 
		gotoxy(69,dongStart+vitri);cout<<listMB.nodeMB[vitri]->loai_MB;
		gotoxy(91,dongStart+vitri);cout<<listMB.nodeMB[vitri]->soday_MB;
		gotoxy(105,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohang_MB;
		gotoxy(119,dongStart+vitri);cout<<(listMB.nodeMB[vitri]->soday_MB*listMB.nodeMB[vitri]->sohang_MB);
				}
				break;
			case UP: 
				if (vitri >=0){
  		            Normal();
              		gotoxy(45,dongStart+vitri);cout<<"|________________|______________________|____________|_____________|_______________|";
		gotoxy(51,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohieu_MB; 
		gotoxy(69,dongStart+vitri);cout<<listMB.nodeMB[vitri]->loai_MB;
		gotoxy(91,dongStart+vitri);cout<<listMB.nodeMB[vitri]->soday_MB;
		gotoxy(105,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohang_MB;
		gotoxy(119,dongStart+vitri);cout<<(listMB.nodeMB[vitri]->soday_MB*listMB.nodeMB[vitri]->sohang_MB);
              		vitri --;
              		HighLight();
              		gotoxy(45,dongStart+vitri);cout<<"|________________|______________________|____________|_____________|_______________|";
		gotoxy(51,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohieu_MB; 
		gotoxy(69,dongStart+vitri);cout<<listMB.nodeMB[vitri]->loai_MB;
		gotoxy(91,dongStart+vitri);cout<<listMB.nodeMB[vitri]->soday_MB;
		gotoxy(105,dongStart+vitri);cout<<listMB.nodeMB[vitri]->sohang_MB;
		gotoxy(119,dongStart+vitri);cout<<(listMB.nodeMB[vitri]->soday_MB*listMB.nodeMB[vitri]->sohang_MB);
  				
  			  }
  			  break;
  			case ENTER:
  				
  				return vitri;
  			
		}
	}
}
}


////xoa may bay co SHMB X khoi danh sach
//int deleteMB(List_MB &listMB,char shmb[]){
//
//	int i=search(listMB,shmb);
//	if (i==-1) BaoLoi("So hieu may bay khong co trong danh sach");
//   else  
//   { delete  listMB.nodeMB[i];
//     for (int j=i+1; j <listMB.soluong; j++)
//       listMB.nodeMB[j-1]=listMB.nodeMB[j];       
//       listMB.soluong--;  
//	}
//}
//hieu chinh thong tin may bay
int editInfo_MB(List_MB &listMB, char shmb[]){	
	int i= search(listMB,shmb);
	if(i<0){
		BaoLoi("So hieu may bay khong co trong danh sach ");
	}else{
			char sohieuMBtemp[15],loaiMBtemp[40];
	int sodaytemp,sohangtemp;
	NhapChuoi("Nhap so hieu may bay moi: ",sohieuMBtemp);
//	if(checkchuoi(sohieuMBtemp)==0){
//		BaoLoi("Chua nhap so hieu may bay!");
//	}
	NhapChuoi("Nhap loai may bay: ",loaiMBtemp);
	fflush(stdin);
	cout<<"Nhap so day may bay: ";cin>>sodaytemp;
	cout<<"Nhap so hang may bay: ";cin>>sohangtemp;
	strcpy(listMB.nodeMB[i]->sohieu_MB,sohieuMBtemp);
	strcpy(listMB.nodeMB[i]->loai_MB,loaiMBtemp);
	listMB.nodeMB[i]->soday_MB=sodaytemp;
	listMB.nodeMB[i]->sohang_MB=sohangtemp;
	cout<<"Da chinh sua thanh cong!";
	}
}
// khoi tao danh sach chuyen bay
void createList_CB(List_CB &listCB){	
	listCB.pHead = NULL;
}
//tao node chuyen bay
Node_CB* createNodeCB(CHUYENBAY cb){
	Node_CB *p= new Node_CB;
	if(p==NULL){
		BaoLoi("Cap phat bo nho khong thanh cong");
		exit(1);
	}else{
		p->data=cb;
		p->pNext==NULL;
		return p;
	}
}
//them thong tin cho node chuyen bay
int addInfo_CB(CHUYENBAY &cb){
	NhapChuoi("Nhap ma chuyen bay: ",cb.ma_CB);
	NhapChuoi("Nhap so hieu may bay: ",cb.sohieumb);
	cout<<"Nhap ngay khoi hanh:   "<<"Ngay: ";cin>>cb.ngaygioStart.day;cout<<" Thang: ";cin>>cb.ngaygioStart.month;cout<<" Nam: ";cin>>cb.ngaygioStart.year;cout<<endl;
	cout<<"Nhap gio khoi hanh: "<<" Gio: ";cin>>cb.ngaygioStart.hours;cout<<" Phut: ";cin>>cb.ngaygioStart.minutes;cout<<endl;
	NhapChuoi("Nhap san bay den: ",cb.sanbayDen);
	cb.trangthai=1;
	cout<<"Nhap so luong ve: ";cin>>cb.soluongVe;
	
}
//hien thi thong tin node chuyen bay
int showInfo_CB(CHUYENBAY cb){	
	cout<<cb.ma_CB<<"\t"<<cb.sohieumb<<"\t"<<cb.ngaygioStart.day<<"/"<<cb.ngaygioStart.month<<"/"<<cb.ngaygioStart.year<<"\t"<<cb.ngaygioStart.hours<<":"<<cb.ngaygioStart.minutes<<"\t"<<cb.sanbayDen<<"\t"<<cb.soluongVe<<"\t"<<staTus[cb.trangthai]<<endl;
}
//hien thi list cac chuyen bay
void showList_CB(List_CB listCB){
	cout<<"\t\tDANH SACH CHUYEN BAY"<<endl;
	cout<<"Ma chuyen bay\tSo hieu may bay\tNgay khoi hanh\tGio\tNoi den\tSoluongve\tTrang thai"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	 Node_CB *p;
    p=listCB.pHead;
    while(p!=NULL)
    {
        showInfo_CB(p->data );
        p=p->pNext;
    }
}
// them node chuyen bay cho List chuyen bay
int addList_CB(List_CB &listCB){
	CHUYENBAY cb;
	
    char kt;   
    cout<<"\nNhan phim bat ki de tiep tuc nhap."<<endl;
    cout<<"\nNhan 0 de dung nhap."<<endl;
    do
    {
        kt=getch();
        if(kt=='0')  break;
        addInfo_CB(cb);
        Node_CB *p=createNodeCB(cb);
        if(listCB.pHead==NULL){
        	listCB.pHead=p;
		}else{
			p->pNext=listCB.pHead;
			listCB.pHead=p;
		}
    } while (1);
}
//xoa chuyen bay theo ma chuyen bay
int deleteCB(List_CB &listCB, char maCB[]){
	
}
//luu file danh sach may bay
void saveFileList_MB(List_MB l,char *filename) {
 FILE * f;
 if ((f=fopen(filename,"wb"))==NULL)
 {  Alert("LOI MO FILE DE GHI",78,40,2.5);frameContinue(); return ;
 
 }else if(l.soluong==0){
 	Alert("DANH SACH KHONG CO MAY BAY",72,40,3);frameContinue();return;
 	
 }else{
 	for (int i=0; i < l.soluong; i++)
   fwrite (l.nodeMB[i], sizeof (MAYBAY), 1, f);
 fclose(f);
 Alert("DA GHI XONG DANH SACH VAO FILE",74,40,2.5); return ;
 }
 

}
//doc file danh sach may bay
int openFileList_MB(List_MB &l, char *filename) {
	header();
 FILE * f; MAYBAY mb;
 if ((f=fopen(filename,"rb"))==NULL)
 {  Alert("LOI MO FILE DE DOC",78,40,2.5);frameContinue(); return 0;
 }
 l.soluong=0;
 while  (fread (&mb, sizeof (MAYBAY), 1, f)!=0) {
 	l.nodeMB[l.soluong]= new MAYBAY;
 	*l.nodeMB[l.soluong]= mb;
 	l.soluong++;
 }
    
 fclose(f);
 if(l.soluong==0){
 	Alert("CHUA CO PHAN TU NAO TRONG FILE",62,40,2.3);frameContinue();return 0;
 }else{
 	Alert("DA LOAD FILE VAO BO NHO",67,40,1.2);frameContinue();return 1;
 }
}
int MenuCon(int item, char MenuCon[][50]) {
	char key;
	int vitri = 0;
	while (true) {
		key = GetKey();
		if (key == ENTER)
			return vitri + 1;
		if (key == ESC || key == LEFT)
			return 0;
		switch (key) {
		case DOWN:
			if (vitri == (item - 1)) {
				ToMauMenuCon(4, 11, MenuCon, vitri);
				vitri = 0;
				ToMauMenuCon(4, 14, MenuCon, vitri);
			} else {
				ToMauMenuCon(4, 11, MenuCon, vitri);
				vitri++;
				ToMauMenuCon(4, 14, MenuCon, vitri);
			}
			break;
		case UP:
			if (vitri == 0) {
				ToMauMenuCon(4, 11, MenuCon, vitri);
				vitri = item - 1;
				ToMauMenuCon(4, 14, MenuCon, vitri);
			} else {
				ToMauMenuCon(4, 11, MenuCon, vitri);
				vitri--;
				ToMauMenuCon(4, 14, MenuCon, vitri);
			}
			break;
		}
	}
	return 0;
}
//------------------DAD MENU--------------------------
int DadMenu() {
	int vitri = 0;
	while (true) {
		header();
		footer1();
		char key = GetKey();
		if (key == ENTER || (key == RIGHT && vitri != itemmenuchinh)) // 4 === THOAT
			return vitri + 1;
		switch (key) {
		case DOWN:
			if (vitri == (itemmenuchinh-1)) {
				ToMauMenuChinh(4, 11, vitri);
				vitri = 0;
				ToMauMenuChinh(4, 14, vitri);
			} else {
				ToMauMenuChinh(4, 11, vitri);
				vitri++;
				ToMauMenuChinh(4, 14, vitri);
			}
			break;
		case UP:
			if (vitri == 0) {
				ToMauMenuChinh(4, 11, vitri);
				vitri = (itemmenuchinh - 1);
				ToMauMenuChinh(4, 14, vitri);
			} else {
				ToMauMenuChinh(4, 11, vitri);
				vitri--;
				ToMauMenuChinh(4, 14, vitri);
			}
			break;
		}
	}
	return 0;
}
//---------------ROOT MENU------------------------
void RootMenu(List_MB &l) {
	int choice;
	int choiceMenuCon;
	int vitrinode;
	while (true) {
		clrscr();
		
		for (int i = 0; i < itemmenuchinh; i++) {
			if (i == 0) {
				SetColor(4);
				SetBGColor(14);
			} else {
				SetColor(4);
				SetBGColor(11);
			}
			gotoxy(0, 12 + i * 4); cout << "                     ";
			gotoxy(0, 13 + i * 4); cout << MENU[i];
			gotoxy(0, 14 + i * 4); cout << "                     ";
		}
		
		choice = DadMenu();
		
		switch (choice) {
			
		case 1:// Quan ly may bay
			for (int i = 0; i < itemmenuMB; i++) {
				if (i == 0) {
					SetColor(4);
					SetBGColor(14);
				} else {
					SetColor(4);
					SetBGColor(11);
				}
				gotoxy(25, 8 + (i + 1) * 4);	cout << "                        ";
				gotoxy(25, 9 + (i + 1) * 4);	cout <<MENUMAYBAY[i];
				gotoxy(25, 10 + (i + 1) * 4);	cout << "                        ";
			}
			choiceMenuCon = MenuCon(itemmenuMB, MENUMAYBAY); 
			    // item la so chuc nang cua lop con
			SetBGColor(7);
			clrscr();
						
			switch (choiceMenuCon) {
			case 1://them may bay		 
 					addList_MB(l);				
 					getch(); 
				break;
			case 2:// xoa may bay
				 vitrinode=frameDeleteMB(l);
				deleteMB(l,l.nodeMB[vitrinode]->sohieu_MB);
				getch();
				break;
			case 3://hieu chinh thong tin
				break;
			case 4://in danh sach
					showList_MB(l,TRUE);
  					getch();
				break;
			case 5://save file
			header();
				saveFileList_MB(l,"Danhsachmaybay");
				break;
			case 6://mo file
			if(openFileList_MB(l,"Danhsachmaybay")==0){
				break;
			}else{
				 showList_MB(l,TRUE);
				 getch();
			}
				 
				
				break;
			}
			break;
		case 2://quan ly chuyen bay
			break;
		case 3://quan ly dat ve
			break;
		case 4:// quan ly hanh khach
			break;
		case 5: //thoat
			return;
		}
	}
	return;
}


int main() {
resizeConsole(maxrong,maxcao);
SetBGColor(7);
List_MB l;
RootMenu(l);



	return 0;
}
