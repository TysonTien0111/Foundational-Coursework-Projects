amount_to_withdraw = int(input("Please enter the amount of money you wish to withdraw: "))

one_hundred_bills = int(amount_to_withdraw / 100)
print(f'You received {one_hundred_bills} hundred(s)')

remainder = amount_to_withdraw % 100
fifty_bills = int(remainder / 50)
print(f'You received {fifty_bills} fifty(s)')

remainder2 = remainder % 50
twenty_bills = int(remainder2 / 20)
print(f'You received {twenty_bills} twenty(s)')

remainder3 = remainder2 % 20
ten_bills = int(remainder3 / 10)
print(f'You received {ten_bills} ten(s)')

remainder4 = remainder3 % 10
five_bills = int(remainder4 / 5)
print(f'You received {five_bills} five(s)')

remainder5 = remainder4 % 5
one_bills = int(remainder5 / 1)
print(f'You received {one_bills} one(s)')
