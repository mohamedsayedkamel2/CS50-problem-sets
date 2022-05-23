import cs50

while True:
    money = cs50.get_float('Enter money amount: ')
    if money > 0:
        cents = round(money * 100)
        coins = 0

        # Get quarters values (25¢)
        quarters = int(cents / 25)
        # Calulate dime value (10¢)
        dime = int((cents % 25) / 10)
        # Calulate nickels value (5¢)
        nickels = int(((cents % 25) % 10) / 5)
        # Calulate pennies value (1¢)
        pennies = int(((cents % 25) % 10) % 5)

        coins = coins + quarters
        if dime > 0:
            coins = coins + dime
        if nickels > 0:
            coins = coins + nickels
        if pennies > 0:
            coins = coins + pennies

        print(coins)
        break