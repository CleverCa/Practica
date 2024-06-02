#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// ��������� ��� ������������� �����
struct Card {
    string name;
    int value;
};

// ������� ��� �������� ������ ����
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

// ������� ��� ������������� ������
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for (int i = 0; i < deck.size(); ++i) {
        int randomIndex = rand() % deck.size();
        swap(deck[i], deck[randomIndex]);
    }
}

// ������� ��� ������ �����
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

// ������� ��� �������� ����� ����� � ����
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

// ������� ��� ������ ������ ����
void displayRules() {
    cout << "������� ���� � ��������:" << endl;
    cout << "1. ���� ���� - ������� ����� ����� ������� � 21, �� �� ����������� �." << endl;
    cout << "- ����� �� 2 �� 10 ����� ���������, ������ �� ��������(��������, ����� '7' ����� 7 �����)." << endl;
    cout << "- �����(J), ����(Q) � ������(K) ����� ����� 10 ����� ������." << endl;
    cout << "- ���(A) ����� ������ 1 ��� 11 �����, � ����������� �� ��������.�� ������������� ���������� ���, ����� ���������� ��������� ��������� ���������� ���� ��� ������." << endl;
    cout << "2. ����� � ����� �������� �� ��� �����. � ������ ��� ����� �������, � ������ ���� �������, � ������ - �������." << endl;
    cout << "3. ����� ����� ������, ����� ����� �������������� ����� ��� �������� ��� ������� ����� �����." << endl;
    cout << "4. ����� ���������� ����� �����, ���� ����� ��� ����� ������ 17." << endl;
    cout << "5. ���������� ������������ �� ����� �����, ������������ � 21." << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // ����� ������ ����� ������� ����
    displayRules();

    vector<Card> deck = createDeck();
    shuffleDeck(deck);

    vector<Card> playerHand;
    vector<Card> dealerHand;

    // ������� ���� ������ � ������
    playerHand.push_back(deck.back());
    deck.pop_back();
    dealerHand.push_back(deck.back());
    deck.pop_back();
    playerHand.push_back(deck.back());
    deck.pop_back();
    dealerHand.push_back(deck.back());
    deck.pop_back();

    // ����� ���� ������
    cout << "���� �����: " << endl;
    displayCard(playerHand[0]);
    displayCard(playerHand[1]);
    cout << "����: " << calculatePoints(playerHand) << endl;

    // ����� ����� ����� ������ ��������
    cout << "����� ������: " << endl;
    displayCard(dealerHand[0]);

    // ������� ���� ������
    bool playerBust = false;
    bool playerStand = false;

    while (!playerBust && !playerStand) {
        if (!playerStand) {
            string choice;
            cout << "������ ����� ��� �����? (��/���): ";
            cin >> choice;

            if (choice == "��") {
                playerHand.push_back(deck.back());
                deck.pop_back();

                // ����� ����� ����� ������
                cout << "���� ����� �����: " << endl;
                displayCard(playerHand.back());

                int points = calculatePoints(playerHand);
                cout << "����: " << points << endl;

                if (points > 21) {
                    cout << "�� ���������! �������!\n" << endl;
                    playerBust = true;
                }
            }
            else {
                playerStand = true;
            }
        }
    }


    if (!playerBust) {
        // ��������� ������ ����� ������
        cout << "����� ��������� ������ �����: " << endl;
        displayCard(dealerHand[1]);
        cout << "���� ������: " << calculatePoints(dealerHand) << endl;

        // ������� ���� ��� ������
        while (calculatePoints(dealerHand) < 17) {
            dealerHand.push_back(deck.back());
            deck.pop_back();
        }

        int playerPoints = calculatePoints(playerHand);
        int dealerPoints = calculatePoints(dealerHand);

        // ����������� ����������
        cout << "�������� ����:" << endl;
        cout << "���� ����: " << playerPoints << endl;
        cout << "���� ������: " << dealerPoints << endl;

        if (playerPoints > 21) {
            cout << "�� ���������, �������!" << endl;
        }
        else if (dealerPoints > 21 || playerPoints > dealerPoints) {
            cout << "�� ��������! �����������!" << endl;
        }
        else if (playerPoints < dealerPoints) {
            cout << "�� ���������! ����� � ��������� ���!" << endl;
        }
        else {
            cout << "�����! ����� ����!" << endl;
        }

    }

    return 0;
}

