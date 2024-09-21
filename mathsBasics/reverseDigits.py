def rerverseDigits(n):
    revNum = 0
    while n:
        digit = n%10
        revNum = revNum*10+digit
        n//=10
        print(digit)
    return revNum

print("Reverse number: ",rerverseDigits(int(input("Enter a number: "))))