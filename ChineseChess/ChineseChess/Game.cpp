#include "Game.h"

// ��L���y�X
// �W:		72
// �U:		80
// ��:		75
// �k:		77
// <:		44
// >:		46
// Enter:	13
// Esc:		27

// ��l��&�ŧi Game.h �̪� extern string [gameMenu]
#ifdef _GAME_MENU_
const string gameMenu[5] = {
	"�סססססססססססססססס�",
	"���@�@�@�@�@���}�l�C���@�@�@�@�@��",
	"�סססססססססססססססס�",
	"���@�@�@�@�@�@�����{���@�@�@�@�@��",
	"�סססססססססססססססס�"
};
#endif // _GAME_MENU_

// ��l��&�ŧi Game.h �̪� extern string [clearBoard]
#ifdef _CLEAR_BOARD_
const string clearBoard[21][18] = {
	{"��","�@","��","�@","��","�@","��","�@","��","�@","��","�@","��","�@","��","�@","��"},
	{"�E","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","�E"},
	{"��","�@","�U","�@","�U","�@","�U","�@","�U","��","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","��","�U","�@","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�@","��","�e","�@","�@","�@"," �@"," ","�@","�@","�~","��","�@","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","�@","�U","��","�U","�@","�U","�@","�U","�@","��"},
	{"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"},
	{"��","�@","�U","�@","�U","�@","�U","��","�U","�@","�U","�@","�U","�@","�U","�@","��"},
	{"�E","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","�E"},
	{"�E","�@","�K","�@","�C","�@","��","�@","��","�@","�|","�@","�T","�@","�G","�@","�@"} 
};
#endif // _CLEAR_BOARD_

// ��l��&�ŧi Game.h �̪� extern const string [chessChinese]
#ifdef _CHESS_CHINESE_
const string chessChinese[15] = { 
	"","�N","�h","�H","��","��","�]","��","��","�K","��","��","�X","��","�L" 
};
#endif // _CHESS_CHINESE_

#ifdef _CURRENT_COORDINATE_
COORDINATE currentCoordinate(0, 0);
#endif // _CURRENT_COORDINATE_


namespace {
	void setColor(int f = 7, int b = 0) {
		// �ϥΪ��`�ΥN�X:240>>�թ��¦r�A116>>�ǩ��`���r�A7>>�©��զr�A252>>�թ����r
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(handle, ForeColor);
	}
	// ����Ŧ�
	void printLeftSpace() { 
		// 1+20
		setColor(7); 
		cout << "���@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
	}
	//�k��Ŧ�
	void printRightSpace() { 
		// 20+1
		setColor(7); 
		cout << "�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@��";	
	}
	int setFileNameAndProcess(string fileName, int chessInt[10][9])
	{
		int whosTurn = 0;
		fstream inputStream;
		inputStream.open(("boardText/"+fileName));
		if (!inputStream)  // operator! is used here
		{
			cout << "�S���o���ɮ�\n";
			system("pause");
			exit(1);
		}
		else {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					inputStream >> chessInt[i][j];
				}
			}
			inputStream >> whosTurn;
			if (inputStream.bad())
				cout << "I/O error while reading\n";
			else if (inputStream.eof())
				cout << "End of file reached successfully\n";
			else if (inputStream.fail())
				cout << "Non-integer data encountered\n";
			inputStream.close();
			return whosTurn;
		}
	}
	// ��X�H��(����)
	void printChess(int i)
	{
		cout << chessChinese[i];
	}
	void printBoard(int chessInt[10][9])
	{
		for (int i = 0; i < 21; i++) {
			printLeftSpace();
			for (int j = 0; j < 18; j++) {
				if (i % 2 == 1 && j % 2 == 0 && chessInt[(i / 2)][(j / 2)] != 0)
				{
					if (chessInt[(i / 2)][(j / 2)] >= 1 && chessInt[(i / 2)][(j / 2)] <= 7) 
						setColor(240);
					else if (chessInt[(i / 2)][(j / 2)] >= 8 && chessInt[(i / 2)][(j / 2)] <= 14) 
						setColor(252);
					printChess(chessInt[(i / 2)][(j / 2)]);
				}
				else {
					// �_�ƦC���Ʀ�P�_int�}�C�̭����F�F
					setColor(116);
					cout << clearBoard[i][j];
				}
			}
			printRightSpace();
			cout << endl;
		}
	}
	void printTopBorder() {
		cout << "��";
		for (int i = 0; i < 57; i++)
			cout << "��";
		cout << "��\n";
	}
	void printDownBorder() {
		cout << "��";
		for (int i = 0; i < 57; i++)
			cout << "��";
		cout << "��";
	}
	void cursorVisiable(bool flag) {
		GetConsoleCursorInfo(handle, &cci);
		cci.bVisible = flag;
		SetConsoleCursorInfo(handle, &cci);
	}
	void setConsoleCursorCoordinate(int x = 42, int y = 2) {
		cursorPosition.X = x;	cursorPosition.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}
}


