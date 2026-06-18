# Simple calculator in Python using functions and input validation.
def get_input():
    while True: #infinite loop for user input till desierd input is fed
        try:
            x = float(input("Enter x :"))
            y = float(input("Enter y :"))
            return x, y
        except ValueError:
            print("Please enter a valid number")
        

def get_choice():
    while True: #infinite loop for user choice till desierd choice is fed
        try:
            choice = int(input("Enter your choice: "))
            if 1> choice or choice > 5: #boundation for choice
                print("Invalid choice! Enter a valid choice from 1 to 5")
                continue
            else:
                return choice
        except ValueError:
            print("Invalid choice! Please enter an integer value")


print("Welcome to calculator")
print(" 1. addition\n 2. subtraction\n 3. multiplication\n 4. division\n 5. Exit ")
while True: #infinite loop for main program till user choose to exit the program

    print("Enter your choice from the menu")
    choice = get_choice() #choice function call

    if choice == 1:
        x, y = get_input()
        print(f"The addition of {x} and {y} is {x + y:.2f}")

    elif choice == 2:
        x, y = get_input()
        print(f"The difference of {x} and {y} is {x - y:.2f}")

    elif choice == 3:
        x, y = get_input()
        print(f"The product of {x} and {y} is {x * y:.2f}")

    elif choice == 4:
        x, y = get_input()
        if y==0: #zero division handling
            print("Division by zero is not possible")
        else:
            print(f"The division of {x} and {y} is {x / y:.2f}")
 
    elif choice == 5: #loop termination
        print("Thank you for using Calculator")
        break