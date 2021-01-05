//
// Created by nick on 04.01.21.
//

#include "Client.h"

void Client::update(int s) {
    // print the changed values
    score += s;

}

int Client::getScore() {
    return score;
}
