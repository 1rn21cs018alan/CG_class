x=int(input("Enter x:"))
y=int(input("Enter y:"))
if(x>=0 and y>=0):
    if(x>y):
        print("1st")
    else:
        print("2nd")
elif(x<0 and y>=0):
    if(-x>y):
        print("4th")
    else:
        print("3rd")
elif(x<0 and y<0):
    if(x>y):
        print("6th")
    else:
        print("5th")
else:
    if(x>-y):
        print("8th")
    else:
        print("7th")