import struct

def show_float(f):
    # Interpret float as 32-bit integer
    [u] = struct.unpack('>I', struct.pack('>f', f))
    i = 32
    bit_string = ''.join(str((u >> i) & 0x1) for i in range(i-1, -1, -1))

    print(" ".join(bit_string))
    print("|", "- " * 30, "-|")
    print("|s|{:<9}      {:<6}|{:<25}{:<20}|".format("exp", "", "mantissa", ""))
    print()

def show_double(d):
    # Interpret double as 64-bit integer
    [u] = struct.unpack('>Q', struct.pack('>d', d))
    i = 64
    bit_string = ''.join(str((u >> i) & 0x1) for i in range(i-1, -1, -1))

    print(" ".join(bit_string))
    print("|", "- " * 62, "-|")
    print("|s|{:<12}   {:<9}|{:><55}{:<48}|".format("exp", "", "mantissa", ""))
    print()

def printBinary(n, i):
    for k in range(i-1, -1, -1):
        print(1 if (n >> k) & 1 else 0, end='')
    print()

def printIEEE(f):
    # Decompose float into sign, exponent, and mantissa
    packed = struct.pack('>f', f)
    [bits] = struct.unpack('>I', packed)

    sign = (bits >> 31) & 0x1
    exponent = (bits >> 23) & 0xFF
    mantissa = bits & 0x7FFFFF

    print("{} | ".format(sign), end='')
    printBinary(exponent, 8)
    print(" | ", end='')
    printBinary(mantissa, 23)
    print()

def main():
    f = float(input("Please input the float number you want to convert:\n"))

    print("\nIEEE-754 Single-Precision representation of: {}\n".format(f))
    show_float(f)

    print("\nIEEE-754 Double-Precision representation of: {}\n".format(f))
    show_double(f)

    print("IEEE 754 representation of {} is : ".format(f))
    printIEEE(f)

if __name__ == "__main__":
    main()

