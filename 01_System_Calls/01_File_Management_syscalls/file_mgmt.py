#!/usr/bin/python3

def write_to_file(filename, content):
    try:
        with open(filename, "w") as file:
            file.write(content)
        print(f"Successfully wrote to {filename}")
    except IOError:
        print(f"Error writing t o {filename}")


filename = "python_test.txt"
content = "Hello, Linux from python"
write_to_file(filename, content)