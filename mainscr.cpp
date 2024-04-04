#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <fstream>

void osCriticalError() {
	system("cls");
	std::cerr << "An error ocurred, please restart";
}

void login() {
	class users {
	public:
		int passwd;
		std::string un;
		int inp;
	};
	users user;
	std::string inun;
	user.un = "Admin";
	user.inp;
	user.passwd = 1928;
	while (inun != user.un) {
		std::cout << "Enter user name: ";
		std::cin >> inun;
		if (inun == user.un) {
			std::cout << "Correct username" << std::endl;
		}
		if (inun != user.un) {
			std::cout << "Uncorrect user name" << std::endl;
		}
	}
	while (user.inp != user.passwd) {
		std::cout << "Enter password: ";
		std::cin >> user.inp;
		if (user.inp == user.passwd) {
			std::cout << "Correct password, you had been autorised" << std::endl;
		}
		if (user.inp != user.passwd) {
			std::cout << "Uncorrect password, retry" << std::endl;
		}
	}

}

void syslogo() {
	std::cout << " ||||     Name: Test OS" << std::endl;
	std::cout << " ||||     RAM: 4GB     " << std::endl;
	std::cout << " ||||     ROM: 120GB   " << std::endl;
	std::cout << "||||||    version 5.0  " << std::endl;
	std::cout << " ||||                  " << std::endl;
	std::cout << " ||||                  " << std::endl;
	std::cout << "  ||||||               " << std::endl;
}

void notebook() {
	std::string filename = "notes.txt";
	std::ofstream file;


	file.open(filename, std::ios::app);

	if (!file.is_open()) {
		std::cerr << "File already opened." << std::endl;
	}

	std::cout << "Welcome to notepad (To exit app enter 'exit'):\n";

	std::string input;
	while (true) {
		std::getline(std::cin, input);


		if (input == "exit") {
			break;
		}


		file << input << std::endl;
	}

	std::cout << "Text saved. Your text is:\n";

	std::ifstream readFile(filename);
	if (readFile.is_open()) {
		std::string line;
		while (std::getline(readFile, line)) {
			std::cout << line << std::endl;
		}
		readFile.close();
	}
	else {
		std::cerr << "Îøèáêà îòêðûòèÿ ôàéëà äëÿ ÷òåíèÿ." << std::endl;
	}

	file.close();
}

void calendar() {

	time_t now = time(0);
	tm ltm;


	localtime_s(&ltm, &now);


	std::cout << "Year: " << 1900 + ltm.tm_year << std::endl;
	std::cout << "Month: " << 1 + ltm.tm_mon << std::endl;
	std::cout << "Day: " << ltm.tm_mday << std::endl;
	std::cout << "Time: " << ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec << std::endl;

}

void todo() {
	std::string filename = "tasks.txt";
	std::ofstream file;


	file.open(filename, std::ios::app);

	if (!file.is_open()) {
		std::cerr << "Îøèáêà îòêðûòèÿ ôàéëà." << std::endl;
	}

	std::cout << "Welcome to todo (To exit app enter 'exit'):\n";

	std::string input;
	while (true) {
		std::getline(std::cin, input);


		if (input == "exit") {
			break;
		}


		file << input << std::endl;
	}

	std::cout << "Tasks saved. Your tasks are:\n";

	std::ifstream readFile(filename);
	if (readFile.is_open()) {
		std::string line;
		while (std::getline(readFile, line)) {
			std::cout << line << std::endl;
		}
		readFile.close();
	}
	else {
		std::cerr << "File not aviable." << std::endl;
	}

	file.close();
}


void calc() {
	float num1, num2, res;
	char oper = '.';
	std::cout << "Enter first num: ";
	std::cin >> num1;
	std::cout << "Enter second num: ";
	std::cin >> num2;
	std::cout << "Enter operation(+, -, *, /): ";
	std::cin >> oper;
	if (oper == '+') {
		res = num1 + num2;
	}
	if (oper == '-') {
		res = num1 - num2;
	}
	if (oper == '*') {
		res = num1 * num2;
	}
	if (oper == '/') {
		res = num1 / num2;
	}
	std::cout << "Result: " << res << std::endl;

}

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Starting OS" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "Loading..." << std::endl;
	std::string comm = " ";
	login();
	while (true) {
		std::cout << "Enter command: ";
		std::cin >> comm;
		if (comm == "sysinfo") {
			std::cout << "testOS" << std::endl;
		}
		else if (comm == "calc") {
			calc();
		}
		else if (comm == "todo") {
			todo();
		}
		else if (comm == "cal") {
			calendar();
		}
		else if (comm == "nbook") {
			notebook();
		}
		else if (comm == "syslogo") {
			syslogo();
		}
		else if (comm == "logout") {
			std::string ans;
			while (ans != "no", "No") {
				std::cout << "Are you sure you want to log out? (yes, no)";
				std::cin >> ans;
				if (ans == "yes") {
					login();
					break;
				}
				if (ans == "no") {
					std::cout << "Returning..." << std::endl;
					break;
				}
			}

		}

		else if (comm == "crerr") {
			osCriticalError();
			break;
		}

		else {
			std::cout << "Command not found:" << std::endl;
		}
	}

	return 0;
}