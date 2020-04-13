from cs50 import get_string
import re


text = get_string("Text: ")
words = len(re.findall(r'\w+', text))
S = text.count('.') + text.count('!') + text.count('?')
L = 0
text = text.split()
for ch in text:
    L += len(ch)

grade = int(0.0588 * (100 * L/words) - 0.296 * (100 * S/words) - 15.8)

if grade >= 16:
    print("Grade: 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade: {grade}")

