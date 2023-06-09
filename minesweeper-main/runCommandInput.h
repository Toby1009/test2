/***********************************************************************
 * File: main.cpp
 * Author: B11115028
 * Create Date: 2023/04/16
 * Editor: B11115028
 * Update Date: 2023/04/25
 * Description: main
***********************************************************************/

#ifndef RUNCOMMANDINPUT_H
#define RUNCOMMANDINPUT_H

#include "Mine.h"
using namespace std;

Mine MineSweeper;

void runCommandInput()
{
    bool quitOrReply = true;

    while (quitOrReply)
    {
        string command;
        cout << "Please input Load command : " << endl;
        cin >> command;

        int row, col;
        float mine;

        if (command == "Load")
        {
            cin >> command;
            if (command == "BoardFile")
            {
                string fileName;
                cin >> fileName;
                ifstream file("./boards/" + fileName);

                MineSweeper.readFileMapRange(&file);
                quitOrReply = MineSweeper.boardSet(&file, NULL);
            }
            else if (command == "RandomCount" && MineSweeper.inputCheck(&row, &col, &mine, true))
            {
                quitOrReply = MineSweeper.randomSet(row, col, mine);
            }
            else if (command == "RandomRate" && MineSweeper.inputCheck(&row, &col, &mine, false))
            {
                // Set the mine rate
                mine = row * col * mine;

                quitOrReply = MineSweeper.randomSet(row, col, mine);
            }
        }
    }
}

#endif // RUNCOMMANDINPUT_H
