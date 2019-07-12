#include <iostream>

// ==================== DEFINE VALUE ====================== //
// Ve dâu mui tên
#define ArrowRIGHT 27
#define ArrowLEFT 26
#define ArrowUP 25
#define ArrowDOWN 24
#define MAXMAYBAY 300
#define maxSOHIEUMB 15
#define maxLOAIMB 40
#define maxMACB 15
#define maxCMND 15
#define maxcao 802
#define maxrong 1440
#define DOWN 80
#define UP 72
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27
#define SPACE 32
#define BACKSPACE 8
#define DELETE 83
#define INSERT 82
#define END 79
using namespace std;
const int cotStart= 51;
const int dongStart= 17;

typedef struct  {
	int day,month,year,hours,minutes;
	
}DATETIME;
///////////////////
typedef struct {
	char sohieu_MB[15];
	char loai_MB[40];
	int soday_MB, sohang_MB;
	
}MAYBAY;
typedef struct {
	int soluong;
	MAYBAY *nodeMB[MAXMAYBAY];
}List_MB;
///////////////////
string sanBay[5] = {"HO CHI MINH","PHU QUOC","NHA TRANG","HA NOI","QUY NHON"};
char staTus[4][15] = {"huy chuyen","con ve","het ve","hoan tat"};
typedef struct {
	char cmnd[15];
	char maghe[5];
	int trangthaive;
}VE;
typedef struct  {
	char ma_CB[15];
	DATETIME ngaygioStart;
	char sanbayDen[40];
	int trangthai;
	char sohieumb[15];
	int soluongVe;
	VE *nodeVe;
}CHUYENBAY;
typedef struct Node_CB{
	CHUYENBAY data;
	struct Node_CB *pNext;
};
typedef struct {
	Node_CB *pHead;
}List_CB;
struct hanhkhach
{
	char cmnd[15];
	char ho[30];
	char ten[30];
	int gioiTinh;
};
typedef struct hanhkhach HANHKHACH;

typedef struct nodeHK
{
	
	HANHKHACH data;			
	nodeHK *Left;
	nodeHK *Right;
};



