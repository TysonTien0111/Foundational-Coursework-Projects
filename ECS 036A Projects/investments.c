#include <stdio.h>

/*
This program compares two different strategies two see whether or not it is
better to pay all your loans first before investing or to pay the minimum
amount per month for your loans and investing the rest.
*/

double user_input_loan_amount() {
	/*
	This function checks if the user input loan amount is a real number
	that is greater than or equal to 0.
	@user_loan_amount stores the user's loan amount.
	@returns: the user loan amount.
	*/

	double user_loan_amount;

	do {
		printf("Enter how much you owe in loans: ");
		scanf(" %lf", &user_loan_amount);
	} while (!(user_loan_amount >= 0));

	return user_loan_amount;
}

double user_input_annual_interest_rate() {
	/*
	This function checks if the user input annual interest rate is
	a real number that is greater than or equal to 0.
	@user_annual_interest_rate stores the user's annual interest rate.
	@returns: the user's annual interest rate.
	*/

	double user_annual_interest_rate;

	do {
		printf("Enter the annual interest rate of the loans: ");
		scanf(" %lf", &user_annual_interest_rate);
	} while (!(user_annual_interest_rate >= 0));

	return user_annual_interest_rate;
}

double user_input_minimum_monthly_loan_payment() {
	/*
	This function checks if the user input minimum monthly loan payment
	is a real number that is greater than or equal to 0.
	@user_minimum_monthly_loan_payment stores the user's minimum monthly
	loan payment.
	@return: the user's minimum monthly loan payment.
	*/

	double user_minimum_monthly_loan_payment;

	do {
		printf("Enter your minimum monthly loan payment: ");
		scanf(" %lf", &user_minimum_monthly_loan_payment);
	} while (!(user_minimum_monthly_loan_payment >= 0));

	return user_minimum_monthly_loan_payment;
}

double user_input_money_towards_loans_each_month(double user_minimum_monthly_loan_payment) {
	/*
	This function checks if the user's input for money towards loans each month is
	a real number that is greater than or equal to 0.
	@user_money_towards_loans_each_month stores the user's money towards their loans
	each month.
	returns: the user's money towards their loans each month.
	*/

	double user_money_towards_loans_each_month;

	do {
		printf("Enter how much money you will be putting towards loans/retirement each month: ");
		scanf(" %lf", &user_money_towards_loans_each_month);
	} while (!(user_money_towards_loans_each_month >= user_minimum_monthly_loan_payment));

	return user_money_towards_loans_each_month;
}

int user_input_current_age() {
	/*
	This function checks if the user's age is a real number that is greater than or
	equal to 0.
	@user_current_age stores the user's current age.
	@returns: the user's current age.
	*/

	int user_current_age;

	do {
		printf("Enter your current age: ");
		scanf(" %d", &user_current_age);
	} while (!(user_current_age >= 0));

	return user_current_age;

}

int user_input_retirement_age(int user_current_age) {
	/*
	This function checks if the user's retirement age is a real number that is
	greater than or equal to 0.
	@user_retirement_age stores the user's retirement age.
	@returns: the user retirement age.
	*/

	int user_retirement_age;

	do {
		printf("Enter the age you plan to retire at: ");
		scanf(" %d", &user_retirement_age);
	} while (!(user_retirement_age >= user_current_age));

	return user_retirement_age;
}

double user_input_investment_rate_of_return() {
	/*
	This function checks if the user's input for investment rate of return is a real
	number that is greater than or equal to 0.
	@user_investment_rate_of_return stores the user's investment rate of return.
	@returns: the user's investment rate of return.
	*/

	double user_investment_rate_of_return;

	do {
		printf("Enter your predicted annual rate of return: ");
		scanf(" %lf", &user_investment_rate_of_return);
	} while (!(user_investment_rate_of_return >= 0));

	return user_investment_rate_of_return;
}

double convert_annual_to_monthly_interest_rate(double user_annual_interest_rate) {
	/*
	This function converts the annual interest rate into a monthly one.
	@returns: the annual interest rate divided by 12.
	*/

	return user_annual_interest_rate / 12.0;
}

double convert_annual_to_monthly_investment_rate_of_return(double user_investment_rate_of_return) {
	/*
	This function converts the annual investment rate of return into a monthly one.
	@returns: the investment rate of return divided by 12.
	*/

	return user_investment_rate_of_return / 12.0;
}

double minimum_monthly_payment_strategy(double user_loan_amount, double user_minimum_monthly_loan_payment,
	double user_money_towards_loans_each_month, int user_current_age, int user_retirement_age, double monthly_interest_rate,
	double monthly_investment_rate_of_return) {
	/*
	This function calculates the investment if the user decides to pay their loans
	at the minimum required amount.
	@num_times_to_loop stores the amount of times that the for loop must loop.
	@interest_for_monthly_loans stores 0.
	@rate_of_return_for_investment stores 0.
	@loan stores the user's loan amount.
	@investment stores 0.
	@returns: the investment they would've made with this strategy.
	*/

	int num_times_to_loop = (user_retirement_age - user_current_age) * 12;
	double interest_for_monthly_loans = 0.0;
	double rate_of_return_for_investment = 0.0;
	double loan = user_loan_amount;
	double investment = 0.0;

	for (int i = 0; i < num_times_to_loop; ++i) {
		if (loan <= user_minimum_monthly_loan_payment) {
			interest_for_monthly_loans = loan * monthly_interest_rate;
			rate_of_return_for_investment = investment * monthly_investment_rate_of_return;
			loan += interest_for_monthly_loans;
			investment += rate_of_return_for_investment;
			user_minimum_monthly_loan_payment -= loan;
			investment += user_money_towards_loans_each_month - loan;
			loan = 0.0;
			interest_for_monthly_loans = 0.0;
			rate_of_return_for_investment = 0.0;
		} else {
			interest_for_monthly_loans = loan * monthly_interest_rate;
			rate_of_return_for_investment = investment * monthly_investment_rate_of_return;
			loan += interest_for_monthly_loans;
			investment += rate_of_return_for_investment;
			loan -= user_minimum_monthly_loan_payment;
			investment += (user_money_towards_loans_each_month - user_minimum_monthly_loan_payment);
			interest_for_monthly_loans = 0.0;
			rate_of_return_for_investment = 0.0;
		}
	}

	if (loan > 0) {
		investment -= loan;
	}

	return investment;
}

