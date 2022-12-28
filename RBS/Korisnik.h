#pragma once
#include<string>

typedef struct singleUser {
    char name[10];
    int credit;

    singleUser(char _name[], int _credit) {
        strcpy(name, _name);
        credit = _credit;
    }
} singleUser;

typedef struct ctf2 {
    static singleUser users[];
    char logIme[20];
    bool successfullLogin;
} korisnikData;