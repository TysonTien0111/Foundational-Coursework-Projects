'''This program takes in a homework directory and calculates the students' grade.'''

import math
import os


def grading():
    '''This is the main function where all other function interact
        with each other.'''

    file_data = read_csv_file()
    calculated_grade = calculate_student_grades(file_data)
    letter_grade = convert_percent_to_letter_grade(calculated_grade)
    alphabetical_order = sort_names_alphabetically(letter_grade)
    mean = mean_of_grade(letter_grade)
    median = median_of_grade(alphabetical_order)
    mode = mode_of_grade(alphabetical_order)
    standard_deviation = standard_deviation_of_grade(mean, alphabetical_order)
    display_grade(alphabetical_order, mean, median, mode, standard_deviation)


def user_file_input():
    '''This function takes in the user input'''

    user_input = input('Please enter the name of the directory containing the homeworks: ')
    return user_input


def read_csv_file():
    '''This function reads the csv file.'''

    user_file = user_file_input()
    values_of_csv_file_dict = {}
    num_of_files = 0
    i = 0

    for file_name in os.listdir(user_file):
        with open(os.path.join(os.path.abspath(user_file), file_name), 'r') as file:
            for line in file.readlines()[0:2]:
                line = line.split(',')
                line.remove('\n')
                (key, value) = line
                if key in values_of_csv_file_dict:
                    values_of_csv_file_dict[key].append(value)
                else:
                    values_of_csv_file_dict[key] = []
                    values_of_csv_file_dict[key].append(value)

    for file_name in os.listdir(user_file):
        with open(os.path.join(os.path.abspath(user_file), file_name), 'r') as file:
            for categories in file.readlines()[3:4]:
                categories = categories.strip('\n')
                categories = categories.split(',')
                for header in categories:
                    if header in values_of_csv_file_dict:
                        continue
                    else:
                        values_of_csv_file_dict[header] = []

    for file_name in os.listdir(user_file):
        num_of_files += 1
        i = 0
        with open(os.path.join(os.path.abspath(user_file), file_name), 'r') as file:
            for line in file.readlines()[4:-1]:
                line = line.strip('\n')
                line = line.split(',')
                for key, value in zip(categories, line):
                    if ((value in values_of_csv_file_dict['Last Name']) and (
                            line[1] in values_of_csv_file_dict['First Name'])) or (
                            (value in values_of_csv_file_dict['First Name']) and (
                            line[0] in values_of_csv_file_dict['Last Name'])):
                        continue
                    elif num_of_files > 1:
                        if type(values_of_csv_file_dict['Grade'][i]) == str:
                            values_of_csv_file_dict['Grade'][i] = values_of_csv_file_dict['Grade'][i].split()

                        values_of_csv_file_dict['Grade'][i].append(value)
                        i += 1
                    else:
                        values_of_csv_file_dict[key].append(value)
    num_of_files = 0

    for file_name in os.listdir(user_file):
        num_of_files += 1
        with open(os.path.join(os.path.abspath(user_file), file_name), 'r') as file:
            for line in file.readlines()[-1:-2:-1]:
                i = (len(file.readlines()) - 1)
                line = line.strip('\n')
                line = line.split(',')
                for key, value in zip(categories, line):
                    if ((value in values_of_csv_file_dict['Last Name']) and (
                            line[1] in values_of_csv_file_dict['First Name'])) or (
                            (value in values_of_csv_file_dict['First Name']) and (
                            line[0] in values_of_csv_file_dict['Last Name'])):
                        continue
                    elif num_of_files > 1:
                        if type(values_of_csv_file_dict['Grade'][i]) == str:
                            values_of_csv_file_dict['Grade'][i] = values_of_csv_file_dict['Grade'][i].split()

                        values_of_csv_file_dict['Grade'][i].append(value)
                    else:
                        values_of_csv_file_dict[key].append(value)
    num_of_files = 0

    return values_of_csv_file_dict


def calculate_student_grades(values_of_csv_file_dict):
    '''This function calculates the students grade.'''

    students_grades = string_to_integer(values_of_csv_file_dict)

    if any(isinstance(i, list) for i in students_grades['Grade']):
        for row in range(len(students_grades['Grade'])):
            for col in range(len(students_grades['Grade'][0])):
                students_grades['Grade'][row][col] = students_grades['Grade'][row][col] / students_grades['Max Points'][
                    col]
                students_grades['Grade'][row][col] = students_grades['Grade'][row][col] * \
                                                     students_grades['Percent Total'][col]
    else:
        i = 0

        for values in students_grades['Grade']:
            students_grades['Grade'][i] = values / students_grades['Max Points'][0]
            students_grades['Grade'][i] = students_grades['Grade'][i] * students_grades['Percent Total'][0]
            i += 1
        i = 0

    students_grades_calculated = calculate_sum_of_student_grade(students_grades)

    return students_grades_calculated


