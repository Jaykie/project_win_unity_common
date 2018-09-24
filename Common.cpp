#include "pch.h"
#include "Common.h"
#include "CommonInternal.h"
#include "AppPackageInfo.h"

//https://blog.csdn.net/jigetage/article/details/80689809
//Converting a WChar string to a Ansi string  
std::string WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);

	if (nLen <= 0) return std::string("");

	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");

	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;

	std::string strTemp(pszDst);
	delete[] pszDst;

	return strTemp;
}



//Converting a Ansi string to WChar string  

std::wstring Ansi2WChar(LPCSTR pszSrc, int nLen)

{
	int nSize = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pszSrc, nLen, 0, 0);
	if (nSize <= 0) return NULL;

	WCHAR *pwszDst = new WCHAR[nSize + 1];
	if (NULL == pwszDst) return NULL;

	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pszSrc, nLen, pwszDst, nSize);
	pwszDst[nSize] = 0;

	if (pwszDst[0] == 0xFEFF) // skip Oxfeff  
		for (int i = 0; i < nSize; i++)
			pwszDst[i] = pwszDst[i + 1];

	std::wstring wcharString(pwszDst);
	delete pwszDst;

	return wcharString;
}

std::wstring s2ws(const std::string& s)
{ 
	return Ansi2WChar(s.c_str(), s.size()); 
}
std::string ws2s(std::wstring& inputws)
{ 
	return WChar2Ansi(inputws.c_str());
}
String^ string2PlatformString(const std::string& s)
{
	String^ ret = ref new String(s2ws(s).c_str());
	return ret;
}

std::string  PlatformString2string(String^ s)
{
	std::wstring wsstr(s->Data());
	std::string ret(wsstr.begin(), wsstr.end());
	return ret;
}

 char* makeStringCopy(const char*str)
{
	 
	int len = strlen(str) + 1;
	char* res = (char*)malloc(len);
	strcpy_s(res, strlen(res), str);
	//strcpy(res, str);
	return res;
}

 std::wstring UTF8ToUnicode(const std::string& str)
 {
	 int  len = 0;
	 len = str.length();
	 int  unicodeLen = ::MultiByteToWideChar(CP_UTF8,
		 0,
		 str.c_str(),
		 -1,
		 NULL,
		 0);
	 wchar_t *  pUnicode;
	 pUnicode = new  wchar_t[unicodeLen + 1];
	 memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	 ::MultiByteToWideChar(CP_UTF8,
		 0,
		 str.c_str(),
		 -1,
		 (LPWSTR)pUnicode,
		 unicodeLen);
	 std::wstring  rt;
	 rt = (wchar_t*)pUnicode;
	 delete  pUnicode;


	 return  rt;
 }
 char* UnicodeToUtf8(const wchar_t* buf)
 {
	 char* result;


	 int textlen = 0;


	 textlen = WideCharToMultiByte(CP_UTF8, 0, buf, -1, NULL, 0, NULL, NULL);


	 result = (char *)malloc((textlen + 1) * sizeof(char));


	 memset(result, 0, sizeof(char) * (textlen + 1));


	 WideCharToMultiByte(CP_UTF8, 0, buf, -1, result, textlen, NULL, NULL);


	 return result;
 }

 ////GBK 转 UTF8
 //void ConvertGBKToUtf8(CString& strGBK)
 //{
	// int len = ::MultiByteToWideChar(CP_ACP, 0, (LPCSTR)strGBK.GetString(), -1, NULL, 0);
	// unsigned short * wszUtf8 = new unsigned short[len + 1];
	// memset(wszUtf8, 0, len * 2 + 2);
	// ::MultiByteToWideChar(CP_ACP, 0, (LPCSTR)strGBK.GetString(), -1, (LPWSTR)wszUtf8, len);


	// len = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)wszUtf8, -1, NULL, 0, NULL, NULL);
	// char *szUtf8 = new char[len + 1];
	// memset(szUtf8, 0, len + 1);
	// ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)wszUtf8, -1, szUtf8, len, NULL, NULL);


	// strGBK = szUtf8;
	// delete[] szUtf8;
	// delete[] wszUtf8;
 //}


  
char* Common_GetAppName()
{
	String^s = AppPackageInfo::Main()->GetAppName();
	char *p = UnicodeToUtf8(s->Data());
	return p;
 }
 char* Common_GetAppPackage()
{ 
	 String^s = AppPackageInfo::Main()->GetPackage();
	 char *p = UnicodeToUtf8(s->Data());
	 return p;
}
 char* Common_GetAppVerssion()
{
	 String^s = AppPackageInfo::Main()->GetAppVersion();
	 char *p = UnicodeToUtf8(s->Data());
	 return p;
	 /*
	 std::string str = PlatformString2string(AppPackageInfo::Main()->GetAppVersion());
	 return makeStringCopy(str.c_str());*/
}

