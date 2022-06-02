# TODO
from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Calculate avg

    l = (letters / words) * 100
    s = (sentences / words) * 100
    index = round(0.0588 * l - 0.296 * s - 15.8)

    # Check grade

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

# Count letters


def count_letters(text):
    n = 0
    for i in text:
        if i.isalpha():
            n += 1
    print(n)
    return n

# Count words


def count_words(text):
    print(text.count(" ") + 1)
    return text.count(" ") + 1

# Count sentences


def count_sentences(text):
    sentences = 0
    sentences += text.count(".")
    sentences += text.count("?")
    sentences += text.count("!")
    print(sentences)
    return sentences


main()
