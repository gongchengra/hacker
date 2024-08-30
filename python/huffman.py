import heapq
from collections import defaultdict, Counter

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(freq):
    heap = [HuffmanNode(char, freq) for char, freq in freq.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = HuffmanNode(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(heap, merged)

    return heap[0]

def generate_huffman_codes(root, current_code, codes):
    if not root:
        return

    if root.char is not None:
        codes[root.char] = current_code

    generate_huffman_codes(root.left, current_code + "0", codes)
    generate_huffman_codes(root.right, current_code + "1", codes)

def huffman_encoding(data):
    if not data:
        return "", None

    freq = Counter(data)
    root = build_huffman_tree(freq)

    codes = {}
    generate_huffman_codes(root, "", codes)

    encoded_data = ''.join(codes[char] for char in data)
    return encoded_data, codes, freq

def huffman_decoding(encoded_data, root):
    if not encoded_data or not root:
        return ""

    decoded_data = []
    current_node = root

    for bit in encoded_data:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.char is not None:
            decoded_data.append(current_node.char)
            current_node = root

    return ''.join(decoded_data)

if __name__ == "__main__":
    data = input("请输入要编码的字符串: ")

    # 原始编码
    original_encoding = ''.join(format(ord(char), '08b') for char in data)

    encoded_data, codes, freq = huffman_encoding(data)

    # 计算压缩比
    original_size = len(original_encoding)
    compressed_size = len(encoded_data)
    compression_ratio = compressed_size / original_size

    print(f"原始编码: {original_encoding}")
    print(f"霍夫曼编码: {encoded_data}")
    print(f"霍夫曼树编码表: {codes}")
    print(f"压缩比: {compression_ratio:.2f}")

    # 验证霍夫曼编码的解码
    root = build_huffman_tree(freq)
    decoded_data = huffman_decoding(encoded_data, root)
    print(f"解码后的字符串: {decoded_data}")

