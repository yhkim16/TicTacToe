#include <windows.h>
#include <tchar.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPWSTR lpszClass=L"TicTacToe";


int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style=CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);

	while(GetMessage(&Message,0,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	typedef enum TicTurn{Oturn,Xturn} TicTurn;
	HDC hdc;
	PAINTSTRUCT ps;

	LPARAM Lx,Ly;
	static TicTurn turns=Oturn;
	static BOOL bboard[3][3]={0,0,0,0,0,0,0,0,0};
	static BOOL bboardO[3][3]={0,0,0,0,0,0,0,0,0};
	static BOOL bboardX[3][3]={0,0,0,0,0,0,0,0,0};
	int i,j;
	int ix=100,ix2=100,jy=200,jy2=200;
	int Lxs=100,Lys=200,Lxss=100,Lyss=200;

	switch(iMessage)
	{
	case WM_CREATE:
		MoveWindow(hWnd,100,100,500,500,TRUE);
		return 0;
	case WM_PAINT:
        hdc=BeginPaint(hWnd,&ps);
		for(i=0;i<=2;i++)
		{
			for(jy=200;jy<=400;jy=jy+100)
			{
			Rectangle(hdc,ix,ix2,jy,jy2);
			ix=ix+100;
			}
			ix2=ix2+100;
			jy2=jy2+100;
			ix=100;
		}
		if(bboardX[0][0]==TRUE)
		{
		MoveToEx(hdc,125,125,NULL);
		LineTo(hdc,175,175);
		MoveToEx(hdc,175,125,NULL);
		LineTo(hdc,125,175);
		}
		if(bboardX[0][1]==TRUE)
		{
		MoveToEx(hdc,225,125,NULL);
		LineTo(hdc,275,175);
		MoveToEx(hdc,275,125,NULL);
		LineTo(hdc,225,175);
		}
		if(bboardX[0][2]==TRUE)
		{
		MoveToEx(hdc,325,125,NULL);
		LineTo(hdc,375,175);
		MoveToEx(hdc,375,125,NULL);
		LineTo(hdc,325,175);
		}
		if(bboardX[1][0]==TRUE)
		{
		MoveToEx(hdc,125,225,NULL);
		LineTo(hdc,175,275);
		MoveToEx(hdc,175,225,NULL);
		LineTo(hdc,125,275);
		}
		if(bboardX[1][1]==TRUE)
		{
		MoveToEx(hdc,225,225,NULL);
		LineTo(hdc,275,275);
		MoveToEx(hdc,275,225,NULL);
		LineTo(hdc,225,275);
		}
		if(bboardX[1][2]==TRUE)
		{
		MoveToEx(hdc,325,225,NULL);
		LineTo(hdc,375,275);
		MoveToEx(hdc,375,225,NULL);
		LineTo(hdc,325,275);
		}
		if(bboardX[2][0]==TRUE)
		{
		MoveToEx(hdc,125,325,NULL);
		LineTo(hdc,175,375);
		MoveToEx(hdc,175,325,NULL);
		LineTo(hdc,125,375);
		}
		if(bboardX[2][1]==TRUE)
		{
		MoveToEx(hdc,225,325,NULL);
		LineTo(hdc,275,375);
		MoveToEx(hdc,275,325,NULL);
		LineTo(hdc,225,375);
		}
		if(bboardX[2][2]==TRUE)
		{
		MoveToEx(hdc,325,325,NULL);
		LineTo(hdc,375,375);
		MoveToEx(hdc,375,325,NULL);
		LineTo(hdc,325,375);
		}
	if(bboardO[0][0]==TRUE)
	{
		Ellipse(hdc,125,125,175,175);
	}
	if(bboardO[0][1]==TRUE)
	{
		Ellipse(hdc,225,125,275,175);
	}
	if(bboardO[0][2]==TRUE)
	{
		Ellipse(hdc,325,125,375,175);
	}
	if(bboardO[1][0]==TRUE)
	{
		Ellipse(hdc,125,225,175,275);
	}
	if(bboardO[1][1]==TRUE)
		
	{
		Ellipse(hdc,225,225,275,275);
	}
	if(bboardO[1][2]==TRUE)
	{
		Ellipse(hdc,325,225,375,275);
	}
	if(bboardO[2][0]==TRUE)
	{
		Ellipse(hdc,125,325,175,375);
	}
	if(bboardO[2][1]==TRUE)
	{
		Ellipse(hdc,225,325,275,375);
	}
	if(bboardO[2][2]==TRUE)
	{
		Ellipse(hdc,325,325,375,375);
	}
		EndPaint(hWnd,&ps);
		return 0;
	case WM_LBUTTONDOWN:
		Lx=LOWORD(lParam);
		Ly=HIWORD(lParam);
		for(i=0;i<=2;i++)
		{
			if(Lxs<=Ly&&Lys>=Ly)
			{
				for(j=0;j<=2;j++)
				{

						if(Lxss<=Lx&&Lyss>=Lx)
						{
							if(bboard[i][j]!=TRUE)
							{
								bboard[i][j]=TRUE;
							}
							else
							{
								MessageBox(hWnd,L"유효한 위치가 아닙니다!",L"TicTacToe",MB_OK);
								return 0;
							}
							if(turns==Oturn)
							{
								bboardO[i][j]=TRUE;
							}
							if(turns==Xturn)
							{
								bboardX[i][j]=TRUE;
							}
						}
						Lxss=Lxss+100;
						Lyss=Lyss+100;
				}
			}
			Lxs=Lxs+100;
			Lys=Lys+100;
		}
		if(100<=Lx&&400>=Lx)
		{
			if(100<=Ly&&400>=Ly)
			{
				if(turns==Oturn)
				{
					turns=Xturn;
				}
				else
				{
					turns=Oturn;
				}
			}
		}
		InvalidateRect(hWnd,NULL,FALSE);
		SendMessage(hWnd,WM_PAINT,0,0);
		return 0;
		case WM_KEYDOWN:
			switch(wParam)
			{
			case VK_F5:
				for(i=0;i<=2;i++)
				{
					for(j=0;j<=2;j++)
					{
						bboard[i][j]=bboardO[i][j]=bboardX[i][j]=FALSE;
					}
				}
				InvalidateRect(hWnd,NULL,TRUE);
				SendMessage(hWnd,WM_PAINT,0,0);
				return 0;
			}
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_40001:
			SendMessage(hWnd,WM_KEYDOWN,VK_F5,0);
			break;
		case ID_40002:
			SendMessage(hWnd,WM_DESTROY,0,0);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}