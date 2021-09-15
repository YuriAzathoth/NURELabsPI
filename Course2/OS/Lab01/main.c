#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define DATA_COUNT 3
#define DATA_SIZE 32

#define UNICODE
#ifdef UNICODE
	typedef wchar_t TCHAR;
	#define _T(a) L##a
	#define _tcslen wcslen
	#define _tprintf wprintf
#else
	typedef char TCHAR;
	#define _T(a) a
	#define _tcslen strlen
	#define _tprintf printf
#endif // UNICODE

char IsUnicode()
{
	if (sizeof(TCHAR) == 1)
		return 0;
	else
		return 1;
}

int str_comparator(const void* lhs, const void* rhs)
{
	return wcscmp((wchar_t*)lhs, (wchar_t*) rhs);
}

int main()
{
	setlocale(LC_ALL, "");

	_tprintf(_T("Текущая кодировка: %S\n\n"), (IsUnicode() == 0) ? _T("ASCII") : _T("Юникод"));

	const char szSource[DATA_COUNT][DATA_SIZE] =
	{
		"Зинченко Юрий",
		"Зинченко Ирина",
		"Зинченко Сергей"
	};

	char szAscii[DATA_COUNT][DATA_SIZE];
	wchar_t wszUnicode[DATA_COUNT][DATA_SIZE];

	_tprintf(_T("Исходные данные в ASCII:\n"));
	for (int i = 0; i < DATA_COUNT; i++)
		_tprintf(_T("%s\n"), szSource[i]);
	_tprintf(_T("\n"));

	for (int i = 0; i < DATA_COUNT; i++)
		mbstowcs(wszUnicode[i], szSource[i], DATA_SIZE);

	_tprintf(_T("Данные в Юникоде:\n"));
	for (int i = 0; i < DATA_COUNT; i++)
		_tprintf(_T("%S\n"), wszUnicode[i]);
	_tprintf(_T("\n"));

	for (int i = 0; i < DATA_COUNT; i++)
		wcstombs(szAscii[i], wszUnicode[i], DATA_SIZE);

	_tprintf(_T("И обратно в ASCII:\n"));
	for (int i = 0; i < DATA_COUNT; i++)
		_tprintf(_T("%s\n"), szAscii[i]);
	_tprintf(_T("\n"));

	qsort(wszUnicode, DATA_COUNT, DATA_SIZE * sizeof(wchar_t), str_comparator);

	_tprintf(_T("Отсортированные данные:\n"));
	for (int i = 0; i < DATA_COUNT; i++)
		_tprintf(_T("%S\n"), wszUnicode[i]);
	_tprintf(_T("\n"));

	return 0;
}
