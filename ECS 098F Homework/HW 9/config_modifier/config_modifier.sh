#!/usr/bin/bash

target_dir=$1
mode=$2
shift 2

appendMode() {
    # Appends a new field to a pre-existing section
    #
    # Args:
    # $1: Section name
    # $2: New field name
    # $3: New field value
    section_name="$1"
    new_field_name="$2"
    new_field_value="$3"

    # Find all ini files and append the field to the specified section
    find "$target_dir" -type f -name "*.ini" -exec sed -i "/^\[$section_name\]/a$new_field_name = $new_field_value" {} \;
    echo "Appended field '$new_field_name = $new_field_value' to section '$section_name'"
}

deleteMode() {
    # Deletes the specified field
    #
    # Args:
    # $1: Field name to delete
    field_name="$1"

    # Find all ini files and delete the specified field
    find "$target_dir" -type f -name "*.ini" -exec sed -i "/^\s*$field_name\s*=/d" {} \;
    echo "Deleted field '$field_name' from all ini files"
}

subMode() {
    # Replaces the value of a particular field with a new one
    #
    # Args:
    # $1: Field name to replace
    # $2: New value
    field_name="$1"
    new_value="$2"

    # Find all ini files and replace the field value
    find "$target_dir" -type f -name "*.ini" -exec sed -i "s/^\($field_name *= *\).*/\1$new_value/" {} \;
    echo "Replaced value of field '$field_name' with '$new_value' in all ini files"
}

case $mode in
    '-a')
        appendMode "$@"
        ;;
    '-d')
        deleteMode "$@"
        ;;
    '-s')
        subMode "$@"
        ;;
    *)
        echo 'Unrecognized flag for first argument'
        exit 2
        ;;
esac
