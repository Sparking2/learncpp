// Question #6
//Let’s pretend we’re writing a card game.
//a) A deck of cards has 52 unique cards(13 card ranks of 4 suits).
//Create enumerations for the card ranks(2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits(clubs, diamonds, hearts, spades).
//Those enumerators will not be used to index arrays.

#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <algorithm>
#include <random>

const int maxScore{ 21 };
const int maxDealerChance{ 17 };

enum class CardRank {
	rank_2,
	rank_3,
	rank_4,
	rank_5,
	rank_6,
	rank_7,
	rank_8,
	rank_9,
	rank_10,
	rank_jack,
	rank_queen,
	rank_king,
	rank_ace,

	rank_max
};

enum class CardSuits {
	suit_clubs,
	suit_diamonds,
	suit_hearts,
	suit_spades,
	suit_max
};

struct Card {
	CardRank cardRank{};
	CardSuits cardSuit{};
};

void printCard(const Card& card) {
	std::string code{};

	switch (card.cardRank)
	{
	case CardRank::rank_2:		code += '2';	break;
	case CardRank::rank_3:		code += '3';	break;
	case CardRank::rank_4:		code += '4';	break;
	case CardRank::rank_5:		code += '5';	break;
	case CardRank::rank_6:		code += '6';	break;
	case CardRank::rank_7:		code += '7';	break;
	case CardRank::rank_8:		code += '8';	break;
	case CardRank::rank_9:		code += '9';	break;
	case CardRank::rank_10:		code += "10";	break;
	case CardRank::rank_jack:	code += 'J';	break;
	case CardRank::rank_queen:	code += 'Q';	break;
	case CardRank::rank_king:	code += 'K';	break;
	case CardRank::rank_ace:	code += 'A';	break;
	default:
		code += '?';
		break;
	}

	switch (card.cardSuit)
	{
	case CardSuits::suit_clubs:		code += 'C'; break;
	case CardSuits::suit_diamonds:	code += 'D'; break;
	case CardSuits::suit_hearts:	code += 'H'; break;
	case CardSuits::suit_spades:	code += 'S'; break;
	default:
		code += '?';
		break;
	}

	int a{ 0 };

	std::cout << code;
}

std::array<Card, 52> createDeck() {

	std::array<Card, 52> cardDeck{};

	int cardNumber{ 0 };

	for (int suitIndex{ 0 }; suitIndex < static_cast<int>(CardSuits::suit_max); ++suitIndex) {
		for (int rankIndex{ 0 }; rankIndex < static_cast<int>(CardRank::rank_max); ++rankIndex) {

			cardDeck[cardNumber] = Card{ static_cast<CardRank>(rankIndex), static_cast<CardSuits>(suitIndex) };

			++cardNumber;
		}
	}

	return cardDeck;
}

void printDeck(const std::array<Card, 52>& deck) {
	for (const auto& card : deck) {
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

void shuffleDeck(std::array<Card, 52>& deck) {

	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle(deck.begin(), deck.end(), mt);

}

int getCardValue(const Card& card) {
	switch (card.cardRank)
	{
	case CardRank::rank_2: return 2;
	case CardRank::rank_3: return 3;
	case CardRank::rank_4: return 4;
	case CardRank::rank_5: return 5;
	case CardRank::rank_6: return 6;
	case CardRank::rank_7: return 7;
	case CardRank::rank_8: return 8;
	case CardRank::rank_9: return 9;
	case CardRank::rank_10:
	case CardRank::rank_jack:
	case CardRank::rank_queen:
	case CardRank::rank_king:
		return 10;
	case CardRank::rank_ace: return 11;
	default:
		return 0;
		break;
	}
}

int giveCard(int& index, const std::array<Card, 52>& deck) {

	auto card{ deck[index] };

	std::cout << "Card:";
	printCard(card);
	std::cout << "\n";

	int value = getCardValue(card);

	--index;

	return value;
}

void startGame() {

}

void hitOrStand() {

}


int playerTurn(const std::array<Card, 52>& deck, int& index) {

	std::cout << "Player turn:\n";

	int playerScore{};

	playerScore += giveCard(index, deck);
	playerScore += giveCard(index, deck);

	while (true)
	{
		if (playerScore > maxScore) {
			return playerScore;
		}
		else if (playerScore == maxScore) {
			return playerScore;
		}

		std::cout << "\nCurrent player score: " << playerScore << '\n';

		std::cout << "Do you want to hit or stand? (h/s): ";
		char playerSelection{};
		std::cin >> playerSelection;

		if (playerSelection == 'h')
		{
			playerScore += giveCard(index, deck);
		}
		else if (playerSelection == 's') {
			return playerScore;
		}
	}
}

int dealerTurn(const std::array<Card, 52>& deck, int& index) {
	std::cout << "Dealer turn: \n";

	int dealerScore{};
	dealerScore += giveCard(index, deck);

	while (dealerScore <= maxDealerChance)
	{
		dealerScore += giveCard(index, deck);
	}

	return dealerScore;
}


int main() {

	auto deck{ createDeck() };

	shuffleDeck(deck);

	int cardIndex = static_cast<int>(deck.size()) - 1;

	int playerScore{ playerTurn(deck, cardIndex) };

	if (playerScore > maxScore) {
		std::cout << "You busted! :( score " << playerScore << '\n';
		return 0;
	}
	else if (playerScore == maxScore) {
		std::cout << "YOU WIN MTRFKR! :)\n";
		return 0;
	}

	int dealerScore{ dealerTurn(deck,cardIndex) };

	if (dealerScore > maxScore) {
		std::cout << "Dealer busted! dealer score: " << dealerScore << " player win\n";
		return 0;
	}
	else if (dealerScore == maxScore) {
		std::cout << "Dealer win :( dealer score: " << dealerScore << '\n';
		return 0;
	}
	else if (dealerScore > playerScore) {
		std::cout << "Dealer win " << dealerScore << " vs " << playerScore << '\n';
		return 0;
	}
	else if (dealerScore < playerScore) {
		std::cout << "Player win " << playerScore << " vs " << dealerScore << '\n';
		return 0;
	}

	if (dealerScore == playerScore) {
		std::cout << "Tie :()" << '\n';
		return 0;
	}

	return 0;
}
