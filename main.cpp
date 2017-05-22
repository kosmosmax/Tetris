#include "window.h"
#include "game.h"
#include "piece.h"

int main()
{

	Game main_game(BOARD_WIDTH, BOARD_HEIGHT);
	cout << "Game created " << endl;
	cout << "size of shape rectangle is " << sizeof(sf::RectangleShape) << endl;

	/*  Window module is not in charge of drawing contents  */
    sf::RenderWindow window;
    window.create(sf::VideoMode(WINDOW_WIDTH_X, WINDOW_HEIGHT_Y), 
    			  "Tetris by Yuchen He");

    // sf::CircleShape shape(300.f);
    // shape.setFillColor(sf::Color::Blue);
    
    /*  this loads the texture and sprite with the logo.png
        from the directory
        The size is 300*200
        And we want to set the position to (700, 0), top right corner
    */
    sf::Texture logo_t;
    sf::Sprite  logo_s;
    if(! logo_t.loadFromFile("./resource/logo.png")){
        cout << "Failed to load logo image" << endl;
    }
    logo_s.setTexture(logo_t);
    logo_s.setPosition(sf::Vector2f(700, 0));

    /*  Loading the font into the program
    */
    sf::Font font_consolas;
    if(! font_consolas.loadFromFile("./resource/Consolas.ttf")){
        cout << "Failed to load Consolas font" << endl;
    }

    /*  Setting up the text to display with name and date
    */
    sf::Text text_intro;
    text_intro.setFont(font_consolas);
    text_intro.setString("Developed by Yuchen He\n       2017-06");
    text_intro.setCharacterSize(24);
    text_intro.setFillColor(sf::Color::Red);
    text_intro.setPosition(sf::Vector2f(700, 250));
    
    /*  Setting up the variables for time   */
    sf::Time elapsed;
    sf::Int64 usec;
    float elapsed_second;
    sf::Clock clock;
    /*  
        Main Loop / Game Loop
        a loop that ensures the app will be refersed until
        window is closed
    */
    while (window.isOpen()){
        /*  checking timing condition here  */
        // the following code is able to provide an "almost 1-second" periodic 
        // interrupt
        if (clock.getElapsedTime().asSeconds() >= (float)1){
            cout << "1 second passed " << clock.getElapsedTime().asSeconds() << endl;
            uni_active_piece->active_piece_fall();
            clock.restart();
        }



        /*  
            Checking Any Event  
            pollEvent returns true if any event occurs
            Note: this function must be called in the same thread
            where window is creaed
        */
        sf::Event event;
        while (window.pollEvent(event)){
            /*  close the window if close event is detected 
                Window will get closed, program terminated
            */
            //if (event.type == sf::Event::Closed){window.close();}
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TextEntered:
                    // if (event.text.unicode< 128){
                    //     cout << "key pressed is " << 
                    //     (char)(event.text.unicode) << endl;
                    //     if (event.text.unicode == 119 ||
                    //         event.text.unicode == 87){
                    //         cout << "yes " << endl;
                    //         shape.setFillColor(color[flag]);
                    //         flag ++;
                    //         if(flag >= 3){flag = 0;}
                    //         window.clear();
                    //         window.draw(shape);
                    //         window.display();
                    //     }
                    //     else{
                    //         cout << "no " << endl;
                    //         window.clear(sf::Color::White);
                    //         window.display();
                    //     }
                    // }
                    // break;
                //case sf::Event:KeyPressed:

                default:
                    break;
            }

            /*  Draw the logo and intro text   */
            window.clear();
            window.draw(logo_s);
            window.draw(text_intro);
            main_game.draw_board(&window);
            window.display();
        }
    }

	return 0;
}