enter_string = input('Please enter a string: ').lower()

new_string = enter_string.replace('a', 'A')
new_string = new_string.replace('e', 'E')
new_string = new_string.replace('i', 'I')
new_string = new_string.replace('o', 'O')
new_string = new_string.replace('u', 'U')

print(new_string)
