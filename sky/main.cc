#include "level.h"
#include "game.h"
#include "textDisplay.h"
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include "graph.h"


int main(int argc, char *argv[]) {
    Game g1{};
    TextDisplay td{&g1};
    Graph graph { nullptr, nullptr, nullptr };
    
    g1.newGame();
    
    int startLevel = 0;
    bool graphical = true;
    std::string file1 = "sequence1.txt";
    std::string file2 = "sequence2.txt";
    int index = 1;
    while (index < argc) {
        std::string flag = argv[index];
        if (flag == "-text") { graphical = false; }
        if (flag == "-seed") {
            index += 1;
            //TODO: doing nothing, add something here!
        }
        if (flag == "-scriptfile1") {
            index += 1;
            file1 = argv[index];
        }
        if (flag == "-scriptfile2") {
            index += 1;
            file2 = argv[index];
        }
        if (flag == "-startlevel") {
            index += 1;
            std::string temp = argv[index];
            std::istringstream iss {temp};
            iss >> startLevel;
        }
        index += 1;
    }



    // int times = 0;
    std::string cmd;

    // std::cin >> times;

    g1.players[0]->init();
    g1.players[1]->init();
    bool isPlayer0GameOver = false;
    bool isPlayer1GameOver = false;

    td.print();
    if (true) {
        graph = Graph {g1.players[0].get(), g1.players[1].get(), &td};
    }
    if(true) { //TODO: to graphical
                graph.printGraph();
            }

    while (true) {
        while (g1.players[0]->is_playing) {
            // player 0 is playing
            std::cout << "cmd for player 0?" << std::endl;
            std::cin >> cmd;
            if (cmd == "left") {
                g1.players[0]->left();
            } else if (cmd == "right") {
                g1.players[0]->right();
            } else if (cmd == "down") {
                g1.players[0]->down();
            } else if (cmd == "drop") {
                std::cout << "next Block for player 0?" << std::endl;
                g1.players[0]->drop();
            } else if (cmd == "cw") {
                g1.players[0]->rot_cw();
            } else if (cmd == "ccw") {
                g1.players[0]->rot_ccw();
            } else {
                continue;
            }
            td.print();
            if(true) { //TODO: to graphical
                graph.printGraph();
            }
        }
        if (g1.players[0]->gameOver) {// check if player 0 game over
            std::cout << "player 0 game over" << std::endl;
            isPlayer0GameOver = true;
        }

        if (isPlayer1GameOver == false) {
            g1.players[1]->is_playing = true;
        }

        while (g1.players[1]->is_playing) {
            // player 1 is playing
            std::cout << "cmd for player 1?" << std::endl;
            std::cin >> cmd;
            if (cmd == "left") {
                g1.players[1]->left();
            } else if (cmd == "right") {
                g1.players[1]->right();
            } else if (cmd == "down") {
                g1.players[1]->down();
            } else if (cmd == "drop") {
                std::cout << "next Block for player 1?" << std::endl;
                g1.players[1]->drop();
            } else if (cmd == "cw") {
                g1.players[1]->rot_cw();
            } else if (cmd == "ccw") {
                g1.players[1]->rot_ccw();
            } else {
                continue;
            }
            td.print();
            if(true) {
                graph.printGraph();
            }
        }
        if (g1.players[1]->gameOver) {//check if player1 game over
            std::cout << "player 1 game over" << std::endl;
            isPlayer1GameOver = true;
        }
        if (isPlayer0GameOver == false) {
            g1.players[0]->is_playing = true;
        }

       //TODO: if both game over, the game loop breaks
       if (isPlayer0GameOver && isPlayer1GameOver) { break; }
    }
}
