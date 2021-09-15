#include <clocale>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include "CLetter.h"
#include "CStorage.h"
using namespace std;

void Pause()
{
	system(R"(read -p "Для продолжения нажмите [ENTER]" pause)");
}

void PrintMessages(CStorage &rStorage)
{
	const CStorage::TLetters &Letters = rStorage.GetLetters();
	int j = 1;
	for (auto it : Letters)
	{
		cout << j << ". ";
		for (int i = 0; i < it->GetSize(); i++)
			cout << it->GetMessage()[i];
		cout << endl;
		j++;
	}
}

void UserMenu(CStorage &rStorage)
{
	constexpr uint16_t INPUT_BUFFER_SIZE = 256;

	uint16_t hAnswer = 0;
	do
	{
		try
		{
			cout << "Размер ящика(текущ): " << rStorage.GetCurrentSize() << endl;
			cout << "Размер ящика(макс): " << rStorage.GetMaxSize() << endl;
			cout << "Колличество сообщений: " << rStorage.GetMessagesCount() << endl;
			cout << "1. Новое письмо" << endl;
			cout << "2. Читать письма без удаления" << endl;
			cout << "3. Читать письма с удалением" << endl;
			cout << "4. Удалить письмо по номеру" << endl;
			cout << "5. Удалить все письма" << endl;
			cout << "6. Сохранить в резервную копию" << endl;
			cout << "7. Загрузить из резервной копии" << endl;
			cout << "0. Выход" << endl;
			cout << "=>";
			cin >> hAnswer;

			char szInputBuffer[INPUT_BUFFER_SIZE];
			uint32_t nIndex;
			switch(hAnswer)
			{
			case 0: // Exit
				break;
			case 1: // New
				cout << "==>";
				cin.sync();
				cin.getline(szInputBuffer, INPUT_BUFFER_SIZE);
				rStorage.PushMessage(szInputBuffer);
				break;
			case 2: // Read
				PrintMessages(rStorage);
				Pause();
				break;
			case 3: // Read with delete
				PrintMessages(rStorage);
				rStorage.ClearMessages();
				Pause();
				break;
			case 4: // Delete
				PrintMessages(rStorage);
				cout << "0. Back" << endl;
				cout << "=>";
				cin >> nIndex;
				if (nIndex)
					rStorage.RemoveMessage(nIndex - 1);
				break;
			case 5: // Clear
				rStorage.ClearMessages();
				break;
			case 6:
				rStorage.SaveBackup();
				break;
			case 7:
				rStorage.LoadBackup();
				break;
			default:
				cout << "ОШИБКА: Пункта меню " << hAnswer << " не существует!" << endl;
				break;
			}
		}
		catch(logic_error &e)
		{
			cerr << e.what() << endl;
			Pause();
		}

#ifdef __WIN32
		system("cls");
#else
		system("clear");
#endif // __WIN32
	}
	while (hAnswer);
}

int main()
{
	setlocale(LC_ALL, "ru");
	CStorage Storage("../../post/post.dat");
	UserMenu(Storage);
	return 0;
}
