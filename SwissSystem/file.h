#ifndef FILE_H
#define FILE_H

#include "game.h"
#include "list.h"
#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;

class File {
public:
    static void openPlayer(List<Player>* list, string file) {
        ifstream in(file);
        while (EOF) {
            int id;
            string surname;
            double result;
            in >> id;
            if (!in) break;
            in.get();
            getline(in, surname);
            in >> result;
            Player player(id, QString::fromStdString(surname), result);
            list->pushTail(player);
            in.get();
        }
        in.close();
    }

    static void savePlayer(List<Player>* list, string file) {
        ofstream on(file);
        for (int i = 0; i < list->size(); i++) {
            on << list->operator[](i).getId() << "." << list->operator[](i).getSurname().toStdString() << endl
               << list->operator[](i).getPoint() << endl;
        }
        on.close();
    }

    static void openGame(List<Game>* list, string file) {
        ifstream in(file);
        while (EOF) {
            int id;
            double result;
            in >> id;
            if (!in) break;
            in >> result;
            Game game(id, result);
            list->pushTail(game);
        }
        in.close();
    }

    static void saveGame(List<Game>* list, string file) {
        ofstream on(file);
        for (int i = 0; i < list->size(); i++) {
            on << list->operator[](i).getEnemyId() << " " << list->operator[](i).getResult() << endl;
        }
        on.close();
    }
};

#endif // FILE_H