double pay_loan_first_strategy(double user_loan_amount, double user_money_towards_loans_each_month,
 int user_current_age, int user_retirement_age, double monthly_interest_rate,
	double monthly_investment_rate_of_return) {
	/*
	This function calculates the investment if the user decides to pay their loans
	off first.
	@num_times_to_loop stores the amount of times that the for loop must loop.
	@interest_for_monthly_loans stores 0.
	@rate_of_return_for_investment stores 0.
	@loan stores the user's loan amount.
	@investment stores 0.
	@returns: the investment they would've made with this strategy.
	*/

	int num_times_to_loop = (user_retirement_age - user_current_age) * 12;
	double interest_for_monthly_loans = 0.0;
	double rate_of_return_for_investment = 0.0;
	double loan = user_loan_amount;
	double investment = 0.0;

	for (int i = 0; i < num_times_to_loop; ++i) {
		if (loan <= user_money_towards_loans_each_month) {
			interest_for_monthly_loans = loan * monthly_interest_rate;
			rate_of_return_for_investment = investment * monthly_investment_rate_of_return;

			loan += interest_for_monthly_loans;
			investment += rate_of_return_for_investment;

			investment += (user_money_towards_loans_each_month - loan);

			loan = 0.0;
			interest_for_monthly_loans = 0.0;
			rate_of_return_for_investment = 0.0;
		} else {
			interest_for_monthly_loans = loan * monthly_interest_rate;
			rate_of_return_for_investment = investment * monthly_investment_rate_of_return;

			loan += interest_for_monthly_loans;
			investment += rate_of_return_for_investment;

			loan -= user_money_towards_loans_each_month;
			investment += (user_money_towards_loans_each_month - user_money_towards_loans_each_month);

			interest_for_monthly_loans = 0.0;
			rate_of_return_for_investment = 0.0;
		}
	}

	if (loan > 0) {
		investment -= loan;
	}

	return investment;
}

void display_best_strategy(double user_loan_amount, double user_minimum_monthly_loan_payment, double user_money_towards_loans_each_month,
	int user_current_age, int user_retirement_age, double monthly_interest_rate, double monthly_investment_rate_of_return) {
	/*
	This function displays the best strategy that the user should take.
	*/

	double minimum_monthly_payment_strat = minimum_monthly_payment_strategy(user_loan_amount, user_minimum_monthly_loan_payment,
		user_money_towards_loans_each_month, user_current_age, user_retirement_age, monthly_interest_rate, monthly_investment_rate_of_return);
	double pay_loan_first_strat = pay_loan_first_strategy(user_loan_amount, user_money_towards_loans_each_month, user_current_age,
	 user_retirement_age, monthly_interest_rate, monthly_investment_rate_of_return);

	if (minimum_monthly_payment_strat > pay_loan_first_strat) {
		printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
		printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.",
			minimum_monthly_payment_strat, pay_loan_first_strat);
	} else if (minimum_monthly_payment_strat < pay_loan_first_strat) {
		printf("You should apply all $%.2lf towards your loan before making any investments.\n", user_money_towards_loans_each_month);
		printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.",
			pay_loan_first_strat, minimum_monthly_payment_strat);
	} else {
		printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
		printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.",
			minimum_monthly_payment_strat, pay_loan_first_strat);
	}


}

int main() {
	/*
	This is the main function of the program.
	@user_loan_amount stores the user's loan amount.
	@user_annual_interest_rate stores the loan's annual interest rate.
	@user_minimum_monthly_loan_payment stores the user's minimum monthly loan payment that they have to make.
	@user_money_towards_loans_each_month stores the user's amount of money that they will put towards loans
	each month.
	@user_current_age stores the user's current age.
	@user_retirement_age stores the user's retirement age.
	@user_investment_rate_of_return stores the investment rate of return that they user has.
	@monthly_interest_rate stores the monthly interest rate of the loans.
	@monthly_investment_rate_of_return stores the monthly investment rate of return that
	the user has.
	*/

	double user_loan_amount = user_input_loan_amount();
	double user_annual_interest_rate = user_input_annual_interest_rate();
	double user_minimum_monthly_loan_payment = user_input_minimum_monthly_loan_payment();
	double user_money_towards_loans_each_month = user_input_money_towards_loans_each_month(user_minimum_monthly_loan_payment);
	int user_current_age = user_input_current_age();
	int user_retirement_age = user_input_retirement_age(user_current_age);
	double user_investment_rate_of_return = user_input_investment_rate_of_return();
	double monthly_interest_rate = convert_annual_to_monthly_interest_rate(user_annual_interest_rate);
	double monthly_investment_rate_of_return = convert_annual_to_monthly_investment_rate_of_return(user_investment_rate_of_return);

	display_best_strategy(user_loan_amount, user_minimum_monthly_loan_payment, user_money_towards_loans_each_month,
	user_current_age, user_retirement_age, monthly_interest_rate, monthly_investment_rate_of_return);

	return 0;
}
