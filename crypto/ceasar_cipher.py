import math
import numpy
import string

print("\n Hello World, lets do some cryptography ")
print("\n We will utilize Ceasar's cipher")

ceasar=int(input("\n How many spaces do you want me to shift" ))
plaintext=input("\n Enter the lowercase, plain text that you want me to encrypt")

temp=[]
x=0

for i in plaintext:
	for j in string.ascii_lowercase:
		if string.ascii_lowercase[j]==plaintext[i]:
			temp.insert(x,j)
			x=x+1
			break

for i in range(len(temp)):
    temp[i]=(temp[i]+ceasar)%26


cipher=""
for i in range(len(temp)):
	cipher+=string.ascii_lowercase[temp[i]]

print(cipher)