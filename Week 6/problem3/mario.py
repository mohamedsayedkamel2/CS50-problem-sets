# Get number of blocks from the user
# Check if the number of blocks is in range 1 to 8
# If it doesn't satisfy the condition prompt the user again
while True:
    try:
        n = int(input("Enter the number of blocks: "))
    except ValueError:
        pass
    else:
        break
while n < 1 or n > 8:
    n = int(input("Enter the number of blocks: "))

if n == 0:
    exit()

else:
    for i in range(n):
        k = n - 1
        # This loop creates n - 1 number of hashes and it iterates as long as k's value is larger than i
        while k > i:
            print(" ", end='')
            k -= 1
        j = 0
        # This loop prints a hash in the end of each line
        while j <= i:
            print("#", end='')
            i -= 1
        print("")