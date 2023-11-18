#!/usr/local/bin/bash

# Check if the argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 /path/to/your/folder"
    exit 1
fi

# Store the provided directory path
folder_path="$1"

# Calculate MD5 hashes and sort them. Use the full path to avoid confusion.
find "$folder_path" -type f -exec md5 -r {} + | awk '{print $1, $2}' | sort > /tmp/hashes.txt

# Initialize an associative array to hold file groups by hash
declare -A file_groups

# Read the hashes and group files by MD5
while IFS=' ' read -r hash file_path; do
    file_groups[$hash]+="${file_path}"$'\n'
done < /tmp/hashes.txt

# Variable to track if any duplicates are found
duplicates_found=false

# Display duplicate groups
echo "=== Duplicate file groups ==="
for hash in "${!file_groups[@]}"; do
    # Using temporary array to handle newlines properly
    IFS=$'\n' read -d '' -r -a files <<< "${file_groups[$hash]}"

    if (( ${#files[@]} > 1 )); then
        duplicates_found=true
        echo "Group of files with hash $hash:"
        printf '%s\n' "${files[@]}"
        echo
    fi
done

# Exit if no duplicates
if ! $duplicates_found; then
    echo "No duplicate files found."
    rm /tmp/hashes.txt
    exit 0
fi

# Ask the user if they want to delete duplicates
read -p "Would you like to delete duplicates, keeping only one copy of each file? (yes/no) " delete_choice

if [[ "$delete_choice" != "yes" ]]; then
    echo "Exiting without deleting any files."
    rm /tmp/hashes.txt
    exit 0
fi

# Delete duplicate files
for hash in "${!file_groups[@]}"; do
    IFS=$'\n' read -d '' -r -a files <<< "${file_groups[$hash]}"

    if (( ${#files[@]} > 1 )); then
        echo "Duplicates for hash $hash:"
        echo "0) Keep all duplicates"
        for i in "${!files[@]}"; do
            echo "$((i+1))) ${files[i]}"
        done

        # Ask the user which file to keep
        while true; do
            read -p "Enter the number of the file you wish to keep, or 'd' to delete all: " keep_choice

            if [[ "$keep_choice" == "d" ]]; then # Delete all files
                for i in "${!files[@]}"; do
                    echo "Deleting: ${files[i]}"
                    rm -- "${files[i]}"
                done
                echo "All duplicates have been deleted."
                break
            elif (( keep_choice == 0 )); then # Keep all files
                echo "Keeping all duplicate files for hash $hash."
                break
            elif (( keep_choice >= 1 && keep_choice <= ${#files[@]} )); then
                # Convert user input to zero-based index
                keep_index=$((keep_choice-1))
                # Delete all files except the chosen one
                for i in "${!files[@]}"; do
                    if (( i != keep_index )); then
                        echo "Deleting: ${files[i]}"
                        rm -- "${files[i]}"
                    fi
                done

                echo "Kept: ${files[keep_index]}"
                break
            else
                echo "Invalid selection. Please choose a valid file number or 'd' to delete all."
            fi
        done
        echo
    fi
done

echo "Duplicate files deletion complete."

# Optional: Remove the temporary file
rm /tmp/hashes.txt
