#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Структура для представления карты
struct Card {
    string name;
    int value;
};

// Функция для создания колоды карт
vector<Card> createDeck() {
    vector<Card> deck;

    vector<string> names = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    vector<int> values = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

    for (int i = 0; i < names.size(); ++i) {
        Card card = { names[i], values[i] };
        deck.push_back(card);
    }

    return deck;
}

// Функция для перемешивания колоды
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for (int i = 0; i < deck.size(); ++i) {
        int randomIndex = rand() % deck.size();
        swap(deck[i], deck[randomIndex]);
    }
}

// Функция для вывода карты
void displayCard(Card card) {
    cout << "+-----+" << "   ";
    cout << "+-----+" << endl;
    cout << "|     |" << "   ";
    cout << "|     |" << endl;
    cout << "|  " << card.name << "  |" << "   ";
    cout << "|  " << card.name << "  |" << endl;
    cout << "|     |" << "   ";
    cout << "|     |" << endl;
    cout << "+-----+" << "   ";
    cout << "+-----+" << endl;
    cout << endl;
}

// Функция для подсчета суммы очков в руке
int calculatePoints(vector<Card> hand) {
    int totalPoints = 0;
    int aceCount = 0;

    for (Card card : hand) {
        totalPoints += card.value;
        if (card.name == "A") {
            aceCount++;
        }
    }

    while (totalPoints > 21 && aceCount > 0) {
        totalPoints -= 10;
        aceCount--;
    }

    return totalPoints;
}

// Функция для вывода правил игры
void displayRules() {
    cout << "Правила игры в Блекджек:" << endl;
    cout << "1. Цель игры - набрать сумму очков близкую к 21, но не превышающую её." << endl;
    cout << "- Карты от 2 до 10 имеют стоимость, равную их номиналу(например, карта '7' стоит 7 очков)." << endl;
    cout << "- Валет(J), дама(Q) и король(K) также стоят 10 очков каждый." << endl;
    cout << "- Туз(A) может стоить 1 или 11 очков, в зависимости от ситуации.Он автоматически выбирается так, чтобы обеспечить наилучшую возможную комбинацию карт для игрока." << endl;
    cout << "2. Игрок и дилер получают по две карты. У игрока обе карты открыты, у дилера одна открыта, а другая - закрыта." << endl;
    cout << "3. Игрок ходит первым, может взять дополнительные карты или остаться при текущей сумме очков." << endl;
    cout << "4. Дилер продолжает брать карты, пока сумма его очков меньше 17." << endl;
    cout << "5. Победитель определяется по сумме очков, приближенной к 21." << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Вывод правил перед началом игры
    displayRules();

    vector<Card> deck = createDeck();
    shuffleDeck(deck);

    vector<Card> playerHand;
    vector<Card> dealerHand;

    // Раздача карт игроку и дилеру
    playerHand.push_back(deck.back());
    deck.pop_back();
    dealerHand.push_back(deck.back());
    deck.pop_back();
    playerHand.push_back(deck.back());
    deck.pop_back();
    dealerHand.push_back(deck.back());
    deck.pop_back();

    // Вывод карт игрока
    cout << "Ваши карты: " << endl;
    displayCard(playerHand[0]);
    displayCard(playerHand[1]);
    cout << "Очки: " << calculatePoints(playerHand) << endl;

    // Вывод одной карты дилера закрытой
    cout << "Карта дилера: " << endl;
    displayCard(dealerHand[0]);

    // Игровой цикл игрока
    bool playerBust = false;
    bool playerStand = false;

    while (!playerBust && !playerStand) {
        if (!playerStand) {
            string choice;
            cout << "Хотите взять еще карту? (Да/Нет): ";
            cin >> choice;

            if (choice == "Да") {
                playerHand.push_back(deck.back());
                deck.pop_back();

                // Вывод новой карты игрока
                cout << "Ваша новая карта: " << endl;
                displayCard(playerHand.back());

                int points = calculatePoints(playerHand);
                cout << "Очки: " << points << endl;

                if (points > 21) {
                    cout << "Вы проиграли! Перебор!\n" << endl;
                    playerBust = true;
                }
            }
            else {
                playerStand = true;
            }
        }
    }


    if (!playerBust) {
        // Открываем вторую карту дилера
        cout << "Дилер открывает вторую карту: " << endl;
        displayCard(dealerHand[1]);
        cout << "Очки дилера: " << calculatePoints(dealerHand) << endl;

        // Игровой цикл для дилера
        while (calculatePoints(dealerHand) < 17) {
            dealerHand.push_back(deck.back());
            deck.pop_back();
        }

        int playerPoints = calculatePoints(playerHand);
        int dealerPoints = calculatePoints(dealerHand);

        // Определение победителя
        cout << "Итоговые очки:" << endl;
        cout << "Ваши очки: " << playerPoints << endl;
        cout << "Очки дилера: " << dealerPoints << endl;

        if (playerPoints > 21) {
            cout << "Вы проиграли, перебор!" << endl;
        }
        else if (dealerPoints > 21 || playerPoints > dealerPoints) {
            cout << "Вы победили! Поздравляем!" << endl;
        }
        else if (playerPoints < dealerPoints) {
            cout << "Вы проиграли! Удачи в следующий раз!" << endl;
        }
        else {
            cout << "Ничья! Конец игры!" << endl;
        }

    }

    return 0;
}

