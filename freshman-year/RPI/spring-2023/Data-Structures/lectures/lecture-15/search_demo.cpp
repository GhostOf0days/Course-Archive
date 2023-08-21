// This is just a walk through demo, there is no optimization at all; therefore, following the logic here doesn't guarantee you pass all 8 test cases in terms of runtime constrains on Submitty.

bool insert_word(i,j){
		// store path
		// incrementing index
		// call insert_word()
}

bool search_word(){
	// call search_word()
}

// say we are inserting rest
void insert(words){
	// traverse all the words,
	// for each word:
	// try all i
	// for each i:
	// try all j
	// for each j:
	// try all directions
	// for each direction:
				// insert word
				// if success, store success paths
					// if count is words.size()
						// add board to boards
						// remove current word: rest
						// remove success paths: paths.size() 4->3
						// try next direction.
				// if failure, try other directions.
	// the moment you get here: boards.size() could be 0, but could be 100.
	// all i, all j are tried.
	// remove the previous word: east
	// retry east.	assume you stored the (i,j,dir) of east
	// remove success paths: paths.size() 3->2 or 2->1 or 1->0
	// try another i,j,dir and keep searching east;
}

int main(){
	// read input file to get m and n.
	int m=4;
	int n=4;

	// vector words;
	// vector invalid_words;
	// create one board: '0'
	// vector<vector<char>> board;
	// vector<string> board;
	// vector<vector<vector<char>>> boards
	// board_overlay[][] = 0;
	// + arts
	// + arid
	// + east
	// + rest
	// board:
	// define boards
	// 1. produces the boards (each board contain all the + words
	// print boards.
	// if(boards.size()==0) nothing found, exit
	// if(boards.size()>0)
	// 2. eliminate invalid boards
	// remove_boards(boards)
	// traverse the boards{
	// 	for each board, traverse invalid words{
	// 		search_word();
	// 		search each invalid word,
	// 		if found, boards.erase();	// trap here.
	// 		// i<size, 800, 400
	// 	}
	// }
	// 2.5. replace all the '0's with 26 letters.
	// 
}
