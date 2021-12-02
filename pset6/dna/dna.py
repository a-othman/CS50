import sys
import csv
import re

#checking arguments are entered properly from the cli
if len(sys.argv) != 3:
    print("error, should enter 3 CLI args")
    sys.exit(1)

database= {} #will be used to store csv data

# Reading the csv data into a dictionary
with open(sys.argv[1], 'r') as file:
    reader= csv.reader(file)
    flag= True
    for row in reader:
        # database[row[0]]= [int(i) for i in row[1:]]
        if flag:
            sequences= row[1:] #reading the names of sequences (header) from the csv
            flag= False 
            continue
        database[row[0]]= [int(i) for i in row[1:]] #reading the count of sequences per each name
# print(database)
# print(sequences)
# print(database)

# Reading the DNA sequence to be checked
with open(sys.argv[2], 'r') as file:
    dna= file.read()

#finding the length of each sequence in our data based on csv header
seq_count = [] 
for seq in sequences: 
    # print(seq)
    reg= re.compile("(?:" + seq + ")+")
    reg = reg.findall(dna)
    try:
        reg = max(reg, key= len)
    except ValueError:
        reg= []
    seq_count.append(int(len(reg)/len(seq)))

#looking up the DNA details (seq_count) in the database
found= False
for name, lengths in database.items():
    if lengths == seq_count:
        print(name)
        found= True
        break
if found != True:
    print("No match")


