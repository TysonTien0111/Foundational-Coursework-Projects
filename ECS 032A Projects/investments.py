def main():
    user_money_owed_in_loan = float(input('Enter how much money you owe in loans: '))
    while user_money_owed_in_loan < 0:
        user_money_owed_in_loan = float(input('Enter how much money you owe in loans: '))

    user_annual_interest_rate_of_loan = float(input('Enter the annual interest rate of the loans: '))
    while user_annual_interest_rate_of_loan < 0:
        user_annual_interest_rate_of_loan = float(input('Enter the annual interest rate of the loans: '))

    user_minimum_monthly_loan_payment = float(input('Enter your minimum monthly loan payment: '))
    while user_minimum_monthly_loan_payment < 0:
        user_minimum_monthly_loan_payment = float(input('Enter your minimum monthly loan payment: '))

    user_money_towards_loans_or_retirement_each_month = float(input('Enter how much money you will be '
                                                                  'putting towards loans/retirement each month: '))
    while user_money_towards_loans_or_retirement_each_month < user_minimum_monthly_loan_payment:
        user_money_towards_loans_or_retirement_each_month = float(input('Enter how much money you will be '
                                                                      'putting towards loans/retirement each month: '))

    user_age = int(input('Enter your current age: '))
    while user_age < 0:
        user_age = int(input('Enter your current age: '))

    user_age_to_retire = int(input('Enter the age you plan to retire at: '))
    while user_age_to_retire <= user_age:
        user_age_to_retire = int(input('Enter the age you plan to retire at: '))

    user_predicted_annual_rate_of_return = float(input('Enter your predicted annual rate of return: '))
    while user_predicted_annual_rate_of_return < 0:
        user_predicted_annual_rate_of_return = float(input('Enter your predicted annual rate of return: '))

    best_plan_for_user(user_annual_interest_rate_of_loan, user_predicted_annual_rate_of_return,
                       user_money_towards_loans_or_retirement_each_month,
                       user_minimum_monthly_loan_payment, user_age_to_retire, user_age, user_money_owed_in_loan)


def best_plan_for_user(user_annual_interest_rate_of_loan, user_predicted_annual_rate_of_return,
                       user_money_towards_loans_or_retirement_each_month,
                       user_minimum_monthly_loan_payment, user_age_to_retire, user_age, user_money_owed_in_loan):
    minimum_payment_route = minimum_monthly_payment_route(user_annual_interest_rate_of_loan,
                                                          user_predicted_annual_rate_of_return,
                                                          user_money_towards_loans_or_retirement_each_month,
                                                          user_minimum_monthly_loan_payment, user_age_to_retire,
                                                          user_age,
                                                          user_money_owed_in_loan)
    pay_off_loan_route = pay_off_loan_first_route(user_annual_interest_rate_of_loan,
                                                  user_predicted_annual_rate_of_return,
                                                  user_money_towards_loans_or_retirement_each_month,
                                                  user_minimum_monthly_loan_payment, user_age_to_retire, user_age,
                                                  user_money_owed_in_loan)

    if minimum_payment_route > pay_off_loan_route:
        print('You should only make minimum payments on your loans and invest the rest')
        print(f'If you do you will have ${minimum_payment_route:.2f} as opposed to ${pay_off_loan_route:.2f} when you retire.')
    elif minimum_payment_route == pay_off_loan_route:
        print('You should only make minimum payments on your loans and invest the rest')
        print(f'If you do you will have ${minimum_payment_route:.2f} as opposed to ${pay_off_loan_route:.2f} when you retire.')
    else:
        print('You should pay of all of your loans before you start investing')
        print(f'If you do you will have ${pay_off_loan_route:.2f} as opposed to ${minimum_payment_route:.2f} when you retire.')


