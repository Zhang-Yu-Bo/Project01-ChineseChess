#include "Game.h"

// 鍵盤掃描碼
// 上:		72
// 下:		80
// 左:		75
// 右:		77
// <:		44
// >:		46
// Enter:	13
// Esc:		27

#ifdef _CONSOLE_INFO_HANDLE_
CONSOLE_CURSOR_INFO cci;
HANDLE handle;
COORD cursorPosition;
#endif // _CONSOLE_INFO_HANDLE_


#ifdef _CHESS_CHINESE_
const string chessChinese[15] = {
		"","將","士","象","車","馬","包","卒","帥","仕","相","車","傌","炮","兵"
};
#endif // _CHESS_CHINESE_

#ifdef _CELAR_BOARD_
const string clearBoard[21][18] = {
		{"１","　","２","　","３","　","４","　","５","　","６","　","７","　","８","　","９"},
		{"‧","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","‧"},
		{"∥","　","｜","　","｜","　","｜","＼","｜","／","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","／","｜","＼","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","－","－","－","－","－","－","－","－","－","－","－","－","－","－","∥"},
		{"∥","　","　","楚","河","　","　","　"," 　"," ","　","　","漢","界","　","　","∥"},
		{"∥","－","－","－","－","－","－","－","－","－","－","－","－","－","－","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","＼","｜","／","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","／","｜","＼","｜","　","｜","　","｜","　","∥"},
		{"‧","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","‧"},
		{"九","　","八","　","七","　","六","　","五","　","四","　","三","　","二","　","一"}
};
#endif // _CLEAR_BOARD_


