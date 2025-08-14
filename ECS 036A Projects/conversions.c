#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
This program converts either a temperature type or a distance type to a new temperature type or a distance type
depending on the user's wants.
*/

char is_conversion_type_format_valid() {
  /*
  This function checks if the conversion type that the user inputted is in the
  correct format.
  @user_conversion_type stores the user input.
  @should_be_newline stores the user last input.
  @return the user input.
  */

  char user_conversion_type;
  scanf(" %c", &user_conversion_type);

  char should_be_newline;
  scanf("%c", &should_be_newline);

  if (should_be_newline == '\n') {
    return user_conversion_type;
  } else {
    printf("Invalid formatting. Ending program.");
    exit(0);
  }
}

char is_conversion_type_known() {
  /*
  This function checks if the conversion type, from the user input, is known in
  the program.
  @user_conversion_type stores the function, is_conversion_type_format_valid(),
  output.
  @return the conversion type.
  */

  char user_conversion_type = is_conversion_type_format_valid();
  user_conversion_type = toupper(user_conversion_type);

  if ((user_conversion_type == 'D') || (user_conversion_type == 'T')) {
    return user_conversion_type;
  } else {
    printf("Unknown conversion type %c chosen. Ending program.", user_conversion_type);
    exit(0);
  }
}

double is_user_num_for_conversion_type_format_valid() {
  /*
  This function checks if the user number for the conversion type is in the
  correct format.
  @num_args_read stores the number of argument that was read.
  @user_num_for_conversion_type stores the user input.
  @return the user input.
  */

  double user_num_for_conversion_type;
  double num_args_read = scanf(" %lf", &user_num_for_conversion_type);

  if (num_args_read == 1) {
    return user_num_for_conversion_type;
  } else {
    printf("Invalid formatting. Ending program.");
    exit(0);
  }
}

char is_user_suffix_for_conversion_type_format_valid() {
  /*
  This function checks if the suffix inputted by the user is in the correct format.
  @user_suffix_for_conversion_type stores the user input for the suffix.
  @should_be_newline stores the user last input.
  @return the user input.
  */

  char user_suffix_for_conversion_type;
  scanf(" %c", &user_suffix_for_conversion_type);

  char should_be_newline;
  scanf("%c", &should_be_newline);

  if (should_be_newline == '\n') {
    return user_suffix_for_conversion_type;
  } else {
    printf("Invalid formatting. Ending program.");
    exit(0);
  }
}

char is_user_suffix_for_conversion_type_distance_unit_valid() {
  /*
  This function checks if the suffix inputted by the user is a valid unit.
  @user_suffix_for_conversion_type stores the function, is_user_suffix_for_conversion_type_format_valid(),
  output.
  @return the user input but in an uppercase format.
  */

  char user_suffix_for_conversion_type = is_user_suffix_for_conversion_type_format_valid();
  user_suffix_for_conversion_type = toupper(user_suffix_for_conversion_type);

  if ((user_suffix_for_conversion_type == 'I') || (user_suffix_for_conversion_type == 'F') ||
  (user_suffix_for_conversion_type == 'Y') || (user_suffix_for_conversion_type == 'M')) {
    return user_suffix_for_conversion_type;
  } else {
    printf("%c is not a valid distance type. Ending program.", user_suffix_for_conversion_type);
    exit(0);
  }
}

char is_new_unit_for_conversion_type_valid_format() {
  /*
  This function checks if the new unit inputted by the user is in the correct format.
  @user_new_unit_for_conversion_type stores the user new unit input.
  @should_be_newline stores the user last input.
  @return the user input.
  */

  char user_new_unit_for_conversion_type;
  scanf(" %c", &user_new_unit_for_conversion_type);

  char should_be_newline;
  scanf("%c", &should_be_newline);

  if (should_be_newline == '\n') {
    return user_new_unit_for_conversion_type;
  } else {
    printf("Invalid formatting. Ending program.");
    exit(0);
  }
}

