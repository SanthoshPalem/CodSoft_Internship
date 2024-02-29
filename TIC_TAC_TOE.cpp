#include <iostream> 
using namespace std;  
void drawBoard(char board[3][3]) 
{ 
	cout << "-----------------\n"; 
	for (int row = 0; row < 3; row++) { 
        if(row==0||row==2)
		cout <<"   ";
        else
        cout<<" | "; 
		for (int col = 0; col < 3; col++) { 
			cout << board[row][col];
            if(col==2&&(row==0||row==2))
            cout<<"   ";
            else
            cout<<" | ";
		} 
		cout << "\n-----------------\n"; 
	} 
} 
void drawBoard_1(string refer_board[3][3]) 
{ 
	cout << "-----------------\n"; 
	for (int row = 0; row < 3; row++) { 
        if(row==0||row==2)
		cout <<"   ";
        else
        cout<<" | "; 
		for (int col = 0; col < 3; col++) { 
			cout << refer_board[row][col];
            if(col==2&&(row==0||row==2))
            cout<<"   ";
            else
            cout<<" | ";
		} 
		cout << "\n-----------------\n"; 
	} 
} 

// Function to check for a win 
bool checkWin(char board[3][3], char currentPlayer) 
{ 
	// Check rows and columns 
	for (int i = 0; i < 3; i++) { 
		if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
		    (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) 
			return true; 
	} 
	// Check diagonals 
	if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || 
	    (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) 
		return true; 
	return false; 
} 

int main() 
{ 
    char gameBoard[3][3] = { { ' ', ' ', ' ' }, 
					         { ' ', ' ', ' ' }, 
					         { ' ', ' ', ' ' } }; 

    cout<<"Reference Board"<<endl;
    string refer_board[3][3] = {{"00", "01", "02"},
                                {"10", "11", "12"},
                                {"20", "21", "22"}};
    drawBoard_1(refer_board);
    
	char currentPlayer = 'X'; 
	int selectedRow, selectedCol; 
	int turn; 
    cout << "Welcome to Tic-Tac-Toe!\n"; 
	for (turn = 0; turn < 9; turn++) { 
		drawBoard(gameBoard);

		while (true) { 
            cout<<"You can use reference board to enter row and column\n\n";
			cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): "; 
			cin >> selectedRow >> selectedCol; 
            if (selectedRow < 0 || selectedRow > 2 || selectedCol < 0 || selectedCol > 2 || 
				gameBoard[selectedRow][selectedCol] != ' ') { 
				cout << "Invalid move. Try again.\n"; 
			} 
			else { 
				break; 
			} 
		} 
		gameBoard[selectedRow][selectedCol] = currentPlayer; 
		if (checkWin(gameBoard, currentPlayer)) { 
			drawBoard(gameBoard); 
			cout << "Player " << currentPlayer << " wins!\n"; 
			break; 
		} 
        if(currentPlayer=='X')
            currentPlayer='O';
        else
            currentPlayer='X';
	} 
	drawBoard(gameBoard); // Check for a draw 
	if (turn == 9 && !checkWin(gameBoard, 'X') && !checkWin(gameBoard, 'O')) { 
		cout << "It's a draw!\n"; 
	} 
    return 0; 
}
