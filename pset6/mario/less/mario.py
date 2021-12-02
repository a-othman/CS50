height= input("Height: ", )
# try:
#     height= int(height)
# except ValueError:
#     height= int(input("Height: ", ))
while (int(height)<=0 or int(height) > 8):
    height= int(input("Height: ", ))

height_edited= height+1
for i in range(1, height_edited):
    print(" "*(height-i)+i*"#")
