#include <iostream>
using namespace std;

enum Choice {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
};

int P_SCORE{0}, AI_SCORE{0};

int ai_getNumber () {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    const int random_value = (std::rand() % 3) + 1;
    return random_value;
}

ostream &operator << ( ostream& strm, Choice c )
{
    const string nameC[] = { "EXIT", "ROCK", "PAPER", "SCISSORS" };
    return strm << nameC[c];
}

void Win(int p, int ai) {
    cout << "You Win! You selected "<< static_cast<Choice>(p) << ", while AI selected " << static_cast<Choice>(ai) << "! " << static_cast<Choice>(p) << " beats " << static_cast<Choice>(ai) << endl;
    P_SCORE++;
}

void Lose(int p, int ai) {
    cout << "You Lose! You selected "<< static_cast<Choice>(p) << ", while AI selected " << static_cast<Choice>(ai) << "! " << static_cast<Choice>(ai) << " beats " << static_cast<Choice>(p) << endl;
    AI_SCORE++;
}


int main () {

    int p_choice, ai_choice;
    do {
        cout << "Make a choice! 1 for rock, 2 for paper, 3 for scissors! (press 0 for exit):" <<endl;
        cin >> p_choice;
        if (p_choice < 0 || p_choice > 4) {
            cout << "Wrong Choice! Choose between 1 and 3" << endl;
            continue;
        }
        ai_choice = ai_getNumber();
        if (p_choice == ai_choice) {
            cout << "It's a draw! You've both selected " << static_cast<Choice>(p_choice) << endl;
            continue;
        }

        switch (p_choice) {
            case ROCK:
                if (ai_choice == PAPER) {
                    Lose(p_choice, ai_choice);
                } else {
                    Win(p_choice, ai_choice);
                }
                break;
            case PAPER:
                if (ai_choice == SCISSORS) {
                    Lose(p_choice, ai_choice);
                } else {
                    Win(p_choice, ai_choice);
                }
                break;
            case SCISSORS:
                if (ai_choice == ROCK) {
                    Lose(p_choice, ai_choice);
                } else {
                    Win(p_choice, ai_choice);
                }
                break;
        }

    } while (p_choice != 0);

    cout << "Your stats is: " << P_SCORE << " " << AI_SCORE << endl;

    return 0;
}