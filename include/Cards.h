#include <vector>
#include <memory>

const char FACES[] = "A23456789TJQK";
const char SUITS[] = "DHCS";
const int VALUES[] = {11,2,3,4,5,6,7,8,9,10,10,10,10};

using namespace std;

struct Card{
    char face;
    char suit;
    int value;
    ostream& printCard(ostream &);
};


class Deck {
    public:    
        Deck(int size);
        void shuffle();
        shared_ptr<Card> deal();
        ostream& printHand(ostream& out);
    private:
        vector<shared_ptr<Card>> cards;
};

class Hand
{
private:    
    vector<shared_ptr<Card>> cards;
public:
    void draw(Deck& deck);
    void printHand(ostream& out);
};