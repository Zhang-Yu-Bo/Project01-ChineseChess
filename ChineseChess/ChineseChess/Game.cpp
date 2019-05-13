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

#ifdef _GAME_MENU_
const string gameMenuOption[5] = {
		"▼＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▼",
		"∥　　　　　→繼續遊戲　　　　　∥",
		"∥＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝∥",
		"∥　　　　　　返回主選單　　　　∥",
		"▲＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▲"
};
#endif // _GAME_MENU_

#ifdef _LEFT_RIGHT_SPACE_
const string leftSpace[21] = {
	"∥　　　　　　　　　　　　　　　　　　　　",
	"∥　。－－－－－－戰況顯示－－－－－－。　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　｜　　　　　　　　　　　　　　　　｜　",
	"∥　。－－－－－－－－－－－－－－－－。　",
	"∥　　　　　　　　　　　　　　　　　　　　"
};
const string rightSpace[21] = {
	"　　　　　　　　　　　　　　　　　　　　∥",
	"　。－－－－－－－－－－－－－－－－。　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　。－－－－－－－－－－－－－－－－。　∥",
	"　　　　　　　　　　　　　　　　　　　　∥",
	"　　　　　　　　　　　　　　　　　　　　∥",
	"　。－－－－－－－－－－－－－－－－。　∥",
	"　｜　　　↑　　　　　　　　　　　　｜　∥",
	"　｜　　←＋→　　方向鍵選棋　　　　｜　∥",
	"　｜　　　↓　　　　　　　　　　　　｜　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　｜　　Ｅｎｔｅｒ　選取棋子　　　　｜　∥",
	"　｜　　　Ｅｓｃ　　開啟選單　　　　｜　∥",
	"　｜　　　　＜　　　悔棋　　　　　　｜　∥",
	"　｜　　　　　　　　　　　　　　　　｜　∥",
	"　。－－－－－－－－－－－－－－－－。　∥",
	"　　　　　　　　　　　　　　　　　　　　∥"
};
#endif // _LEFT_RIGHT_SPACE_




namespace {
	void setColor(int f = 7, int b = 0) {
		// 使用的常用代碼:240>>白底黑字，116>>灰底深紅字，7>>黑底白字，252>>白底紅字
		// 28>>可移動位置，201>>可叫吃位置
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(handle, ForeColor);
	}
	// Intent:顯示/隱藏 console 的游(光)標 cursor
	// Pre:傳入bool，true->顯示 / false->隱藏
	// Post:無
	void cursorVisiable(bool flag) {
		GetConsoleCursorInfo(handle, &cci);
		cci.bVisible = flag;
		SetConsoleCursorInfo(handle, &cci);
	}
	// Intent:設置console游(光)標cursor 位置
	// Pre:int [x]、[y]，左上角為(0,0)			/// (42,2)為棋盤內可移動的最左上角
	// Post:無
	void setConsoleCursorCoordinate(int x = 42, int y = 1) {
		cursorPosition.X = x;	cursorPosition.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}
	// 左方空位
	void printLeftSpace(int i) {
		// 1+20
		setColor(7);
		cout << leftSpace[i];
	}
	//右方空位
	void printRightSpace(int i) {
		// 20+1
		setColor(7);
		cout << rightSpace[i];
	}
	void printTopBorder() {
		setColor(7);
		cout << "▼";
		for (int i = 0; i < 57; i++)
			cout << "＝";
		cout << "▼\n";
	}
	void printDownBorder() {
		setColor(7);
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
			printLeftSpace(i);
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
			printRightSpace(i);
			cout << endl;
		}
	}

	// 更新整個棋盤without空白
	void printBoardNoSpace(vector<vector<int>> chessInt, int m = 42, int n = 1) {
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

	// 顯示yes no對話框
	bool showDialog(string msg) {
		setColor(132);
		setConsoleCursorCoordinate(42, 6);
		cout << "▼＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▼";
		for (int i = 1; i <= 11; i++) {
			setConsoleCursorCoordinate(42, 6 + i);
			cout << "∥　　　　　　　　　　　　　　　∥";
			if (i == 3) {
				setConsoleCursorCoordinate(46, 6 + i);
				cout << msg;
			}
			else if (i == 8) {
				setConsoleCursorCoordinate(60, 6 + i);
				cout << "是";
				setConsoleCursorCoordinate(68, 6 + i);
				cout << "否";
			}
		}
		setConsoleCursorCoordinate(42, 17);
		cout << "▲＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▲";

		setConsoleCursorCoordinate(60, 14);
		int commandPress = 0, x = 60;
		while (commandPress = _getch())
		{
			if (commandPress == KEYBOARD_LEFT) {
				x -= 8;
			}
			else if (commandPress == KEYBOARD_RIGHT) {
				x += 8;
			}
			else if (commandPress == KEYBOARD_ENTER) {
				if (x == 60) {
					return true;
				}
				else if (x == 68) {
					return false;
				}
			}
			else if (commandPress == KEYBOARD_ESCAPE) {
				return false;
			}
			x = (x > 68) ? 60 : x;
			x = (x < 60) ? 68 : x;
			setConsoleCursorCoordinate(x, 14);
		}
	}

}