char is_new_unit_for_conversion_type_distance_unit_valid() {
  /*
  This function checks if the conversion type of the new unit is a valid unit.
  @user_new_unit_for_conversion_type stores the function, is_new_unit_for_conversion_type_valid_format(),
  output.
  @return the user input in an uppercase format.
  */

  char user_new_unit_for_conversion_type = is_new_unit_for_conversion_type_valid_format();
  user_new_unit_for_conversion_type = toupper(user_new_unit_for_conversion_type);

  if ((user_new_unit_for_conversion_type == 'I') || (user_new_unit_for_conversion_type == 'F') ||
  (user_new_unit_for_conversion_type == 'Y') || (user_new_unit_for_conversion_type == 'M')) {
    return user_new_unit_for_conversion_type;
  } else {
    printf("%c is not a valid distance type. Ending program.", user_new_unit_for_conversion_type);
    exit(0);
  }
}

double inches_distance_conversion(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts inches into other distance units depending on the user new,
  desired units.
  @final_inches_conversion_value stores the new distance value and unit depending
  on the user input.
  @return the final new distance conversion depending on the user new, desired
  unit.
  */

  double final_inches_conversion_value;

  if (user_new_unit_for_conversion_type == 'F') {
    final_inches_conversion_value = user_num_for_conversion_type / 12.0;
    return final_inches_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'Y') {
    final_inches_conversion_value = user_num_for_conversion_type / 36.0;
    return final_inches_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'M') {
    final_inches_conversion_value = user_num_for_conversion_type / 63360.0;
    return final_inches_conversion_value;
  } else {
    final_inches_conversion_value = user_num_for_conversion_type;
    return final_inches_conversion_value;
  }
}

double feet_distance_converison(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts feet into the other distance units depending on the
  user input.
  @final_feet_conversion_value stores the new converted value from feet.
  @return the new converted value from feet depending on the user input.
  */

  double final_feet_conversion_value;

  if (user_new_unit_for_conversion_type == 'I') {
    final_feet_conversion_value = user_num_for_conversion_type * 12.0;
    return final_feet_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'Y') {
    final_feet_conversion_value = user_num_for_conversion_type / 3.0;
    return final_feet_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'M') {
    final_feet_conversion_value = user_num_for_conversion_type / 5280.0;
    return final_feet_conversion_value;
  } else {
    final_feet_conversion_value = user_num_for_conversion_type;
    return final_feet_conversion_value;
  }
}

double yards_distance_conversion(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts yards into other distance units depending on the user input.
  @final_yards_conversion_value stores the new converted value from yards.
  @return the new converted value from yards depending on the user input.
  */

  double final_yards_conversion_value;

  if (user_new_unit_for_conversion_type == 'I') {
    final_yards_conversion_value = user_num_for_conversion_type * 36.0;
    return final_yards_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'F') {
    final_yards_conversion_value = user_num_for_conversion_type * 3.0;
    return final_yards_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'M') {
    final_yards_conversion_value = user_num_for_conversion_type / 1760.0;
    return final_yards_conversion_value;
  } else {
    final_yards_conversion_value = user_num_for_conversion_type;
    return final_yards_conversion_value;
  }
}

double miles_distance_conversion(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts miles into other distance units depending on the user input.
  @final_miles_conversion_value stores the new converted value from miles.
  @return the new converted value from miles depending on the user input.
  */

  double final_miles_conversion_value;

  if (user_new_unit_for_conversion_type == 'I') {
    final_miles_conversion_value = user_num_for_conversion_type * 63360.0;
    return final_miles_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'F') {
    final_miles_conversion_value = user_num_for_conversion_type * 5280.0;
    return final_miles_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'Y') {
    final_miles_conversion_value = user_num_for_conversion_type * 1760.0;
    return final_miles_conversion_value;
  } else {
    final_miles_conversion_value = user_num_for_conversion_type;
    return final_miles_conversion_value;
  }
}