def string_to_integer(values_of_csv_file_dict):
    '''This function converts the list of strings into
        a list of integers for computational purposes.'''

    string_to_integer_nested_list = values_of_csv_file_dict

    for _ in range(len(string_to_integer_nested_list['Max Points'])):
        string_to_integer_nested_list['Max Points'][_] = int(string_to_integer_nested_list['Max Points'][_])

    for _ in range(len(string_to_integer_nested_list['Percent Total'])):
        string_to_integer_nested_list['Percent Total'][_] = int(string_to_integer_nested_list['Percent Total'][_])

    if any(isinstance(i, list) for i in string_to_integer_nested_list['Grade']):
        for row in range(len(string_to_integer_nested_list['Grade'])):
            for col in range(len(string_to_integer_nested_list['Grade'][0])):
                string_to_integer_nested_list['Grade'][row][col] = int(string_to_integer_nested_list['Grade'][row][col])
    else:
        for _ in range(len(string_to_integer_nested_list['Grade'])):
            string_to_integer_nested_list['Grade'][_] = int(string_to_integer_nested_list['Grade'][_])

    return string_to_integer_nested_list


def calculate_sum_of_student_grade(student_grades):
    '''This function calculates the sum of the student grade.'''

    sum_of_each_students_grade = student_grades

    if any(isinstance(i, list) for i in sum_of_each_students_grade['Grade']):
        for _ in range(len(student_grades['Grade'])):
            sum_of_each_students_grade['Grade'][_] = sum(sum_of_each_students_grade['Grade'][_])
    else:
        pass

    return sum_of_each_students_grade


def convert_percent_to_letter_grade(calculated_grade):
    '''This function converts the student's percentage grade
        into a letter grade.'''

    letter_grade = calculated_grade
    letter_grade['Letter'] = []

    for values in letter_grade['Grade']:
        if values >= 90:
            letter_grade['Letter'].append('A')
        elif (values >= 80) and (values < 90):
            letter_grade['Letter'].append('B')
        elif (values >= 70) and (values < 80):
            letter_grade['Letter'].append('C')
        elif (values >= 60) and (values < 70):
            letter_grade['Letter'].append('D')
        else:
            letter_grade['Letter'].append('F')

    return letter_grade


def display_grade(alphabetical_order, mean, median, mode, standard_deviation):
    '''This function displays all the information about the
        students' grades.'''

    last_name = {'Last Name': []}
    first_name = {'First Name': []}
    grade = {'Grade': []}
    letter = {'Letter': []}

    for row in range(len(alphabetical_order)):
        col = 0
        last_name['Last Name'].append(alphabetical_order[row][col])

    for row in range(len(alphabetical_order)):
        col = 1
        first_name['First Name'].append(alphabetical_order[row][col])

    for row in range(len(alphabetical_order)):
        col = 2
        grade['Grade'].append(alphabetical_order[row][col])

    for row in range(len(alphabetical_order)):
        col = 3
        letter['Letter'].append(alphabetical_order[row][col])

    print(f'Mean  | Median |  Mode  | Standard Deviation')
    print(f'{mean:<6.2f}|{median:>7.2f} | {mode:<7.2f}| {standard_deviation:.2f}')
    print()
    print(f'Last Name  | First Name | Percent | Letter')

    for _ in range(len(last_name['Last Name'])):
        print(
            f'{last_name["Last Name"][_]:<11}| {first_name["First Name"][_]:<11}|{grade["Grade"][_]:>8.2f} | {letter["Letter"][_]:<7}')


def mean_of_grade(letter_grade):
    '''This function calculates the mean of the grade.'''

    mean = 0
    number_of_values = 0

    for _ in letter_grade['Grade']:
        number_of_values += 1

    mean = sum(letter_grade['Grade']) / number_of_values

    return mean


def mode_of_grade(alphabetical_order):
    '''This function calculates the mode of the grade.'''

    i = 0
    numbers_list = []

    for _ in alphabetical_order:
        col = 2
        numbers_list.append(alphabetical_order[i][col])
        i += 1
    i = 0

    mode = sorted(numbers_list)
    mode = max(set(mode), key=mode.count)

    return mode


def median_of_grade(alphabetical_order):
    '''This function calculates the median of the grade.'''

    i = 0
    numbers_list = []

    for _ in alphabetical_order:
        col = 2
        numbers_list.append(alphabetical_order[i][col])
        i += 1

    length_of_grade = i // 2
    median = sorted(numbers_list)
    median = median[length_of_grade]
    i = 0

    return median


def standard_deviation_of_grade(mean, alphabetical_order):
    '''This function calculates the standard deviation of the grade.'''

    standard_deviation = 0
    values_list = []
    sum_of_values_list = []
    i = 0

    for _ in alphabetical_order:
        col = 2
        values_list.append(alphabetical_order[i][col])
        i += 1

    for value in values_list:
        sum_of_values_list.append((abs(value - mean)) ** 2)

    sum_of_values_list = sum(sum_of_values_list)
    sum_of_values_list = sum_of_values_list / i
    standard_deviation = math.sqrt(sum_of_values_list)

    return round(standard_deviation, 2)


def sort_names_alphabetically(letter_grade):
    '''This function sorts the names alphabetically.'''

    student_info = student_full_grade_info(letter_grade)
    student_info = sorted(student_info)

    return student_info


def student_full_grade_info(letter_grade):
    '''This function puts all the students' information in a list.'''

    student_grade_info_list = []
    i = 0

    for names in letter_grade['Last Name']:
        student_grade_info_list += [[]]
        student_grade_info_list[i].append(names)
        student_grade_info_list[i].append(letter_grade['First Name'][i])
        student_grade_info_list[i].append(letter_grade['Grade'][i])
        student_grade_info_list[i].append(letter_grade['Letter'][i])
        i += 1
    i = 0

    return student_grade_info_list


grading()