Game::Game()
{
	// 初始化 (黑/紅) (0/1) 的回合
	this->nowTurn = 0;
	// 初始化 棋盤檔名
	this->tableFileName = "Initial.txt";
	//this->tableFileName = "Check.txt";
	//this->tableFileName = "Test.txt";
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
	// 清空vector
	for (int i = 0; i < this->boardStatus.size(); i++) 
		this->boardStatus[i].erase(this->boardStatus[i].begin(), this->boardStatus[i].end());
	this->boardStatus.erase(this->boardStatus.begin(), this->boardStatus.end());

	for (int i = 0; i < this->pointBoardStatus.size(); i++) 
		this->pointBoardStatus[i].erase(this->pointBoardStatus[i].begin(), this->pointBoardStatus[i].end());
	this->pointBoardStatus.erase(this->pointBoardStatus.begin(), this->pointBoardStatus.end());

	for (int i = 0; i < this->theLogsOfBS.size(); i++) {
		for (int j = 0; j < this->theLogsOfBS[i].size(); j++) {
			this->theLogsOfBS[i][j].erase(this->theLogsOfBS[i][j].begin(), this->theLogsOfBS[i][j].end());
		}
		this->theLogsOfBS[i].erase(this->theLogsOfBS[i].begin(), this->theLogsOfBS[i].end());
	}
	this->theLogsOfBS.erase(this->theLogsOfBS.begin(), this->theLogsOfBS.end());

}