double distance_conversion(double user_num_for_conversion_type, char user_suffix_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts one distance value to the other depending on the user input.
  */

  if (user_suffix_for_conversion_type == 'I') {
    return inches_distance_conversion(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  } else if (user_suffix_for_conversion_type == 'F') {
    return feet_distance_converison(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  } else if (user_suffix_for_conversion_type == 'Y') {
    return yards_distance_conversion(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  } else {
    return miles_distance_conversion(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  }
}

void display_distance_final_conversion(double user_num_for_conversion_type, char user_suffix_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function displays the final distance conversion value.
  @final_distance_conversion stores the newly converted distance value that the user
  desired.
  */

  double final_distance_conversion = distance_conversion(user_num_for_conversion_type, user_suffix_for_conversion_type, user_new_unit_for_conversion_type);

  printf("%.2lf%c is %.2lf%c", user_num_for_conversion_type, user_suffix_for_conversion_type, final_distance_conversion, user_new_unit_for_conversion_type);
}

char is_user_suffix_for_conversion_type_temperature_unit_valid() {
  /*
  This function checks if the user suffix is a valid unit.
  @user_suffix_for_conversion_type stores the function, is_user_suffix_for_conversion_type_format_valid(),
  output.
  @return the user input in an uppercase format.
  */

  char user_suffix_for_conversion_type = is_user_suffix_for_conversion_type_format_valid();
  user_suffix_for_conversion_type = toupper(user_suffix_for_conversion_type);

  if ((user_suffix_for_conversion_type == 'F') || (user_suffix_for_conversion_type == 'C') ||
  (user_suffix_for_conversion_type == 'K')) {
    return user_suffix_for_conversion_type;
  } else {
    printf("%c is not a valid temperature type. Ending program.", user_suffix_for_conversion_type);
    exit(0);
  }
}

char is_new_unit_for_conversion_type_temperature_unit_valid() {
  /*
  This function checks if the new unit is a valid unit.
  @user_new_unit_for_conversion_type stores the function, is_new_unit_for_conversion_type_valid_format,
  output.
  @return the user input in an uppercase format.
  */

  char user_new_unit_for_conversion_type = is_new_unit_for_conversion_type_valid_format();
  user_new_unit_for_conversion_type = toupper(user_new_unit_for_conversion_type);

  if ((user_new_unit_for_conversion_type == 'F') || (user_new_unit_for_conversion_type == 'C') ||
  (user_new_unit_for_conversion_type == 'K')) {
    return user_new_unit_for_conversion_type;
  } else {
    printf("%c is not a valid temperature type. Ending program.", user_new_unit_for_conversion_type);
    exit(0);
  }
}

double fahrenheit_temperature_conversion(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts fahrenheit into other temperature units.
  @final_fahrenheit_conversion_value stores the final conversion value depending on the
  user new, desired unit.
  @return the final temperature conversion depending on the user new, desired unit.
  */

  double final_fahrenheit_conversion_value;

  if (user_new_unit_for_conversion_type == 'C') {
    final_fahrenheit_conversion_value = ((user_num_for_conversion_type - 32) * 5) / 9;
    return final_fahrenheit_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'K') {
    final_fahrenheit_conversion_value = ((user_num_for_conversion_type - 32) * 5) / 9 + 273.15;
    return final_fahrenheit_conversion_value;
  } else {
    final_fahrenheit_conversion_value = user_num_for_conversion_type;
    return final_fahrenheit_conversion_value;
  }
}

double celsius_temperature_conversion(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts celsius into other temperature units.
  @final_celsius_conversion_value stores the final conversion value depending
  on the user new, desired unit.
  @return the final temperature conversion depending on the user new, desired unit.
  */

  double final_celsius_conversion_value;

  if (user_new_unit_for_conversion_type == 'F') {
    final_celsius_conversion_value = ((user_num_for_conversion_type * 9) / (5)) + 32;
    return final_celsius_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'K') {
    final_celsius_conversion_value = user_num_for_conversion_type + 273.15;
    return final_celsius_conversion_value;
  } else {
    final_celsius_conversion_value = user_num_for_conversion_type;
    return final_celsius_conversion_value;
  }
}

double kelvin_temperature_conversion(double user_num_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts kelvin into the other temperature units.
  @final_kelvin_conversion_value stores the final conversion value depending
  on the user new, desired unit.
  @return the final temperature conversion value depending on the user
  new, desired unit.
  */

  double final_kelvin_conversion_value;

  if (user_new_unit_for_conversion_type == 'F') {
    final_kelvin_conversion_value = (((user_num_for_conversion_type - 273.15) * 9) / (5)) + 32;
    return final_kelvin_conversion_value;
  } else if (user_new_unit_for_conversion_type == 'C') {
    final_kelvin_conversion_value = user_num_for_conversion_type - 273.15;
    return final_kelvin_conversion_value;
  } else {
    final_kelvin_conversion_value = user_num_for_conversion_type;
    return final_kelvin_conversion_value;
  }
}

double temperature_conversion(double user_num_for_conversion_type, char user_suffix_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function converts the temperature to the new, desired unit.
  @return the fahrenheit, celsius, or kelvin temperature depending on the user input.
  */

  if (user_suffix_for_conversion_type == 'F') {
    return fahrenheit_temperature_conversion(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  } else if (user_suffix_for_conversion_type == 'C') {
    return celsius_temperature_conversion(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  } else {
    return kelvin_temperature_conversion(user_num_for_conversion_type, user_new_unit_for_conversion_type);
  }
}

void display_temperature_final_conversion(double user_num_for_conversion_type, char user_suffix_for_conversion_type, char user_new_unit_for_conversion_type) {
  /*
  This function prints/displays the final conversion of the temperature.
  @final_temperature_conversion stores the final value after the temperature conversion.
  */

  double final_temperature_conversion = temperature_conversion(user_num_for_conversion_type, user_suffix_for_conversion_type, user_new_unit_for_conversion_type);

  printf("%.2lf%c is %.2lf%c", user_num_for_conversion_type, user_suffix_for_conversion_type, final_temperature_conversion, user_new_unit_for_conversion_type);
}

int main() {
  /*
  This is the main function of the program.
  @user_conversion_type stores the user input, whether they inputted T for temperature
  or D for distance.
  @user_num_for_conversion_type stores the user input number for the conversion.
  @user_suffix_for_conversion_type stores the user suffix for the conversion.
  @user_new_unit_for_conversion_type stores the new, desired conversion from the
  user input.
  */

  char user_conversion_type;
  double user_num_for_conversion_type;
  char user_suffix_for_conversion_type;
  char user_new_unit_for_conversion_type;

  printf("Pick the type of conversion that you would like to do.\n");
  printf("T or t for temperature\n");
  printf("D or d for distance\n");

  printf("Enter your choice: ");

  user_conversion_type = is_conversion_type_known();

  if (user_conversion_type == 'D') {
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");

    user_num_for_conversion_type = is_user_num_for_conversion_type_format_valid();
    user_suffix_for_conversion_type = is_user_suffix_for_conversion_type_distance_unit_valid();

    printf("Enter the new unit type (I,F,Y,M): ");

    user_new_unit_for_conversion_type = is_new_unit_for_conversion_type_distance_unit_valid();

    display_distance_final_conversion(user_num_for_conversion_type, user_suffix_for_conversion_type, user_new_unit_for_conversion_type);
  } else {
    printf("Enter the temperature followed by its suffix (F, C, or K): ");

    user_num_for_conversion_type = is_user_num_for_conversion_type_format_valid();
    user_suffix_for_conversion_type = is_user_suffix_for_conversion_type_temperature_unit_valid();

    printf("Enter the new unit type (F, C, or K): ");

    user_new_unit_for_conversion_type = is_new_unit_for_conversion_type_temperature_unit_valid();

    display_temperature_final_conversion(user_num_for_conversion_type, user_suffix_for_conversion_type, user_new_unit_for_conversion_type);
  }

  return 0;
}