namespace {
	void setColor(int f = 7, int b = 0) {
		// 使用的常用代碼:240>>白底黑字，116>>灰底深紅字，7>>黑底白字，252>>白底紅字
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(handle, ForeColor);
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
	// 左方空位
	void printLeftSpace() {
		// 1+20
		setColor(7);
		cout << "∥　　　　　　　　　　　　　　　　　　　　";
	}
	//右方空位
	void printRightSpace() {
		// 20+1
		setColor(7);
		cout << "　　　　　　　　　　　　　　　　　　　　∥";
	}
	void printTopBorder() {
		cout << "▼";
		for (int i = 0; i < 57; i++)
			cout << "＝";
		cout << "▼\n";
	}
	void printDownBorder() {
		cout << "▲";
		for (int i = 0; i < 57; i++)
			cout << "＝";
		cout << "▲";
	}
	void printChess(int i) {
		cout << chessChinese[i];
	}
	void printBoard(vector<vector<int>> chessInt) {
		__int64 row, col;
		for (int i = 0; i < 21; i++) {
			printLeftSpace();
			for (int j = 0; j < 18; j++) {
				row = (__int64)(i / 2) + 1;	col = (__int64)(j / 2) + 1;
				if (i % 2 == 1 && j % 2 == 0 && chessInt[row][col] != 0)
				{
					if (chessInt[row][col] >= 1 && chessInt[row][col] <= 7)
						setColor(240, 0);
					else if (chessInt[row][col] >= 8 && chessInt[row][col] <= 14)
						setColor(252, 0);
					printChess(chessInt[row][col]);
				}
				else {
					// 奇數列偶數行判斷int陣列裡面的東東
					setColor(116, 0);
					cout << clearBoard[i][j];
				}
			}
			printRightSpace();
			cout << endl;
		}
	}
	void printBoardNoSpace(vector<vector<int>> chessInt,int m, int n) {
		__int64 row, col;
		for (int i = 0; i < 21; i++) {
			setConsoleCursorCoordinate(m, n + i);
			for (int j = 0; j < 18; j++) {
				row = (__int64)(i / 2) + 1;	col = (__int64)(j / 2) + 1;
				if (i % 2 == 1 && j % 2 == 0 && chessInt[row][col] != 0)
				{
					if (chessInt[row][col] >= 1 && chessInt[row][col] <= 7)
						setColor(240, 0);
					else if (chessInt[row][col] >= 8 && chessInt[row][col] <= 14)
						setColor(252, 0);
					printChess(chessInt[row][col]);
				}
				else {
					// 奇數列偶數行判斷int陣列裡面的東東
					setColor(116, 0);
					cout << clearBoard[i][j];
				}
			}
		}
	}
}


Game::Game()
{
	// 初始化 (黑/紅) (0/1) 的回合
	this->nowTurn = 0;
	// 初始化 棋盤檔名
	this->tableFileName = "Initial.txt";
	// =====================初始化console控制元件=====================
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	// =====================初始化console控制元件=====================
	// 初始化 [boardStatus] 、 [pointBoardStatus]
	for (int i = 0; i < 12; i++) {
		this->boardStatus.push_back(vector<int>());
		this->pointBoardStatus.push_back(vector<Pieces*>());
		for (int j = 0; j < 11; j++) {
			this->boardStatus[i].push_back(-1);
			this->pointBoardStatus[i].push_back(NULL);
		}
	}
}

Game::~Game()
{
	this->boardStatus.erase(this->boardStatus.begin(), this->boardStatus.end());
	this->pointBoardStatus.erase(this->pointBoardStatus.begin(), this->pointBoardStatus.end());
}

void Game::showMenu() {
	if (menu != NULL) {
		menu->showMenu();
		this->~Game();
	}
	
}

void Game::gameStart() {
	// 清空console
	system("cls");
	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,117, 22 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// 繪製遊戲畫面
	setFileNameAndProcess();
	printTopBorder();
	printBoard(this->boardStatus);
	printDownBorder();

	// 將畫面往上拉，若不將光標位置y提至0的話，console畫面將會往下一點
	setConsoleCursorCoordinate(0, 0);

	// 顯示光標(Cursor)
	cursorVisiable(true);

	int commandPress, x = 42, y = 2;
	setConsoleCursorCoordinate(42, 2);
	bool isTakingPiece = false;
	COORDINATE virtualCoordinate = make_pair(1, 1);
	COORDINATE destinationCoordinate = make_pair(1, 1);
	vector<COORDINATE> whereCanMove;
	vector<COORDINATE> whereCanEat;

	while (commandPress = _getch())
	{
		if (commandPress == KEYBOARD_UP) {
			y -= 2;
		}
		else if (commandPress == KEYBOARD_DOWN) {
			y += 2;
		}
		else if (commandPress == KEYBOARD_LEFT) {
			x -= 4;
		}
		else if (commandPress == KEYBOARD_RIGHT) {
			x += 4;
		}
		else if (commandPress == KEYBOARD_LEFT_SHIFT) {

		}
		else if (commandPress == KEYBOARD_RIGHT_SHIFT) {

		}
		else if (commandPress == KEYBOARD_ENTER) {
			if (!isTakingPiece) {
				// 如果現在還沒拿起棋子時：
				// console座標轉換為棋盤座標
				virtualCoordinate.first = (y - 2) / 2 + 1;				//row
				virtualCoordinate.second = (x - 42) / 4 + 1;			//col

				if (this->nowTurn == 0) {
					// 現在回合:黑手
					if (this->boardStatus[virtualCoordinate.first][virtualCoordinate.second] >= 1
						&& this->boardStatus[virtualCoordinate.first][virtualCoordinate.second] <= 7) {
						isTakingPiece = true;

						// 繪製可走範圍
						whereCanMove = this->pointBoardStatus[virtualCoordinate.first][virtualCoordinate.second]->movable(this->boardStatus);
						whereCanEat = this->pointBoardStatus[virtualCoordinate.first][virtualCoordinate.second]->eatable(this->boardStatus);
						for (int j = 0; j < whereCanMove.size(); j++) {
							// 棋盤座標轉換為console座標
							setConsoleCursorCoordinate((whereCanMove[j].second - 1) * 4 + 42, (whereCanMove[j].first - 1) * 2 + 2);
							setColor(28);
							// row=2*y-1		col=2*x-2
							cout << clearBoard[2 * whereCanMove[j].first - 1][2 * whereCanMove[j].second - 2];
						}
						for (int j = 0; j < whereCanEat.size(); j++) {
							// 棋盤座標轉換為console座標
							setConsoleCursorCoordinate((whereCanEat[j].second - 1) * 4 + 42, (whereCanEat[j].first - 1) * 2 + 2);
							setColor(201);
							printChess(this->boardStatus[whereCanEat[j].first][whereCanEat[j].second]);
						}

					}
					else {
						cout << "\a";
					}
				}
				else if (this->nowTurn == 1) {
					// 現在回合:紅手
					if (this->boardStatus[virtualCoordinate.first][virtualCoordinate.second] >= 8
						&& this->boardStatus[virtualCoordinate.first][virtualCoordinate.second] <= 14) {
						isTakingPiece = true;
						
						// 繪製可走範圍
						whereCanMove = this->pointBoardStatus[virtualCoordinate.first][virtualCoordinate.second]->movable(this->boardStatus);
						whereCanEat = this->pointBoardStatus[virtualCoordinate.first][virtualCoordinate.second]->eatable(this->boardStatus);
						for (int j = 0; j < whereCanMove.size(); j++) {
							// 棋盤座標轉換為console座標
							setConsoleCursorCoordinate((whereCanMove[j].second - 1) * 4 + 42, (whereCanMove[j].first - 1) * 2 + 2);
							setColor(28);
							// row=2*y-1		col=2*x-2
							cout << clearBoard[2 * whereCanMove[j].first - 1][2 * whereCanMove[j].second - 2];
						}
						for (int j = 0; j < whereCanEat.size(); j++) {
							// 棋盤座標轉換為console座標
							setConsoleCursorCoordinate((whereCanEat[j].second - 1) * 4 + 42, (whereCanEat[j].first - 1) * 2 + 2);
							setColor(201);
							printChess(this->boardStatus[whereCanEat[j].first][whereCanEat[j].second]);
						}
					}
					else {
						cout << "\a";
					}
				}

			}
			else {
				// 如果現在拿起棋子時：
				// console座標轉換為棋盤座標
				destinationCoordinate.first = (y - 2) / 2 + 1;				//row
				destinationCoordinate.second = (x - 42) / 4 + 1;			//col

				if (virtualCoordinate == destinationCoordinate) {
					// 如果選取原本的位置，則視為放下棋子重新選擇
					isTakingPiece = false;
					setConsoleCursorCoordinate(0, 1);
					printBoard(this->boardStatus);
				}
				else {
					bool isSuccess = false;
					isSuccess = this->pointBoardStatus[virtualCoordinate.first][virtualCoordinate.second]->MoveAndEat(
						destinationCoordinate,
						this->boardStatus,
						this->pointBoardStatus
					);
					if (isSuccess) {
						// 移動或吃棋成功
						isTakingPiece = false;
						this->nowTurn = (this->nowTurn == 0) ? 1 : 0;
						printBoardNoSpace(this->boardStatus, 42, 1);
					}
					else {
						cout << "\a";
					}
				}
			}
		}
		else if (commandPress == KEYBOARD_ESCAPE) {
			system("cls");
			this->showMenu();
		}

		x = (x > (42 + 32)) ? 42 : x;
		x = (x < 42) ? (42 + 32) : x;
		y = (y > (2 + 18)) ? 2 : y;
		y = (y < 2) ? (2 + 18) : y;
		setConsoleCursorCoordinate(x, y);
	}
}

void Game::setFileNameAndProcess() {
	fstream inputStream;
	
	inputStream.open(("boardText/" + this->tableFileName));
	if (!inputStream)  // operator! is used here
	{
		cout << "沒有這個檔案\n";
		system("pause");
		exit(1);
	}
	else {
		bool isBlackOrRed = false;
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 10; j++) {
				inputStream >> boardStatus[i][j];
				isBlackOrRed = (boardStatus[i][j] >= 1 && boardStatus[i][j] <= 7) ? false : true;
				// 建立pointboardStatus
				if (boardStatus[i][j] == 1 || boardStatus[i][j]==8) {
					this->pointBoardStatus[i][j] = new ClassGeneral(i, j, isBlackOrRed);
				}
				else if (boardStatus[i][j] == 2 || boardStatus[i][j]==9) {
					this->pointBoardStatus[i][j] = new ClassGuard(i, j, isBlackOrRed);
				}
				else if (boardStatus[i][j] == 3 || boardStatus[i][j]==10) {
					this->pointBoardStatus[i][j] = new ClassMinister(i, j, isBlackOrRed);
				}
				else if (boardStatus[i][j] == 4 || boardStatus[i][j]==11) {
					this->pointBoardStatus[i][j] = new ClassRook(i, j, isBlackOrRed);
				}
				else if (boardStatus[i][j] == 5 || boardStatus[i][j]==12) {
					this->pointBoardStatus[i][j] = new ClassHorse(i, j, isBlackOrRed);
				}
				else if (boardStatus[i][j] == 6 || boardStatus[i][j]==13) {
					this->pointBoardStatus[i][j] = new ClassCannon(i, j, isBlackOrRed);
				}
				else if (boardStatus[i][j] == 7 || boardStatus[i][j]==14) {
					this->pointBoardStatus[i][j] = new ClassSoldier(i, j, isBlackOrRed);
				}
				// 結束建立pointboardStatus
			}
		}
		inputStream >> this->nowTurn;
		inputStream.close();
	}
}