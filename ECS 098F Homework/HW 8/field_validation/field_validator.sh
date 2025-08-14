#!/usr/bin/bash

# The only command line argument is a file name
file_name=$1

passed=true

# Iterate over each line of the input file
while IFS= read -r line; do
    # Here's where you can use regex capture groups to extract the info from each line
    # You'll need to capture two pieces of data: the field name and the value of the field.
    # Put your regex with capture groups to the right of the =~ operator
    #([ \t\n\r\f\v]{1}[])|
    #([ \t\n\r\f\v]{1}[^ \t\n\r\f\v]|$)
    #([a-zA-Z_]+):[[:space:]]*([[:space:]]|[a-zA-Z0-9.&$\(#!@-]+|[a-zA-Z]+[[:space:]]*[a-zA-Z]+)


    if [[ $line =~ ([a-zA-Z_]+):[[:space:]]*(([a-zA-Z0-9.&$\(#!@\)*\-]+|[a-zA-Z]+[[:space:]]*[a-zA-Z.&$\(#!@\)*\-]+)|\s*) ]]; then
      # Recall how to access text from regex capture groups
      # See slide 15 from the lecture
      field=${BASH_REMATCH[1]}
      value=${BASH_REMATCH[2]}
    else
      # If nothing could be extracted, then skip the line
      continue
    fi


    case $field in
        first_name)
          pattern='^([A-Z]{1}[a-z]+)$'
          ;;
        last_name) 
          pattern='^([A-Z]{1}[a-z]+)$'
          ;;
        phone_number)
          pattern='^([0-9]{3}+)-([0-9]{3}+)-([0-9]{4})$'
          ;;
        # You can follow this pattern for all other fields
        email) # Case where the field name is literally the string "email"
            # Same regex for email that we used in lecture
          pattern='^[[:alnum:]_#-]+@[[:alnum:]-]+\.[[:alnum:]]{2,4}$'
          ;;
        street_number)
          pattern='^([0-9]{1,5})$'
          ;;
        street_name)
          pattern='^[[:alpha:]]+[[:space:]]*([[:alpha:]]+[[:space:]]*)*$'
          ;;
         apartment_number)
          pattern='^(|[0-9]{1,4})$'
          ;;
        city)
          pattern='^[[:alpha:]]+[[:space:]]*([[:alpha:]]+[[:space:]]*)*$'
          ;;
        state)
          pattern='^([A-Z]{2})$'
          ;;
        zip)
          pattern='^([0-9]{5})$'
          ;;
        card_number)
          pattern='^([0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4})$'
          ;;
        expiration_month)
          pattern='^([0]{1}[0-9]{1}|[1]{1}[0-2]{1})$'
          ;;
        expiration_year)
          pattern='^([2]{1}[0]{1}[2]{1}[1-9]{1}$)'
          ;;
        ccv)
          pattern='^([0-9]{3})$'
          ;;
        # Copy paste the previous example for every field, changing the email to the correct
        # field name and the pattern to the correct regex for said field
        *) # Case where there the field name didn't match anything
            continue
            ;;
    esac
    
    if ! [[ $value =~ $pattern ]]; then
        # We need to print out a message if the field isn't valid
        echo "field $field with value $value is not valid"
        passed=false
    fi

done < "$file_name"

# We need to print something if all fields were valid
# Remember, booleans are useful for this assignment
if [[ $passed = true ]]; then
    echo "purchase is valid"
    exit 0
else
    exit 1
fi
