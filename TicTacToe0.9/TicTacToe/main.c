#include <windows.h>
#include <tchar.h>

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
	WndClass.lpszMenuName=NULL;
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

	switch(iMessage)
	{
	case WM_CREATE:
		MoveWindow(hWnd,100,100,500,500,TRUE);
		return 0;
	case WM_PAINT:
        hdc=BeginPaint(hWnd,&ps);
		Rectangle(hdc,100,100,200,200);
		Rectangle(hdc,200,100,300,200);
		Rectangle(hdc,300,100,400,200);
		Rectangle(hdc,100,200,200,300);
		Rectangle(hdc,200,200,300,300);
		Rectangle(hdc,300,200,400,300);
		Rectangle(hdc,100,300,200,400);
		Rectangle(hdc,200,300,300,400);
		Rectangle(hdc,300,300,400,400);
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
		if(100<=Ly&&200>=Ly)
		{
			if(100<=Lx&&200>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[0][0]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[0][0]=TRUE;
				}
		
			}
			if(200<=Lx&&300>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[0][1]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[0][1]=TRUE;
				}
			}
			if(300<=Lx&&400>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[0][2]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[0][2]=TRUE;
				}
			}
		}
		if(200<=Ly&&300>=Ly)
		{
			if(100<=Lx&&200>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[1][0]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[1][0]=TRUE;
				}
			}
			if(200<=Lx&&300>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[1][1]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[1][1]=TRUE;
				}
			}
			if(300<=Lx&&400>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[1][2]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[1][2]=TRUE;
				}
			}
		}
		if(300<=Ly&&400>=Ly)
		{
			if(100<=Lx&&200>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[2][0]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[2][0]=TRUE;
				}
			}
			if(200<=Lx&&300>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[2][1]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[2][1]=TRUE;
				}
			}
			if(300<=Lx&&400>=Lx)
			{
				if(turns==Oturn)
				{
					bboardO[2][2]=TRUE;
				}
				if(turns==Xturn)
				{
					bboardX[2][2]=TRUE;
				}
			}
		}
		if(turns==Oturn)
		{
			turns=Xturn;
		}
		else
		{
			turns=Oturn;
		}
		InvalidateRect(hWnd,NULL,FALSE);
		SendMessage(hWnd,WM_PAINT,0,0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}