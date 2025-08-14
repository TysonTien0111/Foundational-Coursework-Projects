#include <stdio.h>

/*
This program calculates the probability of having at least on special card drawn
by the user desired turn to draw by.
*/

double initial_draw_phase(double num_of_cards_in_deck, double num_of_specified_cards_in_deck, double initial_hand_size) {
	/*
	This function calculates the probability of not drawing the special card for the initial draw phase.
	@initial_draw_phase_probability stores the probability for this portion of the program.
	@returns: the initial draw phase probability.
	*/

	double initial_draw_phase_probability = 0;

	if (initial_hand_size > 0) {
		initial_draw_phase_probability = (num_of_cards_in_deck - num_of_specified_cards_in_deck) / num_of_cards_in_deck;

		for (int i = 1; i < initial_hand_size; ++i) {
			initial_draw_phase_probability = initial_draw_phase_probability * ((num_of_cards_in_deck - num_of_specified_cards_in_deck - i) /
			(num_of_cards_in_deck - i));
		}
	}

	return initial_draw_phase_probability;
}

double mulligan_phase(double num_of_cards_in_deck, double num_of_specified_cards_in_deck, double initial_hand_size, double num_of_cards_to_mulligan) {
	/*
	This function calculates the probability of not drawing the special card in the mulligan phase.
	@mulligan_phase_probability stores the probability for this portion of the program.
	@returns: the mulligan phase probability.
	*/

	double mulligan_phase_probability = 0;

	if (num_of_cards_to_mulligan > 0) {
		mulligan_phase_probability = (num_of_cards_in_deck - num_of_specified_cards_in_deck - initial_hand_size) /
		 (num_of_cards_in_deck - initial_hand_size);

		for (int i = 1; i < num_of_cards_to_mulligan; ++i) {
			mulligan_phase_probability = mulligan_phase_probability * ((num_of_cards_in_deck -
				 num_of_specified_cards_in_deck - initial_hand_size - i) /
			 (num_of_cards_in_deck - initial_hand_size - i));
		}
	}

	return mulligan_phase_probability;
}

double one_card_each_turn_phase(double num_of_cards_in_deck, double num_of_specified_cards_in_deck, double initial_hand_size, double turn_to_draw_by) {
	/*
	This function calculates the probability of not drawing the special card in the draw one card each turn phase.
	@one_card_each_turn_phase_probability stores the probability for this portion of the program.
	@returns: the draw one card each turn phase probability.
	*/

	double one_card_each_turn_phase_probability = 0;

	if (turn_to_draw_by > 0) {
		one_card_each_turn_phase_probability = (num_of_cards_in_deck - num_of_specified_cards_in_deck - initial_hand_size) /
		 (num_of_cards_in_deck - initial_hand_size);

		 for (int i = 1; i < turn_to_draw_by; ++i) {
			 one_card_each_turn_phase_probability = one_card_each_turn_phase_probability *
			 ((num_of_cards_in_deck - num_of_specified_cards_in_deck - initial_hand_size - i) /
			  (num_of_cards_in_deck - initial_hand_size - i));
		 }
	}

	return one_card_each_turn_phase_probability;
}

double calculate_final_probability(double num_of_cards_in_deck, double num_of_specified_cards_in_deck, double initial_hand_size,
double num_of_cards_to_mulligan, double turn_to_draw_by) {
	/*
	This function calculates the final probability.
	@initial_draw_phase_probability stores the initial draw phase probability.
	@mulligan_phase_probability stores the mulligan_phase_probability.
	@one_card_each_turn_phase_probability stores the one card each turn probability.
	@returns: the final probability.
	*/

	double initial_draw_phase_probability = initial_draw_phase(num_of_cards_in_deck, num_of_specified_cards_in_deck, initial_hand_size);
	double mulligan_phase_probability = mulligan_phase(num_of_cards_in_deck, num_of_specified_cards_in_deck, initial_hand_size, num_of_cards_to_mulligan);
	double one_card_each_turn_phase_probability = one_card_each_turn_phase(num_of_cards_in_deck, num_of_specified_cards_in_deck, initial_hand_size, turn_to_draw_by);


	if ((initial_draw_phase_probability > 0) && (mulligan_phase_probability > 0) && (one_card_each_turn_phase_probability > 0)) {
		return 1 - (initial_draw_phase_probability * mulligan_phase_probability * one_card_each_turn_phase_probability);
	} else if ((initial_draw_phase_probability > 0) && (mulligan_phase_probability <= 0) && (one_card_each_turn_phase_probability > 0)) {
		return 1 - (initial_draw_phase_probability * one_card_each_turn_phase_probability);
	} else if ((initial_draw_phase_probability > 0) && (mulligan_phase_probability > 0) && (one_card_each_turn_phase_probability <= 0)) {
		return 1 - (initial_draw_phase_probability * mulligan_phase_probability);
	} else {
		return 1 - (mulligan_phase_probability * one_card_each_turn_phase_probability);
	}
}

void display_final_probability(double num_of_cards_in_deck, double num_of_specified_cards_in_deck, double initial_hand_size,
double num_of_cards_to_mulligan, double turn_to_draw_by) {
	/*
	This function prints/displays the final probability value to the user.
	*/

	printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf",
	 (int)turn_to_draw_by, (int)num_of_cards_to_mulligan,
	 calculate_final_probability(num_of_cards_in_deck, num_of_specified_cards_in_deck, initial_hand_size, num_of_cards_to_mulligan,
	turn_to_draw_by));
}

int main() {
	/*
	This is the main function of the program.
	@num_of_cards_in_deck stores the number of cards in the deck.
	@num_of_specified_cards_in_deck stores the number of special cards in the deck.
	@initial_hand_size stores the inital amount of cards drawn by the user.
	@num_of_cards_to_mulligan stores the number of cards that the user wants to mulligan.
	@turn_to_draw_by stores the number of turns that the special card must be drawn by.
	*/

	int num_of_cards_in_deck;
	int num_of_specified_cards_in_deck;
	int initial_hand_size;
	int num_of_cards_to_mulligan;
	int turn_to_draw_by;

	printf("Enter how many total cards there are in the deck: ");
	scanf(" %d", &num_of_cards_in_deck);

	printf("Enter how many copies of the card that you are looking for are in the deck: ");
	scanf(" %d", &num_of_specified_cards_in_deck);

	printf("Enter your initial hand size: ");
	scanf(" %d", &initial_hand_size);

	printf("Enter how many cards you are mulliganing: ");
	scanf(" %d", &num_of_cards_to_mulligan);

	printf("Enter what turn you want to draw the card by: ");
	scanf(" %d", &turn_to_draw_by);

	display_final_probability(num_of_cards_in_deck, num_of_specified_cards_in_deck, initial_hand_size, num_of_cards_to_mulligan,
	turn_to_draw_by);

	return 0;
}
