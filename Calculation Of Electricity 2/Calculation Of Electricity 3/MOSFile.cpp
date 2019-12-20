
//файл реализации
#include "stdafx.h"
#include "MOSFile.h"

bool MOSFile::FileExists(LPCTSTR fname) {
	return CFileFind().FindFile(fname) == TRUE;
}

CString MOSFile::logNameCreationByDate(bool dateTime, COleDateTime date) {
	CString time;
	if (dateTime == false) {
		time = CTime::GetCurrentTime().Format("%m-%d-%Y %H-%M-%S");
	}
	else {
		time = date.Format(_T("%m-%d-%Y"));
	}
	return time;
}

MOSFile::~MOSFile() {
	delete this;
}