void Game::showMenu() {
	setColor(7);

	// 顯示gameMenu
	for (int i = 0; i < (sizeof(gameMenuOption) / sizeof(gameMenuOption[0])); i++) {
		setConsoleCursorCoordinate(42, 5 + i);
		cout << gameMenuOption[i];
	}
	// 宣告gameMenu 專屬console座標 int [y]
	int commandPress, y = 6;
	// 設定console座標位置，從(54,6)開始繪製
	setConsoleCursorCoordinate(54, 6);
	cursorVisiable(false);
	while (commandPress = _getch())
	{
		if (commandPress == KEYBOARD_UP) {
			y -= 2;
		}
		else if (commandPress == KEYBOARD_DOWN) {
			y += 2;
		}
		else if (commandPress == KEYBOARD_ENTER) {
			if (y == 6) {
				cursorVisiable(true);
				printBoardNoSpace(this->boardStatus, 42, 1);
				break;
			}
			else if (y == 8) {
				if (menu != NULL) {
					system("cls");
					menu->showMenu();
					this->~Game();
				}
			}
		}
		else if (commandPress == KEYBOARD_ESCAPE) {
			cursorVisiable(true);
			printBoardNoSpace(this->boardStatus, 42, 1);
			break;
		}
		y = (y > 8) ? 6 : y;
		y = (y < 6) ? 8 : y;
		cout << "　\b\b";
		setConsoleCursorCoordinate(54, y);
		cout << "→\b\b";
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

	// 下背景音樂
	//PlaySound("Sounds/Lucid_Dreamer.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	// 將畫面往上拉，若不將光標位置y提至0的話，console畫面將會往下一點
	setConsoleCursorCoordinate(0, 0);

	// 顯示光標(Cursor)
	cursorVisiable(true);

	// 顯示提示，現在回合
	this->showTurn();

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
			
			if (this->battleStatus.size() >= 2) {
				// 放下棋子
				isTakingPiece = false;

				if (showDialog("是否要悔棋呢？")) {
					// 刪除棋盤和戰況紀錄
					this->theLogsOfBS.erase(this->theLogsOfBS.end() - 2, this->theLogsOfBS.end());
					this->battleStatus.erase(this->battleStatus.end() - 2, this->battleStatus.end());
				}


				if (this->theLogsOfBS.size() == 0)
					setFileNameAndProcess();
				else
					this->boardStatus = *(this->theLogsOfBS.end() - 1);

				boardStatusToPointBoardStatus();
				setColor(7);
				setConsoleCursorCoordinate(0, 1);
				// 將舊戰況紀錄擦掉
				printBoard(this->boardStatus);
				this->showTurn();
				this->showChoice(0);
				this->showBattleStatus();
				// 更新第二次畫面，較不會顯示錯誤
				printBoardNoSpace(this->boardStatus);
				
			}
			else {
				cout << "\a";
			}

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

						// 顯示提示，選取棋子
						this->showChoice(this->boardStatus[virtualCoordinate.first][virtualCoordinate.second]);

						// 繪製可走/吃範圍
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

						// 顯示提示，選取棋子
						this->showChoice(this->boardStatus[virtualCoordinate.first][virtualCoordinate.second]);
						
						// 繪製可走/吃範圍
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
					printBoardNoSpace(this->boardStatus);
					// 顯示提示，現在回合，選取棋子
					this->showTurn();
					this->showChoice(0);
				}
				else {
					string chineseNotation;
					bool isSuccess = false;
					isSuccess = this->pointBoardStatus[virtualCoordinate.first]
						[virtualCoordinate.second]
					->MoveAndEat(
						destinationCoordinate,
						this->boardStatus,
						this->pointBoardStatus,
						chineseNotation
					);
					if (isSuccess) {
						this->battleStatus.push_back(chineseNotation);
						this->theLogsOfBS.push_back(this->boardStatus);

						// 下棋聲
						mciSendString("play \"Sounds/下棋聲.mp3\" ", NULL, 0, 0);

						// 移動或吃棋成功
						isTakingPiece = false;
						int victory = JudgeVictory(boardStatus);

						if(victory == BLACK){
							//BLACK wins;
							if (showDialog("黑方勝利，重新開始一局嗎？")) {
								system("cls");
								menu->showMenu();
								this->~Game();
							}
							else {
								if (menu != NULL) {
									system("cls");
									menu->showMenu();
									this->~Game();
								}
							}
						}
						else if (victory == RED) {
							//RED wins;
							if (showDialog("紅方勝利，重新開始一局嗎？")) {
								system("cls");
								menu->showMenu();
								this->~Game();
							}
							else {
								if (menu != NULL) {
									system("cls");
									menu->showMenu();
									this->~Game();
								}
							}
						}
						
						this->nowTurn = (this->nowTurn == 0) ? 1 : 0;
						printBoardNoSpace(this->boardStatus, 42, 1);
						// 顯示提示，現在回合，選取棋子
						this->showTurn();
						this->showChoice(0);
						this->showBattleStatus();
					}
					else {
						cout << "\a";
					}
				}
			}
		}
		else if (commandPress == KEYBOARD_ESCAPE) {
			isTakingPiece = false;
			this->showTurn();
			this->showChoice(0);
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
		whoStart = nowTurn;
		inputStream.close();
	}
}

void Game::showTurn() {
	setConsoleCursorCoordinate(86, 4);
	setColor(27);
	cout << "現在輪到　";
	if (this->nowTurn == 1) {
		setColor(76);
		cout << "紅色方";
	}
	else {
		setColor(128);
		cout << "黑色方";
	}
	setColor(27);
	cout << "下棋";
}

void Game::showBattleStatus() {
	if (battleStatus.size() <= 8) {
		int i = 1;
		for (vector<string>::iterator iter = battleStatus.begin(); iter != battleStatus.end(); iter++,i++) {
			setConsoleCursorCoordinate(12, 2 + 2 * i);
			cout << std::setw(4) << i << "　";// << *iter;
			if ((whoStart + i) % 2 == 1) {
				setColor(240);
				cout << "黑";
			}
			else {
				setColor(252);
				cout << "紅";
			}
			setColor(7);
			cout << "：" << *iter;
		}
	}
	else if (battleStatus.size() > 7) {
		vector<string>::reverse_iterator r_iter = battleStatus.rbegin();
		for (int i = 0; i <= 7; i++) {
			setConsoleCursorCoordinate(12, 4 + (2 * i));
			cout << std::setw(4) << battleStatus.size() - (7 - i) << "　";
			if ((whoStart + battleStatus.size() - (7 - i)) % 2 == 1) {
				setColor(240);
				cout << "黑";
			}
			else {
				setColor(252);
				cout << "紅";
			}
			setColor(7);
			cout << "：" << *(r_iter + (7 - i));
		}
	}
	//setConsoleCursorCoordinate(12, 4);
}

