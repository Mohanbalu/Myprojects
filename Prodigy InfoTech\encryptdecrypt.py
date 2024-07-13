def encrypt(text, shift):
    result = ""

    # Traverse through each character in the text
    for i in range(len(text)):
        char = text[i]

        # Encrypt uppercase characters
        if char.isupper():
            result += chr((ord(char) + shift - 65) % 26 + 65)

        # Encrypt lowercase characters
        elif char.islower():
            result += chr((ord(char) + shift - 97) % 26 + 97)
        
        # Non-alphabetical characters remain the same
        else:
            result += char

    return result

def decrypt(text, shift):
    return encrypt(text, -shift)

def main():
    while True:
        choice = input("Choose an option (encrypt/decrypt/exit): ").lower()

        if choice == "exit":
            break
        elif choice not in ["encrypt", "decrypt"]:
            print("Invalid choice, please select 'encrypt', 'decrypt', or 'exit'.")
            continue

        text = input("Enter your message: ")
        shift = int(input("Enter shift value: "))

        if choice == "encrypt":
            print("Encrypted message:", encrypt(text, shift))
        elif choice == "decrypt":
            print("Decrypted message:", decrypt(text, shift))

if __name__ == "__main__":
    main()
