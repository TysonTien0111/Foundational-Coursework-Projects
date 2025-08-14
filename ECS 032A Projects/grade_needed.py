def needed_score_on_final(needed_percent_for_that_grade, current_percent, weight_of_final):
    weight_of_final = weight_of_final / 100
    final_grade = (needed_percent_for_that_grade - ((1 - weight_of_final) * current_percent)) / (weight_of_final)
    return final_grade

desired_grade = input('Enter the grade you want in the class: ')
needed_percent_for_that_grade = float(input('Enter the percent you need to get that grade: '))
current_percent = float(input('Enter your current percent in the class: '))
weight_of_final = float(input('Enter the weight of the final: '))

print(f'You need to get at least {needed_score_on_final(needed_percent_for_that_grade, current_percent, weight_of_final):.2f}% on the final to get a {desired_grade} in the class.')