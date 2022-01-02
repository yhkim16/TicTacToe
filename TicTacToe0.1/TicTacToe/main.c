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
	HDC hdc;
	PAINTSTRUCT ps;
	LPARAM Lx,Ly;
	static BOOL bboard[3][3]={0,0,0,0,0,0,0,0,0};
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
		if(bboard[0][0]==TRUE)
		{
		Ellipse(hdc,125,125,175,175);
		}
		if(bboard[0][1]==TRUE)
		{
		Ellipse(hdc,225,125,275,175);
		}
		if(bboard[0][2]==TRUE)
		{
		Ellipse(hdc,325,125,375,175);
		}
		if(bboard[1][0]==TRUE)
		{
		Ellipse(hdc,125,225,175,275);
		}
		if(bboard[1][1]==TRUE)
		{
		Ellipse(hdc,225,225,275,275);
		}
		if(bboard[1][2]==TRUE)
		{
		Ellipse(hdc,325,225,375,275);
		}
		if(bboard[2][0]==TRUE)
		{
		Ellipse(hdc,125,325,175,375);
		}
		if(bboard[2][1]==TRUE)
		{
		Ellipse(hdc,225,325,275,375);
		}
		if(bboard[2][2]==TRUE)
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
				bboard[0][0]=TRUE;
		
			}
			if(200<=Lx&&300>=Lx)
			{
				bboard[0][1]=TRUE;
		
			}
			if(300<=Lx&&400>=Lx)
			{
				bboard[0][2]=TRUE;
		
			}
		}
		if(200<=Ly&&300>=Ly)
		{
			if(100<=Lx&&200>=Lx)
			{
				bboard[1][0]=TRUE;
		
			}
			if(200<=Lx&&300>=Lx)
			{
				bboard[1][1]=TRUE;
		
			}
			if(300<=Lx&&400>=Lx)
			{
				bboard[1][2]=TRUE;
		
			}
		}
		if(300<=Ly&&400>=Ly)
		{
			if(100<=Lx&&200>=Lx)
			{
				bboard[2][0]=TRUE;
		
			}
			if(200<=Lx&&300>=Lx)
			{
				bboard[2][1]=TRUE;
		
			}
			if(300<=Lx&&400>=Lx)
			{
				bboard[2][2]=TRUE;
		
			}
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