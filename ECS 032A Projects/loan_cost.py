import math
def monthly_payment(principal, annual_interest_rate, num_payments_to_be_made):
    monthly_interest_rate = annual_interest_rate / 12
    the_monthly_payment = (principal * monthly_interest_rate) / (1 - math.pow((1 + monthly_interest_rate), -num_payments_to_be_made))
    return the_monthly_payment

principal = float(input('Please enter the amount of money you borrowed: $'))
annual_interest_rate = float(input('Please enter the annual interest rate: '))
num_payments_to_be_made = int(input('Please enter the number of payments to be made: '))

print(f'A loan of ${principal:.2f} with an annual interest of {annual_interest_rate:.2f} paid off over {num_payments_to_be_made} months will have monthly payments of ${monthly_payment(principal,annual_interest_rate,num_payments_to_be_made):.2f}.')
print(f'In total, you will pay ${(monthly_payment(principal,annual_interest_rate,num_payments_to_be_made) * num_payments_to_be_made):.2f}, making the cost of your loan ${(monthly_payment(principal,annual_interest_rate,num_payments_to_be_made) * num_payments_to_be_made) - principal:.2f}.')