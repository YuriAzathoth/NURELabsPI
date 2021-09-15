using namespace std;
using namespace TgBot;

constexpr char	token[]	= "855482418:AAEEtbv1WCpIXSN5RPECQFlY78coMAlU6p0";
constexpr char	dfile[]	= "database.dat";

void PreInitBot()
{
#ifndef __DEBUG
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
#endif // __DEBUG

	signal(SIGINT, [](int s)
	{
		exit(0);
	});
}

bool IsLoginExist(const char* login)
{
	constexpr uint8_t NAME_SIZE = 64;
	const size_t size = strlen(login);
	char name[NAME_SIZE];
	ifstream db(dfile);

	if (!db)
		return false;
	while (!db.eof())
	{
		db.getline(name, NAME_SIZE, '\n');
		if (!strncmp(name, login, size))
			return true;
	}
	return false;
}

void SaveLogin(const char* login, int64_t chat_id)
{
	ofstream db(dfile, ostream::out | ostream::app);
	db << login << "," << chat_id << endl;
	db.close();
}

void BotListener()
{
	PreInitBot();

    umask(0);
    setsid();

	Bot bot(token);
	const Api &api = bot.getApi();

	EventBroadcaster &events = bot.getEvents();
	events.onCommand("start", [&api](Message::Ptr message)
	{
		const char* login	= message->chat->username.c_str();
		uint64_t chat_id	= message->chat->id;

		if (!IsLoginExist(login))
		{
			api.sendMessage(chat_id, "Добро пожаловать в AlgoLearn!");
			SaveLogin(login, chat_id);
		}
		else
			api.sendMessage(chat_id, "Вы уже зарегистрированы в AlgoLearn.");
		cout << "Registered user: Login = " << login << " ChatId = " << chat_id << endl;
	});

	cout << "Bot username: " << api.getMe()->username.c_str() << endl;

	try
	{
		api.deleteWebhook();

		TgLongPoll longPoll(bot);
		while (true)
		{
			cout << "Long poll started" << endl;
			longPoll.start();
		}
	}
	catch (exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
}

void BotWrite(int64_t chat_id = 0, const char* message = nullptr)
{
	PreInitBot();

	Bot bot(token);
	const Api &api = bot.getApi();

	try
	{
		api.deleteWebhook();
		api.sendMessage(chat_id, message);
	}
	catch (exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	if (argc == 2 && !strcmp(argv[1], "start"))
	{
		pid_t pid = fork();
		if (pid)
			BotListener();
	}
	else if (argc == 3)
	{
		pid_t pid = fork();
		if (!pid)
			return 0;
		BotWrite(atoi(argv[1]), argv[2]);
	}
	else
	{
		cout << "Commands:\n" << endl;
		cout << "PrPBot start\n" << endl;
		cout << "PrPBot [user_id] [message]\n" << endl;
	}
}
