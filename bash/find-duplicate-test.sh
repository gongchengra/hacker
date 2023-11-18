#!/usr/bin/env bash

# Create a temporary test folder
TEST_FOLDER=$(mktemp -d)
trap 'rm -rf "$TEST_FOLDER"' EXIT

# Create test files
echo "File content" > "$TEST_FOLDER/file1.txt"
cp "$TEST_FOLDER/file1.txt" "$TEST_FOLDER/file2.txt" # Duplicate
echo "Different content" > "$TEST_FOLDER/file3.txt"

# Function to simulate user input
simulate_input() {
    # Pass the simulated input to the find-duplicate
    {
        sleep 1
        echo "$1"
        sleep 1
        echo "$2"
    } | bash find-duplicate.sh "$TEST_FOLDER"
}

# Test case: Not providing any arguments
echo "Testing missing argument..."
output=$(bash find-duplicate.sh 2>&1)
expected_output="Usage: find-duplicate.sh /path/to/your/folder"
if [[ "$output" == *"$expected_output"* ]]; then
    echo "Test 1 passed!"
else
    echo "Test 1 failed! Expected '$expected_output', got '$output'"
    exit 1
fi

# Test case: Providing the wrong number of arguments
echo "Testing wrong number of arguments..."
output=$(bash find-duplicate.sh arg1 arg2 2>&1)
expected_output="Usage: find-duplicate.sh /path/to/your/folder"
if [[ "$output" == *"$expected_output"* ]]; then
    echo "Test 2 passed!"
else
    echo "Test 2 failed! Expected '$expected_output', got '$output'"
    exit 1
fi

# Test case: Finding duplicates and not deleting them
echo "Testing finding duplicates without deletion..."
output=$(simulate_input "no" "")
expected_output="No duplicate files found."
if [[ "$output" == *"$expected_output"* ]]; then
    echo "Test 3 failed! Expected no duplicates but found some."
    exit 1
else
    echo "Test 3 passed!"
fi

# Test case: Finding duplicates and deleting them (keeping one)
echo "Testing finding duplicates with deletion (keeping one)..."
output=$(simulate_input "yes" "2")
if [[ "$output" == *"All duplicates have been deleted."* ]]; then
    echo "Test 4 failed! Expected to keep one duplicate."
    exit 1
else
    echo "Test 4 passed!"
fi

# Test case: Finding duplicates and deleting them (all)
echo "Testing finding duplicates with deletion (all)..."
# Recreate a duplicate for testing
cp "$TEST_FOLDER/file3.txt" "$TEST_FOLDER/file4.txt"
output=$(simulate_input "yes" "d")
if [[ "$output" == *"Deleting"* && "$output" == *"All duplicates have been deleted."* ]]; then
    echo "Test 5 passed!"
else
    echo "Test 5 failed! Expected to delete all duplicates."
    exit 1
fi

echo "All tests passed successfully!"