Game::Game()
{
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	currentCoordinate = make_pair(0, 0);
	//system("cls");
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SMALL_RECT windowSize = { 0,0,33, 20 };
	//SetConsoleWindowInfo(handle, TRUE, &windowSize);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

Game::~Game()
{

}

void Game::showMenu() {

	// �]�m�����j�p
	SMALL_RECT windowSize = { 0,0,34, 4 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// ��ܿ�XMenu���e
	for (int i = 0; i < (sizeof(gameMenu) / sizeof(gameMenu[0])); i++)
		cout << gameMenu[i] << endl;
	
	// �N�e�����W�ԡA�Y���N���Ц�my����0���ܡAconsole�e���N�|���U�@�I
	setConsoleCursorCoordinate(0, 0);

	// �]�w��l���Ц�m
	int commandPress = 0, y = 1;
	setConsoleCursorCoordinate(14, 1);

	// ���å���
	cursorVisiable(false);

	// ���б���
	while (commandPress =_getch())
	{
		if (commandPress == 72)	y -= 2;
		if (commandPress == 80)	y += 2;

		if (commandPress == 13) {
			if (y == 3) {
				exit(1);
			}
			else {
				cout << "\a";
				this->gameStart();
			}
		}

		if (y < 1)	y = 3;
		if (y > 3)	y = 1;

		cout << "\b\b�@";
		cursorPosition.Y = y;
		SetConsoleCursorPosition(handle, cursorPosition);
		cout << "\b\b��";
	}
}

void Game::gameStart() {
	int chessInt[10][9];
	int whosTurn = 0;

	// �M��console
	system("cls");
	// �]�m�����j�p
	SMALL_RECT windowSize = { 0,0,117, 22 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// ø�s�C���e��
	whosTurn = setFileNameAndProcess("Test.txt", chessInt);
	printTopBorder();
	printBoard(chessInt);
	printDownBorder();

	// �N�e�����W�ԡA�Y���N���Ц�my����0���ܡAconsole�e���N�|���U�@�I
	setConsoleCursorCoordinate(0, 0);

	// ��ܥ���(Cursor)
	cursorVisiable(true);

	int commandPress, x = 42, y = 2;
	setConsoleCursorCoordinate();

	while (commandPress = _getch())
	{
		switch (commandPress)
		{
		case 72:				//�W
			y -= 2;
			break;
		case 80:				//�U
			y += 2;
			break;
		case 75:				//��
			x -= 4;
			break;
		case 77:				//�k
			x += 4;
			break;
		case 44:				//<

			break;
		case 46:				//>

			break;
		case 13:				//Enter

			break;
		case 27:				//Esc
			system("cls");
			this->showMenu();
			break;
		default:
			break;
		}

		x = (x > (42 + 32)) ? 42 : x;
		x = (x < 42) ? (42 + 32) : x;
		y = (y > (2 + 18)) ? 2 : y;
		y = (y < 2) ? (2 + 18) : y;
		setConsoleCursorCoordinate(x, y);
	}
}