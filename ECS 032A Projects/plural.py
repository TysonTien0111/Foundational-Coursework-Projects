'''Takes a noun from the user and shoots it out in its plural form'''

def main():
    '''Takes user input and returns the pluralize noun function call'''
    user_input = input('Please enter a word: ')
    return 'The plural form of ' + user_input + ' is ' + pluralize_noun(user_input) + '.'

def scan_user_input(user_input):
    '''Takes in the user input and checks each if statement until one returns true'''
    if user_input.endswith('ch'):
        return True
    elif user_input.endswith('sh'):
        return True
    elif user_input.endswith('s'):
        return True
    elif user_input.endswith('x'):
        return True
    elif user_input.endswith('z'):
        return True
    elif user_input.endswith('f'):
        return True
    elif user_input.endswith('fe'):
        return True
    elif user_input.endswith('by'):
        return True
    elif user_input.endswith('cy'):
        return True
    elif user_input.endswith('dy'):
        return True
    elif user_input.endswith('fy'):
        return True
    elif user_input.endswith('gy'):
        return True
    elif user_input.endswith('hy'):
        return True
    elif user_input.endswith('jy'):
        return True
    elif user_input.endswith('ky'):
        return True
    elif user_input.endswith('ly'):
        return True
    elif user_input.endswith('my'):
        return True
    elif user_input.endswith('ny'):
        return True
    elif user_input.endswith('py'):
        return True
    elif user_input.endswith('qy'):
        return True
    elif user_input.endswith('ry'):
        return True
    elif user_input.endswith('sy'):
        return True
    elif user_input.endswith('ty'):
        return True
    elif user_input.endswith('vy'):
        return True
    elif user_input.endswith('wy'):
        return True
    elif user_input.endswith('xy'):
        return True
    elif user_input.endswith('yy'):
        return True
    elif user_input.endswith('zy'):
        return True
    else:
        return True

def pluralize_noun(user_input):
    '''Checks each if statement until one matches and then executes that branch to pluralize the noun'''
    new_user_input = user_input
    if scan_user_input(user_input) == True:
        if user_input.endswith('ch'):
            new_user_input = new_user_input + 'es'
            return new_user_input
        elif user_input.endswith('sh'):
            new_user_input = new_user_input + 'es'
            return new_user_input
        elif user_input.endswith('s'):
            new_user_input = new_user_input + 'es'
            return new_user_input
        elif user_input.endswith('x'):
            new_user_input = new_user_input + 'es'
            return new_user_input
        elif user_input.endswith('z'):
            new_user_input = new_user_input + 'es'
            return new_user_input
        elif user_input.endswith('f'):
            x = new_user_input.rsplit('f', 1)
            x.pop(1)
            x.append('ves')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('fe'):
            x = new_user_input.rsplit('fe', 1)
            x.pop(1)
            x.append('ves')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('by'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('cy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('dy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('fy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('gy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('hy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('jy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('ky'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('ly'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('my'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('ny'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('py'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('qy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('ry'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('sy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('ty'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('vy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('wy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('xy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('yy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        elif user_input.endswith('zy'):
            x = new_user_input.rsplit('y', 1)
            x.pop(1)
            x.append('ies')
            new_user_input = ''.join(x)
            return new_user_input
        else:
            new_user_input = new_user_input + 's'
            return new_user_input

print(main())