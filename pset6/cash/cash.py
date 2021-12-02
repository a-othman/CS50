import cs50
num_coins = 0
cash = cs50.get_float("Change owed: ")
while cash<0:
    cash = cs50.get_float("Change owed: ")

cash = int(round(cash*100, 2)) 

while cash> 0:
    if cash>= 25:
        cash -= 25
        num_coins+=1
        
    elif (cash>= 10 and cash< 25):
        cash-=10
        num_coins+=1
    elif (cash>=5 and cash< 10):
        cash-=5
        num_coins+=1
    else:
        cash-=1
        num_coins+=1

print(num_coins)
