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
        if (flag == "-text") { 
            graphical = false; }
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

    // modify board levelNo to match startLevel
    g1.players[0]->levelNo = startLevel;
    g1.players[1]->levelNo = startLevel;

    // update file stream for level0
    g1.players[0]->file = file1;
    g1.players[1]->file = file2;
    g1.players[0]->level0.updateFile(g1.players[0]->file);
    g1.players[1]->level0.updateFile(g1.players[1]->file);

    // int times = 0;
    std::string cmd;

    // std::cin >> times;

    g1.players[0]->init();
    g1.players[1]->init();
    bool isPlayer0GameOver = false;
    bool isPlayer1GameOver = false;

    td.print();
    

    if (graphical) {
        graph = Graph {g1.players[0].get(), g1.players[1].get(), &td};
    }
    if (graphical) {
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
            } else if (cmd == "clockwise") {
                g1.players[0]->rot_cw();
            } else if (cmd == "counterclockwise") {
                g1.players[0]->rot_ccw();
            } else if (cmd == "drop") {
                if (g1.players[0]->heavy) { g1.players[0]->heavy = false; }
                if (g1.players[0]->force) { g1.players[0]->force = false; }
                if (g1.players[0]->blind) { g1.players[0]->blind = false; }

                int rowsRemoved = 0;
                g1.players[0]->drop(&rowsRemoved);

                g1.updateTopScore();
                std::cout << "next Block for player 0?" << std::endl;
                
                if (rowsRemoved >= 2) {
                    std::string specialAction;
                    std::cin >> specialAction;
                    if (specialAction == "heavy") {
                        g1.players[1]->heavy = true;
                    } else if (specialAction == "force") {
                        std::string type;
                        std::cin >> type;
                        if (type == "I") {
                            if (g1.players[1]->currBlock->getType() == 'I') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Iblock>();
                            }
                        } else if (type == "J") {
                            if (g1.players[1]->currBlock->getType() == 'J') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Jblock>();
                            }
                        } else if (type == "L") {
                            if (g1.players[1]->currBlock->getType() == 'L') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Lblock>();
                            }
                        } else if (type == "O") {
                            if (g1.players[1]->currBlock->getType() == 'O') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Oblock>();
                            }
                        } else if (type == "S") {
                            if (g1.players[1]->currBlock->getType() == 'S') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Sblock>();
                            }
                        } else if (type == "Z") {
                            if (g1.players[1]->currBlock->getType() == 'Z') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Zblock>();
                            }
                        } else if (type == "T") {
                            if (g1.players[1]->currBlock->getType() == 'T') {
                                continue; 
                            } else {
                                g1.players[1]->currBlock = std::make_unique<Tblock>();
                            }
                        }
                    } else if (specialAction == "blind") {
                        g1.players[1]->blind = true;
                        td.isBlind2 = true;
                    } else {
                        std::cout << "Invalid special action input" << std::endl;
                        // do nothing
                    }
                }

                // if two or more rows are cleared
                // ask for a cmd input to trigger special action
                // let the otherboard.heavy = true;
                // inside drop() { heavy = false; }
            } else if (cmd == "levelup") {
                g1.players[0]->levelUp();
            } else if (cmd == "leveldown") {
                g1.players[0]->levelDown();
            } else if (cmd == "I") {
                if (g1.players[0]->currBlock->getType() == 'I') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Iblock>();
                }
            } else if (cmd == "J") {
                if (g1.players[0]->currBlock->getType() == 'J') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Jblock>();
                }
            } else if (cmd == "L") {
                if (g1.players[0]->currBlock->getType() == 'L') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Lblock>();
                }
            } else if (cmd == "O") {
                if (g1.players[0]->currBlock->getType() == 'O') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Oblock>();
                }
            } else if (cmd == "S") {
                if (g1.players[0]->currBlock->getType() == 'S') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Sblock>();
                }
            } else if (cmd == "Z") {
                if (g1.players[0]->currBlock->getType() == 'Z') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Zblock>();
                }
            } else if (cmd == "T") {
                if (g1.players[0]->currBlock->getType() == 'T') { continue; }
                else {
                    g1.players[0]->currBlock = std::make_unique<Tblock>();
                }
            } else if (cmd == "restart") {
                g1.newGame();
                td.restart();
                //////////////////////////////////////////////////
                // modify board levelNo to match startLevel
                g1.players[0]->levelNo = startLevel;
                g1.players[1]->levelNo = startLevel;
                
                // update file stream for level0
                g1.players[0]->file = file1;
                g1.players[1]->file = file2;
                g1.players[0]->level0.updateFile(g1.players[0]->file);
                g1.players[1]->level0.updateFile(g1.players[1]->file);

                // board initialization
                g1.players[0]->init();
                g1.players[1]->init();
                isPlayer0GameOver = false;
                isPlayer1GameOver = false;

                td.print();
                
                if (graphical) {
                    graph = Graph {g1.players[0].get(), g1.players[1].get(), &td};
                }
                if (graphical) {
                    graph.printGraph();
                }
                /////////////////////////////////////////
                // g1.players[1]->is_playing = false;
                break;
            } else {
                int times = cmd[0] - '0';
                int times1 = cmd[1] - '0';
                int num = 0;
                std::string subCmd;
                if (times > 9) {
                    continue;
                } else {
                    if (times1 < 9) {
                        num = times * 10 + times1;
                        subCmd = cmd.substr(2);
                    } else {
                        num = times;
                        subCmd = cmd.substr(1);
                    }
                }

                for (int i = num; i > 0; i--) {
                    if (subCmd == "left") {
                        g1.players[0]->left();
                    }
                    if (subCmd == "right") {
                        g1.players[0]->right();
                    }
                    if (subCmd == "clockwise") {
                        g1.players[0]->rot_cw();
                    }
                    if (subCmd == "counterclockwise") {
                        g1.players[0]->rot_ccw();
                    }
                    if (subCmd == "levelup") {
                        g1.players[0]->levelUp();
                    }
                    if (subCmd == "leveldown") {
                        g1.players[0]->levelDown();
                    }
                }
            }

            // moving 2 rows down due to heavy
            if (g1.players[0]->heavy) {
                g1.players[0]->down();
                if (!g1.players[0]->isMoveValid('d')) {
                    g1.players[0]->drop();
                } else {
                    g1.players[0]->down();
                }
            }


            td.print();
            if(graphical) { //TODO: to graphical
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
            } else if (cmd == "clockwise") {
                g1.players[1]->rot_cw();
            } else if (cmd == "counterclockwise") {
                g1.players[1]->rot_ccw();
            } else if (cmd == "drop") {
                if (g1.players[1]->heavy) { g1.players[1]->heavy = false; }
                if (g1.players[1]->force) { g1.players[1]->force = false; }
                if (g1.players[1]->blind) { g1.players[1]->blind = false; }

                int rowsRemoved = 0;
                g1.players[1]->drop(&rowsRemoved);

                g1.updateTopScore();
                std::cout << "next Block for player 1?" << std::endl;

                if (rowsRemoved >= 2) {
                    std::string specialAction;
                    std::cin >> specialAction;
                    if (specialAction == "heavy") {
                        g1.players[0]->heavy = true;//TODO: add blind and force option here
                    } else if (specialAction == "force") {
                        std::string type;
                        std::cin >> type;
                        if (type == "I") {
                            if (g1.players[0]->currBlock->getType() == 'I') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Iblock>();
                            }
                        } else if (type == "J") {
                            if (g1.players[0]->currBlock->getType() == 'J') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Jblock>();
                            }
                        } else if (type == "L") {
                            if (g1.players[0]->currBlock->getType() == 'L') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Lblock>();
                            }
                        } else if (type == "O") {
                            if (g1.players[0]->currBlock->getType() == 'O') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Oblock>();
                            }
                        } else if (type == "S") {
                            if (g1.players[0]->currBlock->getType() == 'S') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Sblock>();
                            }
                        } else if (type == "Z") {
                            if (g1.players[0]->currBlock->getType() == 'Z') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Zblock>();
                            }
                        } else if (type == "T") {
                            if (g1.players[0]->currBlock->getType() == 'T') {
                                continue; 
                            } else {
                                g1.players[0]->currBlock = std::make_unique<Tblock>();
                            }
                        }
                    } else if (specialAction == "blind") {
                        g1.players[0]->blind = true;
                        td.isBlind1 = true;
                    } else {
                        std::cout << "Invalid special action input" << std::endl;
                    }
                }
            } else if (cmd == "levelup") {
                g1.players[1]->levelUp();
            } else if (cmd == "leveldown") {
                g1.players[1]->levelDown();
            } else if (cmd == "I") {
                if (g1.players[1]->currBlock->getType() == 'I') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Iblock>();
                }
            } else if (cmd == "J") {
                if (g1.players[1]->currBlock->getType() == 'J') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Jblock>();
                }
            } else if (cmd == "L") {
                if (g1.players[1]->currBlock->getType() == 'L') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Lblock>();
                }
            } else if (cmd == "O") {
                if (g1.players[1]->currBlock->getType() == 'O') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Oblock>();
                }
            } else if (cmd == "S") {
                if (g1.players[1]->currBlock->getType() == 'S') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Sblock>();
                }
            } else if (cmd == "Z") {
                if (g1.players[1]->currBlock->getType() == 'Z') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Zblock>();
                }
            } else if (cmd == "T") {
                if (g1.players[1]->currBlock->getType() == 'T') { continue; }
                else {
                    g1.players[1]->currBlock = std::make_unique<Tblock>();
                }
            } else if (cmd == "restart") {
                g1.newGame();
                td.restart();
                //////////////////////////////////////////////////
                // modify board levelNo to match startLevel
                g1.players[0]->levelNo = startLevel;
                g1.players[1]->levelNo = startLevel;
                
                // update file stream for level0
                g1.players[0]->file = file1;
                g1.players[1]->file = file2;
                g1.players[0]->level0.updateFile(g1.players[0]->file);
                g1.players[1]->level0.updateFile(g1.players[1]->file);

                // board initialization
                g1.players[0]->init();
                g1.players[1]->init();
                isPlayer0GameOver = false;
                isPlayer1GameOver = false;

                td.print();
                
                if (graphical) {
                    graph = Graph {g1.players[0].get(), g1.players[1].get(), &td};
                }
                if (graphical) {
                    graph.printGraph();
                }
                /////////////////////////////////////////
                break;
            } else {
                int times = cmd[0] - '0';
                int times1 = cmd[1] - '0';
                int num = 0;
                std::string subCmd;
                if (times > 9) {
                    continue;
                } else {
                    if (times1 < 9) {
                        num = times * 10 + times1;
                        subCmd = cmd.substr(2);
                    } else {
                        num = times;
                        subCmd = cmd.substr(1);
                    }
                }

                for (int i = num; i > 0; i--) {
                    if (subCmd == "left") {
                        g1.players[1]->left();
                    }
                    if (subCmd == "right") {
                        g1.players[1]->right();
                    }
                    if (subCmd == "clockwise") {
                        g1.players[1]->rot_cw();
                    }
                    if (subCmd == "counterclockwise") {
                        g1.players[1]->rot_ccw();
                    }
                    if (subCmd == "levelup") {
                        g1.players[1]->levelUp();
                    }
                    if (subCmd == "leveldown") {
                        g1.players[1]->levelDown();
                    }
                }
            }

            // moving 2 rows down due to heavy
            if (g1.players[1]->heavy) {
                g1.players[1]->down();
                if (!g1.players[1]->isMoveValid('d')) {
                    g1.players[1]->drop();
                } else {
                    g1.players[1]->down();
                }
            }


            td.print();
            if(graphical) {
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

       //if both game over, the game loop breaks
       if (isPlayer0GameOver && isPlayer1GameOver) { 
           std::cout << "The Top Score of All players is " << g1.topScore << std::endl;
           if (g1.players[0]->topScore == g1.players[1]->topScore) {
               std::cout << "Game end in Tie!" << std::endl;
           } else if (g1.players[0]->topScore > g1.players[1]->topScore) {
               std::cout << "Player 0 is the winner!" << std::endl;
           } else {
               std::cout << "Player 1 is the winner!" << std::endl;
           }
           break;
        }
    }
}
