
// edgeSearching.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CedgeSearchingApp: 
// �йش����ʵ�֣������ edgeSearching.cpp
//

class CedgeSearchingApp : public CWinApp
{
public:
	CedgeSearchingApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CedgeSearchingApp theApp;