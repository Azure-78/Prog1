def impares():
    y = 0
    for i in range(7):
        x = int(input("Dame 1 numero: "))
        if (x % 2) != 0:
            y = y + x
    print(f"Suma de impares = {y}")


def main():
    impares()


if __name__ == "__main__":
    main()
