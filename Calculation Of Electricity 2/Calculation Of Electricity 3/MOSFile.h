
//файл заголовка
#pragma once

#include "afxcmn.h"
#include "afxwin.h"

class MOSFile {

public:
	bool FileExists(LPCTSTR fname);
	CString logNameCreationByDate(bool dateTime, COleDateTime date);

	~MOSFile();
};