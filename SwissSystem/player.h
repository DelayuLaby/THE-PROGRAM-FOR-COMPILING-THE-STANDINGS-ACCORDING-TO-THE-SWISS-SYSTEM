#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {
private:
    int id;
    QString surname;
    double point;

public:
    explicit Player(int id = 0, QString surname = "", double point = 0.0) : id(id), surname(surname), point(point){};

    int getId() { return id; }
    void setId(int id) { this->id = id; }
    QString getSurname() { return surname; }
    void setSurname(QString surname) { this->surname = surname; }
    double getPoint() { return point; }
    void setPoint(double point) { this->point = point; }

    Player& operator=(Player player) {
        this->id = player.id;
        this->point = player.point;
        this->surname = player.surname;
        return *this;
    }
};

#endif // PLAYER_H