void Game::showChoice(int choice) {
	setConsoleCursorCoordinate(90, 6);
	if (choice == 0) {
		setColor(7);
		cout << "　　　　　　";
	}
	else {
		setColor(27);
		cout << "您選擇了　";
		if (this->nowTurn == 1) {
			setColor(76);
			printChess(choice);
		}
		else {
			setColor(128);
			printChess(choice);
		}
	}
}

int Game::JudgeVictory(const vector<vector<int>>& boardStatus) {
	//查找將與帥的位置
	vector<int>::const_iterator iterB, iterR;
	int ib, ir;
	bool isBAlive = false, isRAlive = false;
	//ib from 1~3(將)
	for (ib = 1; ib <= 3; ib++) {
		iterB = find(boardStatus[ib].begin(), boardStatus[ib].end(), 1);
		if (iterB != boardStatus[ib].end()) {
			isBAlive = true;
			break;
		}
	}
	//ir from 8~10(帥)
	for (ir = 8; ir <= 10; ir++) {
		iterR = find(boardStatus[ir].begin(), boardStatus[ir].end(), 8);
		if (iterR != boardStatus[ir].end()) {
			isRAlive = true;
			break;
		}
	}

	if (!isRAlive)return BLACK;
	if (!isBAlive)return RED;
	
	if (iterB == boardStatus[ib].end() || iterR == boardStatus[ir].end()) {
		//error
		return -2;
	}
	
	Pieces BG(*pointBoardStatus[ib][iterB - boardStatus[ib].begin()]);
	Pieces RG(*pointBoardStatus[ir][iterR - boardStatus[ir].begin()]);
	if (!BG.JudgeAlive()) return RED;//紅方獲勝
	else if (!RG.JudgeAlive()) return BLACK;//黑方獲勝
	if (BG.FetchPosition().second == RG.FetchPosition().second) {//在同一個column上
		int j = BG.FetchPosition().second;
		int ib = BG.FetchPosition().first;
		int ir = RG.FetchPosition().first;
		int k = 1;
		while (ib + k < boardBottom &&
			(boardStatus[ib + k][j] == 0)) {
			k++;
		}
		ib += k;
		if (ib == ir) {//射箭
			if (nowTurn == BLACK) {//黑方
				return RED;//紅方獲勝
			}
			else {//紅方
				return BLACK;//黑方獲勝
			}
		}
	}
	return -1;
}

void Game::boardStatusToPointBoardStatus() {

	bool isBlackOrRed = false;

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 10; j++) {
			isBlackOrRed = (this->boardStatus[i][j] >= 1 && this->boardStatus[i][j] <= 7) ? false : true;
			// 建立pointboardStatus
			if (boardStatus[i][j] == 1 || boardStatus[i][j] == 8) {
				this->pointBoardStatus[i][j] = new ClassGeneral(i, j, isBlackOrRed);
			}
			else if (boardStatus[i][j] == 2 || boardStatus[i][j] == 9) {
				this->pointBoardStatus[i][j] = new ClassGuard(i, j, isBlackOrRed);
			}
			else if (boardStatus[i][j] == 3 || boardStatus[i][j] == 10) {
				this->pointBoardStatus[i][j] = new ClassMinister(i, j, isBlackOrRed);
			}
			else if (boardStatus[i][j] == 4 || boardStatus[i][j] == 11) {
				this->pointBoardStatus[i][j] = new ClassRook(i, j, isBlackOrRed);
			}
			else if (boardStatus[i][j] == 5 || boardStatus[i][j] == 12) {
				this->pointBoardStatus[i][j] = new ClassHorse(i, j, isBlackOrRed);
			}
			else if (boardStatus[i][j] == 6 || boardStatus[i][j] == 13) {
				this->pointBoardStatus[i][j] = new ClassCannon(i, j, isBlackOrRed);
			}
			else if (boardStatus[i][j] == 7 || boardStatus[i][j] == 14) {
				this->pointBoardStatus[i][j] = new ClassSoldier(i, j, isBlackOrRed);
			}
			// 結束建立pointboardStatus
		}
	}
}