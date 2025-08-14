''''''
def main():
    ''''''
    valid_numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12',
                     '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25']
    ciphered_string = input('Please enter a string to be ciphered: ')
    num_of_shifts = input('Please enter a shift amount between 0 and 25: ')
    while not(num_of_shifts in valid_numbers):
        num_of_shifts = input('Please enter a shift amount between 0 and 25: ')


    num_of_shifts = int(num_of_shifts)
    cipher_the_string(ciphered_string, num_of_shifts)

def cipher_the_string(ciphered_string, num_of_shifts):
    ''''''
    ciphered_string = ciphered_string
    list = []
    new_list = []

    for character in ciphered_string:
        list.append(character)

    length_of_list = len(list)
    num_of_shifts = num_of_shifts

    i = 0
    while i != length_of_list:
        if (ord(list[i]) >= 65 and ord(list[i]) <= 90) or (ord(list[i]) >= 97 and ord(list[i]) <= 122):
            if ord(list[i]) >= 65 and ord(list[i]) <= 90:
                if (ord(list[i]) + num_of_shifts) > 90:
                    difference = (ord(list[i]) + num_of_shifts) - 90
                    new_num_shifts = difference
                    list.pop(i)
                    list.insert(i, '@')
                    new_list.append(chr(ord(list[i]) + new_num_shifts))
                else:
                    new_list.append(chr(ord(list[i]) + num_of_shifts))
            else:
                if (ord(list[i]) + num_of_shifts) > 122:
                    difference2 = (ord(list[i]) + num_of_shifts) - 122
                    new_num_shifts2 = difference2
                    list.pop(i)
                    list.insert(i, "`")
                    new_list.append(chr(ord(list[i]) + new_num_shifts2))
                else:
                    new_list.append(chr(ord(list[i]) + num_of_shifts))
            i += 1
        else:
            new_list.append(chr(ord(list[i])))
            i += 1


    new_list = ''.join(new_list)
    print(new_list)

main()