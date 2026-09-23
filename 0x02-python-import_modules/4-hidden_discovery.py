#!/usr/bin/python3

if __name__ == "__main__":
    with open("hidden_4.pyc", "r") as file:
        names = file.read().splitlines()

for name in sorted(names):
    if not name.startswith("__"):

        print(name)
