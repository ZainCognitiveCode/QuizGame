#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#include "Game.h"

class Quiz : public Game{
    private:
    struct Question {
        string questionText;
        vector<string> options;
        int correctAnswer; // Index of the correct option
    };

    vector<Question> questions; // List of questions
    int score = 0;

    public:
    Quiz(string t) : Game(t) {
        questions = {
            {"What is the capital of France?", {"Paris", "London", "Berlin", "Rome", "Madrid"}, 0},
            {"Who wrote 'Hamlet'?", {"Shakespeare", "Dickens", "Hemingway", "Tolkien", "Austen"}, 0},
            {"What is 5 + 3?", {"5", "8", "10", "7", "9"}, 1},
            {"Which planet is known as the Red Planet?", {"Earth", "Venus", "Mars", "Jupiter", "Saturn"}, 2},
            {"What is the boiling point of water?", {"50�C", "100�C", "120�C", "200�C", "90�C"}, 1}
        };
    }

    void askQuestion(const Question& q, int& score) {
        cout << q.questionText << endl;
        for (int i = 0; i < q.options.size(); i++) {
            cout << i + 1 << ". " << q.options[i] << endl;
        }

        int answer;
        cout << "Enter your choice (1-5): ";
        cin >> answer;
        if (answer - 1 == q.correctAnswer) {
            cout << "Correct!\n";
            score ++;
        }
        else {
            cout << "Wrong answer. The correct answer was: " << q.options[q.correctAnswer] << endl;
        }
    }

    void play() {
    for (const auto& question : questions) {
        askQuestion(question, score);
    }
    }

    bool checkWin(){
        if (score == questions.size()) {
            cout << "Congratulations! You answered all questions correctly and earned a Quiz Badge!\n";
            return true;
        }
        else {
            cout << "Better luck next time!\n";
            cout << "You didn't earn the badge" << endl;
            return false;
        }
    }

};