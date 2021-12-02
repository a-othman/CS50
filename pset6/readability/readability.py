from cs50 import get_string

string= get_string("Text: ")
num_letters=0
num_words= len(string.split(" "))
num_sentences= 0
for i in string:
    if i.isalpha()== True:
        num_letters+=1
    elif i in "?.!":
        num_sentences+=1
# Calculating the L and S
L= 100* (num_letters/num_words)
S= 100* (num_sentences/num_words)
grade= round(0.0588 * L - 0.296 * S - 15.8)
if grade < 1:
    print("Before Grade 1")
elif grade< 16:
    print("Grade", grade)
else:
    print("Grade 16+")

