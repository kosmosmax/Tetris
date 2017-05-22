#include "game.h"

/*	Game::Game()	Default Constructor
	INPUT:	NONE
	OUTPUT:	A default Game object
	EFFECT:	Creates a Game object with board size 0*0 and
			NULL board pointer
*/
Game::Game()
{
	width = 0;
	height = 0;
	board = NULL;
	status = 0;
}

/*	Game::Game(width_arg, height_arg)
	INPUT:	width_arg -- desired width of game board
			height_arg -- desired height of game board
	OUTPUT:	A Game object with board of size width_arg * height_arg
	EFFECT: Creates a Game object with desired dimension
			and board pointer to a corresponding uint8_t array
*/
Game::Game(int32_t width_arg, int32_t height_arg)
{
	if(width_arg <= 0 || height_arg <= 0){
		cout << "width is " << width << endl;
		cout << "height is " << height << endl;
		cout << "Invalid Board Dimension" << endl;
	}
	this->width = width_arg;
	this->height = height_arg;
	this->board = new sf::RectangleShape[width_arg*height_arg];		
	this->status = 0;
	/*	fill in all "cell" with default properties	*/
	int i = 0;
	int pos_x = 0;
	int pos_y = 0;
	for (int row = 0; row < height_arg; ++row){
		for (int col = 0; col < width_arg; ++col){
			i = row * width_arg + col;
			pos_x = board_start_x + col * size_cell;
			pos_y = board_start_y + row * size_cell;
			//	resize the rectangle to single square "cell"	
			(this->board)[i].setSize(sf::Vector2f(size_cell,size_cell));			
			//	set the fill color to blue(just to see if it works)
			(this->board)[i].setFillColor(sf::Color::Blue);
			//	set the location of the shape 
			(this->board)[i].setPosition(sf::Vector2f(pos_x, pos_y));
			//	set the outline of the shape
			(this->board)[i].setOutlineThickness(-1);
			(this->board)[i].setOutlineColor(sf::Color::White);
		}
	}


}

/*	Game::Game(other)	Copy Constructor
	INPUT:	other -- reference to another Game object
	OUPUT:	a Game object which is the same as other
	EFFECT:	Creates a new Game object by copying everything from other
*/
Game::Game(Game const & other)
{
	copy(other);
}
		

/*	Game::~Game()	Destructor	
	INPUT:	NONE
	OUTPUT:	NONE
	EFFECT:	Destroys a Game object by clearing all related field
*/
Game::~Game()
{
	clear();
}
		
/*	operator=(other)	Assignment Operator	
	INPUT:	other -- reference to another Game object
	OUTPUT:	NONE
	EFFECT:	Assign everything from another Game object to this Game
			object
*/
Game const & Game::operator=(Game const & other)
{
	if(this != &other){
		clear();
		copy(other);
	}
	return *this;
}
		
/*	draw_board
	INPUT:	cur_window	-- pointer to the window where we want to draw 
	OUTPUT:	NONE
	EFFECT:	This is supposed to draw the whole game board into window based on
			starting location defined in game.h
*/
void Game::draw_board(sf::RenderWindow* cur_window)
{
	int i = 0;
	for(i = 0; i < (this->width * this->height); ++i){
		cur_window->draw(this->board[i]);
	}
}


/*	copy	private helper function
	INPUT:	other -- reference to another Game object
	OUTPUT:	NONE
	EFFECT:	Assign everything from another Game object to this Game
			object
*/
void Game::copy(Game const & other)
{
	width = other.width;
	height = other.height;
	status = other.status;
	board = new sf::RectangleShape[width*height];
	for (int r = 0; r < height; r++){
		for (int c = 0; c < width; c++){
			board[r*width + c] = (other.board)[r*width + c];		}
	}
}

/*	clear	private helper function
	INPUT:	NONE
	OUTPUT:	NONE
	EFFECT:	clearing all related field of this Game object
*/
void Game::clear()
{
	width = 0;
	height = 0;
	delete [] board;
	status = 0;
}


