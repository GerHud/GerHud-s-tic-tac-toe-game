#include <iostream>
#include <string>
using namespace std;

void telltable(string fields[3][3]){
    cout << "\n\n\n";
    cout << "  0_1_2\n";
    cout << "0|" << fields[0][0] << " " << fields[0][1] << " " << fields[0][2] << "\n";
    cout << "1|" << fields[1][0] << " " << fields[1][1] << " " << fields[1][2] << "\n";
    cout << "2|" << fields[2][0] << " " << fields[2][1] << " " << fields[2][2] << "\n";
}

string iswinn(string fields[3][3]){
    string win;
    /*x*/
    if(fields[0][0] == "x" && fields[1][1] == "x" && fields[2][2] == "x"){
        win = "x";
    }else if(fields[0][2] == "x" && fields[1][1] == "x" && fields[2][0] == "x"){
        win = "x";
    }else if(fields[0][0] == "x" && fields[0][1] == "x" && fields[0][2] == "x"){
        win = "x";
    }else if(fields[1][0] == "x" && fields[1][1] == "x" && fields[1][2] == "x"){
        win = "x";
    }else if(fields[2][0] == "x" && fields[2][1] == "x" && fields[2][2] == "x"){
        win = "x";
    }else if(fields[0][0] == "x" && fields[1][0] == "x" && fields[2][0] == "x"){
        win = "x";
    }else if(fields[0][1] == "x" && fields[1][1] == "x" && fields[2][1] == "x"){
        win = "x";
    }else if(fields[0][2] == "x" && fields[1][2] == "x" && fields[2][2] == "x"){
        win = "x";
    }/*o*/else if(fields[0][0] == "o" && fields[1][1] == "o" && fields[2][2] == "o"){
        win = "o";
    }else if(fields[0][2] == "o" && fields[1][1] == "o" && fields[2][0] == "o"){
        win = "o";
    }else if(fields[0][0] == "o" && fields[0][1] == "o" && fields[0][2] == "o"){
        win = "o";
    }else if(fields[1][0] == "o" && fields[1][1] == "o" && fields[1][2] == "o"){
        win = "o";
    }else if(fields[2][0] == "o" && fields[2][1] == "o" && fields[2][2] == "o"){
        win = "o";
    }else if(fields[0][0] == "o" && fields[1][0] == "o" && fields[2][0] == "o"){
        win = "o";
    }else if(fields[0][1] == "o" && fields[1][1] == "o" && fields[2][1] == "o"){
        win = "o";
    }else if(fields[0][2] == "o" && fields[1][2] == "o" && fields[2][2] == "o"){
        win = "o";
    }else{
        win = "*";
    }
    return win;
}

int main() {
    string fields[3][3] = {
        {"*","*","*"},
        {"*","*","*"},
        {"*","*","*"}
    };
    telltable(fields);
    int x,y;
    int count = 0;
    while(iswinn(fields) == "*"){
        cout << "X ist am Zug\nWähle x achse[0/1/2]:";
        cin >> x;
        cout << "Wähle y achse[0/1/2]:";
        cin >> y;
        if(fields[y][x] != "*"){
            while(true){
                cout << "Feld schon belegt\nWähle x achse[0/1/2]:";
                cin >> x;
                cout << "Wähle y achse[0/1/2]:";
                cin >> y;
                if(fields[y][x] == "*"){
                    fields[y][x] = "x";
                    count ++;
                    break;
                }
            }
        }else{
            fields[y][x] = "x";
            count ++;
        }
        telltable(fields);
        
        if(iswinn(fields) != "*"){
            break;
        }
        if(count >= 9){
            break;
        }

        cout << "O ist am Zug\nWähle x achse[0/1/2]:";
        cin >> x;
        cout << "Wähle y achse[0/1/2]:";
        cin >> y;
        if(fields[y][x] != "*"){
            while(true){
                cout << "Feld schon belegt\nWähle x achse[0/1/2]:";
                cin >> x;
                cout << "Wähle y achse[0/1/2]:";
                cin >> y;
                if(fields[y][x] == "*"){
                    fields[y][x] = "o";
                    count ++;
                    break;
                }
            }
        }else{
            fields[y][x] = "o";
            count ++;
        }
        telltable(fields);
    }
    
    cout << "Gewinner ist " << iswinn(fields) << "\n";
    return 0;
}