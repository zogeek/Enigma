x = input("Enter an integer between 0 and 1024: ")

try:
    x = float(x)
    if x.is_integer():
        x = int(x)
        if x < 0 or x > 1024:
            print("Your number is not between 0 and 1024.")
        else:
            print("Your number is"+x+",he is between 0 and 1024.")
    else:
        print("You entered a floating point number.")
except ValueError:
    print("You did not enter a number.")
