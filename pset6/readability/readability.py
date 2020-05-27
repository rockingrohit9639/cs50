from cs50 import get_string


def grade(para):
    letters = 0
    for c in para:
        if c.isalpha():
            letters += 1

    words_c = len(para.split())

    sentence = 0
    for stop in para:
        if stop == '.' or stop == '?' or stop == '!':
            sentence += 1

    grade = 0.0588 * (100 * letters / words_c) - 0.296 * (100 * sentence/words_c)-15.8
    if grade < 16 and grade >= 0:
        print(f"Grade : {round(grade)}")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")


para = get_string("Enter the para : ")

grade(para)