def minimum_monthly_payment_route(user_annual_interest_rate_of_loan, user_predicted_annual_rate_of_return,
                                  user_money_towards_loans_or_retirement_each_month,
                                  user_minimum_monthly_loan_payment, user_age_to_retire, user_age,
                                  user_money_owed_in_loan):
    monthly_loan_interest_rate = annual_to_monthly_loan_interest(user_annual_interest_rate_of_loan)
    user_monthly_rate_of_return = annual_to_monthly_rate_of_return(user_predicted_annual_rate_of_return)
    user_loan = user_money_owed_in_loan
    user_left_over_cash = 0.0
    user_loan_earn_interest = 0.0
    user_investment = 0.0
    user_investment_earn_interest = 0.0
    money_available_to_invest = user_money_towards_loans_or_retirement_each_month - user_minimum_monthly_loan_payment
    how_many_times_to_loop = (user_age_to_retire - user_age) * 12
    i = 1

    while i <= how_many_times_to_loop:
        if user_loan < user_minimum_monthly_loan_payment and user_loan != 0:
            user_loan_earn_interest = user_loan * monthly_loan_interest_rate
            user_loan = user_loan + user_loan_earn_interest
            user_investment_earn_interest = user_investment * user_monthly_rate_of_return
            user_investment = user_investment + user_investment_earn_interest
            user_loan = user_loan - user_minimum_monthly_loan_payment
            user_left_over_cash = user_loan * (-1)
            user_loan = 0
            user_investment = user_investment + money_available_to_invest + user_left_over_cash
        elif user_loan == 0:
            user_investment_earn_interest = user_investment * user_monthly_rate_of_return
            user_investment = user_investment + user_investment_earn_interest + user_money_towards_loans_or_retirement_each_month
        else:
            user_loan_earn_interest = user_loan * monthly_loan_interest_rate
            user_loan = user_loan + user_loan_earn_interest
            user_investment_earn_interest = user_investment * user_monthly_rate_of_return
            user_investment = user_investment + user_investment_earn_interest
            user_loan = user_loan - user_minimum_monthly_loan_payment
            user_investment = user_investment + money_available_to_invest
        i += 1

    if user_loan > 0:
        user_investment -= user_loan

    return round(user_investment, 2)


def annual_to_monthly_loan_interest(user_annual_interest_rate_of_loan):
    return user_annual_interest_rate_of_loan / 12


def annual_to_monthly_rate_of_return(user_predicted_annual_rate_of_return):
    return user_predicted_annual_rate_of_return / 12


def pay_off_loan_first_route(user_annual_interest_rate_of_loan, user_predicted_annual_rate_of_return,
                             user_money_towards_loans_or_retirement_each_month,
                             user_minimum_monthly_loan_payment, user_age_to_retire, user_age,
                             user_money_owed_in_loan):
    monthly_loan_interest_rate2 = annual_to_monthly_loan_interest(user_annual_interest_rate_of_loan)
    user_monthly_rate_of_return2 = annual_to_monthly_rate_of_return(user_predicted_annual_rate_of_return)
    user_loan2 = user_money_owed_in_loan
    user_left_over_cash2 = 0.0
    user_loan_earn_interest2 = 0.0
    user_investment2 = 0.0
    user_investment_earn_interest2 = 0.0
    how_many_times_to_loop2 = (user_age_to_retire - user_age) * 12
    i = 1

    while i <= how_many_times_to_loop2:
        if user_loan2 < user_money_towards_loans_or_retirement_each_month and user_loan2 != 0:
            user_loan_earn_interest2 = user_loan2 * monthly_loan_interest_rate2
            user_loan2 = user_loan2 + user_loan_earn_interest2
            user_investment_earn_interest2 = user_investment2 * user_monthly_rate_of_return2
            user_investment2 = user_investment2 + user_investment_earn_interest2
            user_loan2 = user_loan2 - user_money_towards_loans_or_retirement_each_month
            user_left_over_cash2 = user_loan2 * (-1)
            user_loan2 = 0
            user_investment2 = user_investment2 + user_left_over_cash2
        elif user_loan2 == 0:
            user_investment_earn_interest2 = user_investment2 * user_monthly_rate_of_return2
            user_investment2 = user_investment2 + user_investment_earn_interest2 + user_money_towards_loans_or_retirement_each_month
        else:
            user_loan_earn_interest2 = user_loan2 * monthly_loan_interest_rate2
            user_loan2 = user_loan2 + user_loan_earn_interest2
            user_investment_earn_interest2 = user_investment2 * user_monthly_rate_of_return2
            user_investment2 = user_investment2 + user_investment_earn_interest2
            user_loan2 = user_loan2 - user_money_towards_loans_or_retirement_each_month
            user_investment2 = user_investment2
        i += 1

    if user_loan2 > 0:
        user_investment2 -= user_loan2

    return round(user_investment2, 2)


main()
